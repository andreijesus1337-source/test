class CfgPatches
{
	class ApocalypseWeather
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		// ВАЖНО: должен грузиться ПОСЛЕ конфига карты, иначе блок CfgWorlds
		// ниже не сможет "домёржить" цвета в существующий класс мира.
		// "DZ_ChernarusPlus_Data" - предположительное имя аддона карты,
		// ПРОВЕРЬТЕ его в Workbench (Config Viewer -> CfgPatches той
		// записи, что объявляет CfgWorlds >> ChernarusPlus) и поправьте,
		// если оно называется иначе.
		requiredAddons[] = {"DZ_ChernarusPlus_Data"};
	};
};

class CfgMods
{
	class ApocalypseWeather
	{
		dir = "ApocalypseWeather";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Apocalypse Weather";
		credits = "";
		author = "";
		authorID = "0";
		version = "1.0.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game", "World", "Mission"};

		class defs
		{
			class missionScriptModule
			{
				value = "";
				files[] = {"ApocalypseWeather/5_Mission"};
			};
		};
	};
};

// -----------------------------------------------------------------------
// Красное небо/туман при высокой облачности.
// В движке DayZ (как и в Arma-конфигах карт) цвет неба/тумана/солнца
// задаётся ПОКАРТОЧНО в CfgWorlds >> <Карта> >> Weather >> Overcast >>
// OvercastN (N = 0..9, соответствует уровню облачности 0.0..1.0).
// Наш скрипт держит Overcast в диапазоне 0.85-1.0, поэтому красим
// верхние уровни (7-9) в красно-оранжевые тона - чем плотнее тучи,
// тем краснее и темнее небо.
//
// ВАЖНО: это переопределение (мёрж) существующего класса ChernarusPlus,
// а не новый мир. Названия полей ниже (colorSky/colorHorizon/...)
// соответствуют классической структуре Overcast в Arma/DayZ-картах, но
// точный набор полей может отличаться в вашей версии DayZ Tools.
// Откройте в Workbench Config Viewer -> CfgWorlds >> ChernarusPlus >>
// Weather >> Overcast >> Overcast9, посмотрите реальные имена полей
// оригинала и при необходимости поправьте/дополните блок ниже.
// -----------------------------------------------------------------------
class CfgWorlds
{
	class ChernarusPlus
	{
		class Weather
		{
			class Overcast
			{
				class Overcast7
				{
					colorSky[] = {0.55, 0.18, 0.08};
					colorHorizon[] = {0.5, 0.15, 0.07};
					colorFogNear[] = {0.45, 0.14, 0.07};
					colorFogFar[] = {0.3, 0.08, 0.05};
					colorSun[] = {0.9, 0.35, 0.1};
				};
				class Overcast8: Overcast7
				{
					colorSky[] = {0.5, 0.14, 0.06};
					colorHorizon[] = {0.45, 0.12, 0.05};
					colorFogNear[] = {0.4, 0.1, 0.05};
					colorFogFar[] = {0.22, 0.05, 0.03};
				};
				class Overcast9: Overcast8
				{
					colorSky[] = {0.4, 0.08, 0.04};
					colorHorizon[] = {0.35, 0.07, 0.03};
					colorFogNear[] = {0.3, 0.06, 0.03};
					colorFogFar[] = {0.15, 0.03, 0.02};
				};
			};
		};
	};
};

// -----------------------------------------------------------------------
// Кастомный particle-эффект "пепел", летящий вокруг игрока.
// Класс назван по числовому ID (50521) - так DayZ/Arma-движок определяет
// пользовательские particle-эффекты (CfgCloudlets) без правки базового
// перечисления ParticleList. ID выбран в "безопасном" диапазоне (>50000),
// чтобы не пересекаться с ванильными эффектами.
//
// ВАЖНО: texture ниже - ПРИМЕР пути. Замените на реальный путь к любой
// имеющейся в игре dust/smoke/ember текстуре (посмотрите в Workbench
// Config Viewer на существующий CfgCloudlets-эффект, например у костра,
// и скопируйте оттуда рабочий путь и структуру полей - схема ниже
// приближённая, точные имена полей стоит сверить с реальным примером).
// -----------------------------------------------------------------------
class CfgCloudlets
{
	class Default;
	class 50521: Default
	{
		texture = "dz\particleeffects\data\dust_ca.paa";
		particleFXType = "Billboard";
		timerPeriod = 0.15;
		lifeTime = 6;
		priority = 1;
		positionVar[] = {2.5, 3, 2.5};
		emissive = 0;

		class Time0
		{
			time = 0;
			position[] = {0, 0, 0};
			velocity[] = {0, -0.15, 0};
			velocityVar = 40;
			rotation = 0;
			rotationVar = 180;
			size[] = {0.15};
			color[] = {{0.55,0.53,0.5,0.0}, {0.55,0.53,0.5,0.35}, {0.5,0.48,0.45,0.3}, {0.45,0.43,0.4,0.0}};
			animationSpeed[] = {1};
		};
		class Time1: Time0
		{
			time = 1;
		};
	};
};
