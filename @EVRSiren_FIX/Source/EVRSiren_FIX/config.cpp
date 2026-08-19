#define _ARMA_

// ============================================================
// Звуковой ассет сирены для EVRStormOverride.c (EVRSirenConstants).
// Отдельный маленький аддон - просто регистрирует .ogg как soundSet,
// который потом проигрывает скрипт. Файлов оригинального EVRStorm
// не трогаем.
//
// is2D = 1 - звук не позиционный, слышен игроку одинаково громко
// независимо от расстояния (сирена-оповещение, а не звук с шара).
// Если хотите, чтобы сирена звучала именно ОТ шара и затихала с
// расстоянием - поставьте is2D = 0 и настройте distanceFilter.
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
		samples[] = {{"EVRSiren_FIX\sound\evr_siren.ogg", 1}};
		volume = 1.0;
		frequency = 1.0;
		is2D = 1;
	};
};

class CfgSoundSets
{
	class EVR_Siren_SoundSet
	{
		soundShaders[] = {"EVR_Siren_SoundShader"};
		volumeFactor = 1.0;
		is2D = 1;
	};
};
