// ============================================================
// Патч поверх Namalsk Survival (EVRStorm / EVRConstants).
// Оригинальные файлы мода НЕ трогаем и не репакуем - это
// отдельный аддон, который патчит классы через modded class.
// ============================================================

modded class EVRConstants
{
	// Урон при попадании под выброс без укрытия (было 50.0)
	static const float DAMAGE_WHEN_UNSAFE = 70.0;

	// Шок при попадании (было 10.0) - чем меньше, тем сильнее вырубает игрока
	static const float SHOCK_WHEN_UNSAFE = 10.0;

	// Радиус гарантированной смерти у самого шара (было 200)
	static const float ANOMALY_KILL_RADIUS = 1000;
}

modded class EVRStorm
{
	// -----------------------------------------------------------
	// ГДЕ появляется сам шар (аномалия). Это m_Position/m_AnomalyPosition,
	// задаётся через GetEventPosition() - вызывается один раз в
	// конструкторе EVRStorm(). НЕ связано с местом телепорта.
	// Список точек - при каждом новом выбросе шар случайно берёт
	// одну из них. Добавляйте/убирайте точки, размер списка не важен.
	// -----------------------------------------------------------
	static const ref array<vector> ORB_SPAWN_POSITIONS = {
        "1569 450 13822",  // тисы
		"8144 565 9099"    // "8145 565 9095"
	};

	// -----------------------------------------------------------
	// КУДА телепортирует шар игроков. Это m_TeleportPosition,
	// задаётся через GetRandomTeleportPosition() - тоже вызывается
	// один раз в конструкторе, но отдельно от места спавна шара.
	// Можно указать ту же точку, что и выше, а можно другую.
	// -----------------------------------------------------------
	static const vector CUSTOM_TELEPORT_POSITION = "13574 43 2921";

	// -----------------------------------------------------------
	// Classname предмета, который игрок ДОЛЖЕН держать в руках,
	// чтобы шар вообще его телепортировал. Без этого предмета в
	// руках - шар игрока просто игнорирует (не телепортирует).
	// -----------------------------------------------------------
	static const string REQUIRED_HAND_ITEM = "TacticalBaconCan";

	// Место появления самого шара. Оригинал делает свитч по карте
	// (namalsk/deerisle/chernarusplus/enoch) - нам нужен только Чернорусь.
	//
	// ВАЖНО: GetEventPosition() вызывается НЕЗАВИСИМО на сервере И на
	// каждом клиенте отдельно (NamEventManager не передаёт координаты
	// по сети, только event_type/phase/time) - поэтому GetRandomElement()
	// тут нельзя, каждая сторона получит свой случайный результат и
	// возникнет рассинхрон (кто-то видит шар, кто-то нет).
	//
	// GetGame().GetTime() тут не подходит - это мс с момента старта
	// именно ЭТОГО процесса (сервера/клиента по отдельности), а не
	// общее сетевое время, поэтому корзины расходились. Берём вместо
	// этого игровую дату/время МИРА (GetWorld().GetDate) - она честно
	// синхронна для всех (иначе погода/освещение отличались бы).
	override vector GetEventPosition()
	{
		int year, month, day, hour, minute;
		GetGame().GetWorld().GetDate(year, month, day, hour, minute);

		int index = (hour * 60 + minute) % ORB_SPAWN_POSITIONS.Count();
		return ORB_SPAWN_POSITIONS[index];
	}

	// Место, куда шар телепортирует объекты (m_TeleportPosition).
	// Оригинал зовёт этот метод БЕЗ аргументов из конструктора для
	// рандомной точки - здесь возвращаем фиксированную свою.
	override vector GetRandomTeleportPosition(float x = 5467, float z = 8660, float radius = 5250)
	{
		return CUSTOM_TELEPORT_POSITION;
	}

	// -----------------------------------------------------------
	// Полностью переопределённый UpdateServer - 1:1 копия оригинала
	// (см. EVRStorm.c) с одной вставкой: если объект - игрок и в
	// руках у него не REQUIRED_HAND_ITEM, шар его пропускает (continue)
	// и не телепортирует вообще.
	// -----------------------------------------------------------
	override void UpdateServer()
	{
		if (m_CanTeleport && EVRConstants.ALLOW_TELEPORTING) {
			array<Object> objects = {};
			array<CargoBase> cargos = {};
			GetGame().GetObjectsAtPosition3D(m_AnomalyPosition, m_AnomalyScale * 4.5 * 1.5, objects, cargos);
			foreach (Object object: objects) {
				Transport transport;
				PlayerBase player;

				// Dont want to teleport buildings, or things like #animator and #particlesourceenf
				if (object.IsInherited(BuildingSuper) || object.GetType()[0] == "#") {
					continue;
				}

				// Get HierarchyRoot
				Object parent = object;
				while (parent) {
					object = parent;
					parent = Object.Cast(object.GetParent());
				}

				// --- НАША ВСТАВКА: телепортируем ТОЛЬКО игрока с нужным предметом в руках.
				// Всё остальное (брошенные предметы, машины, животные, любые другие
				// объекты) - гарантированно пропускаем, никаких исключений.

				// Объект уже обработан в этом тике (например, предмет в руках попал
				// в objects отдельной записью и после резолва в root совпал с игроком,
				// который уже телепортирован) - не трогаем повторно.
				if (m_TeleportedObjects.Find(object) != -1) {
					continue;
				}

				PlayerBase hand_check_player;
				if (!Class.CastTo(hand_check_player, object)) {
					// Не игрок (машина / брошенный предмет / прочее) - шар это игнорирует
					continue;
				}

				ItemBase hand_item = ItemBase.Cast(hand_check_player.GetHumanInventory().GetEntityInHands());
				if (!hand_item || !hand_item.IsKindOf(REQUIRED_HAND_ITEM)) {
					continue;
				}
				// --- конец вставки ---

				// Save object that was teleported so sound is only played once
				if (m_TeleportedObjects.Find(object) == -1) {
					m_TeleportedObjects.Insert(object);
					PlayEnvironmentSoundServer(BlowoutSound.Blowout_Teleport, object.GetPosition());
					PlayTeleportFlashServer(object.GetPosition() + vector.Direction(m_AnomalyPosition, object.GetPosition()) * 0.25);
				}

				int apsi_warning_color = COLOR_RED;
				string apsi_warning_text = "LINK NOT ESTABLISHED";

				if (IsAnomalyStable() && !m_ForceRandomTeleport && GetA3Chamber() && !Class.CastTo(transport, object)) {
					TeleportObject( object, GetA3Chamber().GetTeleportPosition(), IsAnomalyStable() );
					apsi_warning_color = COLOR_GREEN;
					apsi_warning_text = "TELEPORTATION SUCCESSFUL";
				} else {
					TeleportObject( object, m_TeleportPosition, IsAnomalyStable() );
				}

				// Предмет, который "открыл портал", исчезает - удаляем ПОСЛЕ того,
				// как телепорт уже точно вызван, чтобы не мешать резолву объекта выше.
				GetGame().ObjectDelete(hand_item);

				// This is only the case when the orb is in A3 already
				if (m_ForceRandomTeleport) {
					continue;
				}

				if (Class.CastTo(player, object)) {
					GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayAPSIWarningSignalToPlayer, 2000, false, apsi_warning_text, apsi_warning_color, player);
					GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayLEHSWarningSignalToPlayer, 2000, false, apsi_warning_text, apsi_warning_color, player);
				}

				// This is edge-casey, but if you are wearing an APSI in a car, we want to
				// warn the passengers
				if (Class.CastTo(transport, object)) {

					if (IsAnomalyStable()) {
						apsi_warning_color = COLOR_YELLOW;
						apsi_warning_text = "TELEPORTATION OVERLOAD";
					}

					for (int i = 0; i < transport.CrewSize(); i++) {
						Human human = transport.CrewMember(i);
						if (human) {
							GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayAPSIWarningSignalToPlayer, 2000, false, apsi_warning_text, apsi_warning_color, human);
							GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayLEHSWarningSignalToPlayer, 2000, false, apsi_warning_text, apsi_warning_color, human);
						}
					}
				}
			}
		}
	}

	// На Чернорусе нет реактора A3 (GetFlaxCore() всегда null), поэтому
	// IsAnomalyStable() всегда возвращает false. Это значит, что
	// TeleportObject() каждый раз бьёт телепортированного игрока в шок
	// (сбивает с ног), если на нём нет APSI-очков/LEHS-шлема - см.
	// оригинальный TeleportObject(). Если хотите ОТКЛЮЧИТЬ этот нокдаун
	// при телепортации - раскомментируйте override ниже.
	/*
	override bool IsAnomalyStable()
	{
		return true;
	}
	*/

	// -----------------------------------------------------------
	// ФИКС: "телепорт без шара на алтаре" + скачок размера шара.
	//
	// В оригинальном MidPhaseServer() (см. EVRStorm.c) есть блок,
	// который проверяет ТОЛЬКО GetA3Chamber() (без учёта IsAnomalyStable()):
	//
	//     if (GetA3Chamber()) {
	//         m_CanTeleport = true;
	//         m_ForceRandomTeleport = true;
	//         thread LerpAnomalyScaleServer(0.01, 0.375, 0.5);
	//         thread SetAnomalyPosition(GetA3Chamber().GetAnomalyPosition());
	//         ...
	//     }
	//
	// Если на карте есть объект land_a3_chamber ("алтарь"), эта ветка
	// срабатывает независимо от карты/реактора: она резко сдвигает
	// m_AnomalyPosition (реальную зону поимки объектов в UpdateServer)
	// на алтарь - при этом видимый шар в этот момент улетает вверх на
	// исходной точке спавна (LerpAnomalyPositionServer чуть выше по коду).
	// Отсюда телепорт "без шара" у алтаря.
	//
	// Тем же вызовом резко передёргивается m_AnomalyScale (лерп с 0.01
	// заново, хотя реальное текущее значение уже ~0.65, и рост только
	// до 0.375 за 0.5 сек) - отсюда рассинхрон "шар маленький, а границы
	// (m_AnomalyScale * 4.5 * 1.5) больше видимого шара".
	//
	// GetTeleportPosition()/TELEPORT_DESTINATIONS в land_a3_chamber.c -
	// это координаты именно намальской A3-камеры, нам они не нужны.
	//
	// Возвращаем null - весь этот блок (и другие if (GetA3Chamber())
	// в EVRStorm.c: включение/выключение подсветки самого алтаря)
	// просто перестаёт срабатывать. Сам алтарь как постройка никуда не
	// девается - отключается только его влияние на логику шторма.
	// -----------------------------------------------------------
	override land_a3_chamber GetA3Chamber()
	{
		return null;
	}
}
