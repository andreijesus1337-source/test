#define _ARMA_

// ============================================================
// Патч поверх второго набора оружия IMPWMODPart2 (Weapons/* -
// Automatic, GrL, LMG, Pistol, SMG, Sniper). Оригинальные аддоны
// НЕ трогаем - только наследуемся и переопределяем то, что
// реально изменено: вес, размер, разброс/отдачу по режимам
// стрельбы, прочность и список совместимых магазинов. Модель,
// звуки, анимации, частицы наследуются от оригинала без изменений.
//
// У каждого ствола закрыты ВСЕ его варианты (цвета/комплектации)
// из оригинала, не только первый.
// ============================================================

class CfgPatches
{
	class IMPWMODPart2_FIX2
	{
		units[] = {};
		weapons[] = {"IMP_AEK971_FIX2","IMP_F2000_FIX2","IMP_FG42_FIX2","IMP_FG42M_FIX2","IMP_FedorovAvtomat_FIX2","IMP_Groza_9x39_FIX2","IMP_Groza_762_FIX2","IMP_L85_FIX2","IMP_L85_RIS_FIX2","IMP_M1918_FIX2","IMP_M1941_FIX2","IMP_M1A_Black_FIX2","IMP_MCXSpear_Tan_FIX2","IMP_MCXTacops_Black_FIX2","IMP_MDR_Black_FIX2","IMP_MDR_Tan_FIX2","IMP_MDR_9mm_Black_FIX2","IMP_MDR_9mm_Tan_FIX2","IMP_TheFix_FIX2","IMP_Winchester1873_FIX2","IMP_ChinaLake_FIX2","IMP_MG42_FIX2","IMP_MG42_308_FIX2","IMP_U100_FIX2","IMP_Pistol_Beretta_FIX2","IMP_Pistol_Beretta_Desert_FIX2","IMP_DesertEagle_FIX2","IMP_DesertEagle_BlackSky_FIX2","IMP_DesertEagle_Gold_FIX2","IMP_FiveSeven_FIX2","IMP_Glock18C_FIX2","IMP_Glock26_FIX2","IMP_Glock18PDW_FIX2","IMP_Glock17PDW_FIX2","IMP_Hellcat_FIX2","IMP_MagnumSuperSport_FIX2","IMP_Makarov_FIX2","IMP_MK23_FIX2","IMP_P30L_Black_FIX2","IMP_P30L_Grey_FIX2","IMP_RagingBull_FIX2","IMP_RugerMkIV_Black_FIX2","IMP_RugerMkIV_Red_FIX2","IMP_Tec9_FIX2","IMP_EVO3A1_FIX2","IMP_MP5SDA2_FIX2","IMP_MP5SDA2_FDE_FIX2","IMP_MP5MPA2_FIX2","IMP_MP5MPA2_FDE_FIX2","IMP_MP5RailA2_FIX2","IMP_MP5RailA2_FDE_FIX2","IMP_MP7_FIX2","IMP_MP9_FIX2","IMP_UZI_FIX2","IMP_M87R_FIX2","IMP_OSV_FIX2","IMP_Ruger_FIX2","IMP_SCAR20S_FIX2","IMP_SRSA2_FIX2"};
		requiredVersion = 0.1;
		requiredAddons[] = {"IMP_AEK971","IMP_WeaponZ_F2000","IMP_FG42","IMP_FG42M","IMP_FedorovAvtomat","IMP_Groza","IMP_WeaponZ_L85","IMP_M1918","IMP_M1941","IMP_M1A","IMP_MCXSpear","IMP_MCXTacops","IMP_MDR","IMP_TheFix","IMP_Winchester1873","IMP_ChinaLake","IMP_MG42","IMP_U100","IMP_Pistol_Beretta","IMP_DesertEagle","IMP_FiveSeven","IMP_Glock18C","IMP_Glock26","IMP_GlockPDW","IMP_Hellcat","IMP_MagnumSuperSport","IMP_Makarov","IMP_MK23","IMP_P30L","IMP_RagingBull","IMP_RugerMkIV","IMP_Tec9","IMP_EVO3A1","TheIMP_Firearms_MP5","IMP_MP7","IMP_MP9","IMP_UZI","IMP_M87R","IMP_OSV","IMP_Ruger","IMP_SCAR20S","IMP_SRSA2"};
	};
};

class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class cfgWeapons
{
	class IMP_AEK971;
	class IMP_F2000;
	class IMP_FG42;
	class IMP_FG42M;
	class IMP_FedorovAvtomat;
	class IMP_Groza_9x39;
	class IMP_Groza_762;
	class IMP_L85;
	class IMP_L85_RIS;
	class IMP_M1918;
	class IMP_M1941;
	class IMP_M1A_Black;
	class IMP_MCXSpear_Tan;
	class IMP_MCXTacops_Black;
	class IMP_MDR_Black;
	class IMP_MDR_Tan;
	class IMP_MDR_9mm_Black;
	class IMP_MDR_9mm_Tan;
	class IMP_TheFix;
	class IMP_Winchester1873;
	class IMP_ChinaLake;
	class IMP_MG42;
	class IMP_MG42_308;
	class IMP_U100;
	class IMP_Pistol_Beretta;
	class IMP_Pistol_Beretta_Desert;
	class IMP_DesertEagle;
	class IMP_DesertEagle_BlackSky;
	class IMP_DesertEagle_Gold;
	class IMP_FiveSeven;
	class IMP_Glock18C;
	class IMP_Glock26;
	class IMP_Glock18PDW;
	class IMP_Glock17PDW;
	class IMP_Hellcat;
	class IMP_MagnumSuperSport;
	class IMP_Makarov;
	class IMP_MK23;
	class IMP_P30L_Black;
	class IMP_P30L_Grey;
	class IMP_RagingBull;
	class IMP_RugerMkIV_Black;
	class IMP_RugerMkIV_Red;
	class IMP_Tec9;
	class IMP_EVO3A1;
	class IMP_MP5SDA2;
	class IMP_MP5SDA2_FDE;
	class IMP_MP5MPA2;
	class IMP_MP5MPA2_FDE;
	class IMP_MP5RailA2;
	class IMP_MP5RailA2_FDE;
	class IMP_MP7;
	class IMP_MP9;
	class IMP_UZI;
	class IMP_M87R;
	class IMP_OSV;
	class IMP_Ruger;
	class IMP_SCAR20S;
	class IMP_SRSA2;

	// ================================================================
	// AUTOMATIC - AEK971
	// ================================================================
	class IMP_AEK971_FIX2 : IMP_AEK971
	{
		weight = 3530;
		itemSize[] = {8,3};
		recoilModifier[] = {0.5,0.6,0.45};
		magazines[] = {"Mag_AK74_30Rnd","Mag_AK74_30Rnd_Black","Mag_AK74_30Rnd_Green","Mag_AK74_45Rnd","IMP_Mag_AK74_6L18_45Rnd","IMP_Mag_AK74_6L20_30Rnd","IMP_Mag_AK74_6L23_30Rnd","IMP_Mag_AK74_6L23P_30Rnd","IMP_Mag_AK74_6L26_45Rnd","IMP_Mag_AK74_6L31_60Rnd","IMP_Mag_AK74_DTSaiga_10Rnd","IMP_Mag_AK74_DTSaiga_20Rnd","IMP_Mag_AK74_PMag_30Rnd","IMP_Mag_AK74_PMag_FDE_30Rnd","IMP_Mag_AK74_Drum_95Rnd","IMP_Mag_RPK16_Drum_90Rnd","IMP_Mag_AK12_30Rnd","IMP_Mag_AK12_Tape_60Rnd","IMP_Mag_AK12_Clip_60Rnd"};
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

	// ================================================================
	// AUTOMATIC - F2000
	// ================================================================
	class IMP_F2000_FIX2 : IMP_F2000
	{
		weight = 3600;
		itemSize[] = {8,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.0015; };
		class FullAuto { dispersion = 0.0015; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - FG42
	// ================================================================
	class IMP_FG42_FIX2 : IMP_FG42
	{
		weight = 2140;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_FG42_20rnd"};
		class SemiAuto { dispersion = 0.0015; };
		class FullAuto { dispersion = 0.0015; };
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
	// AUTOMATIC - FG42M
	// ================================================================
	class IMP_FG42M_FIX2 : IMP_FG42M
	{
		weight = 4500;
		itemSize[] = {8,3};
		recoilModifier[] = {0.9,0.9,0.9};
		magazines[] = {"IMP_Mag_FG42_20rnd"};
		class SemiAuto { dispersion = 0.001; };
		class FullAuto { dispersion = 0.001; };
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
	// AUTOMATIC - Fedorov
	// ================================================================
	class IMP_FedorovAvtomat_FIX2 : IMP_FedorovAvtomat
	{
		weight = 4400;
		itemSize[] = {8,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_FedorovAvtomat_25rnd"};
		class SemiAuto { dispersion = 0.00075; };
		class FullAuto { dispersion = 0.00075; };
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
	// AUTOMATIC - GROZA
	// ================================================================
	class IMP_Groza_9x39_FIX2 : IMP_Groza_9x39
	{
		weight = 3180;
		itemSize[] = {7,3};
		recoilModifier[] = {0.9,1.0,0.95};
		magazines[] = {"IMP_Mag_Groza_20rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	class IMP_Groza_762_FIX2 : IMP_Groza_762
	{
		weight = 3180;
		itemSize[] = {7,3};
		recoilModifier[] = {0.75,0.75,0.75};
		magazines[] = {"Mag_AKM_30Rnd","Mag_AKM_Palm30Rnd","Mag_AKM_Palm30Rnd_Black","Mag_AKM_Palm30Rnd_Green","Mag_AKM_Drum75Rnd","Mag_AKM_Drum75Rnd_Green","Mag_AKM_Drum75Rnd_Black","Mag_AKM_Drum_TEST","IMP_Mag_AKM_Magpul_Black","IMP_Mag_AKM_Magpul_Banana","IMP_Mag_AKM_Magpul_FDE","IMP_Mag_AKM_Magpul_Black_Tape_60Rnd","IMP_Mag_AKM_Magpul_Black_Clip_60Rnd","IMP_Mag_AK_Bakelyt_40Rnd","IMP_Mag_AK_Custom_10Rnd","IMP_Mag_AK_FabDefence_30Rnd","IMP_Mag_AK_Izhmash_30Rnd","IMP_Mag_AK_IzhmashSTD_30Rnd","IMP_Mag_AK_MagpulPMag_30Rnd","IMP_Mag_AK_Aluminium_30Rnd","IMP_Mag_AK_ProDrum_75Rnd","IMP_Mag_AK_Drum_50Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - L85
	// ================================================================
	class IMP_L85_FIX2 : IMP_L85
	{
		weight = 3600;
		itemSize[] = {8,3};
		recoilModifier[] = {0.62,0.64,0.63};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.0022; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	class IMP_L85_RIS_FIX2 : IMP_L85_RIS
	{
		weight = 3200;
		itemSize[] = {6,3};
		recoilModifier[] = {0.62,0.64,0.63};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.0022; };
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
	// AUTOMATIC - M1918
	// ================================================================
	class IMP_M1918_FIX2 : IMP_M1918
	{
		weight = 7250;
		itemSize[] = {9,3};
		recoilModifier[] = {0.9,0.9,0.9};
		magazines[] = {"IMP_Mag_M1918_20rnd"};
		class SemiAuto { dispersion = 0.0025; };
		class FullAuto { dispersion = 0.0025; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - M1941
	// ================================================================
	class IMP_M1941_FIX2 : IMP_M1941
	{
		weight = 3900;
		itemSize[] = {9,3};
		recoilModifier[] = {1.1,1.05,1.07};
		class Single { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - M1A
	// ================================================================
	class IMP_M1A_Black_FIX2 : IMP_M1A_Black
	{
		weight = 3200;
		itemSize[] = {8,3};
		recoilModifier[] = {1.1,1.1,1.0};
		magazines[] = {"IMP_Mag_M14_10rnd","IMP_Mag_M14_20rnd","Mag_FAL_20Rnd","IMP_Mag_FNFAL_30rnd","IMP_Mag_FNFAL_40rnd"};
		class SemiAuto { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - MCXSpear
	// ================================================================
	class IMP_MCXSpear_Tan_FIX2 : IMP_MCXSpear_Tan
	{
		weight = 3800;
		itemSize[] = {9,3};
		recoilModifier[] = {0.99,1.1,0.69};
		magazines[] = {"Mag_FAL_20Rnd","IMP_Mag_Fal_Drum_50Rnd","IMP_Mag_FAL_CoupledTape_40Rnd","IMP_Mag_FAL_CoupledClip_40Rnd","IMP_Mag_MCXSpear_20rnd"};
		class SemiAuto { dispersion = 0.0015; };
		class FullAuto { dispersion = 0.0015; };
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
	// AUTOMATIC - MCXTacops
	// ================================================================
	class IMP_MCXTacops_Black_FIX2 : IMP_MCXTacops_Black
	{
		weight = 3800;
		itemSize[] = {8,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.0015; };
		class FullAuto { dispersion = 0.0015; };
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
	// AUTOMATIC - MDR
	// ================================================================
	class IMP_MDR_Black_FIX2 : IMP_MDR_Black
	{
		weight = 3400;
		itemSize[] = {7,3};
		recoilModifier[] = {0.73,0.73,0.73};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.0016; };
		class FullAuto { dispersion = 0.0016; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	class IMP_MDR_Tan_FIX2 : IMP_MDR_Tan
	{
		weight = 3400;
		itemSize[] = {7,3};
		recoilModifier[] = {0.73,0.73,0.73};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.0016; };
		class FullAuto { dispersion = 0.0016; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	class IMP_MDR_9mm_Black_FIX2 : IMP_MDR_9mm_Black
	{
		weight = 3400;
		itemSize[] = {7,3};
		recoilModifier[] = {1.1,1.03,1.05};
		magazines[] = {"IMP_Mag_Glock18C_17rnd","IMP_Mag_Glock18C_33rnd","IMP_Mag_Glock18C_50rnd","IMP_Mag_Glock_21Rnd","IMP_Mag_Glock_30Rnd","IMP_Drum_Glock_50Rnd"};
		class SemiAuto { dispersion = 0.003; };
		class FullAuto { dispersion = 0.0041; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	class IMP_MDR_9mm_Tan_FIX2 : IMP_MDR_9mm_Tan
	{
		weight = 3400;
		itemSize[] = {7,3};
		recoilModifier[] = {1.1,1.03,1.05};
		magazines[] = {"IMP_Mag_Glock18C_17rnd","IMP_Mag_Glock18C_33rnd","IMP_Mag_Glock18C_50rnd","IMP_Mag_Glock_21Rnd","IMP_Mag_Glock_30Rnd","IMP_Drum_Glock_50Rnd"};
		class SemiAuto { dispersion = 0.003; };
		class FullAuto { dispersion = 0.0041; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	// ================================================================
	// AUTOMATIC - TheFix
	// ================================================================
	class IMP_TheFix_FIX2 : IMP_TheFix
	{
		weight = 3300;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_TheFix_10rnd"};
		class Single { dispersion = 0.0005; };
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
	// AUTOMATIC - Winchester
	// ================================================================
	class IMP_Winchester1873_FIX2 : IMP_Winchester1873
	{
		weight = 4300;
		itemSize[] = {9,3};
		recoilModifier[] = {1.2,1.2,1.2};
		class Single { dispersion = 0.001; };
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
	// GRL - ChinaLake
	// ================================================================
	class IMP_ChinaLake_FIX2 : IMP_ChinaLake
	{
		weight = 3720;
		itemSize[] = {8,3};
		recoilModifier[] = {1,1,1};
		class Single { dispersion = 0.025; };
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
	// LMG - MG42
	// ================================================================
	class IMP_MG42_FIX2 : IMP_MG42
	{
		weight = 9000;
		itemSize[] = {10,3};
		recoilModifier[] = {0.5,0.5,0.5};
		magazines[] = {"IMP_Mag_MG42_50rnd"};
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	class IMP_MG42_308_FIX2 : IMP_MG42_308
	{
		weight = 9000;
		itemSize[] = {10,3};
		recoilModifier[] = {0.5,0.5,0.5};
		magazines[] = {"IMP_Mag_MG42_75rnd_308"};
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	// ================================================================
	// LMG - U100
	// ================================================================
	class IMP_U100_FIX2 : IMP_U100
	{
		weight = 4700;
		itemSize[] = {8,3};
		recoilModifier[] = {0.6,0.6,0.6};
		magazines[] = {"IMP_Mag_U100_100rnd","Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black","Mag_STANAG_60Rnd","IMP_Mag_M4_Drum60Rnd","IMP_Mag_M4_Cmag_100Rnd","IMP_Mag_M4_Drum_60Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd"};
		class SemiAuto { dispersion = 0.002; };
		class FullAuto { dispersion = 0.002; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	// ================================================================
	// PISTOL - Beretta
	// ================================================================
	class IMP_Pistol_Beretta_FIX2 : IMP_Pistol_Beretta
	{
		weight = 1106;
		itemSize[] = {3,2};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_Beretta_15rnd"};
		class SemiAuto { dispersion = 0.006; };
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

	class IMP_Pistol_Beretta_Desert_FIX2 : IMP_Pistol_Beretta_Desert
	{
		weight = 1106;
		itemSize[] = {3,2};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_Beretta_15rnd"};
		class SemiAuto { dispersion = 0.006; };
	};

	// ================================================================
	// PISTOL - DesertEagle
	// ================================================================
	class IMP_DesertEagle_FIX2 : IMP_DesertEagle
	{
		weight = 1500;
		itemSize[] = {4,2};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_DesertEagle_9Rnd"};
		class SemiAuto { dispersion = 0.003; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 220;
				};
			};
		};
	};

	class IMP_DesertEagle_BlackSky_FIX2 : IMP_DesertEagle_BlackSky
	{
		weight = 1500;
		itemSize[] = {4,2};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_DesertEagle_9Rnd"};
		class SemiAuto { dispersion = 0.003; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 220;
				};
			};
		};
	};

	class IMP_DesertEagle_Gold_FIX2 : IMP_DesertEagle_Gold
	{
		weight = 1500;
		itemSize[] = {4,2};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_DesertEagle_9Rnd"};
		class SemiAuto { dispersion = 0.003; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 220;
				};
			};
		};
	};

	// ================================================================
	// PISTOL - FiveSeven
	// ================================================================
	class IMP_FiveSeven_FIX2 : IMP_FiveSeven
	{
		weight = 610;
		itemSize[] = {3,2};
		recoilModifier[] = {1.2,1.1,1.05};
		magazines[] = {"IMP_Mag_FiveSeven_20rnd"};
		class SemiAuto { dispersion = 0.006; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
	};

	// ================================================================
	// PISTOL - Glock18C
	// ================================================================
	class IMP_Glock18C_FIX2 : IMP_Glock18C
	{
		weight = 610;
		itemSize[] = {3,2};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_Glock18C_17rnd","IMP_Mag_Glock18C_33rnd","IMP_Mag_Glock18C_50rnd"};
		class Single { dispersion = 0.005; };
		class FullAuto { dispersion = 0.006; };
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
	// PISTOL - Glock26
	// ================================================================
	class IMP_Glock26_FIX2 : IMP_Glock26
	{
		weight = 610;
		itemSize[] = {3,2};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_Glock26_10rnd","IMP_Mag_Glock18C_17rnd","IMP_Mag_Glock18C_33rnd","IMP_Mag_Glock18C_50rnd","IMP_Mag_Glock_21Rnd","IMP_Mag_Glock_30Rnd","IMP_Drum_Glock_50Rnd"};
		class Single { dispersion = 0.005; };
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
	// PISTOL - GlockPDW
	// ================================================================
	class IMP_Glock18PDW_FIX2 : IMP_Glock18PDW
	{
		weight = 1200;
		itemSize[] = {5,3};
		recoilModifier[] = {0.7,0.7,0.7};
		magazines[] = {"IMP_Mag_Glock18C_17rnd","IMP_Mag_Glock18C_33rnd","IMP_Mag_Glock18C_50rnd","IMP_Mag_Glock_21Rnd","IMP_Mag_Glock_30Rnd","IMP_Drum_Glock_50Rnd"};
		class SemiAuto { dispersion = 0.006; };
		class FullAuto { dispersion = 0.006; };
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

	class IMP_Glock17PDW_FIX2 : IMP_Glock17PDW
	{
		weight = 1200;
		itemSize[] = {5,3};
		recoilModifier[] = {0.7,0.7,0.7};
		magazines[] = {"Mag_Glock_15Rnd","IMP_Mag_Glock_21Rnd","IMP_Mag_Glock_30Rnd","IMP_Drum_Glock_50Rnd"};
		class SemiAuto { dispersion = 0.006; };
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
	// PISTOL - Hellcat
	// ================================================================
	class IMP_Hellcat_FIX2 : IMP_Hellcat
	{
		weight = 1000;
		itemSize[] = {3,2};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_Hellcat_11rnd","IMP_Mag_Hellcat_13rnd","IMP_Mag_Hellcat_15rnd"};
		class SemiAuto { dispersion = 0.003; };
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
	// PISTOL - MagnumSuperSport
	// ================================================================
	class IMP_MagnumSuperSport_FIX2 : IMP_MagnumSuperSport
	{
		weight = 1200;
		itemSize[] = {4,2};
		recoilModifier[] = {0.95,1.03,0.95};
		class Single { dispersion = 0.009; };
		class SecondMuzzle { dispersion = 0.009; };
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
	// PISTOL - Makarov
	// ================================================================
	class IMP_Makarov_FIX2 : IMP_Makarov
	{
		weight = 725;
		itemSize[] = {3,2};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_Makarov_12rnd","IMP_Mag_Makarov_84rnd"};
		class SemiAuto { dispersion = 0.013; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
	};

	// ================================================================
	// PISTOL - Mk23
	// ================================================================
	class IMP_MK23_FIX2 : IMP_MK23
	{
		weight = 1200;
		itemSize[] = {3,2};
		recoilModifier[] = {0.95,0.95,0.95};
		magazines[] = {"IMP_Mag_MK23_12rnd"};
		class SemiAuto { dispersion = 0.003; };
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
	// PISTOL - P30L
	// ================================================================
	class IMP_P30L_Black_FIX2 : IMP_P30L_Black
	{
		weight = 740;
		itemSize[] = {3,2};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_P30L_15rnd"};
		class SemiAuto { dispersion = 0.0025; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
	};

	class IMP_P30L_Grey_FIX2 : IMP_P30L_Grey
	{
		weight = 740;
		itemSize[] = {3,2};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_P30L_15rnd"};
		class SemiAuto { dispersion = 0.0025; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
	};

	// ================================================================
	// PISTOL - RagingBull
	// ================================================================
	class IMP_RagingBull_FIX2 : IMP_RagingBull
	{
		weight = 1800;
		itemSize[] = {5,2};
		recoilModifier[] = {1.6,1.6,1.5};
		class Single { dispersion = 0.009; };
		class SecondMuzzle { dispersion = 0.009; };
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
	// PISTOL - RugerMkIV
	// ================================================================
	class IMP_RugerMkIV_Black_FIX2 : IMP_RugerMkIV_Black
	{
		weight = 900;
		itemSize[] = {2,2};
		recoilModifier[] = {0.9,0.9,1};
		magazines[] = {"IMP_Mag_RugerMkIV_10Rnd"};
		class SemiAuto { dispersion = 0.005; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 130;
				};
			};
		};
	};

	class IMP_RugerMkIV_Red_FIX2 : IMP_RugerMkIV_Red
	{
		weight = 900;
		itemSize[] = {2,2};
		recoilModifier[] = {0.9,0.9,1};
		magazines[] = {"IMP_Mag_RugerMkIV_10Rnd"};
		class SemiAuto { dispersion = 0.005; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 130;
				};
			};
		};
	};

	// ================================================================
	// PISTOL - Tec9
	// ================================================================
	class IMP_Tec9_FIX2 : IMP_Tec9
	{
		weight = 1400;
		itemSize[] = {4,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_Tec9_32rnd"};
		class SemiAuto { dispersion = 0.003; };
		class FullAuto { dispersion = 0.006; };
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
	// SMG - EVO
	// ================================================================
	class IMP_EVO3A1_FIX2 : IMP_EVO3A1
	{
		weight = 1840;
		itemSize[] = {5,3};
		recoilModifier[] = {0.75,0.75,0.75};
		magazines[] = {"IMP_Mag_EVO_30rnd"};
		class SemiAuto { dispersion = 0.003; };
		class Burst { dispersion = 0.003; };
		class FullAuto { dispersion = 0.003; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 450;
				};
			};
		};
	};

	// ================================================================
	// SMG - MP5
	// ================================================================
	class IMP_MP5SDA2_FIX2 : IMP_MP5SDA2
	{
		weight = 1840;
		itemSize[] = {5,3};
		recoilModifier[] = {0.45,0.45,0.45};
		magazines[] = {"Mag_MP5_15Rnd","Mag_MP5_30Rnd","IMP_Mag_MP5_30rnd","IMP_Mag_MP5_50rnd"};
		class SemiAuto { dispersion = 0.003; };
		class Burst { dispersion = 0.003; };
		class FullAuto { dispersion = 0.003; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 450;
				};
			};
		};
	};

	class IMP_MP5SDA2_FDE_FIX2 : IMP_MP5SDA2_FDE
	{
		weight = 1840;
		itemSize[] = {5,3};
		recoilModifier[] = {0.45,0.45,0.45};
		magazines[] = {"Mag_MP5_15Rnd","Mag_MP5_30Rnd","IMP_Mag_MP5_30rnd","IMP_Mag_MP5_50rnd"};
		class SemiAuto { dispersion = 0.003; };
		class Burst { dispersion = 0.003; };
		class FullAuto { dispersion = 0.003; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 450;
				};
			};
		};
	};

	class IMP_MP5MPA2_FIX2 : IMP_MP5MPA2
	{
		weight = 1840;
		itemSize[] = {5,3};
		recoilModifier[] = {0.45,0.45,0.45};
		magazines[] = {"Mag_MP5_15Rnd","Mag_MP5_30Rnd","IMP_Mag_MP5_30rnd","IMP_Mag_MP5_50rnd"};
		class SemiAuto { dispersion = 0.003; };
		class Burst { dispersion = 0.003; };
		class FullAuto { dispersion = 0.003; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 450;
				};
			};
		};
	};

	class IMP_MP5MPA2_FDE_FIX2 : IMP_MP5MPA2_FDE
	{
		weight = 1840;
		itemSize[] = {5,3};
		recoilModifier[] = {0.45,0.45,0.45};
		magazines[] = {"Mag_MP5_15Rnd","Mag_MP5_30Rnd","IMP_Mag_MP5_30rnd","IMP_Mag_MP5_50rnd"};
		class SemiAuto { dispersion = 0.003; };
		class Burst { dispersion = 0.003; };
		class FullAuto { dispersion = 0.003; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 450;
				};
			};
		};
	};

	class IMP_MP5RailA2_FIX2 : IMP_MP5RailA2
	{
		weight = 1840;
		itemSize[] = {5,3};
		recoilModifier[] = {0.45,0.45,0.45};
		magazines[] = {"Mag_MP5_15Rnd","Mag_MP5_30Rnd","IMP_Mag_MP5_30rnd","IMP_Mag_MP5_50rnd"};
		class SemiAuto { dispersion = 0.003; };
		class Burst { dispersion = 0.003; };
		class FullAuto { dispersion = 0.003; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 450;
				};
			};
		};
	};

	class IMP_MP5RailA2_FDE_FIX2 : IMP_MP5RailA2_FDE
	{
		weight = 1840;
		itemSize[] = {5,3};
		recoilModifier[] = {0.45,0.45,0.45};
		magazines[] = {"Mag_MP5_15Rnd","Mag_MP5_30Rnd","IMP_Mag_MP5_30rnd","IMP_Mag_MP5_50rnd"};
		class SemiAuto { dispersion = 0.003; };
		class Burst { dispersion = 0.003; };
		class FullAuto { dispersion = 0.003; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 450;
				};
			};
		};
	};

	// ================================================================
	// SMG - MP7
	// ================================================================
	class IMP_MP7_FIX2 : IMP_MP7
	{
		weight = 1800;
		itemSize[] = {5,3};
		recoilModifier[] = {1.0,1.0,1.0};
		magazines[] = {"IMP_Mag_MP7_40rnd"};
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
	// SMG - MP9
	// ================================================================
	class IMP_MP9_FIX2 : IMP_MP9
	{
		weight = 1400;
		itemSize[] = {5,3};
		recoilModifier[] = {0.4,0.4,0.4};
		magazines[] = {"IMP_Mag_MP9_30rnd"};
		class SemiAuto { dispersion = 0.004; };
		class FullAuto { dispersion = 0.004; };
		class Burst { dispersion = 0.004; };
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
	// SMG - UZI
	// ================================================================
	class IMP_UZI_FIX2 : IMP_UZI
	{
		weight = 3500;
		itemSize[] = {4,3};
		recoilModifier[] = {1.1,1.03,1.05};
		magazines[] = {"IMP_Mag_UZI_32rnd","IMP_Mag_UZI_72rnd"};
		class SemiAuto { dispersion = 0.003; };
		class FullAuto { dispersion = 0.0041; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - M87R
	// ================================================================
	class IMP_M87R_FIX2 : IMP_M87R
	{
		weight = 9500;
		itemSize[] = {10,3};
		recoilModifier[] = {1,3,1};
		magazines[] = {"IMP_Mag_M87R_5rnd"};
		class Single { dispersion = 0.001; };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
				};
			};
		};
	};

	// ================================================================
	// SNIPER - OSV
	// ================================================================
	class IMP_OSV_FIX2 : IMP_OSV
	{
		weight = 12500;
		itemSize[] = {10,3};
		recoilModifier[] = {1,1,1};
		magazines[] = {"IMP_Mag_OSV_5rnd"};
		class Single { dispersion = 0.001; };
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
	// SNIPER - Ruger
	// ================================================================
	class IMP_Ruger_FIX2 : IMP_Ruger
	{
		weight = 12500;
		itemSize[] = {10,3};
		recoilModifier[] = {3,1.5,1.2};
		magazines[] = {"IMP_Mag_Ruger_5rnd"};
		class Single { dispersion = 0.0001; };
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
	// SNIPER - SCAR20S
	// ================================================================
	class IMP_SCAR20S_FIX2 : IMP_SCAR20S
	{
		weight = 3500;
		itemSize[] = {9,3};
		recoilModifier[] = {1.3,1.3,1.3};
		magazines[] = {"IMP_Mag_SCAR20S_5rnd"};
		class SemiAuto { dispersion = 0.001; };
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
	// SNIPER - SRSA2
	// ================================================================
	class IMP_SRSA2_FIX2 : IMP_SRSA2
	{
		weight = 4170;
		itemSize[] = {8,3};
		recoilModifier[] = {1.6,1.6,1.4};
		magazines[] = {"IMP_Mag_SRSA2_10rnd"};
		class Single { dispersion = 0.001; };
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

};
