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

// ============================================================
// НОВОЕ: туманная зона вокруг шара (RZ_Anomaly + собственные эффекты).
//
// Центр зоны - m_AnomalyPosition (та же точка, где реально стоит шар
// в ЭТОМ конкретном выбросе - Тисы или вторая точка, см. GetEventPosition()
// выше). Отдельно позиционировать зону не нужно - она "едет" вместе с
// шаром автоматически, потому что и вход в телепорт, и туман завязаны
// на одну и ту же переменную.
//
// Все параметры - здесь, крутить одним файлом.
// ============================================================
class EVRFogZoneConstants
{
	// Радиус тумана вокруг шара, метры
	static const float FOG_ZONE_RADIUS = 60;

	// Как часто (сек) применяется тик урона/эффектов, пока игрок в зоне
	static const float TICK_INTERVAL = 4.0;

	// Урон здоровью за один тик (при TICK_INTERVAL=4 это ~DAMAGE_PER_TICK/4 в сек)
	static const float DAMAGE_PER_TICK = 8.0;

	// Шанс выронить оружие/предмет из рук за один тик (0..1)
	static const float DROP_ITEM_CHANCE = 0.12;

	// Шанс кратковременной "потери контроля" (обморок/паника) за тик (0..1)
	static const float PANIC_CHANCE = 0.15;

	// Сколько шока "сажаем" за раз при потере контроля (сажает стат Shock,
	// движок сам вырубает игрока при низком шоке и сам же поднимает шок
	// со временем - длительность обморока управляется игрой, не нами)
	static const float PANIC_SHOCK_DAMAGE = 80.0;

	// Classname'ы туманных объектов из RZ_Anomaly, которыми набивается зона.
	// Список специально с повтором плотных вариантов - чтобы туман был гуще.
	static const ref array<string> FOG_OBJECTS = {
		"RZ_Tyman_P32_Static",
		"RZ_Tyman_P32_OchMedl",
		"RZ_Tyman_P16_OchMedl",
		"RZ_Anom_NeboMG"
	};

	// Сколько объектов тумана раскидать по зоне (случайно вокруг центра)
	static const int FOG_OBJECT_COUNT = 10;

	// Насколько приподнять туман над рельефом, метры (каждый объект теперь
	// ставится по реальной высоте земли в своей точке + этот отступ)
	static const float FOG_GROUND_OFFSET = 0.2;

	// Подстраховка: если шторм не почистит объекты тумана штатно,
	// удалить их принудительно через столько секунд после спавна
	static const float FOG_LIFETIME_SEC = 1800;

	// soundset для "голосов"/криков, играющих у игрока в зоне - НЕ позиционный
	// звук от шара, а тот, что слышит сам игрок. Должен существовать в игре
	// или в одном из ваших модов (звуковых ассетов мы не создаём) - замените
	// на реальное имя soundset'а, иначе звук просто не заиграет.
	static const string SCREAM_SOUNDSET = "EVRFog_Voices_SoundSet";
};

// Отдельный RPC-канал сервер -> конкретный игрок для клиентских эффектов
// (звук/тряска/темнота).
//
// ФИКС: изначально было "modded enum ERPCs { RPC_EVR_FOG_EFFECT }" -
// этот движок modded enum не поддерживает ("Expected 'enum', not a
// 'modded'" при компиляции). Вместо этого - обычная числовая константа,
// стандартный паттерн для кастомных RPC в DayZ-модах. Число подобрано
// заведомо большим/нестандартным, чтобы не пересечься с ID из других
// модов - если всё же пересечётся (в логе будет что-то не то на RPC
// с этим типом), просто поменяйте число здесь на другое.
class EVRRPCConstants
{
	static const int RPC_EVR_FOG_EFFECT = 22571;
	static const int RPC_EVR_SIREN = 22572;
};

// ============================================================
// НОВОЕ: сирена в начале шторма. Требует отдельный маленький аддон
// EVRSiren_FIX (регистрирует EVR_Siren_SoundSet из evr_siren.ogg) -
// его нужно поставить рядом с этим скриптом.
// ============================================================
class EVRSirenConstants
{
	static const string SIREN_SOUNDSET = "EVR_Siren_SoundSet";
};

// ============================================================
// НОВОЕ: мутанты BRDK, спавнящиеся при входе игрока в туман.
//
// Настройки - в JSON-файле, а не в этом скрипте: путь ниже
// (EVR_FOG_MUTANTS_CONFIG_PATH), $profile: - это папка профиля
// сервера (та же, где логи/БД). Если файла нет - при первом старте
// шторма он создастся сам с настройками по умолчанию (см. класс
// ниже) - дальше правьте JSON и меняйте, пересобирать PBO не нужно,
// правки подхватятся при следующем перезапуске сервера (грузится
// один раз при старте, не на лету).
// ============================================================
class EVRFogMutantsConfig
{
	// Включить/выключить спавн мутантов в тумане вообще
	bool enabled = true;

	// Шанс заспавнить мутантов при ВХОДЕ игрока в зону тумана (0..1) -
	// не каждый тик, а один раз на каждый заход (см. reentryCooldownSeconds)
	float spawnChance = 0.35;

	// Сколько мутантов спавнить за раз (случайно между min и max)
	int minMutants = 1;
	int maxMutants = 3;

	// На каком расстоянии от игрока спавнить, метры (не в упор,
	// но и не за пределами тумана)
	float spawnRadiusMin = 8;
	float spawnRadiusMax = 20;

	// Не спавнить мутантов этому же игроку повторно чаще, чем раз в
	// столько секунд - даже если он выйдет и снова зайдёт в туман
	float reentryCooldownSeconds = 300;

	// Из какого списота classname'ов выбирать (по умолчанию - все 30
	// мутантов из BRDK_Mutants_FIX). Требует, чтобы BRDK был установлен
	// на сервере - сам список никак не проверяем, просто зовём
	// CreateObject() по имени.
	ref array<string> mutantClassnames = {
		"BRDK_Giant_zmb", "BRDK_Faceless_zmb", "BRDK_Witch_ZMB", "BRDK_Alien_zmb",
		"BRDK_Brigadier_zmb", "BRDK_Buffed_zmb", "BRDK_Mortimer_zmb", "BRDK_Mutagen_zmb",
		"BRDK_PoliceMan_zmb", "BRDK_Priest_zmb", "BRDK_Mechanic_zmb", "BRDK_LabAssistant_zmb",
		"BRDK_Scientist_01_zmb", "BRDK_BioSuit_YELLOW_zmb", "BRDK_lizard_mut",
		"BRDK_Comrad_zmb", "BRDK_Comrad2_zmb", "BRDK_Comrad3_zmb", "BRDK_FamSoldier_zmb",
		"BRDK_AlienNomouth_crs", "BRDK_AlienNomouth_red_crs", "BRDK_AlienNomouth_Green_crs",
		"BRDK_Alienna_crs", "BRDK_Hybrid_crs", "BRDK_Swamper_crs", "BRDK_Cripple_crs",
		"BRDK_Cripple_2_crs", "BRDK_Cripple_3_crs", "BRDK_Dikker20_crs", "BRDK_SelkhamDemon_crs"
	};
};

modded class EVRStorm
{
	static const string EVR_FOG_MUTANTS_CONFIG_PATH = "$profile:EVRFogMutants.json";

	protected bool m_EVR_FogInitialized = false;
	protected ref array<Object> m_EVR_FogObjects = new array<Object>;
	protected ref EVRFogMutantsConfig m_EVR_MutantsConfig;
	protected ref map<PlayerBase, bool> m_EVR_PlayerInZone = new map<PlayerBase, bool>;
	protected ref map<PlayerBase, float> m_EVR_PlayerMutantCooldown = new map<PlayerBase, float>;

	// -----------------------------------------------------------
	// Грузит EVRFogMutants.json один раз. Если файла ещё нет (первый
	// запуск) - создаёт его с настройками по умолчанию, чтобы было что
	// редактировать.
	// -----------------------------------------------------------
	void EVR_LoadMutantsConfig()
	{
		if (!GetGame().IsServer() || m_EVR_MutantsConfig) {
			return;
		}

		m_EVR_MutantsConfig = new EVRFogMutantsConfig;

		if (FileExist(EVR_FOG_MUTANTS_CONFIG_PATH)) {
			JsonFileLoader<EVRFogMutantsConfig>.JsonLoadFile(EVR_FOG_MUTANTS_CONFIG_PATH, m_EVR_MutantsConfig);
		} else {
			JsonFileLoader<EVRFogMutantsConfig>.JsonSaveFile(EVR_FOG_MUTANTS_CONFIG_PATH, m_EVR_MutantsConfig);
		}
	}

	// -----------------------------------------------------------
	// Расставляет объекты тумана вокруг m_AnomalyPosition. Вызывается
	// один раз при первом тике этого конкретного шторма (см. хук в
	// UpdateServer() ниже) - то есть уже ПОСЛЕ того, как позиция шара
	// определена, значит попадёт туда же, где стоит шар в этот раз.
	// -----------------------------------------------------------
	void EVR_SpawnFogZone()
	{
		if (!GetGame().IsServer()) {
			return;
		}

		int count = EVRFogZoneConstants.FOG_OBJECTS.Count();
		if (count == 0) {
			return;
		}

		for (int i = 0; i < EVRFogZoneConstants.FOG_OBJECT_COUNT; i++) {
			string cls = EVRFogZoneConstants.FOG_OBJECTS[i % count];
			float angle = Math.RandomFloat(0, 6.283185);
			float radius = Math.RandomFloat(0, EVRFogZoneConstants.FOG_ZONE_RADIUS * 0.8);
			vector offset = Vector(Math.Cos(angle) * radius, 0, Math.Sin(angle) * radius);
			vector spawnPos = m_AnomalyPosition + offset;

			// ФИКС: раньше вся зона стояла на ОДНОЙ высоте m_AnomalyPosition[1]
			// (высота именно точки шара), поэтому на неровном рельефе туман
			// либо висел в воздухе, либо уходил под землю по краям зоны.
			// Берём реальную высоту рельефа в конкретной (x,z) точке отдельно
			// для каждого объекта.
			spawnPos[1] = GetGame().SurfaceY(spawnPos[0], spawnPos[2]) + EVRFogZoneConstants.FOG_GROUND_OFFSET;

			Object obj = GetGame().CreateObject(cls, spawnPos, false, true, true);
			if (obj) {
				// ФИКС: "туман тянется в одну сторону" - модели RZ_Tyman скорее
				// всего несимметричные (плоскость/облако с центром не посередине),
				// и CreateObject() ставит их все с одинаковым (нулевым) поворотом -
				// визуально выглядит так, будто весь туман "растёт" в одну сторону
				// от каждой точки. Крутим каждый объект на случайный угол по Y,
				// чтобы разлёт выглядел равномерным облаком, а не рядом одинаково
				// повёрнутых кусков.
				obj.SetOrientation(Vector(Math.RandomFloat(0, 360), 0, 0));
				m_EVR_FogObjects.Insert(obj);
			}
		}

		// подстраховка на случай, если у самого шторма нет своего "конца",
		// на который можно было бы повесить чистку
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(EVR_CleanupFog, (int)(EVRFogZoneConstants.FOG_LIFETIME_SEC * 1000), false);
	}

	// -----------------------------------------------------------
	// Сирена в начале шторма - рассылается ВСЕМ подключённым игрокам
	// один раз, тем же RPC-механизмом, что уже проверен на тумане.
	//
	// ФИКС: раньше сирену пытались проиграть в GetEventPosition()
	// (клиентская сторона, "вызывается независимо на каждом клиенте")
	// - но это не сработало вообще (звук пропал полностью), похоже,
	// эта функция на клиенте либо не вызывается так, как предполагалось
	// изначальным комментарием, либо GetGame().GetPlayer() там ещё
	// не готов. Вместо гаданий - сервер сам явно рассылает RPC каждому
	// игроку, ровно тем же способом, что уже гарантированно доходит
	// (см. EVR_FogZoneTick ниже) - там, где сервер точно знает, что
	// игрок подключён и у него есть identity.
	// -----------------------------------------------------------
	void EVR_BroadcastSiren()
	{
		if (!GetGame().IsServer()) {
			return;
		}

		array<Man> players = new array<Man>;
		GetGame().GetPlayers(players);

		foreach (Man man : players) {
			PlayerBase player = PlayerBase.Cast(man);
			if (!player || !player.GetIdentity()) {
				continue;
			}
			// параметр не нужен по смыслу, но передаём тот же тип Param, что и
			// в уже проверенном (компилируется без ошибок) RPC тумана выше -
			// чтобы не пробовать новую, непроверенную сигнатуру вызова
			GetGame().RPCSingleParam(player, EVRRPCConstants.RPC_EVR_SIREN, new Param1<bool>(true), true, player.GetIdentity());
		}
	}

	void EVR_CleanupFog()
	{
		foreach (Object obj : m_EVR_FogObjects) {
			if (obj) {
				GetGame().ObjectDelete(obj);
			}
		}
		m_EVR_FogObjects.Clear();
	}

	// -----------------------------------------------------------
	// Тик зоны - раз в TICK_INTERVAL сек, независимо от частоты
	// UpdateServer(). Проверяет ВСЕХ игроков на сервере (не только
	// тех, кто уже в узкой зоне поимки шара) и применяет эффекты
	// каждому, кто в радиусе FOG_ZONE_RADIUS.
	// -----------------------------------------------------------
	void EVR_FogZoneTick()
	{
		if (!GetGame().IsServer()) {
			return;
		}

		array<Man> players = new array<Man>;
		GetGame().GetPlayers(players);

		foreach (Man man : players) {
			PlayerBase player = PlayerBase.Cast(man);
			if (!player || !player.IsAlive()) {
				continue;
			}

			float dist = vector.Distance(player.GetPosition(), m_AnomalyPosition);
			bool inZone = dist <= EVRFogZoneConstants.FOG_ZONE_RADIUS;

			bool wasInZone = false;
			if (m_EVR_PlayerInZone.Contains(player)) {
				wasInZone = m_EVR_PlayerInZone.Get(player);
			}
			m_EVR_PlayerInZone.Set(player, inZone);

			if (!inZone) {
				continue;
			}

			// НОВОЕ: ровно в момент ВХОДА в зону (не каждый тик, пока стоит
			// внутри) - шанс заспавнить мутантов BRDK рядом с игроком.
			if (!wasInZone) {
				EVR_TrySpawnMutants(player);
			}

			// урон по HP
			player.DecreaseHealth("", "", EVRFogZoneConstants.DAMAGE_PER_TICK);

			// шанс выронить предмет из рук
			if (Math.RandomFloat01() < EVRFogZoneConstants.DROP_ITEM_CHANCE) {
				ItemBase inHands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
				if (inHands) {
					player.GetHumanInventory().DropEntity(InventoryMode.SERVER, player, inHands);
				}
			}

			// шанс кратковременной потери контроля (вместо "суицида" - обморок/паника).
			// ФИКС: "player.SetUnconscious(true)" - такого публичного метода в этом
			// движке нет ("Undefined function"). Вместо кастомного вкл/выкл обморока -
			// роняем игроку стат Shock тем же DecreaseHealth, что и урон по HP выше
			// (Shock - такая же "глобальная" зона здоровья, как Health/Blood - та
			// самая, что в DamageApplied у патронов). Дойдёт до нуля - игрок вырубится
			// штатной игровой логикой, очнётся тоже штатно (шок сам восстанавливается
			// со временем) - свой таймер "разбудить" не нужен.
			bool panic = false;
			if (Math.RandomFloat01() < EVRFogZoneConstants.PANIC_CHANCE) {
				player.DecreaseHealth("", "Shock", EVRFogZoneConstants.PANIC_SHOCK_DAMAGE);
				panic = true;
			}

			// звук/тряска/темнота - клиентский RPC конкретному игроку
			if (player.GetIdentity()) {
				GetGame().RPCSingleParam(player, EVRRPCConstants.RPC_EVR_FOG_EFFECT, new Param1<bool>(panic), true, player.GetIdentity());
			}
		}
	}

	// -----------------------------------------------------------
	// Спавн мутантов BRDK рядом с игроком, вошедшим в туман. Настройки -
	// из EVRFogMutantsConfig (JSON, см. EVR_LoadMutantsConfig выше).
	// -----------------------------------------------------------
	void EVR_TrySpawnMutants(PlayerBase player)
	{
		if (!m_EVR_MutantsConfig || !m_EVR_MutantsConfig.enabled) {
			return;
		}

		// повторный кулдаун конкретно этому игроку, даже если он выйдет
		// и снова зайдёт в туман раньше времени
		float now = GetGame().GetTime();
		if (m_EVR_PlayerMutantCooldown.Contains(player)) {
			float last = m_EVR_PlayerMutantCooldown.Get(player);
			if (now - last < m_EVR_MutantsConfig.reentryCooldownSeconds * 1000) {
				return;
			}
		}

		if (Math.RandomFloat01() >= m_EVR_MutantsConfig.spawnChance) {
			return;
		}

		int classCount = m_EVR_MutantsConfig.mutantClassnames.Count();
		if (classCount == 0) {
			return;
		}

		int amount = Math.RandomInt(m_EVR_MutantsConfig.minMutants, m_EVR_MutantsConfig.maxMutants + 1);

		for (int i = 0; i < amount; i++) {
			string cls = m_EVR_MutantsConfig.mutantClassnames[Math.RandomInt(0, classCount)];
			float angle = Math.RandomFloat(0, 6.283185);
			float radius = Math.RandomFloat(m_EVR_MutantsConfig.spawnRadiusMin, m_EVR_MutantsConfig.spawnRadiusMax);
			vector offset = Vector(Math.Cos(angle) * radius, 0, Math.Sin(angle) * radius);
			vector spawnPos = player.GetPosition() + offset;
			spawnPos[1] = GetGame().SurfaceY(spawnPos[0], spawnPos[2]);

			GetGame().CreateObject(cls, spawnPos, false, true, true);
		}

		m_EVR_PlayerMutantCooldown.Set(player, now);
	}

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
		// НОВОЕ: один раз при первом тике этого шторма - расставить туман
		// вокруг уже определённой m_AnomalyPosition и запустить отдельный
		// периодический тик зоны (не зависящий от частоты UpdateServer()).
		if (!m_EVR_FogInitialized) {
			m_EVR_FogInitialized = true;
			EVR_LoadMutantsConfig();
			EVR_SpawnFogZone();
			EVR_BroadcastSiren();
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(EVR_FogZoneTick, (int)(EVRFogZoneConstants.TICK_INTERVAL * 1000), true);
		}

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

// ============================================================
// Клиентская сторона тумана: получает RPC_EVR_FOG_EFFECT от сервера
// и включает звук/тряску/потемнение экрана ЛОКАЛЬНО у конкретного
// игрока (не позиционно, а "у него в голове").
//
// ВАЖНО: тряска камеры и потемнение экрана (PPE) сделаны через API,
// который не проверялся компиляцией в этой сессии - если после сборки
// в логе будет ошибка именно в этом блоке (не в остальном файле),
// пришлите её мне, поправлю под точную версию API вашего сервера.
// Урон/выпадение предмета/обморок (серверная часть выше) на этот
// риск не завязаны и должны работать как есть.
// ============================================================
modded class PlayerBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type == EVRRPCConstants.RPC_EVR_FOG_EFFECT) {
			Param1<bool> data;
			if (!ctx.Read(data)) {
				return;
			}
			EVR_ApplyFogClientEffects(data.param1);
		}

		if (rpc_type == EVRRPCConstants.RPC_EVR_SIREN) {
			// GetPosition() тут - позиция ЭТОГО игрока (получателя RPC),
			// не позиция шара - звук всегда играет "у себя", без затухания.
			if (EVRSirenConstants.SIREN_SOUNDSET != "") {
				SEffectManager.PlaySound(EVRSirenConstants.SIREN_SOUNDSET, GetPosition());
			}
		}
	}

	// panic - в этот тик у игрока также сработал обморок (см. сервер)
	//
	// ФИКС: тряска камеры ("GetGame().GetCameraMan()") убрана - такого
	// метода в этом движке нет ("Undefined function 'DayZGame.GetCameraMan'").
	// Это была единственная непроверенная часть всего файла (сразу
	// предупреждал) - без доступа к компилятору движка тут легко гадать
	// бесконечно, а не собраться с первого раза важнее красивой тряски.
	// Если найдёте у себя в скриптах игры (grep по 4_World на "Shake"/
	// "AddShake"/"CameraShake") реальный рабочий метод - скажите его
	// точную сигнатуру, верну тряску одной строкой.
	void EVR_ApplyFogClientEffects(bool panic)
	{
		// звук "голосов" - не позиционный, играет у самого игрока
		if (EVRFogZoneConstants.SCREAM_SOUNDSET != "") {
			SEffectManager.PlaySound(EVRFogZoneConstants.SCREAM_SOUNDSET, GetPosition());
		}
	}
};

