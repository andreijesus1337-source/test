#define _ARMA_

// ============================================================
// Патч поверх магазинов ВТОРОГО оружейного набора IMPWMODPart2
// (Weapons/Attachments/Magazine/*). Оригинальные аддоны НЕ трогаем
// и не репакуем.
//
// Пока покрыт только AK74 (11 вариантов) - остальные магазины
// добавляются сюда же по мере присылки новых файлов, по такому же
// принципу (см. AK74 ниже как образец).
//
// ВАЖНО: classname этих магазинов (IMP_Mag_AK74_6L18_45Rnd и т.д.)
// уже прописаны в magazines[] у AK12 из ПЕРВОГО набора (IMPWMOD_FIX) -
// то есть первый и второй набор оружия зависят друг от друга по
// магазинам, это не дублирование.
//
// Магазин - обычный лутающийся предмет, но на его classname уже
// ссылаются magazines[] у стволов (в обоих фиксах) и лут-таблицы.
// Поэтому, как и патроны, магазины переопределяются ТЕМ ЖЕ ИМЕНЕМ
// класса (без ": " и без forward declare) - правки применяются сразу
// к существующим магазинам, ничего больше менять не нужно.
// ============================================================

class CfgPatches
{
	class IMPWMODPart2_Magazine_FIX2
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"IMP_Mag_AK74"};
	};
};

class CfgMagazines
{
	// ================================================================
	// AK74
	// ================================================================
	class IMP_Mag_AK74_6L18_45Rnd
	{
		weight = 500;
		count = 45;
		itemSize[] = {1,4};
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

	class IMP_Mag_AK74_6L20_30Rnd
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

	class IMP_Mag_AK74_6L23_30Rnd
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

	class IMP_Mag_AK74_6L23P_30Rnd
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

	class IMP_Mag_AK74_6L26_45Rnd
	{
		weight = 500;
		count = 45;
		itemSize[] = {1,4};
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

	class IMP_Mag_AK74_6L31_60Rnd
	{
		weight = 500;
		count = 60;
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

	class IMP_Mag_AK74_DTSaiga_10Rnd
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

	class IMP_Mag_AK74_DTSaiga_20Rnd
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

	class IMP_Mag_AK74_PMag_30Rnd
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

	class IMP_Mag_AK74_PMag_FDE_30Rnd
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

	class IMP_Mag_AK74_Drum_95Rnd
	{
		weight = 500;
		count = 95;
		itemSize[] = {3,3};
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
