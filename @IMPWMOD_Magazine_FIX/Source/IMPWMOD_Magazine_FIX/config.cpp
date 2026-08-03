#define _ARMA_

// ============================================================
// Патч поверх магазинов оружейного мода IMPWMOD (weapons/
// Attachments/Magazine/*). Оригинальные аддоны НЕ трогаем и не
// репакуем.
//
// Магазин - обычный лутающийся предмет, но на его classname
// уже ссылаются magazines[] у стволов (в т.ч. в уже готовом
// IMPWMOD_FIX) и лут-таблицы. Поэтому, как и патроны, магазины
// переопределяются ТЕМ ЖЕ ИМЕНЕМ класса (без ": " и без
// forward declare) - правки применяются сразу к существующим
// магазинам, ничего больше менять не нужно.
// ============================================================

class CfgPatches
{
	class IMPWMOD_Magazine_FIX
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"IMP_Mag_AKM_Magpul","IMP_Mag_AK_Aluminium_30Rnd","IMP_Mag_AK_Arsenal_30Rnd","IMP_Mag_AK_Bakelyt_40Rnd","IMP_Mag_AK_Custom_10Rnd","IMP_Mag_AK_Drum_50Rnd","IMP_Mag_AK_FabDefence_30Rnd","IMP_Mag_AK_IzhmashSTD_30Rnd","IMP_Mag_AK_Izhmash_30Rnd","IMP_Mag_AK_MagpulPMag_30Rnd","IMP_Mag_AK_ProDrum_75Rnd","IMP_Mag_Glock","IMP_Mag_HK_Polymer_30Rnd","IMP_Mag_M4_Gen2_30Rnd","IMP_Mag_M4_Polymer_10Rnd","IMP_Mag_M4_Polymer_20Rnd","IMP_Mag_M4_Polymer_30Rnd","IMP_Mag_M4_Polymer_40Rnd","IMP_Mag_M4_Stanag_100Rnd","IMP_Mag_M4_Stanag_30Rnd","IMP_Mag_SVD_Coupled","IMP_Mag_VAL_Coupled","IMP_Mag_VSS_Coupled","IMP_Magazine_FAL_Coupled","IMP_Magazine_FAL_Drum","IMP_Magazine_M4_Cmag","IMP_Magazine_M4_Drum"};
	};
};

class CfgMagazines
{
	// ================================================================
	// AK/AKx50
	// ================================================================
	class IMP_Mag_AK_Drum_50Rnd
	{
		weight = 500;
		count = 50;
		itemSize[] = {2,3};
		recoilModifier[] = {0.85,0.85,1};
		swayModifier[] = {0.85,0.85,1};
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
	// AK/Aluminium30
	// ================================================================
	class IMP_Mag_AK_Aluminium_30Rnd
	{
		weight = 500;
		count = 30;
		itemSize[] = {1,3};
		recoilModifier[] = {0.9,0.9,1};
		swayModifier[] = {0.9,0.9,1};
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
	// AK/ArsenalCWP3055645
	// ================================================================
	class IMP_Mag_AK_Arsenal_30Rnd
	{
		weight = 500;
		count = 30;
		itemSize[] = {1,3};
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
	// AK/Bakelyt40
	// ================================================================
	class IMP_Mag_AK_Bakelyt_40Rnd
	{
		weight = 500;
		count = 30;
		itemSize[] = {1,4};
		recoilModifier[] = {0.95,0.95,1};
		swayModifier[] = {0.95,0.95,1};
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
	// AK/Custom10
	// ================================================================
	class IMP_Mag_AK_Custom_10Rnd
	{
		weight = 500;
		count = 10;
		itemSize[] = {1,1};
		recoilModifier[] = {0.85,0.85,1};
		swayModifier[] = {0.85,0.85,1};
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
	// AK/FabDefence30
	// ================================================================
	class IMP_Mag_AK_FabDefence_30Rnd
	{
		weight = 500;
		count = 30;
		itemSize[] = {1,3};
		recoilModifier[] = {0.85,0.85,1};
		swayModifier[] = {0.85,0.85,1};
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
	// AK/Izhmash30
	// ================================================================
	class IMP_Mag_AK_Izhmash_30Rnd
	{
		weight = 500;
		count = 30;
		itemSize[] = {1,3};
		recoilModifier[] = {0.95,0.95,1};
		swayModifier[] = {0.95,0.95,1};
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
	// AK/IzhmashSTD30
	// ================================================================
	class IMP_Mag_AK_IzhmashSTD_30Rnd
	{
		weight = 500;
		count = 30;
		itemSize[] = {1,3};
		recoilModifier[] = {0.9,0.9,1};
		swayModifier[] = {0.9,0.9,1};
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
	// AK/MagpulPmag30
	// ================================================================
	class IMP_Mag_AK_MagpulPMag_30Rnd
	{
		weight = 500;
		count = 30;
		itemSize[] = {1,3};
		recoilModifier[] = {0.85,0.85,1};
		swayModifier[] = {0.85,0.85,1};
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
	// AK/ProDrum75
	// ================================================================
	class IMP_Mag_AK_ProDrum_75Rnd
	{
		weight = 500;
		count = 75;
		itemSize[] = {3,3};
		recoilModifier[] = {0.95,0.95,1};
		swayModifier[] = {0.95,0.95,1};
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
	// AKMagpulMag
	// ================================================================
	class IMP_Mag_AKM_Magpul_Black
	{
		weight = 500;
		count = 30;
		itemSize[] = {1,3};
		recoilModifier[] = {0.9,0.9,1};
		swayModifier[] = {0.9,0.9,1};
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

	class IMP_Mag_AKM_Magpul_Black_Tape_60Rnd
	{
		weight = 1000;
		count = 60;
		itemSize[] = {2,3};
		recoilModifier[] = {0.95,0.95,1};
		swayModifier[] = {0.95,0.95,1};
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

	class IMP_Mag_AKM_Magpul_Black_Clip_60Rnd
	{
		weight = 1000;
		count = 60;
		itemSize[] = {2,3};
		recoilModifier[] = {0.95,0.95,1};
		swayModifier[] = {0.95,0.95,1};
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

	class IMP_Mag_AKM_Magpul_Banana
	{
		weight = 500;
		count = 30;
		itemSize[] = {1,3};
		recoilModifier[] = {0.9,0.9,1};
		swayModifier[] = {0.9,0.9,1};
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

	class IMP_Mag_AKM_Magpul_FDE
	{
		weight = 500;
		count = 30;
		itemSize[] = {1,3};
		recoilModifier[] = {0.9,0.9,1};
		swayModifier[] = {0.9,0.9,1};
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
	// FalCoupled
	// ================================================================
	class IMP_Mag_FAL_CoupledTape_40Rnd
	{
		weight = 500;
		count = 40;
		itemSize[] = {2,3};
		recoilModifier[] = {0.9,0.9,1};
		swayModifier[] = {0.9,0.9,1};
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

	class IMP_Mag_FAL_CoupledClip_40Rnd
	{
		weight = 500;
		count = 40;
		itemSize[] = {2,3};
		recoilModifier[] = {0.9,0.9,1};
		swayModifier[] = {0.9,0.9,1};
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
	// FalDrum
	// ================================================================
	class IMP_Mag_Fal_Drum_50Rnd
	{
		weight = 500;
		count = 50;
		itemSize[] = {2,3};
		recoilModifier[] = {0.95,0.95,1};
		swayModifier[] = {0.95,0.95,1};
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
	// GlockMag
	// ================================================================
	class IMP_Mag_Glock_21Rnd
	{
		weight = 210;
		count = 21;
		itemSize[] = {1,2};
		recoilModifier[] = {0.85,0.85,1};
		swayModifier[] = {0.85,0.85,1};
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

	class IMP_Mag_Glock_30Rnd
	{
		weight = 300;
		count = 30;
		itemSize[] = {1,3};
		recoilModifier[] = {0.9,0.9,1};
		swayModifier[] = {0.9,0.9,1};
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

	class IMP_Drum_Glock_50Rnd
	{
		weight = 500;
		count = 50;
		itemSize[] = {2,3};
		recoilModifier[] = {0.95,0.95,1};
		swayModifier[] = {0.95,0.95,1};
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
	// M4/Gen230
	// ================================================================
	class IMP_Mag_M4_Gen2_30Rnd
	{
		weight = 500;
		count = 30;
		itemSize[] = {1,3};
		recoilModifier[] = {0.9,0.9,1};
		swayModifier[] = {0.9,0.9,1};
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
	// M4/HKPolymer30
	// ================================================================
	class IMP_Mag_HK_Polymer_30Rnd
	{
		weight = 500;
		count = 30;
		itemSize[] = {1,3};
		recoilModifier[] = {0.85,0.85,1};
		swayModifier[] = {0.85,0.85,1};
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
	// M4/M4Stanag30
	// ================================================================
	class IMP_Mag_M4_Stanag_30Rnd
	{
		weight = 500;
		count = 30;
		itemSize[] = {1,3};
		recoilModifier[] = {0.9,0.9,1};
		swayModifier[] = {0.9,0.9,1};
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
	// M4/Pmag10
	// ================================================================
	class IMP_Mag_M4_Polymer_10Rnd
	{
		weight = 500;
		count = 10;
		itemSize[] = {1,1};
		recoilModifier[] = {0.85,0.85,1};
		swayModifier[] = {0.85,0.85,1};
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
	// M4/Pmag20
	// ================================================================
	class IMP_Mag_M4_Polymer_20Rnd
	{
		weight = 500;
		count = 20;
		itemSize[] = {1,2};
		recoilModifier[] = {0.85,0.85,1};
		swayModifier[] = {0.85,0.85,1};
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
	// M4/Pmag30
	// ================================================================
	class IMP_Mag_M4_Polymer_30Rnd
	{
		weight = 500;
		count = 30;
		itemSize[] = {1,3};
		recoilModifier[] = {0.9,0.9,1};
		swayModifier[] = {0.9,0.9,1};
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
	// M4/Pmag40
	// ================================================================
	class IMP_Mag_M4_Polymer_40Rnd
	{
		weight = 500;
		count = 40;
		itemSize[] = {1,4};
		recoilModifier[] = {0.95,0.95,1};
		swayModifier[] = {0.95,0.95,1};
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
	// M4/Stanag100
	// ================================================================
	class IMP_Mag_M4_Stanag_100Rnd
	{
		weight = 500;
		count = 100;
		itemSize[] = {2,4};
		recoilModifier[] = {0.95,0.95,1};
		swayModifier[] = {0.95,0.95,1};
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
	// M4Cmag
	// ================================================================
	class IMP_Mag_M4_Cmag_100Rnd
	{
		weight = 500;
		count = 100;
		itemSize[] = {3,3};
		recoilModifier[] = {0.95,0.95,1};
		swayModifier[] = {0.95,0.95,1};
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
	// M4Drum
	// ================================================================
	class IMP_Mag_M4_Drum60Rnd
	{
		weight = 200;
		count = 60;
		itemSize[] = {2,3};
		recoilModifier[] = {0.9,0.9,1};
		swayModifier[] = {0.9,0.9,1};
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
	// SVDCoupled
	// ================================================================
	class IMP_Mag_SVD_CoupledTape_20Rnd
	{
		weight = 240;
		count = 20;
		itemSize[] = {2,2};
		recoilModifier[] = {0.95,0.95,1};
		swayModifier[] = {0.95,0.95,1};
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

	class IMP_Mag_SVD_CoupledClip_20Rnd
	{
		weight = 240;
		count = 20;
		itemSize[] = {2,2};
		recoilModifier[] = {0.95,0.95,1};
		swayModifier[] = {0.95,0.95,1};
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
	// VALMagCoupled
	// ================================================================
	class IMP_Mag_VAL_CoupledTape_40Rnd
	{
		weight = 1100;
		count = 40;
		itemSize[] = {2,3};
		recoilModifier[] = {0.95,0.95,1};
		swayModifier[] = {0.95,0.95,1};
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

	class IMP_Mag_VAL_CoupledClip_40Rnd
	{
		weight = 1100;
		count = 40;
		itemSize[] = {2,3};
		recoilModifier[] = {0.95,0.95,1};
		swayModifier[] = {0.95,0.95,1};
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
	// VSSMagCoupled
	// ================================================================
	class IMP_Mag_VSS_CoupledTape_20Rnd
	{
		weight = 700;
		count = 20;
		itemSize[] = {1,3};
		recoilModifier[] = {0.85,0.85,1};
		swayModifier[] = {0.85,0.85,1};
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

	class IMP_Mag_VSS_CoupledClip_20Rnd
	{
		weight = 700;
		count = 20;
		itemSize[] = {1,3};
		recoilModifier[] = {0.85,0.85,1};
		swayModifier[] = {0.85,0.85,1};
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

};
