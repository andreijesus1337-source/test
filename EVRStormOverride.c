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
// ниже). Отдельно позиционировать зону не нужно - она "едет" вместе с
// шаром автоматически, потому что и вход в телепорт, и туман завязаны
// на одну и ту же переменную.
//
// ФИКС: раньше это были static const в скрипте - теперь загружается
// из JSON ($profile:EVRStorm/FogZone.json), см. EVR_LoadFogZoneConfig
// в EVRStorm ниже. Значения по умолчанию (если файла ещё нет) - те же,
// что были раньше.
// ============================================================
class EVRFogZoneConfig
{
	// Радиус тумана вокруг шара, метры
	float radius = 150;

	// Как часто (сек) применяется тик урона/эффектов, пока игрок в зоне
	float tickIntervalSeconds = 5.0;

	// Урон здоровью за один тик
	float damagePerTick = 2.0;

	// Шанс выронить оружие/предмет из рук за один тик (0..1)
	float dropItemChance = 0.12;

	// Шанс кратковременной "потери контроля" (обморок/паника) за тик (0..1)
	float panicChance = 0.15;

	// Сколько шока "сажаем" за раз при потере контроля (сажает стат Shock,
	// движок сам вырубает игрока при низком шоке и сам же поднимает шок
	// со временем - длительность обморока управляется игрой, не нами)
	float panicShockDamage = 80.0;

	// Classname'ы туманных объектов из RZ_Anomaly, которыми набивается зона.
	// Список специально с повтором плотных вариантов - чтобы туман был гуще.
	ref array<string> fogObjects = {
		"RZ_Tyman_P32_Static",
		"RZ_Tyman_P32_OchMedl",
		"RZ_Tyman_P16_OchMedl",
		"RZ_Anom_NeboMG"
	};

	// Сколько объектов тумана раскидать по зоне (случайно вокруг центра)
	int fogObjectCount = 30;

	// Насколько приподнять туман над рельефом, метры (каждый объект
	// ставится по реальной высоте земли в своей точке + этот отступ)
	float fogGroundOffset = 0.2;

	// Подстраховка: если шторм не почистит объекты тумана штатно,
	// удалить их принудительно через столько секунд после спавна
	float fogLifetimeSeconds = 1800;
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
// ФИКС: встроенный JsonFileLoader<T> в этой сборке движка не пишет
// файлы на диск (проверено: и путь верный, и штатная остановка сервера
// не помогла - FileExist() внутри игры врёт "true", а на диске пусто).
// Автор TraderPlus столкнулся с тем же самым и в своём коде тоже
// закомментировал вызов JsonFileLoader, заменив его на собственный
// загрузчик поверх низкоуровневых функций OpenFile/FGets/FPrintln/
// CloseFile + JsonSerializer - это те самые примитивы, на которых
// реально работают другие моды этого сервера (TraderPlus, StashSearch,
// VZP и т.д. - видно по их логам, что конфиги у них читаются). Делаем
// свой аналог по той же схеме вместо ненадёжного generic-класса.
// ============================================================
class EVRJsonLoader<Class T>
{
	static bool LoadFromFile(string path, out T data)
	{
		if (!FileExist(path)) {
			Print("[EVRStorm] EVRJsonLoader: file does not exist: " + path);
			return false;
		}

		FileHandle handle = OpenFile(path, FileMode.READ);
		if (!handle) {
			Print("[EVRStorm] EVRJsonLoader: OpenFile(READ) failed: " + path);
			return false;
		}

		string content = "";
		string line;
		while (FGets(handle, line) >= 0) {
			content += line;
		}
		CloseFile(handle);

		JsonSerializer js = new JsonSerializer();
		string error;
		if (!js.ReadFromString(data, content, error)) {
			Print("[EVRStorm] EVRJsonLoader: ReadFromString failed for " + path + ": " + error);
			return false;
		}

		Print("[EVRStorm] EVRJsonLoader: loaded OK from " + path);
		return true;
	}

	static bool SaveToFile(string path, T data)
	{
		JsonSerializer js = new JsonSerializer();
		string content;
		// ФИКС: компилятор ругался "Too many parameters for 'WriteToString'
		// method" - в этой сборке движка у WriteToString нет отдельного
		// out-параметра под текст ошибки (в отличие от ReadFromString).
		if (!js.WriteToString(data, true, content)) {
			Print("[EVRStorm] EVRJsonLoader: WriteToString failed for " + path);
			return false;
		}

		FileHandle handle = OpenFile(path, FileMode.WRITE);
		if (!handle) {
			Print("[EVRStorm] EVRJsonLoader: OpenFile(WRITE) failed: " + path);
			return false;
		}

		FPrintln(handle, content);
		CloseFile(handle);

		Print("[EVRStorm] EVRJsonLoader: saved OK to " + path + ", FileExist now=" + FileExist(path).ToString());
		return true;
	}
};

// ============================================================
// НОВОЕ: имена soundset'ов - сирена в начале шторма (требует отдельный
// маленький аддон EVRSiren_FIX, который регистрирует EVR_Siren_SoundSet
// из evr_siren.ogg - его нужно поставить рядом с этим скриптом) и
// "голоса" в тумане.
//
// ФИКС: раньше это были static const в скрипте - теперь тоже грузится
// из JSON ($profile:EVRStorm/Sounds.json). Имена соundset'ов нужны
// ОБЕИМ сторонам (сервер решает когда играть, но реально проигрывает
// звук клиент) - поэтому сервер передаёт их клиенту прямо в RPC вместе
// с сигналом "играй звук", а не рассчитывает, что у клиента есть свой
// такой же JSON (у клиента нет доступа к $profile: сервера).
// ============================================================
class EVRSoundsConfig
{
	// soundset сирены в начале шторма - не позиционный, слышен везде
	string sirenSoundset = "EVR_Siren_SoundSet";

	// soundset "голосов"/криков в тумане - НЕ позиционный звук от шара,
	// а тот, что слышит сам игрок. Должен существовать в игре или в
	// одном из ваших модов (звуковых ассетов мы не создаём) - замените
	// на реальное имя soundset'а, иначе звук просто не заиграет.
	string screamSoundset = "EVRFog_Voices_SoundSet";
};

// ============================================================
// НОВОЕ: мутанты BRDK, спавнящиеся вокруг ШАРА, когда игрок подходит к
// нему ближе triggerRadius (не привязано к зоне тумана/урона - отдельная
// дистанция и отдельная точка спавна, см. EVR_FogZoneTick/EVR_TrySpawnMutants
// в EVRStorm ниже).
//
// Настройки - в JSON-файле $profile:EVRStorm/Mutants.json (папка
// EVRStorm - там же лежат FogZone.json и Sounds.json, см. ниже).
// Если файла нет - при первом старте шторма он создастся сам с
// настройками по умолчанию (см. класс ниже) - дальше правьте JSON,
// пересобирать PBO не нужно, правки подхватятся при следующем
// перезапуске сервера (грузится один раз при старте, не на лету).
// ============================================================
class EVRFogMutantsConfig
{
	// Включить/выключить спавн мутантов в тумане вообще
	bool enabled = true;

	// Шанс заспавнить мутантов, когда игрок ПОДХОДИТ к шару ближе triggerRadius
	// (0..1) - не каждый тик, а один раз на каждый заход в эту зону
	// (см. reentryCooldownSeconds)
	float spawnChance = 0.35;

	// На каком расстоянии от ШАРА (m_AnomalyPosition) считается, что игрок
	// "подошёл" - именно на этой дистанции срабатывает проверка spawnChance
	// выше. Не связано с радиусом тумана (EVRFogZoneConfig.radius) - можно
	// сделать меньше, больше или таким же, это отдельная зона.
	float triggerRadius = 80;

	// Сколько мутантов спавнить за раз (случайно между min и max)
	int minMutants = 1;
	int maxMutants = 3;

	// На каком расстоянии от ШАРА (не от игрока) раскидывать мутантов,
	// метры - кольцо вокруг m_AnomalyPosition. Задавайте не меньше
	// triggerRadius, иначе они будут появляться позади игрока, ближе к
	// центру, чем сам игрок стоит.
	float spawnRadiusMin = 20;
	float spawnRadiusMax = 60;

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
	// Папка EVRStorm в профиле сервера (та же папка, где логи/БД CE) -
	// создаётся сама при первом сохранении любого из трёх файлов ниже.
	// ФИКС: было "...\FogZone.json" с одинарным бэкслешем в строковом
	// литерале - компилятор молча съедал "\F" как невалидный escape,
	// путь превращался в "...EVRStormFogZone.json" БЕЗ разделителя -
	// файл реально писался прямо в корень profiles, а не в подпапку
	// EVRStorm (подтверждено логом: "loaded OK from
	// $profile:EVRStormFogZone.json"). Отсюда и была папка EVRStorm
	// пустой - файлы всё это время создавались, просто не там. Ставим
	// прямой слэш "/" - движок понимает оба разделителя пути одинаково,
	// а "/" никогда не экранируется.
	static const string EVR_CONFIG_FOLDER = "$profile:EVRStorm";
	static const string EVR_FOGZONE_CONFIG_PATH = "$profile:EVRStorm/FogZone.json";
	static const string EVR_SOUNDS_CONFIG_PATH = "$profile:EVRStorm/Sounds.json";
	static const string EVR_MUTANTS_CONFIG_PATH = "$profile:EVRStorm/Mutants.json";

	protected bool m_EVR_FogInitialized = false;
	protected ref array<Object> m_EVR_FogObjects = new array<Object>;
	protected ref EVRFogZoneConfig m_EVR_FogZoneConfig;
	protected ref EVRSoundsConfig m_EVR_SoundsConfig;
	protected ref EVRFogMutantsConfig m_EVR_MutantsConfig;
	protected ref map<PlayerBase, bool> m_EVR_PlayerInZone = new map<PlayerBase, bool>;
	protected ref map<PlayerBase, bool> m_EVR_PlayerInMutantZone = new map<PlayerBase, bool>;
	protected ref map<PlayerBase, float> m_EVR_PlayerMutantCooldown = new map<PlayerBase, float>;

	// -----------------------------------------------------------
	// Грузит все три JSON-файла из папки EVRStorm один раз. Если файла
	// ещё нет (первый запуск) - создаёт его с настройками по умолчанию,
	// чтобы было что редактировать. Вызывается один раз - при первом
	// тике первого шторма после старта сервера (см. UpdateServer() ниже);
	// правки в JSON подхватываются только при следующем перезапуске
	// сервера, не на лету.
	// -----------------------------------------------------------
	void EVR_LoadAllConfigs()
	{
		if (!GetGame().IsServer() || m_EVR_FogZoneConfig) {
			return;
		}

		Print("[EVRStorm] EVR_LoadAllConfigs: start");

		MakeDirectory(EVR_CONFIG_FOLDER);
		Print("[EVRStorm] EVR_LoadAllConfigs: MakeDirectory called for " + EVR_CONFIG_FOLDER + ", FileExist(folder)=" + FileExist(EVR_CONFIG_FOLDER).ToString());

		// ФИКС: встроенный JsonFileLoader<T> подтверждённо не пишет файлы
		// на диск в этой сборке движка (и путь верный, и штатный рестарт
		// сервера не помог - см. переписку). Заменили на свой EVRJsonLoader<T>
		// (см. класс выше, объявлен рядом с EVRRPCConstants) - он работает
		// через низкоуровневые OpenFile/FGets/FPrintln/CloseFile, как и
		// другие реально работающие моды на этом сервере.
		Print("[EVRStorm] Loading FogZone.json...");
		m_EVR_FogZoneConfig = new EVRFogZoneConfig;
		if (!EVRJsonLoader<EVRFogZoneConfig>.LoadFromFile(EVR_FOGZONE_CONFIG_PATH, m_EVR_FogZoneConfig)) {
			EVRJsonLoader<EVRFogZoneConfig>.SaveToFile(EVR_FOGZONE_CONFIG_PATH, m_EVR_FogZoneConfig);
		}

		Print("[EVRStorm] Loading Sounds.json...");
		m_EVR_SoundsConfig = new EVRSoundsConfig;
		if (!EVRJsonLoader<EVRSoundsConfig>.LoadFromFile(EVR_SOUNDS_CONFIG_PATH, m_EVR_SoundsConfig)) {
			EVRJsonLoader<EVRSoundsConfig>.SaveToFile(EVR_SOUNDS_CONFIG_PATH, m_EVR_SoundsConfig);
		}

		Print("[EVRStorm] Loading Mutants.json...");
		m_EVR_MutantsConfig = new EVRFogMutantsConfig;
		if (!EVRJsonLoader<EVRFogMutantsConfig>.LoadFromFile(EVR_MUTANTS_CONFIG_PATH, m_EVR_MutantsConfig)) {
			EVRJsonLoader<EVRFogMutantsConfig>.SaveToFile(EVR_MUTANTS_CONFIG_PATH, m_EVR_MutantsConfig);
		}

		Print("[EVRStorm] EVR_LoadAllConfigs: done");
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

		int count = m_EVR_FogZoneConfig.fogObjects.Count();
		if (count == 0) {
			return;
		}

		for (int i = 0; i < m_EVR_FogZoneConfig.fogObjectCount; i++) {
			string cls = m_EVR_FogZoneConfig.fogObjects[i % count];
			float angle = Math.RandomFloat(0, 6.283185);
			float radius = Math.RandomFloat(0, m_EVR_FogZoneConfig.radius * 0.8);
			vector offset = Vector(Math.Cos(angle) * radius, 0, Math.Sin(angle) * radius);
			vector spawnPos = m_AnomalyPosition + offset;

			// ФИКС: раньше вся зона стояла на ОДНОЙ высоте m_AnomalyPosition[1]
			// (высота именно точки шара), поэтому на неровном рельефе туман
			// либо висел в воздухе, либо уходил под землю по краям зоны.
			// Берём реальную высоту рельефа в конкретной (x,z) точке отдельно
			// для каждого объекта.
			spawnPos[1] = GetGame().SurfaceY(spawnPos[0], spawnPos[2]) + m_EVR_FogZoneConfig.fogGroundOffset;

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
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(EVR_CleanupFog, (int)(m_EVR_FogZoneConfig.fogLifetimeSeconds * 1000), false);
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
			// передаём имя soundset'а прямо в RPC - у клиента нет доступа
			// к $profile: сервера, откуда взят m_EVR_SoundsConfig
			GetGame().RPCSingleParam(player, EVRRPCConstants.RPC_EVR_SIREN, new Param1<string>(m_EVR_SoundsConfig.sirenSoundset), true, player.GetIdentity());
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

			// НОВОЕ: отдельная от тумана зона - спавн мутантов срабатывает
			// от расстояния игрока до самого ШАРА (triggerRadius), а не от
			// входа в зону урона/эффектов тумана ниже. Проверяем это ДО
			// "continue" по inZone - игрок может быть в триггере мутантов,
			// даже если ещё вне (или уже вне) радиуса тумана.
			if (m_EVR_MutantsConfig) {
				bool inMutantZone = dist <= m_EVR_MutantsConfig.triggerRadius;
				bool wasInMutantZone = false;
				if (m_EVR_PlayerInMutantZone.Contains(player)) {
					wasInMutantZone = m_EVR_PlayerInMutantZone.Get(player);
				}
				m_EVR_PlayerInMutantZone.Set(player, inMutantZone);

				if (inMutantZone && !wasInMutantZone) {
					EVR_TrySpawnMutants(player);
				}
			}

			bool inZone = dist <= m_EVR_FogZoneConfig.radius;

			bool wasInZone = false;
			if (m_EVR_PlayerInZone.Contains(player)) {
				wasInZone = m_EVR_PlayerInZone.Get(player);
			}
			m_EVR_PlayerInZone.Set(player, inZone);

			if (!inZone) {
				continue;
			}

			// урон по HP
			player.DecreaseHealth("", "", m_EVR_FogZoneConfig.damagePerTick);

			// шанс выронить предмет из рук
			if (Math.RandomFloat01() < m_EVR_FogZoneConfig.dropItemChance) {
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
			if (Math.RandomFloat01() < m_EVR_FogZoneConfig.panicChance) {
				player.DecreaseHealth("", "Shock", m_EVR_FogZoneConfig.panicShockDamage);
				panic = true;
			}

			// звук/тряска/темнота - клиентский RPC конкретному игроку.
			// Передаём screamSoundset тем же RPC - у клиента нет доступа
			// к $profile: сервера, откуда взят m_EVR_SoundsConfig.
			if (player.GetIdentity()) {
				GetGame().RPCSingleParam(player, EVRRPCConstants.RPC_EVR_FOG_EFFECT, new Param2<bool, string>(panic, m_EVR_SoundsConfig.screamSoundset), true, player.GetIdentity());
			}
		}
	}

	// -----------------------------------------------------------
	// Спавн мутантов BRDK вокруг ШАРА (m_AnomalyPosition), когда игрок
	// подошёл ближе triggerRadius. Настройки - из EVRFogMutantsConfig
	// (JSON, см. EVR_LoadAllConfigs выше). player тут нужен только для
	// кулдауна (чтобы не спавнить того же игрока повторно каждый заход) -
	// сама точка спавна от его позиции больше не зависит.
	// -----------------------------------------------------------
	void EVR_TrySpawnMutants(PlayerBase player)
	{
		if (!m_EVR_MutantsConfig || !m_EVR_MutantsConfig.enabled) {
			return;
		}

		// повторный кулдаун конкретно этому игроку, даже если он выйдет
		// и снова зайдёт в зону триггера раньше времени
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
			vector spawnPos = m_AnomalyPosition + offset;
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

		// ФИКС: раньше индекс менялся КАЖДУЮ минуту ((hour*60+minute) % N).
		// Сервер вычисляет позицию РОВНО ОДИН РАЗ, когда шторм стартует -
		// но клиент вычисляет её заново при каждом заходе/перезаходе
		// (см. коммент выше - координаты не передаются по сети). Если
		// между стартом шторма на сервере и (пере)заходом игрока минута
		// сменилась - клиент считает уже другой индекс и рисует шар в
		// другой точке, хотя реальная зона поимки на сервере не двигалась.
		//
		// Подтверждено логом: шторм стартовал в 21:23 (индекс на нечётной
		// минуте), игрок перезашёл в 21:28 (индекс на чётной) - две разные
		// точки при одном и том же активном шторме.
		//
		// Округляем время до получасовых интервалов - один шторм по логу
		// длится "Phase Length 1080" = 18 минут, то есть заведомо короче
		// получаса, значит индекс почти всегда остаётся тем же на всё
		// время жизни ОДНОГО шторма, а между РАЗНЫМИ штормами (которые
		// стартуют в разное время дня) по-прежнему меняется. Полной
		// гарантии это не даёт (шторм, стартовавший в последние минуты
		// получасового интервала, всё ещё может зацепить границу при
		// позднем перезаходе) - настоящий 100% фикс нужен через реально
		// синхронизируемое по сети время старта события (NamEventManager),
		// которого у меня нет на руках.
		int bucket = (hour * 60 + minute) / 30;
		int index = bucket % ORB_SPAWN_POSITIONS.Count();
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
			EVR_LoadAllConfigs();
			EVR_SpawnFogZone();
			EVR_BroadcastSiren();
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(EVR_FogZoneTick, (int)(m_EVR_FogZoneConfig.tickIntervalSeconds * 1000), true);

			// НОВОЕ: уведомление в Discord о начале шторма - через мод
			// MDTLogger (отдельный, уже стоит на сервере), категория "storm".
			// Класс MDTPlayerLogger - обычный класс без модификаторов,
			// поэтому виден отовсюду в рамках модуля World, звать напрямую
			// не требует ничего специального. Если MDTLogger вдруг не
			// установлен - собираться не будет (Undefined class), тогда
			// уберите эти два вызова (тут и в EndPhaseServer ниже).
			MDTPlayerLogger.LogStormEvent("start");
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

	// -----------------------------------------------------------
	// НОВОЕ: конец шторма - уведомление в Discord + уборка нашего
	// состояния, чтобы следующий шторм стартовал чисто.
	//
	// ВАЖНО: EndPhaseServer() - единственный метод в этом файле, который
	// не подтверждён напрямую (в отличие от InitPhaseServer - видел в
	// логе, и MidPhaseServer - видел в реальном исходнике, см. комментарий
	// выше). Предполагается по симметрии с этими двумя (стандартная
	// трёхфазная схема Init/Mid/End у ивентов Namalsk). Если компилятор
	// скажет "Undefined method" или похожее - пришлите ошибку, найдём
	// точный метод завершения шторма.
	// -----------------------------------------------------------
	override void EndPhaseServer()
	{
		super.EndPhaseServer();

		MDTPlayerLogger.LogStormEvent("end");

		EVR_CleanupFog();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(EVR_FogZoneTick);
		m_EVR_FogInitialized = false;
		m_EVR_PlayerInZone.Clear();
		m_EVR_PlayerInMutantZone.Clear();
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

		// ФИКС: soundset'ы теперь настраиваются через JSON на сервере
		// (EVRSoundsConfig, $profile:EVRStorm/Sounds.json) - клиент не
		// имеет доступа к $profile: сервера, поэтому имя soundset'а
		// сервер передаёт прямо в параметрах RPC, а не берёт из
		// какой-то общей константы.
		// ФИКС: "Multiple declaration of variable 'data'" - в этом движке
		// if-блоки не создают отдельную область видимости переменных, так
		// что две одноимённые локальные "data" в соседних if - ошибка
		// компиляции, даже если каждая объявлена в своём блоке. Разные
		// имена под каждый RPC.
		if (rpc_type == EVRRPCConstants.RPC_EVR_FOG_EFFECT) {
			Param2<bool, string> fogData;
			if (!ctx.Read(fogData)) {
				return;
			}
			EVR_ApplyFogClientEffects(fogData.param1, fogData.param2);
		}

		if (rpc_type == EVRRPCConstants.RPC_EVR_SIREN) {
			Param1<string> sirenData;
			if (!ctx.Read(sirenData)) {
				return;
			}
			// GetPosition() тут - позиция ЭТОГО игрока (получателя RPC),
			// не позиция шара - звук всегда играет "у себя", без затухания.
			if (sirenData.param1 != "") {
				SEffectManager.PlaySound(sirenData.param1, GetPosition());
			}
		}
	}

	// panic - в этот тик у игрока также сработал обморок (см. сервер)
	// soundset - имя scream-soundset'а, пришедшее от сервера (см. выше)
	//
	// ФИКС: тряска камеры ("GetGame().GetCameraMan()") убрана - такого
	// метода в этом движке нет ("Undefined function 'DayZGame.GetCameraMan'").
	// Это была единственная непроверенная часть всего файла (сразу
	// предупреждал) - без доступа к компилятору движка тут легко гадать
	// бесконечно, а не собраться с первого раза важнее красивой тряски.
	// Если найдёте у себя в скриптах игры (grep по 4_World на "Shake"/
	// "AddShake"/"CameraShake") реальный рабочий метод - скажите его
	// точную сигнатуру, верну тряску одной строкой.
	void EVR_ApplyFogClientEffects(bool panic, string soundset)
	{
		// звук "голосов" - не позиционный, играет у самого игрока
		if (soundset != "") {
			SEffectManager.PlaySound(soundset, GetPosition());
		}
	}
};

