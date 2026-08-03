#define _ARMA_

// ============================================================
// Патч поверх оружейного мода IMPWMOD - блок патронов (weapons/ammo/*).
// Оригинальные аддоны НЕ трогаем и не репакуем.
//
// В отличие от стволов, патрон и цинк - обычные лутающиеся
// предметы, а вот реальный урон пули лежит в CfgAmmo и НЕ
// является отдельным предметом - на него просто ссылаются по
// имени (поле ammo = "..." в патроне). Поэтому здесь везде
// используется переопределение ТЕМ ЖЕ ИМЕНЕМ класса (class X : X),
// а не новый _FIX-класс: правки применяются сразу к существующим
// патронам/цинкам без изменения types.xml.
// ============================================================

class CfgPatches
{
	class IMPWMOD_Ammo_FIX
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"IMP_AmmoBox_3006","IMP_Ammo_127x108","IMP_Ammo_127x42","IMP_Ammo_127x55","IMP_Ammo_127x99","IMP_Ammo_20mm","IMP_Ammo_300AAC","IMP_Ammo_338LM","IMP_Ammo_408","IMP_Ammo_46x30","IMP_Ammo_57x28","IMP_Ammo_762x25","IMP_Ammo_792x57","IMP_Ammo_9x18","IMP_Bullet_Projectiles"};
	};
};

class cfgAmmo
{
	// ==== 127x42 ====
	class IMP_Bullet_127x42
	{
		class DamageApplied
		{
			class Health { damage = 240; };
			class Blood { damage = 200; };
			class Shock { damage = 200; };
		};
	};

	// ==== 338LM ====
	class IMP_Bullet_338LM
	{
		class DamageApplied
		{
			class Health { damage = 350; };
			class Blood { damage = 350; };
			class Shock { damage = 250; };
		};
	};

	// ==== 408 ====
	class IMP_Bullet_408
	{
		class DamageApplied
		{
			class Health { damage = 800; };
			class Blood { damage = 800; };
			class Shock { damage = 400; };
		};
	};

	// ==== 127x55 ====
	class IMP_Bullet_127x55
	{
		class DamageApplied
		{
			class Health { damage = 650; };
			class Blood { damage = 650; };
			class Shock { damage = 100; };
		};
	};

	// ==== 127x99 ====
	class IMP_Bullet_127x99
	{
		class DamageApplied
		{
			class Health { damage = 2000; };
			class Blood { damage = 1000; };
			class Shock { damage = 1000; };
		};
	};

	// ==== 300AAC ====
	class IMP_Bullet_300AAC
	{
		class DamageApplied
		{
			class Health { damage = 60; };
			class Blood { damage = 60; };
			class Shock { damage = 60; };
		};
	};

	// ==== 792x57 ====
	class IMP_Bullet_792x57
	{
		class DamageApplied
		{
			class Health { damage = 180; };
			class Blood { damage = 180; };
			class Shock { damage = 180; };
		};
	};

	// ==== 762x25 ====
	class IMP_Bullet_762x25
	{
		class DamageApplied
		{
			class Health { damage = 24; };
			class Blood { damage = 24; };
			class Shock { damage = 24; };
		};
	};

	// ==== 57x28 ====
	class IMP_Bullet_57x28
	{
		class DamageApplied
		{
			class Health { damage = 24; };
			class Blood { damage = 24; };
			class Shock { damage = 24; };
		};
	};

	// ==== 9x18 ====
	class IMP_Bullet_9x18
	{
		class DamageApplied
		{
			class Health { damage = 40; };
			class Blood { damage = 40; };
			class Shock { damage = 40; };
		};
	};

	// ==== 127x108 ====
	class IMP_Bullet_127x108
	{
		class DamageApplied
		{
			class Health { damage = 5000; };
			class Blood { damage = 5000; };
			class Shock { damage = 5000; };
		};
	};

	// ==== 20mm ====
	class IMP_Bullet_20mm
	{
		class DamageApplied
		{
			class Health { damage = 10000; };
			class Blood { damage = 10000; };
			class Shock { damage = 10000; };
		};
	};

	// ==== 3006 ====
	class IMP_Bullet_3006
	{
		class DamageApplied
		{
			class Health { damage = 150; };
			class Blood { damage = 100; };
			class Shock { damage = 150; };
		};
	};

	// ==== 46x30 ====
	class IMP_Bullet_46x30
	{
		class DamageApplied
		{
			class Health { damage = 40; };
			class Blood { damage = 40; };
			class Shock { damage = 40; };
		};
	};

};

class CfgMagazines
{
	// ==== 127x108 - патрон (IMP_Ammo_127x108) ====
	class IMP_Ammo_127x108
	{
		weight = 4;
		count = 5;
		itemSize[] = {2,3};
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

	// ==== 127x42 - патрон (IMP_Ammo_127x42) ====
	class IMP_Ammo_127x42
	{
		weight = 4;
		count = 15;
		itemSize[] = {2,3};
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

	// ==== 127x55 - патрон (IMP_Ammo_127x55) ====
	class IMP_Ammo_127x55
	{
		weight = 4;
		count = 15;
		itemSize[] = {2,3};
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

	// ==== 127x99 - патрон (IMP_Ammo_127x99) ====
	class IMP_Ammo_127x99
	{
		weight = 4;
		count = 10;
		itemSize[] = {2,3};
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

	// ==== 20mm - патрон (IMP_Ammo_20mm) ====
	class IMP_Ammo_20mm
	{
		weight = 30;
		count = 5;
		itemSize[] = {2,3};
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

	// ==== 30-06 - патрон (IMP_Ammo_3006) ====
	class IMP_Ammo_3006
	{
		weight = 16;
		count = 50;
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

	// ==== 300AACBlackout - патрон (IMP_Ammo_300AAC) ====
	class IMP_Ammo_300AAC
	{
		weight = 4;
		count = 30;
		itemSize[] = {1,2};
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

	// ==== 338LM - патрон (IMP_Ammo_338LM) ====
	class IMP_Ammo_338LM
	{
		weight = 4;
		count = 20;
		itemSize[] = {2,3};
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

	// ==== 408 - патрон (IMP_Ammo_408) ====
	class IMP_Ammo_408
	{
		weight = 4;
		count = 10;
		itemSize[] = {2,3};
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

	// ==== 46x30 - патрон (IMP_Ammo_46x30) ====
	class IMP_Ammo_46x30
	{
		weight = 4;
		count = 40;
		itemSize[] = {1,1};
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

	// ==== 57x28 - патрон (IMP_Ammo_57x28) ====
	class IMP_Ammo_57x28
	{
		weight = 4;
		count = 50;
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

	// ==== 762x25 - патрон (IMP_Ammo_762x25) ====
	class IMP_Ammo_762x25
	{
		weight = 4;
		count = 50;
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

	// ==== 792x57 - патрон (IMP_Ammo_792x57) ====
	class IMP_Ammo_792x57
	{
		weight = 4;
		count = 20;
		itemSize[] = {2,3};
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

	// ==== 9x18 - патрон (IMP_Ammo_9x18) ====
	class IMP_Ammo_9x18
	{
		weight = 4;
		count = 50;
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

class CfgVehicles
{
	// ==== 127x108 - цинк (IMP_AmmoBox_127x108_5Rnd) ====
	class IMP_AmmoBox_127x108_5Rnd
	{
		weight = 185;
		itemSize[] = {3,2};
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

	// ==== 127x42 - цинк (IMP_AmmoBox_127x42_100Rnd) ====
	class IMP_AmmoBox_127x42_100Rnd
	{
		weight = 185;
		itemSize[] = {3,2};
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

	// ==== 127x42 - цинк (IMP_AmmoBox_127x42_15Rnd) ====
	class IMP_AmmoBox_127x42_15Rnd
	{
		weight = 185;
		itemSize[] = {3,2};
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

	// ==== 127x55 - цинк (IMP_AmmoBox_127x55_100Rnd) ====
	class IMP_AmmoBox_127x55_100Rnd
	{
		weight = 185;
		itemSize[] = {3,2};
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

	// ==== 127x55 - цинк (IMP_AmmoBox_127x55_15Rnd) ====
	class IMP_AmmoBox_127x55_15Rnd
	{
		weight = 185;
		itemSize[] = {3,2};
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

	// ==== 127x99 - цинк (IMP_AmmoBox_127x99_100Rnd) ====
	class IMP_AmmoBox_127x99_100Rnd
	{
		weight = 185;
		itemSize[] = {3,2};
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

	// ==== 127x99 - цинк (IMP_AmmoBox_127x99_10Rnd) ====
	class IMP_AmmoBox_127x99_10Rnd
	{
		weight = 185;
		itemSize[] = {3,2};
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

	// ==== 20mm - цинк (IMP_AmmoBox_20mm_5Rnd) ====
	class IMP_AmmoBox_20mm_5Rnd
	{
		weight = 185;
		itemSize[] = {3,2};
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

	// ==== 30-06 - цинк (IMP_AmmoBox_3006_20Rnd) ====
	class IMP_AmmoBox_3006_20Rnd
	{
		weight = 185;
		itemSize[] = {2,1};
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

	// ==== 300AACBlackout - цинк (IMP_AmmoBox_300AAC_100Rnd) ====
	class IMP_AmmoBox_300AAC_100Rnd
	{
		weight = 185;
		itemSize[] = {2,1};
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

	// ==== 300AACBlackout - цинк (IMP_AmmoBox_300AAC_30Rnd) ====
	class IMP_AmmoBox_300AAC_30Rnd
	{
		weight = 185;
		itemSize[] = {2,1};
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

	// ==== 338LM - цинк (IMP_AmmoBox_338LM_100Rnd) ====
	class IMP_AmmoBox_338LM_100Rnd
	{
		weight = 185;
		itemSize[] = {3,2};
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

	// ==== 338LM - цинк (IMP_AmmoBox_338LM_20Rnd) ====
	class IMP_AmmoBox_338LM_20Rnd
	{
		weight = 185;
		itemSize[] = {3,2};
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

	// ==== 408 - цинк (IMP_AmmoBox_408_100Rnd) ====
	class IMP_AmmoBox_408_100Rnd
	{
		weight = 185;
		itemSize[] = {3,2};
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

	// ==== 408 - цинк (IMP_AmmoBox_408_10Rnd) ====
	class IMP_AmmoBox_408_10Rnd
	{
		weight = 185;
		itemSize[] = {3,2};
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

	// ==== 46x30 - цинк (IMP_AmmoBox_46x30_40Rnd) ====
	class IMP_AmmoBox_46x30_40Rnd
	{
		weight = 185;
		itemSize[] = {1,2};
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

	// ==== 46x30 - цинк (IMP_AmmoBox_46x30_15Rnd) ====
	class IMP_AmmoBox_46x30_15Rnd
	{
		weight = 185;
		itemSize[] = {1,2};
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

	// ==== 57x28 - цинк (IMP_AmmoBox_57x28_50Rnd) ====
	class IMP_AmmoBox_57x28_50Rnd
	{
		weight = 185;
		itemSize[] = {2,1};
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

	// ==== 762x25 - цинк (IMP_AmmoBox_762x25_50Rnd) ====
	class IMP_AmmoBox_762x25_50Rnd
	{
		weight = 185;
		itemSize[] = {2,1};
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

	// ==== 792x57 - цинк (IMP_AmmoBox_792x57_100Rnd) ====
	class IMP_AmmoBox_792x57_100Rnd
	{
		weight = 185;
		itemSize[] = {3,2};
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

	// ==== 792x57 - цинк (IMP_AmmoBox_792x57_20Rnd) ====
	class IMP_AmmoBox_792x57_20Rnd
	{
		weight = 185;
		itemSize[] = {3,2};
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

	// ==== 9x18 - цинк (IMP_AmmoBox_9x18_50Rnd) ====
	class IMP_AmmoBox_9x18_50Rnd
	{
		weight = 185;
		itemSize[] = {2,1};
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
