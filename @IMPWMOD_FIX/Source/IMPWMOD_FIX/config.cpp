#define _ARMA_

// ============================================================
// Патч поверх оригинального оружейного мода IMPWMOD (весь пак
// weapons/* - automatic, sniper, SMG, Shotgun, Pistol,
// Submachine, GrenadeLauncher). Оригинальные аддоны НЕ трогаем -
// только наследуемся и переопределяем то, что реально изменено:
// вес, размер, разброс/отдачу по режимам стрельбы, прочность и
// список совместимых магазинов. Модель, звуки, анимации, частицы
// наследуются от оригинала без изменений.
//
// У каждого ствола закрыты ВСЕ его варианты (цвета/комплектации)
// из оригинала, не только первый.
// ============================================================

class CfgPatches
{
	class IMPWMOD_FIX
	{
		units[] = {};
		weapons[] = {"IMP_GL_M32_FIX","IMP_MP443_FIX","IMP_Rev50BMG_FIX","IMP_KelTecSUB2000_FIX","IMP_KelTecSUB2000_Supp_FIX","IMP_Vector_FIX","IMP_PP19Vityaz_FIX","IMP_TommyGun_FIX","IMP_AA12_FIX","IMP_Komrad12_FIX","IMP_M590A1_FIX","IMP_M870_FIX","IMP_Origin12_FIX","IMP_VEPR12_FIX","IMP_HKMG4_FIX","IMP_M240_FIX","IMP_PKM_FIX","IMP_PKP_FIX","IMP_PKP_Tkali_FIX","IMP_PKPZ_Black_FIX","IMP_PKPZ_FDE_FIX","IMP_PKP_Tactical_FIX","IMP_PKP_Tactical_Camo_FIX","IMP_PKP_Tactical_DesertCamo_FIX","IMP_RPD_FIX","IMP_AACHoneyBadger_Tan_FIX","IMP_AACHoneyBadger_Black_FIX","IMP_AACHoneyBadger_Green_FIX","IMP_AACHoneyBadger_Gray_FIX","IMP_ACR_FIX","IMP_AEK_FIX","IMP_AK12_FIX","IMP_AK12New_FIX","IMP_AKAlfa_FIX","IMP_AKM_FIX","IMP_AN94_FIX","IMP_AR15Skeleton_FIX","IMP_ASH12_FIX","IMP_AUGA3_FIX","IMP_Beowulf50_FIX","IMP_DDMV4_FIX","IMP_FAMAS_FIX","IMP_FAL_FIX","IMP_G28_Tan_FIX","IMP_G36_FIX","IMP_G36c_FIX","IMP_HK416_FIX","IMP_HKMR308_Black_FIX","IMP_HoneyBadger_FIX","IMP_M39EMR_FIX","IMP_M39EMR_Brown_FIX","IMP_M39EMR_Tan_FIX","IMP_M39EMR_PixelCity_FIX","IMP_M39EMR_PixelTan_FIX","IMP_MAR10_FIX","IMP_MK47_FIX","IMP_RPK16_Black_FIX","IMP_RPK16_Green_FIX","IMP_RPK16_Tan_FIX","IMP_SCARH_FIX","IMP_SCARL_FIX","IMP_SIG_FIX","IMP_SIG_Tactical_FIX","IMP_SIG_Short_FIX","IMP_SOK94_FIX","IMP_SR25_FIX","IMP_STM9_FIX","IMP_SVU_FIX","IMP_VHS2_FIX","IMP_VHS22_FIX","IMP_VR80_FIX","IMP_VSK94_FIX","IMP_VSS_FIX","IMP_VSS_Tact_FIX","IMP_AK74_FIX","IMP_AR15_FIX","IMP_HK417_FIX","IMP_AR50_FIX","IMP_AR50_Tkali_FIX","IMP_AS50_FIX","IMP_AS50_1_FIX","IMP_AS50_2_FIX","IMP_AS50_3_FIX","IMP_AS50_4_FIX","IMP_AWM_FIX","IMP_AWM_Black_FIX","IMP_AX50_Black_FIX","IMP_AX50_Tkali_FIX","IMP_AXMC_FIX","IMP_Anzio_FIX","IMP_CSR50_FIX","IMP_W_GM6Lynx_FIX","IMP_W_GM6Lynx_Tkali_FIX","IMP_K98_FIX","IMP_KSVK_FIX","IMP_Kivaari_Black_FIX","IMP_Kivaari_Green_FIX","IMP_Kivaari_Tan_FIX","IMP_Kivaari_Silver_FIX","IMP_DVL10M1_Diversant_FIX","IMP_DVL10M1_Diversant_Green_FIX","IMP_DVL10M1_Diversant_Tkali_FIX","IMP_DVL10M2_Urbana_FIX","IMP_DVL10M2_Urbana_Green_FIX","IMP_W_DXL4MSevastopol_FIX","IMP_W_DXL5Havok_FIX","IMP_W_DXL5Havok_Tkali_FIX","IMP_W_SVLK14SSumrak_FIX","IMP_W_TSVL8M1Stalingrad_FIX","IMP_W_TSVL8M3Berserk_FIX","IMP_W_TSVL8M4Antimaterial_FIX","IMP_W_TSVL8M5Dominator_FIX","IMP_M200New_1_FIX","IMP_M200New_2_FIX","IMP_M24_SWS_FIX","IMP_M24_Camo1_FIX","IMP_M24_Camo2_FIX","IMP_M24_Camo3_FIX","IMP_M300_FIX","IMP_M300_Tkali_FIX","IMP_M300New_FIX","IMP_M82A1_FIX","IMP_M98B_FIX","IMP_MK18_FIX","IMP_McMillan_CS5_FIX","IMP_Noreen50_FIX","IMP_Noreen50_Tkali_FIX","IMP_OMEN_FIX","IMP_PTRD_FIX","IMP_AICS_FIX","IMP_McMillan_A5_FIX","IMP_R700_FIX","IMP_RN50_FIX","IMP_RSASS_FIX","IMP_RemingtonMSR_Blue_FIX","IMP_RemingtonMSR_Tan_FIX","IMP_RemingtonMSR_Grey_FIX","IMP_SV98_FIX","IMP_SVD_FIX","IMP_SVD_New_FIX","IMP_SVDRaptor_FIX","IMP_SnipeX_Alligator_FIX","IMP_T5000_FIX","IMP_TAC21_FIX","IMP_VSSK_FIX","IMP_AX338_Tan_FIX","IMP_AX338_Black_FIX","IMP_AX338_Gray_FIX","IMP_AX338_Green_FIX","IMP_FnBallista_FIX","IMP_M200_FIX","IMP_M200_1_FIX","IMP_M200_Tkali_FIX"};
		requiredVersion = 0.1;
		requiredAddons[] = {"IMP_Weapons_GL_M32","IMP_Pistol_MP443","IMP_Weapons_Rev50BMG","IMP_KelTecSUB2000","IMP_Weapons_Vector","IMP_Weapons_PP19Vityaz","IMP_TommyGun","IMP_Weapons_AA12","IMP_Weapons_Komrad12","IMP_M590A1","IMP_M870","IMP_Weapon_ORIGIN12","IMP_Weapons_VEPR12","IMP_Weapons_HKMG4","IMP_Weapons_M240","IMP_Weapons_PKM","IMP_Weapons_PKP","IMP_PKP_Zenitco","IMP_Weapons_PKP_Tactical","IMP_Weapons_RPD","IMP_Weapons_AACHoneyBadger","IMP_Weapons_ACR","IMP_Weapons_AEK","IMP_Weapons_AK12","IMP_Weapons_AK12New","IMP_Weapons_AKAlfa","IMP_Weapons_AKM","IMP_AN94","IMP_Weapons_AR15Skeleton","ASH12","IMP_Weapons_AUGA3","IMP_Beowulf50","IMP_DDMV4","IMP_Famas","IMP_Weapons_Fal","IMP_Weapons_G28","IMP_Weapons_G36","IMP_Weapons_HK416","IMP_Weapons_HKMR308","IMP_Weapons_HoneyBadger","IMP_M39_EMR","IMP_MAR10","IMP_Weapons_MK47","IMP_RPK16","IMP_SCARH","IMP_SCARL","IMP_Weapons_SIG","IMP_Weapons_SOK94","IMP_Weapons_SR25","IMP_Weapons_STM9","IMP_Weapons_SVU","IMP_VHS2","IMP_Weapons_VR80","IMP_VSK94","IMP_Weapons_VSS","IMP_VSS_Tact","IMP_Weapons_AK74","IMP_Weapons_AR15","IMP_Weapons_HK417","IMP_Weapons_AR50","IMP_AS50","IMP_Weapons_AWM","IMP_Weapons_AX50","IMP_Weapons_AXMC","IMP_Weapons_Anzio","IMP_Weapons_CSR","IMP_W_GM6Lynx","IMP_Weapons_K98","IMP_KSVK","IMP_Weapons_Kivaari","IMP_Weapons_DVL1","IMP_Weapons_DVL2","IMP_W_DXL4MSevastopol","IMP_W_DXL5Havok","IMP_W_SVLK14SSumrak","IMP_W_TSVL8M1Stalingrad","IMP_W_TSVL8M3Berserk","IMP_W_TSVL8M4Antimaterial","IMP_W_TSVL8M5Dominator","IMP_Weapons_M200New","IMP_Weapons_M24","IMP_Weapons_M300","IMP_Weapons_M300New","IMP_Weapons_M82A1","IMP_Weapons_M98B","IMP_Weapons_MK18","IMP_Weapons_McMillan_CS5","IMP_Weapons_Noreen50","IMP_OMEN_base","IMP_PTRD","IMP_Weapons_R700","IMP_RN50","IMP_Weapons_RSASS","IMP_Remington_MSR","IMP_Weapons_SV98","IMP_Weapons_SVD","IMP_Weapons_SVDRaptor","IMP_W_SnipeX_Alligator","IMP_Weapons_T5000","IMP_Weapons_TAC21","IMP_Weapons_VSSK","IMP_Weapons_AX338","IMP_Weapons_FNBallista","IMP_Weapons_M200"};
	};
};

class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class cfgWeapons
{
	class IMP_GL_M32;
	class IMP_MP443;
	class IMP_Rev50BMG;
	class IMP_KelTecSUB2000;
	class IMP_KelTecSUB2000_Supp;
	class IMP_Vector;
	class IMP_PP19Vityaz;
	class IMP_TommyGun;
	class IMP_AA12;
	class IMP_Komrad12;
	class IMP_M590A1;
	class IMP_M870;
	class IMP_Origin12;
	class IMP_VEPR12;
	class IMP_HKMG4;
	class IMP_M240;
	class IMP_PKM;
	class IMP_PKP;
	class IMP_PKP_Tkali;
	class IMP_PKPZ_Black;
	class IMP_PKPZ_FDE;
	class IMP_PKP_Tactical;
	class IMP_PKP_Tactical_Camo;
	class IMP_PKP_Tactical_DesertCamo;
	class IMP_RPD;
	class IMP_AACHoneyBadger_Tan;
	class IMP_AACHoneyBadger_Black;
	class IMP_AACHoneyBadger_Green;
	class IMP_AACHoneyBadger_Gray;
	class IMP_ACR;
	class IMP_AEK;
	class IMP_AK12;
	class IMP_AK12New;
	class IMP_AKAlfa;
	class IMP_AKM;
	class IMP_AN94;
	class IMP_AR15Skeleton;
	class IMP_ASH12;
	class IMP_AUGA3;
	class IMP_Beowulf50;
	class IMP_DDMV4;
	class IMP_FAMAS;
	class IMP_FAL;
	class IMP_G28_Tan;
	class IMP_G36;
	class IMP_G36c;
	class IMP_HK416;
	class IMP_HKMR308_Black;
	class IMP_HoneyBadger;
	class IMP_M39EMR;
	class IMP_M39EMR_Brown;
	class IMP_M39EMR_Tan;
	class IMP_M39EMR_PixelCity;
	class IMP_M39EMR_PixelTan;
	class IMP_MAR10;
	class IMP_MK47;
	class IMP_RPK16_Black;
	class IMP_RPK16_Green;
	class IMP_RPK16_Tan;
	class IMP_SCARH;
	class IMP_SCARL;
	class IMP_SIG;
	class IMP_SIG_Tactical;
	class IMP_SIG_Short;
	class IMP_SOK94;
	class IMP_SR25;
	class IMP_STM9;
	class IMP_SVU;
	class IMP_VHS2;
	class IMP_VHS22;
	class IMP_VR80;
	class IMP_VSK94;
	class IMP_VSS;
	class IMP_VSS_Tact;
	class IMP_AK74;
	class IMP_AR15;
	class IMP_HK417;
	class IMP_AR50;
	class IMP_AR50_Tkali;
	class IMP_AS50;
	class IMP_AS50_1;
	class IMP_AS50_2;
	class IMP_AS50_3;
	class IMP_AS50_4;
	class IMP_AWM;
	class IMP_AWM_Black;
	class IMP_AX50_Black;
	class IMP_AX50_Tkali;
	class IMP_AXMC;
	class IMP_Anzio;
	class IMP_CSR50;
	class IMP_W_GM6Lynx;
	class IMP_W_GM6Lynx_Tkali;
	class IMP_K98;
	class IMP_KSVK;
	class IMP_Kivaari_Black;
	class IMP_Kivaari_Green;
	class IMP_Kivaari_Tan;
	class IMP_Kivaari_Silver;
	class IMP_DVL10M1_Diversant;
	class IMP_DVL10M1_Diversant_Green;
	class IMP_DVL10M1_Diversant_Tkali;
	class IMP_DVL10M2_Urbana;
	class IMP_DVL10M2_Urbana_Green;
	class IMP_W_DXL4MSevastopol;
	class IMP_W_DXL5Havok;
	class IMP_W_DXL5Havok_Tkali;
	class IMP_W_SVLK14SSumrak;
	class IMP_W_TSVL8M1Stalingrad;
	class IMP_W_TSVL8M3Berserk;
	class IMP_W_TSVL8M4Antimaterial;
	class IMP_W_TSVL8M5Dominator;
	class IMP_M200New_1;
	class IMP_M200New_2;
	class IMP_M24_SWS;
	class IMP_M24_Camo1;
	class IMP_M24_Camo2;
	class IMP_M24_Camo3;
	class IMP_M300;
	class IMP_M300_Tkali;
	class IMP_M300New;
	class IMP_M82A1;
	class IMP_M98B;
	class IMP_MK18;
	class IMP_McMillan_CS5;
	class IMP_Noreen50;
	class IMP_Noreen50_Tkali;
	class IMP_OMEN;
	class IMP_PTRD;
	class IMP_AICS;
	class IMP_McMillan_A5;
	class IMP_R700;
	class IMP_RN50;
	class IMP_RSASS;
	class IMP_RemingtonMSR_Blue;
	class IMP_RemingtonMSR_Tan;
	class IMP_RemingtonMSR_Grey;
	class IMP_SV98;
	class IMP_SVD;
	class IMP_SVD_New;
	class IMP_SVDRaptor;
	class IMP_SnipeX_Alligator;
	class IMP_T5000;
	class IMP_TAC21;
	class IMP_VSSK;
	class IMP_AX338_Tan;
	class IMP_AX338_Black;
	class IMP_AX338_Gray;
	class IMP_AX338_Green;
	class IMP_FnBallista;
	class IMP_M200;
	class IMP_M200_1;
	class IMP_M200_Tkali;

	// ================================================================
	// GRENADELAUNCHER - M32
	// ================================================================
	class IMP_GL_M32_FIX : IMP_GL_M32
	{
		weight = 5000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		class Single { dispersion = 0.035; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// PISTOL - MP443
	// ================================================================
	class IMP_MP443_FIX : IMP_MP443
	{
		weight = 1106;
		itemSize[] = {3,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_MP443_18Rnd"};
		class SemiAuto { dispersion = 0.0045; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
		};
	};

	// ================================================================
	// PISTOL - Rev50BMG
	// ================================================================
	class IMP_Rev50BMG_FIX : IMP_Rev50BMG
	{
		weight = 2500;
		itemSize[] = {6,6};
		recoilModifier[] = {3,3,3};
		class Single { dispersion = 0.0045; };
		class SecondMuzzle { dispersion = 0.0045; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
				};
			};
		};
	};

	// ================================================================
	// SMG - KelTecSUB2000
	// ================================================================
	class IMP_KelTecSUB2000_FIX : IMP_KelTecSUB2000
	{
		weight = 1500;
		itemSize[] = {6,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_KelTecSUB2000_Mag_15Rnd","IMP_KelTecSUB2000_Mag_50Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
				};
			};
		};
	};

	class IMP_KelTecSUB2000_Supp_FIX : IMP_KelTecSUB2000_Supp
	{
		weight = 1500;
		itemSize[] = {6,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_KelTecSUB2000_Mag_15Rnd","IMP_KelTecSUB2000_Mag_50Rnd"};
		class SemiAuto { dispersion = 0.0035; };
		class FullAuto { dispersion = 0.0035; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
				};
			};
		};
	};

	// ================================================================
	// SMG - KrissVector
	// ================================================================
	class IMP_Vector_FIX : IMP_Vector
	{
		weight = 2500;
		itemSize[] = {7,3};
		recoilModifier[] = {0.93,0.93,0.93};
		magazines[] = {"IMP_Mag_Vector_35Rnd"};
		class SemiAuto { dispersion = 0.0035; };
		class FullAuto { dispersion = 0.0035; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SMG - PP19Vityaz
	// ================================================================
	class IMP_PP19Vityaz_FIX : IMP_PP19Vityaz
	{
		weight = 2140;
		itemSize[] = {7,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_PP19Vityaz_30Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SMG - TommyGun
	// ================================================================
	class IMP_TommyGun_FIX : IMP_TommyGun
	{
		weight = 2200;
		itemSize[] = {6,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_TommyGun_Drum_100Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.0022; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
		};
	};

	// ================================================================
	// SHOTGUN - AA12
	// ================================================================
	class IMP_AA12_FIX : IMP_AA12
	{
		weight = 3600;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_Saiga_5Rnd","Mag_Saiga_8Rnd","Mag_Saiga_Drum20Rnd"};
		class SemiAuto { dispersion = 0.01; };
		class FullAuto { dispersion = 0.0015; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SHOTGUN - Komrad12
	// ================================================================
	class IMP_Komrad12_FIX : IMP_Komrad12
	{
		weight = 3600;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_Komrad12_10Rnd","IMP_Mag_Komrad12_Tape_20Rnd","IMP_Mag_Komrad12_Clip_20Rnd"};
		class SemiAuto { dispersion = 0.01; };
		class FullAuto { dispersion = 0.0015; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SHOTGUN - M590A1
	// ================================================================
	class IMP_M590A1_FIX : IMP_M590A1
	{
		weight = 3300;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		class Single { dispersion = 0.01; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SHOTGUN - M870
	// ================================================================
	class IMP_M870_FIX : IMP_M870
	{
		weight = 3300;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		class Single { dispersion = 0.01; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SHOTGUN - ORIGIN12
	// ================================================================
	class IMP_Origin12_FIX : IMP_Origin12
	{
		weight = 5800;
		itemSize[] = {9,3};
		recoilModifier[] = {1.2,1.2,1.2};
		magazines[] = {"IMP_Origin12_Drum_30Rnd","IMP_Origin12_Mag_15Rnd"};
		class SemiAuto { dispersion = 0.0001; };
		class FullAuto { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SHOTGUN - VEPR12
	// ================================================================
	class IMP_VEPR12_FIX : IMP_VEPR12
	{
		weight = 3600;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_VEPR12_20Rnd"};
		class SemiAuto { dispersion = 0.01; };
		class FullAuto { dispersion = 0.0015; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SUBMACHINE - HKMG4
	// ================================================================
	class IMP_HKMG4_FIX : IMP_HKMG4
	{
		weight = 8000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Drum_HKMG4_80Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SUBMACHINE - M240
	// ================================================================
	class IMP_M240_FIX : IMP_M240
	{
		weight = 12290;
		itemSize[] = {10,3};
		recoilModifier[] = {1.2,1.25,1.25};
		magazines[] = {"IMP_Mag_M240_150Rnd"};
		class FullAuto { dispersion = 0.0015; };
		class SemiAuto { dispersion = 0.00075; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SUBMACHINE - PKM
	// ================================================================
	class IMP_PKM_FIX : IMP_PKM
	{
		weight = 18200;
		itemSize[] = {10,3};
		recoilModifier[] = {0.9,0.7,0.7};
		magazines[] = {"IMP_Mag_PKM_150Rnd"};
		class SemiAuto { dispersion = 0.00075; };
		class FullAuto { dispersion = 0.00075; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SUBMACHINE - PKP
	// ================================================================
	class IMP_PKP_FIX : IMP_PKP
	{
		weight = 18200;
		itemSize[] = {10,3};
		recoilModifier[] = {0.7,0.8,0.7};
		magazines[] = {"IMP_Mag_PKP_200Rnd"};
		class SemiAuto { dispersion = 0.0055; };
		class FullAuto { dispersion = 0.0055; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_PKP_Tkali_FIX : IMP_PKP_Tkali
	{
		weight = 18200;
		itemSize[] = {10,3};
		recoilModifier[] = {0.7,0.8,0.7};
		magazines[] = {"IMP_Mag_PKP_200Rnd"};
		class SemiAuto { dispersion = 0.0055; };
		class FullAuto { dispersion = 0.0055; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SUBMACHINE - PKPZenitco
	// ================================================================
	class IMP_PKPZ_Black_FIX : IMP_PKPZ_Black
	{
		weight = 14000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_PKP_200Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_PKPZ_FDE_FIX : IMP_PKPZ_FDE
	{
		weight = 14000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_PKP_200Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SUBMACHINE - PKP_Tactical
	// ================================================================
	class IMP_PKP_Tactical_FIX : IMP_PKP_Tactical
	{
		weight = 18200;
		itemSize[] = {10,3};
		recoilModifier[] = {0.7,0.8,0.7};
		magazines[] = {"IMP_Mag_PKP_200Rnd"};
		class SemiAuto { dispersion = 0.0055; };
		class FullAuto { dispersion = 0.0055; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_PKP_Tactical_Camo_FIX : IMP_PKP_Tactical_Camo
	{
		weight = 18200;
		itemSize[] = {10,3};
		recoilModifier[] = {0.7,0.8,0.7};
		magazines[] = {"IMP_Mag_PKP_200Rnd"};
		class SemiAuto { dispersion = 0.0055; };
		class FullAuto { dispersion = 0.0055; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_PKP_Tactical_DesertCamo_FIX : IMP_PKP_Tactical_DesertCamo
	{
		weight = 18200;
		itemSize[] = {10,3};
		recoilModifier[] = {0.7,0.8,0.7};
		magazines[] = {"IMP_Mag_PKP_200Rnd"};
		class SemiAuto { dispersion = 0.0055; };
		class FullAuto { dispersion = 0.0055; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SUBMACHINE - RPD
	// ================================================================
	class IMP_RPD_FIX : IMP_RPD
	{
		weight = 12000;
		itemSize[] = {10,3};
		recoilModifier[] = {0.7,0.8,0.7};
		magazines[] = {"IMP_Mag_RPD_200Rnd"};
		class FullAuto { dispersion = 0.0055; };
		class SemiAuto { dispersion = 0.0055; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - AACHoneyBadger
	// ================================================================
	class IMP_AACHoneyBadger_Tan_FIX : IMP_AACHoneyBadger_Tan
	{
		weight = 1746;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.00125; };
		class FullAuto { dispersion = 0.00125; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_AACHoneyBadger_Black_FIX : IMP_AACHoneyBadger_Black
	{
		weight = 1746;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.00125; };
		class FullAuto { dispersion = 0.00125; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_AACHoneyBadger_Green_FIX : IMP_AACHoneyBadger_Green
	{
		weight = 1746;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.00125; };
		class FullAuto { dispersion = 0.00125; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_AACHoneyBadger_Gray_FIX : IMP_AACHoneyBadger_Gray
	{
		weight = 1746;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.00125; };
		class FullAuto { dispersion = 0.00125; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - ACR
	// ================================================================
	class IMP_ACR_FIX : IMP_ACR
	{
		weight = 2276;
		itemSize[] = {9,3};
		recoilModifier[] = {0.9,0.9,0.9};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.00125; };
		class FullAuto { dispersion = 0.00125; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - AEK
	// ================================================================
	class IMP_AEK_FIX : IMP_AEK
	{
		weight = 1990;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_AK74_30Rnd","Mag_AK74_30Rnd_Black","Mag_AK74_30Rnd_Green","Mag_AK74_45Rnd","IMP_Mag_AK74_6L18_45Rnd","IMP_Mag_AK74_6L20_30Rnd","IMP_Mag_AK74_6L23_30Rnd","IMP_Mag_AK74_6L23P_30Rnd","IMP_Mag_AK74_6L26_45Rnd","IMP_Mag_AK74_6L31_60Rnd","IMP_Mag_AK74_DTSaiga_10Rnd","IMP_Mag_AK74_DTSaiga_20Rnd","IMP_Mag_AK74_PMag_30Rnd","IMP_Mag_AK74_PMag_FDE_30Rnd","IMP_Mag_AK74_Drum_95Rnd","IMP_Mag_RPK16_Drum_90Rnd","IMP_Mag_AK12_30Rnd","IMP_Mag_AK12_Tape_60Rnd","IMP_Mag_AK12_Clip_60Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - AK12
	// ================================================================
	class IMP_AK12_FIX : IMP_AK12
	{
		weight = 2140;
		itemSize[] = {9,3};
		recoilModifier[] = {0.45,1,1};
		magazines[] = {"Mag_AK74_30Rnd","Mag_AK74_30Rnd_Black","Mag_AK74_30Rnd_Green","Mag_AK74_45Rnd","IMP_Mag_AK74_6L18_45Rnd","IMP_Mag_AK74_6L20_30Rnd","IMP_Mag_AK74_6L23_30Rnd","IMP_Mag_AK74_6L23P_30Rnd","IMP_Mag_AK74_6L26_45Rnd","IMP_Mag_AK74_6L31_60Rnd","IMP_Mag_AK74_DTSaiga_10Rnd","IMP_Mag_AK74_DTSaiga_20Rnd","IMP_Mag_AK74_PMag_30Rnd","IMP_Mag_AK74_PMag_FDE_30Rnd","IMP_Mag_AK74_Drum_95Rnd","IMP_Mag_RPK16_Drum_90Rnd","IMP_Mag_AK12_30Rnd","IMP_Mag_AK12_Tape_60Rnd","IMP_Mag_AK12_Clip_60Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - AK12New
	// ================================================================
	class IMP_AK12New_FIX : IMP_AK12New
	{
		weight = 3000;
		itemSize[] = {9,3};
		recoilModifier[] = {0.45,1,1};
		magazines[] = {"Mag_AK74_30Rnd","Mag_AK74_30Rnd_Black","Mag_AK74_30Rnd_Green","Mag_AK74_45Rnd","IMP_Mag_AK74_6L18_45Rnd","IMP_Mag_AK74_6L20_30Rnd","IMP_Mag_AK74_6L23_30Rnd","IMP_Mag_AK74_6L23P_30Rnd","IMP_Mag_AK74_6L26_45Rnd","IMP_Mag_AK74_6L31_60Rnd","IMP_Mag_AK74_DTSaiga_10Rnd","IMP_Mag_AK74_DTSaiga_20Rnd","IMP_Mag_AK74_PMag_30Rnd","IMP_Mag_AK74_PMag_FDE_30Rnd","IMP_Mag_AK74_Drum_95Rnd","IMP_Mag_RPK16_Drum_90Rnd","IMP_Mag_AK12_30Rnd","IMP_Mag_AK12_Tape_60Rnd","IMP_Mag_AK12_Clip_60Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - AKAlfa
	// ================================================================
	class IMP_AKAlfa_FIX : IMP_AKAlfa
	{
		weight = 2140;
		itemSize[] = {9,3};
		recoilModifier[] = {0.85,0.85,1};
		magazines[] = {"IMP_Mag_AKAlfa_30Rnd","Mag_AKM_30Rnd","Mag_AKM_Palm30Rnd","Mag_AKM_Palm30Rnd_Black","Mag_AKM_Palm30Rnd_Green","Mag_AKM_Drum75Rnd","Mag_AKM_Drum75Rnd_Green","Mag_AKM_Drum75Rnd_Black","Mag_AKM_Drum_TEST","IMP_Mag_AKM_Magpul_Black","IMP_Mag_AKM_Magpul_Banana","IMP_Mag_AKM_Magpul_FDE","IMP_Mag_AKM_Magpul_Black_Tape_60Rnd","IMP_Mag_AKM_Magpul_Black_Clip_60Rnd","IMP_Mag_AK_Bakelyt_40Rnd","IMP_Mag_AK_Custom_10Rnd","IMP_Mag_AK_FabDefence_30Rnd","IMP_Mag_AK_Izhmash_30Rnd","IMP_Mag_AK_IzhmashSTD_30Rnd","IMP_Mag_AK_MagpulPMag_30Rnd","IMP_Mag_AK_Aluminium_30Rnd","IMP_Mag_AK_ProDrum_75Rnd","IMP_Mag_AK_Drum_50Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - AKM
	// ================================================================
	class IMP_AKM_FIX : IMP_AKM
	{
		weight = 2140;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_AKM_30Rnd","Mag_AKM_Palm30Rnd","Mag_AKM_Palm30Rnd_Black","Mag_AKM_Palm30Rnd_Green","Mag_AKM_Drum75Rnd","Mag_AKM_Drum75Rnd_Green","Mag_AKM_Drum75Rnd_Black","Mag_AKM_Drum_TEST","IMP_Mag_AKM_Magpul_Black","IMP_Mag_AKM_Magpul_Banana","IMP_Mag_AKM_Magpul_FDE","IMP_Mag_AKM_Magpul_Black_Tape_60Rnd","IMP_Mag_AKM_Magpul_Black_Clip_60Rnd","IMP_Mag_AK_Bakelyt_40Rnd","IMP_Mag_AK_Custom_10Rnd","IMP_Mag_AK_FabDefence_30Rnd","IMP_Mag_AK_Izhmash_30Rnd","IMP_Mag_AK_IzhmashSTD_30Rnd","IMP_Mag_AK_MagpulPMag_30Rnd","IMP_Mag_AK_Aluminium_30Rnd","IMP_Mag_AK_ProDrum_75Rnd","IMP_Mag_AK_Drum_50Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - AN94
	// ================================================================
	class IMP_AN94_FIX : IMP_AN94
	{
		weight = 3500;
		itemSize[] = {9,3};
		recoilModifier[] = {0.4,0.5,0.4};
		magazines[] = {"Mag_AK74_30Rnd","Mag_AK74_30Rnd_Black","Mag_AK74_30Rnd_Green","Mag_AK74_45Rnd","IMP_Mag_AK74_6L18_45Rnd","IMP_Mag_AK74_6L20_30Rnd","IMP_Mag_AK74_6L23_30Rnd","IMP_Mag_AK74_6L23P_30Rnd","IMP_Mag_AK74_6L26_45Rnd","IMP_Mag_AK74_6L31_60Rnd","IMP_Mag_AK74_DTSaiga_10Rnd","IMP_Mag_AK74_DTSaiga_20Rnd","IMP_Mag_AK74_PMag_30Rnd","IMP_Mag_AK74_PMag_FDE_30Rnd","IMP_Mag_AK74_Drum_95Rnd","IMP_Mag_RPK16_Drum_90Rnd","IMP_Mag_AK12_30Rnd","IMP_Mag_AK12_Tape_60Rnd","IMP_Mag_AK12_Clip_60Rnd"};
		class SemiAuto { dispersion = 0.0001; };
		class Burst { dispersion = 0.0001; };
		class FullAuto { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - AR15Skeleton
	// ================================================================
	class IMP_AR15Skeleton_FIX : IMP_AR15Skeleton
	{
		weight = 2976;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - ASH12
	// ================================================================
	class IMP_ASH12_FIX : IMP_ASH12
	{
		weight = 3500;
		itemSize[] = {10,3};
		recoilModifier[] = {2,2,2};
		magazines[] = {"IMP_Mag_ASH12_10Rnd","IMP_Mag_ASH12_20Rnd","IMP_Mag_ASH12_Tape_40Rnd","IMP_Mag_ASH12_Clip_40Rnd"};
		class FullAuto { dispersion = 0.002; };
		class SemiAuto { dispersion = 0.004; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - AUGA3
	// ================================================================
	class IMP_AUGA3_FIX : IMP_AUGA3
	{
		weight = 4500;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.0015; };
		class Burst { dispersion = 0.0015; };
		class FullAuto { dispersion = 0.0015; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - Beowulf50
	// ================================================================
	class IMP_Beowulf50_FIX : IMP_Beowulf50
	{
		weight = 3970;
		itemSize[] = {10,3};
		recoilModifier[] = {2.5,2.5,2.5};
		magazines[] = {"IMP_Mag_Beowulf50_20Rnd","IMP_Mag_Beowulf50_Clip_40Rnd","IMP_Mag_Beowulf50_Tape_40Rnd"};
		class SemiAuto { dispersion = 0.00125; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - DDMV4
	// ================================================================
	class IMP_DDMV4_FIX : IMP_DDMV4
	{
		weight = 3500;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - Famas
	// ================================================================
	class IMP_FAMAS_FIX : IMP_FAMAS
	{
		weight = 3600;
		itemSize[] = {6,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class Burst { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - FnFal
	// ================================================================
	class IMP_FAL_FIX : IMP_FAL
	{
		weight = 3700;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_FAL_20Rnd","IMP_Mag_Fal_Drum_50Rnd","IMP_Mag_FAL_CoupledTape_40Rnd","IMP_Mag_FAL_CoupledClip_40Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - G28
	// ================================================================
	class IMP_G28_Tan_FIX : IMP_G28_Tan
	{
		weight = 3800;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_G28_20Rnd","IMP_Mag_G28_Tape_40Rnd","IMP_Mag_G28_Clip_40Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - G36
	// ================================================================
	class IMP_G36_FIX : IMP_G36
	{
		weight = 3800;
		itemSize[] = {9,3};
		recoilModifier[] = {0.8,0.8,1};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class Burst { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_G36c_FIX : IMP_G36c
	{
		weight = 2800;
		itemSize[] = {8,3};
		recoilModifier[] = {0.5,0.5,1};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd"};
		class SemiAuto { dispersion = 0.0015; };
		class Burst { dispersion = 0.0015; };
		class FullAuto { dispersion = 0.0015; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - HK416
	// ================================================================
	class IMP_HK416_FIX : IMP_HK416
	{
		weight = 3800;
		itemSize[] = {9,3};
		recoilModifier[] = {1.5,1.5,1};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - HKMR308
	// ================================================================
	class IMP_HKMR308_Black_FIX : IMP_HKMR308_Black
	{
		weight = 3800;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_HKMR308_20Rnd","IMP_Mag_HKMR308_Tape_40Rnd","IMP_Mag_HKMR308_Clip_40Rnd"};
		class SemiAuto { dispersion = 0.0007; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - HoneyBadger
	// ================================================================
	class IMP_HoneyBadger_FIX : IMP_HoneyBadger
	{
		weight = 1746;
		itemSize[] = {8,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_HB_30Rnd","IMP_Mag_HB_Clip_60Rnd","IMP_Mag_HB_Tape_60Rnd"};
		class SemiAuto { dispersion = 0.00125; };
		class FullAuto { dispersion = 0.00125; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - M39EMR
	// ================================================================
	class IMP_M39EMR_FIX : IMP_M39EMR
	{
		weight = 2140;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_M39EMR_20Rnd","IMP_Mag_M39EMR_Tape_40Rnd","IMP_Mag_M39EMR_Clip_40Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_M39EMR_Brown_FIX : IMP_M39EMR_Brown
	{
		weight = 2140;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_M39EMR_20Rnd","IMP_Mag_M39EMR_Tape_40Rnd","IMP_Mag_M39EMR_Clip_40Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_M39EMR_Tan_FIX : IMP_M39EMR_Tan
	{
		weight = 2140;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_M39EMR_20Rnd","IMP_Mag_M39EMR_Tape_40Rnd","IMP_Mag_M39EMR_Clip_40Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_M39EMR_PixelCity_FIX : IMP_M39EMR_PixelCity
	{
		weight = 2140;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_M39EMR_20Rnd","IMP_Mag_M39EMR_Tape_40Rnd","IMP_Mag_M39EMR_Clip_40Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_M39EMR_PixelTan_FIX : IMP_M39EMR_PixelTan
	{
		weight = 2140;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_M39EMR_20Rnd","IMP_Mag_M39EMR_Tape_40Rnd","IMP_Mag_M39EMR_Clip_40Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - MAR10
	// ================================================================
	class IMP_MAR10_FIX : IMP_MAR10
	{
		weight = 7265;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_MAR10_10rnd"};
		class SemiAuto { dispersion = 0.00044; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - MK47
	// ================================================================
	class IMP_MK47_FIX : IMP_MK47
	{
		weight = 1746;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_AKM_30Rnd","Mag_AKM_Palm30Rnd","Mag_AKM_Palm30Rnd_Black","Mag_AKM_Palm30Rnd_Green","Mag_AKM_Drum75Rnd","Mag_AKM_Drum75Rnd_Green","Mag_AKM_Drum75Rnd_Black","Mag_AKM_Drum_TEST","IMP_Mag_AKM_Magpul_Black","IMP_Mag_AKM_Magpul_Banana","IMP_Mag_AKM_Magpul_FDE","IMP_Mag_AKM_Magpul_Black_Tape_60Rnd","IMP_Mag_AKM_Magpul_Black_Clip_60Rnd","IMP_Mag_AK_Bakelyt_40Rnd","IMP_Mag_AK_Custom_10Rnd","IMP_Mag_AK_FabDefence_30Rnd","IMP_Mag_AK_Izhmash_30Rnd","IMP_Mag_AK_IzhmashSTD_30Rnd","IMP_Mag_AK_MagpulPMag_30Rnd","IMP_Mag_AK_Aluminium_30Rnd","IMP_Mag_AK_ProDrum_75Rnd","IMP_Mag_AK_Drum_50Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - RPK16
	// ================================================================
	class IMP_RPK16_Black_FIX : IMP_RPK16_Black
	{
		weight = 4500;
		itemSize[] = {9,3};
		recoilModifier[] = {0.7,0.9,0.7};
		magazines[] = {"Mag_AK74_30Rnd","Mag_AK74_30Rnd_Black","Mag_AK74_30Rnd_Green","Mag_AK74_45Rnd","IMP_Mag_AK74_6L18_45Rnd","IMP_Mag_AK74_6L20_30Rnd","IMP_Mag_AK74_6L23_30Rnd","IMP_Mag_AK74_6L23P_30Rnd","IMP_Mag_AK74_6L26_45Rnd","IMP_Mag_AK74_6L31_60Rnd","IMP_Mag_AK74_DTSaiga_10Rnd","IMP_Mag_AK74_DTSaiga_20Rnd","IMP_Mag_AK74_PMag_30Rnd","IMP_Mag_AK74_PMag_FDE_30Rnd","IMP_Mag_AK74_Drum_95Rnd","IMP_Mag_RPK16_Drum_90Rnd","IMP_Mag_AK12_30Rnd","IMP_Mag_AK12_Tape_60Rnd","IMP_Mag_AK12_Clip_60Rnd"};
		class SemiAuto { dispersion = 0.0001; };
		class FullAuto { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_RPK16_Green_FIX : IMP_RPK16_Green
	{
		weight = 4500;
		itemSize[] = {9,3};
		recoilModifier[] = {0.7,0.9,0.7};
		magazines[] = {"Mag_AK74_30Rnd","Mag_AK74_30Rnd_Black","Mag_AK74_30Rnd_Green","Mag_AK74_45Rnd","IMP_Mag_AK74_6L18_45Rnd","IMP_Mag_AK74_6L20_30Rnd","IMP_Mag_AK74_6L23_30Rnd","IMP_Mag_AK74_6L23P_30Rnd","IMP_Mag_AK74_6L26_45Rnd","IMP_Mag_AK74_6L31_60Rnd","IMP_Mag_AK74_DTSaiga_10Rnd","IMP_Mag_AK74_DTSaiga_20Rnd","IMP_Mag_AK74_PMag_30Rnd","IMP_Mag_AK74_PMag_FDE_30Rnd","IMP_Mag_AK74_Drum_95Rnd","IMP_Mag_RPK16_Drum_90Rnd","IMP_Mag_AK12_30Rnd","IMP_Mag_AK12_Tape_60Rnd","IMP_Mag_AK12_Clip_60Rnd"};
		class SemiAuto { dispersion = 0.0001; };
		class FullAuto { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_RPK16_Tan_FIX : IMP_RPK16_Tan
	{
		weight = 4500;
		itemSize[] = {9,3};
		recoilModifier[] = {0.7,0.9,0.7};
		magazines[] = {"Mag_AK74_30Rnd","Mag_AK74_30Rnd_Black","Mag_AK74_30Rnd_Green","Mag_AK74_45Rnd","IMP_Mag_AK74_6L18_45Rnd","IMP_Mag_AK74_6L20_30Rnd","IMP_Mag_AK74_6L23_30Rnd","IMP_Mag_AK74_6L23P_30Rnd","IMP_Mag_AK74_6L26_45Rnd","IMP_Mag_AK74_6L31_60Rnd","IMP_Mag_AK74_DTSaiga_10Rnd","IMP_Mag_AK74_DTSaiga_20Rnd","IMP_Mag_AK74_PMag_30Rnd","IMP_Mag_AK74_PMag_FDE_30Rnd","IMP_Mag_AK74_Drum_95Rnd","IMP_Mag_RPK16_Drum_90Rnd","IMP_Mag_AK12_30Rnd","IMP_Mag_AK12_Tape_60Rnd","IMP_Mag_AK12_Clip_60Rnd"};
		class SemiAuto { dispersion = 0.0001; };
		class FullAuto { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - SCARH
	// ================================================================
	class IMP_SCARH_FIX : IMP_SCARH
	{
		weight = 3500;
		itemSize[] = {7,3};
		recoilModifier[] = {1.2,1.2,1.2};
		magazines[] = {"IMP_Mag_SCARH_30Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - SCARL
	// ================================================================
	class IMP_SCARL_FIX : IMP_SCARL
	{
		weight = 3500;
		itemSize[] = {9,3};
		recoilModifier[] = {1.2,1.2,1.2};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - SIG
	// ================================================================
	class IMP_SIG_FIX : IMP_SIG
	{
		weight = 3000;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_SIG_30Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_SIG_Tactical_FIX : IMP_SIG_Tactical
	{
		weight = 3000;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_SIG_30Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_SIG_Short_FIX : IMP_SIG_Short
	{
		weight = 3000;
		itemSize[] = {7,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_SIG_30Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - SOK94
	// ================================================================
	class IMP_SOK94_FIX : IMP_SOK94
	{
		weight = 2140;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_SOK94_10Rnd","IMP_Mag_SOK94_20Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - SR25
	// ================================================================
	class IMP_SR25_FIX : IMP_SR25
	{
		weight = 3800;
		itemSize[] = {9,3};
		recoilModifier[] = {1.5,1.5,1};
		magazines[] = {"IMP_Mag_SR25_10Rnd","IMP_Mag_SR25_20Rnd","IMP_Mag_SR25_Tape_40Rnd","IMP_Mag_SR25_Clip_40Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - STM9
	// ================================================================
	class IMP_STM9_FIX : IMP_STM9
	{
		weight = 1746;
		itemSize[] = {8,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_Glock_15Rnd","IMP_Mag_Glock_21Rnd","IMP_Mag_Glock_30Rnd","IMP_Drum_Glock_50Rnd"};
		class SemiAuto { dispersion = 0.00125; };
		class FullAuto { dispersion = 0.00125; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - SVU
	// ================================================================
	class IMP_SVU_FIX : IMP_SVU
	{
		weight = 4400;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_SVD_10Rnd","IMP_Mag_SVD_CoupledTape_20Rnd","IMP_Mag_SVD_CoupledClip_20Rnd"};
		class SemiAuto { dispersion = 0.00125; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - VHS2
	// ================================================================
	class IMP_VHS2_FIX : IMP_VHS2
	{
		weight = 3500;
		itemSize[] = {7,3};
		recoilModifier[] = {2,2,2};
		magazines[] = {"IMP_Mag_VHS2_30Rnd","IMP_Mag_VHS2_Tape_60Rnd","IMP_Mag_VHS2_Clip_60Rnd"};
		class FullAuto { dispersion = 0.002; };
		class SemiAuto { dispersion = 0.004; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_VHS22_FIX : IMP_VHS22
	{
		weight = 3500;
		itemSize[] = {7,3};
		recoilModifier[] = {2,2,2};
		magazines[] = {"IMP_Mag_VHS2_30Rnd","IMP_Mag_VHS2_Tape_60Rnd","IMP_Mag_VHS2_Clip_60Rnd"};
		class FullAuto { dispersion = 0.002; };
		class SemiAuto { dispersion = 0.004; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - VR80
	// ================================================================
	class IMP_VR80_FIX : IMP_VR80
	{
		weight = 3600;
		itemSize[] = {9,3};
		recoilModifier[] = {0.9,0.9,0.9};
		magazines[] = {"IMP_Mag_VR80_5Rnd","IMP_Mag_VR80_10Rnd","IMP_Mag_VR80_Tape_20Rnd","IMP_Mag_VR80_Clip_20Rnd"};
		class SemiAuto { dispersion = 0.01; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - VSK94
	// ================================================================
	class IMP_VSK94_FIX : IMP_VSK94
	{
		weight = 2600;
		itemSize[] = {8,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_VSK94_20Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - VSS
	// ================================================================
	class IMP_VSS_FIX : IMP_VSS
	{
		weight = 2500;
		itemSize[] = {8,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_VSS_10Rnd","Mag_VAL_20Rnd","Mag_VSS_CoupledDT_20Rnd","Mag_VSS_Coupled_20Rnd","IMP_Mag_VAL_CoupledTape_40Rnd","IMP_Mag_VAL_CoupledClip_40Rnd","IMP_Mag_VSS_CoupledTape_20Rnd","IMP_Mag_VSS_CoupledClip_20Rnd","IMP_Mag_VSS_30Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - VSSTactical
	// ================================================================
	class IMP_VSS_Tact_FIX : IMP_VSS_Tact
	{
		weight = 2600;
		itemSize[] = {8,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_VSS_10Rnd","Mag_VAL_20Rnd","Mag_VSS_CoupledDT_20Rnd","Mag_VSS_Coupled_20Rnd","IMP_Mag_VAL_CoupledTape_40Rnd","IMP_Mag_VAL_CoupledClip_40Rnd","IMP_Mag_VSS_CoupledTape_20Rnd","IMP_Mag_VSS_CoupledClip_20Rnd","IMP_Mag_VSS_30Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - ak74
	// ================================================================
	class IMP_AK74_FIX : IMP_AK74
	{
		weight = 2140;
		itemSize[] = {9,3};
		recoilModifier[] = {0.45,1,1};
		magazines[] = {"Mag_AK74_30Rnd","Mag_AK74_30Rnd_Black","Mag_AK74_30Rnd_Green","Mag_AK74_45Rnd","IMP_Mag_AK74_6L18_45Rnd","IMP_Mag_AK74_6L20_30Rnd","IMP_Mag_AK74_6L23_30Rnd","IMP_Mag_AK74_6L23P_30Rnd","IMP_Mag_AK74_6L26_45Rnd","IMP_Mag_AK74_6L31_60Rnd","IMP_Mag_AK74_DTSaiga_10Rnd","IMP_Mag_AK74_DTSaiga_20Rnd","IMP_Mag_AK74_PMag_30Rnd","IMP_Mag_AK74_PMag_FDE_30Rnd","IMP_Mag_AK74_Drum_95Rnd","IMP_Mag_RPK16_Drum_90Rnd","IMP_Mag_AK12_30Rnd","IMP_Mag_AK12_Tape_60Rnd","IMP_Mag_AK12_Clip_60Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - ar15
	// ================================================================
	class IMP_AR15_FIX : IMP_AR15
	{
		weight = 1746;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.00125; };
		class FullAuto { dispersion = 0.00125; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - hk417
	// ================================================================
	class IMP_HK417_FIX : IMP_HK417
	{
		weight = 1746;
		itemSize[] = {9,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_HK417_10Rnd","IMP_Mag_HK417_20Rnd"};
		class SemiAuto { dispersion = 0.00125; };
		class FullAuto { dispersion = 0.00125; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - AR50
	// ================================================================
	class IMP_AR50_FIX : IMP_AR50
	{
		weight = 12300;
		itemSize[] = {10,3};
		recoilModifier[] = {0.8,0.8,1};
		magazines[] = {""};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_AR50_Tkali_FIX : IMP_AR50_Tkali
	{
		weight = 12300;
		itemSize[] = {10,3};
		recoilModifier[] = {0.8,0.8,1};
		magazines[] = {""};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - AS50
	// ================================================================
	class IMP_AS50_FIX : IMP_AS50
	{
		weight = 12000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_AS50_10rnd"};
		class SemiAuto { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	class IMP_AS50_1_FIX : IMP_AS50_1
	{
		weight = 12000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_AS50_10rnd"};
		class SemiAuto { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	class IMP_AS50_2_FIX : IMP_AS50_2
	{
		weight = 12000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_AS50_10rnd"};
		class SemiAuto { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	class IMP_AS50_3_FIX : IMP_AS50_3
	{
		weight = 12000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_AS50_10rnd"};
		class SemiAuto { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	class IMP_AS50_4_FIX : IMP_AS50_4
	{
		weight = 12000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_AS50_10rnd"};
		class SemiAuto { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - AWM
	// ================================================================
	class IMP_AWM_FIX : IMP_AWM
	{
		weight = 6100;
		itemSize[] = {10,3};
		recoilModifier[] = {1,0.8,1};
		magazines[] = {"IMP_Mag_AWM_5Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_AWM_Black_FIX : IMP_AWM_Black
	{
		weight = 6100;
		itemSize[] = {10,3};
		recoilModifier[] = {1,0.8,1};
		magazines[] = {"IMP_Mag_AWM_5Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - AX50
	// ================================================================
	class IMP_AX50_Black_FIX : IMP_AX50_Black
	{
		weight = 14800;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_AX50_5Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_AX50_Tkali_FIX : IMP_AX50_Tkali
	{
		weight = 14800;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_AX50_5Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - AXMC
	// ================================================================
	class IMP_AXMC_FIX : IMP_AXMC
	{
		weight = 12000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_AXMC_10Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - Anzio
	// ================================================================
	class IMP_Anzio_FIX : IMP_Anzio
	{
		weight = 16000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - CSR
	// ================================================================
	class IMP_CSR50_FIX : IMP_CSR50
	{
		weight = 16000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - GM6Lynx
	// ================================================================
	class IMP_W_GM6Lynx_FIX : IMP_W_GM6Lynx
	{
		weight = 8000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_GM6Lynx_5Rnd"};
		class SemiAuto { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_W_GM6Lynx_Tkali_FIX : IMP_W_GM6Lynx_Tkali
	{
		weight = 8000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_GM6Lynx_5Rnd"};
		class SemiAuto { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - K98
	// ================================================================
	class IMP_K98_FIX : IMP_K98
	{
		weight = 4000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		class Single { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - KSVK
	// ================================================================
	class IMP_KSVK_FIX : IMP_KSVK
	{
		weight = 10000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,3,2};
		magazines[] = {"IMP_KSVK_Mag_5Rnd"};
		class SemiAuto { dispersion = 0.00075; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 5000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - Kivaari
	// ================================================================
	class IMP_Kivaari_Black_FIX : IMP_Kivaari_Black
	{
		weight = 5824;
		itemSize[] = {10,3};
		recoilModifier[] = {2,3,2};
		magazines[] = {"IMP_Mag_Kivaari_5Rnd"};
		class SemiAuto { dispersion = 0.0007; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_Kivaari_Green_FIX : IMP_Kivaari_Green
	{
		weight = 5824;
		itemSize[] = {10,3};
		recoilModifier[] = {2,3,2};
		magazines[] = {"IMP_Mag_Kivaari_5Rnd"};
		class SemiAuto { dispersion = 0.0007; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_Kivaari_Tan_FIX : IMP_Kivaari_Tan
	{
		weight = 5824;
		itemSize[] = {10,3};
		recoilModifier[] = {2,3,2};
		magazines[] = {"IMP_Mag_Kivaari_5Rnd"};
		class SemiAuto { dispersion = 0.0007; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_Kivaari_Silver_FIX : IMP_Kivaari_Silver
	{
		weight = 5824;
		itemSize[] = {10,3};
		recoilModifier[] = {2,3,2};
		magazines[] = {"IMP_Mag_Kivaari_5Rnd"};
		class SemiAuto { dispersion = 0.0007; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - LobaevArms/DVL10M1Diversant
	// ================================================================
	class IMP_DVL10M1_Diversant_FIX : IMP_DVL10M1_Diversant
	{
		weight = 7100;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_DVL10M1_10Rnd","IMP_Mag_DVL10M1_Tkali_10Rnd"};
		class Single { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_DVL10M1_Diversant_Green_FIX : IMP_DVL10M1_Diversant_Green
	{
		weight = 7100;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_DVL10M1_10Rnd","IMP_Mag_DVL10M1_Tkali_10Rnd"};
		class Single { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_DVL10M1_Diversant_Tkali_FIX : IMP_DVL10M1_Diversant_Tkali
	{
		weight = 7100;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_DVL10M1_10Rnd","IMP_Mag_DVL10M1_Tkali_10Rnd"};
		class Single { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - LobaevArms/DVL10M2Urbana
	// ================================================================
	class IMP_DVL10M2_Urbana_FIX : IMP_DVL10M2_Urbana
	{
		weight = 5200;
		itemSize[] = {10,3};
		recoilModifier[] = {2.1,2.1,1};
		magazines[] = {"IMP_Mag_DVL10M2_10Rnd"};
		class Single { dispersion = 0.0003; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_DVL10M2_Urbana_Green_FIX : IMP_DVL10M2_Urbana_Green
	{
		weight = 5200;
		itemSize[] = {10,3};
		recoilModifier[] = {2.1,2.1,1};
		magazines[] = {"IMP_Mag_DVL10M2_10Rnd"};
		class Single { dispersion = 0.0003; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - LobaevArms/DXL4MSevastopol
	// ================================================================
	class IMP_W_DXL4MSevastopol_FIX : IMP_W_DXL4MSevastopol
	{
		weight = 8500;
		itemSize[] = {12,3};
		recoilModifier[] = {1,1.1,1};
		magazines[] = {"IMP_Mag_DXL4MSevastopol_5Rnd"};
		class Single { dispersion = 0.00025; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - LobaevArms/DXL5Havok
	// ================================================================
	class IMP_W_DXL5Havok_FIX : IMP_W_DXL5Havok
	{
		weight = 13000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1.4,1};
		magazines[] = {"IMP_Mag_DXL5Havok_7Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	class IMP_W_DXL5Havok_Tkali_FIX : IMP_W_DXL5Havok_Tkali
	{
		weight = 13000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1.4,1};
		magazines[] = {"IMP_Mag_DXL5Havok_7Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - LobaevArms/SVLK14SSumrak
	// ================================================================
	class IMP_W_SVLK14SSumrak_FIX : IMP_W_SVLK14SSumrak
	{
		weight = 9600;
		itemSize[] = {11,3};
		recoilModifier[] = {1,1,1};
		class Single { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - LobaevArms/TSVL8M1Stalingrad
	// ================================================================
	class IMP_W_TSVL8M1Stalingrad_FIX : IMP_W_TSVL8M1Stalingrad
	{
		weight = 7400;
		itemSize[] = {11,3};
		recoilModifier[] = {1,1.1,1};
		magazines[] = {"IMP_Mag_TSVL8M1Stalingrad_10Rnd"};
		class Single { dispersion = 0.00025; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - LobaevArms/TSVL8M3Berserk
	// ================================================================
	class IMP_W_TSVL8M3Berserk_FIX : IMP_W_TSVL8M3Berserk
	{
		weight = 5500;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1.2,1};
		magazines[] = {"IMP_Mag_TSVL8M1Stalingrad_10Rnd"};
		class Single { dispersion = 0.0025; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - LobaevArms/TSVL8M4Antimaterial
	// ================================================================
	class IMP_W_TSVL8M4Antimaterial_FIX : IMP_W_TSVL8M4Antimaterial
	{
		weight = 7100;
		itemSize[] = {11,3};
		recoilModifier[] = {1,1.1,1};
		magazines[] = {"IMP_Mag_TSVL8M1Stalingrad_10Rnd"};
		class Single { dispersion = 0.0025; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - LobaevArms/TSVL8M5Dominator
	// ================================================================
	class IMP_W_TSVL8M5Dominator_FIX : IMP_W_TSVL8M5Dominator
	{
		weight = 8000;
		itemSize[] = {11,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_TSVL8M1Stalingrad_10Rnd"};
		class Single { dispersion = 0.00025; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - M200New
	// ================================================================
	class IMP_M200New_1_FIX : IMP_M200New_1
	{
		weight = 12300;
		itemSize[] = {10,3};
		recoilModifier[] = {0.8,0.8,1};
		magazines[] = {"IMP_Mag_M200_5Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_M200New_2_FIX : IMP_M200New_2
	{
		weight = 12300;
		itemSize[] = {10,3};
		recoilModifier[] = {0.8,0.8,1};
		magazines[] = {"IMP_Mag_M200_5Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - M24
	// ================================================================
	class IMP_M24_SWS_FIX : IMP_M24_SWS
	{
		weight = 5400;
		itemSize[] = {10,3};
		recoilModifier[] = {0.7,0.7,0.7};
		magazines[] = {"IMP_Mag_M24_5Rnd"};
		class Single { dispersion = 0.004; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_M24_Camo1_FIX : IMP_M24_Camo1
	{
		weight = 5400;
		itemSize[] = {10,3};
		recoilModifier[] = {0.7,0.7,0.7};
		magazines[] = {"IMP_Mag_M24_5Rnd"};
		class Single { dispersion = 0.004; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_M24_Camo2_FIX : IMP_M24_Camo2
	{
		weight = 5400;
		itemSize[] = {10,3};
		recoilModifier[] = {0.7,0.7,0.7};
		magazines[] = {"IMP_Mag_M24_5Rnd"};
		class Single { dispersion = 0.004; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_M24_Camo3_FIX : IMP_M24_Camo3
	{
		weight = 5400;
		itemSize[] = {10,3};
		recoilModifier[] = {0.7,0.7,0.7};
		magazines[] = {"IMP_Mag_M24_5Rnd"};
		class Single { dispersion = 0.004; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - M300
	// ================================================================
	class IMP_M300_FIX : IMP_M300
	{
		weight = 3621;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_M300_5Rnd"};
		class Single { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_M300_Tkali_FIX : IMP_M300_Tkali
	{
		weight = 3621;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_M300_5Rnd"};
		class Single { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - M300New
	// ================================================================
	class IMP_M300New_FIX : IMP_M300New
	{
		weight = 3621;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_M300New_5Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - M82A1
	// ================================================================
	class IMP_M82A1_FIX : IMP_M82A1
	{
		weight = 13500;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_M82A1_10Rnd"};
		class Single { dispersion = 0.0005; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1300;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - M98B
	// ================================================================
	class IMP_M98B_FIX : IMP_M98B
	{
		weight = 6120;
		itemSize[] = {10,3};
		recoilModifier[] = {1.9,1.9,1.7};
		magazines[] = {"IMP_Mag_M98B_10Rnd"};
		class Single { dispersion = 0.0006; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - MK18
	// ================================================================
	class IMP_MK18_FIX : IMP_MK18
	{
		weight = 2900;
		itemSize[] = {10,3};
		recoilModifier[] = {0.8,0.8,1};
		magazines[] = {"IMP_Mag_MK18_5Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - McMillan
	// ================================================================
	class IMP_McMillan_CS5_FIX : IMP_McMillan_CS5
	{
		weight = 1820;
		itemSize[] = {8,3};
		recoilModifier[] = {0.6,0.6,0.6};
		magazines[] = {"IMP_Mag_McMillan_CS5_10Rnd"};
		class Single { dispersion = 0.0007; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - Noreen50
	// ================================================================
	class IMP_Noreen50_FIX : IMP_Noreen50
	{
		weight = 12300;
		itemSize[] = {10,3};
		recoilModifier[] = {0.8,0.8,1};
		magazines[] = {""};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_Noreen50_Tkali_FIX : IMP_Noreen50_Tkali
	{
		weight = 12300;
		itemSize[] = {10,3};
		recoilModifier[] = {0.8,0.8,1};
		magazines[] = {""};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - OMEN
	// ================================================================
	class IMP_OMEN_FIX : IMP_OMEN
	{
		weight = 2700;
		itemSize[] = {10,3};
		recoilModifier[] = {1,3,2};
		magazines[] = {"IMP_OMENMag_10Rnd"};
		class SemiAuto { dispersion = 0.00075; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 5000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - PTRD
	// ================================================================
	class IMP_PTRD_FIX : IMP_PTRD
	{
		weight = 3700;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - R700
	// ================================================================
	class IMP_AICS_FIX : IMP_AICS
	{
		weight = 8391;
		itemSize[] = {10,3};
		recoilModifier[] = {2.7,1.9,1.9};
		magazines[] = {"IMP_Mag_R700_5Rnd","IMP_Mag_R700_8Rnd"};
		class Single { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_McMillan_A5_FIX : IMP_McMillan_A5
	{
		weight = 8391;
		itemSize[] = {10,3};
		recoilModifier[] = {2.7,1.9,1.9};
		magazines[] = {"IMP_Mag_R700_5Rnd","IMP_Mag_R700_8Rnd"};
		class Single { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_R700_FIX : IMP_R700
	{
		weight = 8391;
		itemSize[] = {10,3};
		recoilModifier[] = {2.7,1.9,1.9};
		magazines[] = {"IMP_Mag_R700_5Rnd","IMP_Mag_R700_8Rnd"};
		class Single { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - RN50
	// ================================================================
	class IMP_RN50_FIX : IMP_RN50
	{
		weight = 8000;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		class Single { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - RSASS
	// ================================================================
	class IMP_RSASS_FIX : IMP_RSASS
	{
		weight = 5941;
		itemSize[] = {10,3};
		recoilModifier[] = {0.8,0.8,1};
		magazines[] = {"IMP_Mag_RSASS_20Rnd","IMP_Mag_RSASS_Clip_40Rnd","IMP_Mag_RSASS_Tape_40Rnd"};
		class SemiAuto { dispersion = 0.0007; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - RemingtonMSR
	// ================================================================
	class IMP_RemingtonMSR_Blue_FIX : IMP_RemingtonMSR_Blue
	{
		weight = 8391;
		itemSize[] = {10,3};
		recoilModifier[] = {2.7,1.9,1.9};
		magazines[] = {"IMP_Mag_MSR_5Rnd"};
		class Single { dispersion = 0.00014; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_RemingtonMSR_Tan_FIX : IMP_RemingtonMSR_Tan
	{
		weight = 8391;
		itemSize[] = {10,3};
		recoilModifier[] = {2.7,1.9,1.9};
		magazines[] = {"IMP_Mag_MSR_5Rnd"};
		class Single { dispersion = 0.00014; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_RemingtonMSR_Grey_FIX : IMP_RemingtonMSR_Grey
	{
		weight = 8391;
		itemSize[] = {10,3};
		recoilModifier[] = {2.7,1.9,1.9};
		magazines[] = {"IMP_Mag_MSR_5Rnd"};
		class Single { dispersion = 0.00014; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - SV98
	// ================================================================
	class IMP_SV98_FIX : IMP_SV98
	{
		weight = 5400;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_SV98_5Rnd"};
		class Single { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - SVD
	// ================================================================
	class IMP_SVD_FIX : IMP_SVD
	{
		weight = 3700;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_SVD_10Rnd","IMP_Mag_SVD_CoupledTape_20Rnd","IMP_Mag_SVD_CoupledClip_20Rnd"};
		class SemiAuto { dispersion = 0.00075; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - SVDRaptor
	// ================================================================
	class IMP_SVD_New_FIX : IMP_SVD_New
	{
		weight = 3700;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_SVD_10Rnd","IMP_Mag_SVD_CoupledTape_20Rnd","IMP_Mag_SVD_CoupledClip_20Rnd"};
		class SemiAuto { dispersion = 0.00075; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_SVDRaptor_FIX : IMP_SVDRaptor
	{
		weight = 3700;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_SVD_10Rnd","IMP_Mag_SVD_CoupledTape_20Rnd","IMP_Mag_SVD_CoupledClip_20Rnd"};
		class SemiAuto { dispersion = 0.00075; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - SnipeXAlligator
	// ================================================================
	class IMP_SnipeX_Alligator_FIX : IMP_SnipeX_Alligator
	{
		weight = 15000;
		itemSize[] = {10,4};
		recoilModifier[] = {1,1.1,1};
		magazines[] = {"IMP_Mag_SnipeX_Alligator_5Rnd"};
		class Single { dispersion = 0.00025; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - T5000
	// ================================================================
	class IMP_T5000_FIX : IMP_T5000
	{
		weight = 5000;
		itemSize[] = {10,3};
		recoilModifier[] = {0.8,0.8,1};
		magazines[] = {"IMP_Mag_T5000_5Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - TAC21
	// ================================================================
	class IMP_TAC21_FIX : IMP_TAC21
	{
		weight = 8391;
		itemSize[] = {10,3};
		recoilModifier[] = {2.7,1.9,1.9};
		magazines[] = {"IMP_Mag_TAC21_5Rnd"};
		class Single { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - VSSK
	// ================================================================
	class IMP_VSSK_FIX : IMP_VSSK
	{
		weight = 9700;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_VSSK_5Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - ax338
	// ================================================================
	class IMP_AX338_Tan_FIX : IMP_AX338_Tan
	{
		weight = 8391;
		itemSize[] = {10,3};
		recoilModifier[] = {2.7,1.9,1.9};
		magazines[] = {"IMP_Mag_AX338_5Rnd"};
		class Single { dispersion = 0.00014; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_AX338_Black_FIX : IMP_AX338_Black
	{
		weight = 8391;
		itemSize[] = {10,3};
		recoilModifier[] = {2.7,1.9,1.9};
		magazines[] = {"IMP_Mag_AX338_5Rnd"};
		class Single { dispersion = 0.00014; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_AX338_Gray_FIX : IMP_AX338_Gray
	{
		weight = 8391;
		itemSize[] = {10,3};
		recoilModifier[] = {2.7,1.9,1.9};
		magazines[] = {"IMP_Mag_AX338_5Rnd"};
		class Single { dispersion = 0.00014; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_AX338_Green_FIX : IMP_AX338_Green
	{
		weight = 8391;
		itemSize[] = {10,3};
		recoilModifier[] = {2.7,1.9,1.9};
		magazines[] = {"IMP_Mag_AX338_5Rnd"};
		class Single { dispersion = 0.00014; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - fnballista
	// ================================================================
	class IMP_FnBallista_FIX : IMP_FnBallista
	{
		weight = 5000;
		itemSize[] = {10,3};
		recoilModifier[] = {0.8,0.8,1};
		magazines[] = {"IMP_Mag_FNBallista_5Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - m200
	// ================================================================
	class IMP_M200_FIX : IMP_M200
	{
		weight = 12300;
		itemSize[] = {10,3};
		recoilModifier[] = {0.8,0.8,1};
		magazines[] = {"IMP_Mag_M200_5Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_M200_1_FIX : IMP_M200_1
	{
		weight = 12300;
		itemSize[] = {10,3};
		recoilModifier[] = {0.8,0.8,1};
		magazines[] = {"IMP_Mag_M200_5Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

	class IMP_M200_Tkali_FIX : IMP_M200_Tkali
	{
		weight = 12300;
		itemSize[] = {10,3};
		recoilModifier[] = {0.8,0.8,1};
		magazines[] = {"IMP_Mag_M200_5Rnd"};
		class Single { dispersion = 0.0001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};

};
