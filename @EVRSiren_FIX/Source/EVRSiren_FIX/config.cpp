#define _ARMA_

// ============================================================
// Звуковой ассет сирены для EVRStormOverride.c (EVRSirenConstants).
// Отдельный маленький аддон - просто регистрирует .ogg как soundSet,
// который потом проигрывает скрипт. Файлов оригинального EVRStorm
// не трогаем.
//
// ФИКС: изначально было поле "is2D" - в реальном звуковом конфиге
// Namalsk (effects\sounds\config.cpp) такого поля вообще нет, значит
// движок его просто молча игнорировал как неизвестное - отсюда звук
// оставался позиционным ("идёт от шара") несмотря на is2D=1.
//
// Реальное поле для "звук слышен одинаково у любого игрока, не
// позиционный" - spatial = 0 в CfgSoundSets (у Namalsk все Blowout_*
// звуки идут с spatial = 1 - обычный 3D-звук с точки в мире).
//
// Путь к сэмплу - БЕЗ расширения .ogg (как и во всех samples[] у
// Namalsk) - движок сам ищет .ogg по этому пути.
// ============================================================

class CfgPatches
{
	class EVRSiren_FIX
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Sounds_Effects"};
	};
};

class CfgSoundShaders
{
	class EVR_Siren_SoundShader
	{
		samples[] = {{"EVRSiren_FIX\sound\evr_siren", 1}};
		volume = 1.0;
		frequency = 1.0;
		limitation = 0;
		radius = 20000;
		range = 20000;
	};
};

class CfgSoundSets
{
	class EVR_Siren_SoundSet
	{
		soundShaders[] = {"EVR_Siren_SoundShader"};
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "characterAttenuationCurve";
		distanceFilter = "defaultDistanceFilter";
		spatial = 0;
		doppler = 0;
		loop = 0;
		volumeFactor = 1.0;
	};
};
