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
//
// НОВОЕ: добавлен второй, отдельный звук - "голоса"/эмбиент тумана
// (EVRFog_Voices_SoundSet, играет через screamSoundset в Sounds.json,
// см. EVRStormOverride.c). Это ДРУГОЙ soundset, не сирена - раньше
// его тут не было вообще, поэтому звук в тумане молчал (soundset с
// таким именем нигде не существовал). Путь к сэмплу собран по тому,
// что вы прислали (P:\EVRSiren_FIX\sound, имя файла = имя SoundSet'а,
// как и с сиреной) - если реальное имя .ogg-файла отличается, поправьте
// путь в samples[] у EVRFog_Voices_SoundShader ниже под ваше точное имя.
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

	class EVRFog_Voices_SoundShader
	{
		samples[] = {{"EVRSiren_FIX\sound\EVRFog_Voices_SoundSet", 1}};
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

	class EVRFog_Voices_SoundSet
	{
		soundShaders[] = {"EVRFog_Voices_SoundShader"};
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "characterAttenuationCurve";
		distanceFilter = "defaultDistanceFilter";
		spatial = 0;
		doppler = 0;
		loop = 0;
		volumeFactor = 1.0;
	};
};
