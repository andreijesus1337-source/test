#define _ARMA_

// ============================================================
// Патч поверх оригинального IMPSET21 "Megalith" (IMP_*_SET21).
// Оригинальные аддоны НЕ трогаем - только наследуемся и
// переопределяем то, что реально изменено. Переустановите/обновите
// оригинал - этот патч продолжит работать поверх него.
//
// У каждой вещи закрыты ВСЕ цветовые варианты оригинала (не один).
// ============================================================

class CfgPatches
{
	class IMPSET21_FIX
	{
		units[] = {"IMP_Bag_SET21_FIX","IMP_Bag_SET21_2_FIX","IMP_Balaclava_SET21_FIX","IMP_Balaclava_SET21_2_FIX","IMP_Belt_SET21_FIX","IMP_Belt_SET21_2_FIX","IMP_Boots_SET21_FIX","IMP_Boots_SET21_2_FIX","IMP_Helmet_SET21_FIX","IMP_Helmet_SET21_2_FIX","IMP_Jacket_SET21_1_FIX","IMP_Jacket_SET21_2_FIX","IMP_Jacket_SET21_1_2_FIX","IMP_Jacket_SET21_2_2_FIX","IMP_Pants_SET21_1_FIX","IMP_Pants_SET21_2_FIX","IMP_Pants_SET21_1_2_FIX","IMP_Pants_SET21_2_2_FIX","IMP_Vest_SET21_1_FIX","IMP_Vest_SET21_2_FIX","IMP_SET21_Pouch_Blue_FIX","IMP_SET21_Pouch_Black_FIX"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"IMP_Bag_SET21","IMP_Balaclava_SET21","IMP_Belt_SET21","IMP_Boots_SET21","IMP_Helmet_SET21","IMP_Jacket_SET21","IMP_Pants_SET21","IMP_Vest_SET21","IMP_SET21_Pouch"};
	};
};

class CfgVehicles
{
	class IMP_Bag_SET21;
	class IMP_Bag_SET21_2;
	class IMP_Balaclava_SET21;
	class IMP_Balaclava_SET21_2;
	class IMP_Belt_SET21;
	class IMP_Belt_SET21_2;
	class IMP_Boots_SET21;
	class IMP_Boots_SET21_2;
	class IMP_Helmet_SET21;
	class IMP_Helmet_SET21_2;
	class IMP_Jacket_SET21_1;
	class IMP_Jacket_SET21_2;
	class IMP_Jacket_SET21_1_2;
	class IMP_Jacket_SET21_2_2;
	class IMP_Pants_SET21_1;
	class IMP_Pants_SET21_2;
	class IMP_Pants_SET21_1_2;
	class IMP_Pants_SET21_2_2;
	class IMP_Vest_SET21_1;
	class IMP_Vest_SET21_2;
	class IMP_SET21_Pouch_Blue;
	class IMP_SET21_Pouch_Black;

	// ================================================================
	// BACKPACK
	// ================================================================
	class IMP_Bag_SET21_FIX : IMP_Bag_SET21
	{
		scope = 2;
		displayName = "Рюкзак Megalith";
		descriptionShort = "Вместительный рюкзак снаряжения «Megalith» — трофейная выкладка, которую бойцы забирают у обеспеченных отрядов после стычек.";
		itemSize[] = {4, 4};
		itemsCargoSize[] = {8, 10};
		weight = 1300;
		heatIsolation = 0.5;
		varWetMax = 0;

		// В оригинале у этой вещи вообще не было GlobalArmor - добавляем целиком
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	class IMP_Bag_SET21_2_FIX : IMP_Bag_SET21_2
	{
		scope = 2;
		displayName = "Рюкзак Megalith";
		descriptionShort = "Вместительный рюкзак снаряжения «Megalith» — трофейная выкладка, которую бойцы забирают у обеспеченных отрядов после стычек.";
		itemSize[] = {4, 4};
		itemsCargoSize[] = {8, 10};
		weight = 1300;
		heatIsolation = 0.5;
		varWetMax = 0;

		// В оригинале у этой вещи вообще не было GlobalArmor - добавляем целиком
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	// ================================================================
	// BALACLAVA
	// ================================================================
	class IMP_Balaclava_SET21_FIX : IMP_Balaclava_SET21
	{
		scope = 2;
		displayName = "Балаклава Megalith";
		descriptionShort = "Плотная балаклава «Megalith», скрывающая лицо владельца — часть фирменной экипировки одноимённой группировки.";
		itemSize[] = {3, 2};
		weight = 400;
		heatIsolation = 1;
		varWetMax = 0;

		class Protection
		{
			biological = 0.8;
		};

		// В оригинале у этой вещи вообще не было GlobalArmor - добавляем целиком
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	class IMP_Balaclava_SET21_2_FIX : IMP_Balaclava_SET21_2
	{
		scope = 2;
		displayName = "Балаклава Megalith";
		descriptionShort = "Плотная балаклава «Megalith», скрывающая лицо владельца — часть фирменной экипировки одноимённой группировки.";
		itemSize[] = {3, 2};
		weight = 400;
		heatIsolation = 1;
		varWetMax = 0;

		class Protection
		{
			biological = 0.8;
		};

		// В оригинале у этой вещи вообще не было GlobalArmor - добавляем целиком
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	// ================================================================
	// BELT
	// ================================================================
	class IMP_Belt_SET21_FIX : IMP_Belt_SET21
	{
		scope = 2;
		displayName = "Ремень Megalith";
		descriptionShort = "Тактический ремень «Megalith» с подсумками под руку — стандартная деталь снаряжения бойцов группировки.";
		itemSize[] = {5, 1};
		itemsCargoSize[] = {4, 10};
		weight = 550;
		heatIsolation = 0.5;
		varWetMax = 0;

		// В оригинале у этой вещи вообще не было GlobalArmor - добавляем целиком
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	class IMP_Belt_SET21_2_FIX : IMP_Belt_SET21_2
	{
		scope = 2;
		displayName = "Ремень Megalith";
		descriptionShort = "Тактический ремень «Megalith» с подсумками под руку — стандартная деталь снаряжения бойцов группировки.";
		itemSize[] = {5, 1};
		itemsCargoSize[] = {4, 10};
		weight = 550;
		heatIsolation = 0.5;
		varWetMax = 0;

		// В оригинале у этой вещи вообще не было GlobalArmor - добавляем целиком
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	// ================================================================
	// BOOTS
	// ================================================================
	class IMP_Boots_SET21_FIX : IMP_Boots_SET21
	{
		scope = 2;
		displayName = "Обувь Megalith";
		descriptionShort = "Крепкие берцы «Megalith», рассчитанные на долгие переходы по разрушенной территории.";
		itemSize[] = {3, 3};
		weight = 400;
		durability = 0.5;
		heatIsolation = 0.9;
		varWetMax = 0;

		// В оригинале у этой вещи вообще не было GlobalArmor - добавляем целиком
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	class IMP_Boots_SET21_2_FIX : IMP_Boots_SET21_2
	{
		scope = 2;
		displayName = "Обувь Megalith";
		descriptionShort = "Крепкие берцы «Megalith», рассчитанные на долгие переходы по разрушенной территории.";
		itemSize[] = {3, 3};
		weight = 400;
		durability = 0.5;
		heatIsolation = 0.9;
		varWetMax = 0;

		// В оригинале у этой вещи вообще не было GlobalArmor - добавляем целиком
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	// ================================================================
	// HELMET
	// ================================================================
	class IMP_Helmet_SET21_FIX : IMP_Helmet_SET21
	{
		scope = 2;
		displayName = "Шлем Megalith";
		descriptionShort = "Тяжёлый тактический шлем «Megalith» с креплением под ПНВ и фонарь — редкий трофей с элитных бойцов группировки.";
		itemSize[] = {4, 4};
		weight = 3000;
		heatIsolation = 1;
		varWetMax = 0;

		class Protection
		{
			biological = 0.8;
		};

		// В оригинале уже было GlobalArmor (0.35) - просто меняем значение на 0.2
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	class IMP_Helmet_SET21_2_FIX : IMP_Helmet_SET21_2
	{
		scope = 2;
		displayName = "Шлем Megalith";
		descriptionShort = "Тяжёлый тактический шлем «Megalith» с креплением под ПНВ и фонарь — редкий трофей с элитных бойцов группировки.";
		itemSize[] = {4, 4};
		weight = 3000;
		heatIsolation = 1;
		varWetMax = 0;

		class Protection
		{
			biological = 0.8;
		};

		// В оригинале уже было GlobalArmor (0.35) - просто меняем значение на 0.2
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	// ================================================================
	// JACKET
	// ================================================================
	class IMP_Jacket_SET21_1_FIX : IMP_Jacket_SET21_1
	{
		scope = 2;
		displayName = "Куртка Megalith";
		descriptionShort = "Полевая куртка «Megalith» из плотной ткани — часть фирменной экипировки группировки, узнаваемой издалека.";
		itemSize[] = {4, 4};
		itemsCargoSize[] = {6, 10};
		weight = 800;
		heatIsolation = 0.7;
		varWetMax = 0;

		// В оригинале уже было GlobalArmor (0.5) - просто меняем значение на 0.2
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	class IMP_Jacket_SET21_2_FIX : IMP_Jacket_SET21_2
	{
		scope = 2;
		displayName = "Куртка Megalith";
		descriptionShort = "Полевая куртка «Megalith» из плотной ткани — часть фирменной экипировки группировки, узнаваемой издалека.";
		itemSize[] = {4, 4};
		itemsCargoSize[] = {6, 10};
		weight = 800;
		heatIsolation = 0.7;
		varWetMax = 0;

		// В оригинале уже было GlobalArmor (0.5) - просто меняем значение на 0.2
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	class IMP_Jacket_SET21_1_2_FIX : IMP_Jacket_SET21_1_2
	{
		scope = 2;
		displayName = "Куртка Megalith";
		descriptionShort = "Полевая куртка «Megalith» из плотной ткани — часть фирменной экипировки группировки, узнаваемой издалека.";
		itemSize[] = {4, 4};
		itemsCargoSize[] = {6, 10};
		weight = 800;
		heatIsolation = 0.7;
		varWetMax = 0;

		// В оригинале уже было GlobalArmor (0.5) - просто меняем значение на 0.2
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	class IMP_Jacket_SET21_2_2_FIX : IMP_Jacket_SET21_2_2
	{
		scope = 2;
		displayName = "Куртка Megalith";
		descriptionShort = "Полевая куртка «Megalith» из плотной ткани — часть фирменной экипировки группировки, узнаваемой издалека.";
		itemSize[] = {4, 4};
		itemsCargoSize[] = {6, 10};
		weight = 800;
		heatIsolation = 0.7;
		varWetMax = 0;

		// В оригинале уже было GlobalArmor (0.5) - просто меняем значение на 0.2
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	// ================================================================
	// PANTS
	// ================================================================
	class IMP_Pants_SET21_1_FIX : IMP_Pants_SET21_1
	{
		scope = 2;
		displayName = "Штаны Megalith";
		descriptionShort = "Штаны «Megalith» с усиленными вставками и карманами под магазины — стандартная выкладка бойца группировки.";
		itemSize[] = {4, 4};
		itemsCargoSize[] = {6, 10};
		weight = 530;
		heatIsolation = 0.8;
		varWetMax = 0;

		// В оригинале уже было GlobalArmor (0.5) - просто меняем значение на 0.2
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	class IMP_Pants_SET21_2_FIX : IMP_Pants_SET21_2
	{
		scope = 2;
		displayName = "Штаны Megalith";
		descriptionShort = "Штаны «Megalith» с усиленными вставками и карманами под магазины — стандартная выкладка бойца группировки.";
		itemSize[] = {4, 4};
		itemsCargoSize[] = {6, 10};
		weight = 530;
		heatIsolation = 0.8;
		varWetMax = 0;

		// В оригинале уже было GlobalArmor (0.5) - просто меняем значение на 0.2
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	class IMP_Pants_SET21_1_2_FIX : IMP_Pants_SET21_1_2
	{
		scope = 2;
		displayName = "Штаны Megalith";
		descriptionShort = "Штаны «Megalith» с усиленными вставками и карманами под магазины — стандартная выкладка бойца группировки.";
		itemSize[] = {4, 4};
		itemsCargoSize[] = {6, 10};
		weight = 530;
		heatIsolation = 0.8;
		varWetMax = 0;

		// В оригинале уже было GlobalArmor (0.5) - просто меняем значение на 0.2
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	class IMP_Pants_SET21_2_2_FIX : IMP_Pants_SET21_2_2
	{
		scope = 2;
		displayName = "Штаны Megalith";
		descriptionShort = "Штаны «Megalith» с усиленными вставками и карманами под магазины — стандартная выкладка бойца группировки.";
		itemSize[] = {4, 4};
		itemsCargoSize[] = {6, 10};
		weight = 530;
		heatIsolation = 0.8;
		varWetMax = 0;

		// В оригинале уже было GlobalArmor (0.5) - просто меняем значение на 0.2
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	// ================================================================
	// VEST
	// ================================================================
	class IMP_Vest_SET21_1_FIX : IMP_Vest_SET21_1
	{
		scope = 2;
		displayName = "Бронежилет Megalith";
		descriptionShort = "Тяжёлый бронежилет «Megalith» с системой креплений под подсумки — основа защитного снаряжения группировки.";
		itemSize[] = {5, 5};
		itemsCargoSize[] = {6, 10};
		weight = 10000;
		heatIsolation = 1;
		varWetMax = 0;

		// В оригинале уже было GlobalArmor (0.5) - просто меняем значение на 0.2
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	class IMP_Vest_SET21_2_FIX : IMP_Vest_SET21_2
	{
		scope = 2;
		displayName = "Бронежилет Megalith";
		descriptionShort = "Тяжёлый бронежилет «Megalith» с системой креплений под подсумки — основа защитного снаряжения группировки.";
		itemSize[] = {5, 5};
		itemsCargoSize[] = {6, 10};
		weight = 10000;
		heatIsolation = 1;
		varWetMax = 0;

		// В оригинале уже было GlobalArmor (0.5) - просто меняем значение на 0.2
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	// ================================================================
	// VEST POUCH (подсумок на бронежилет)
	// ================================================================
	class IMP_SET21_Pouch_Blue_FIX : IMP_SET21_Pouch_Blue
	{
		scope = 2;
		displayName = "Подсумки Megalith";
		descriptionShort = "Подсумки «Megalith», крепящиеся на бронежилет — увеличивают запас снаряжения под рукой.";
		itemSize[] = {3, 5};
		itemsCargoSize[] = {4, 5};
		weight = 250;

		// В оригинале у этой вещи вообще не было GlobalArmor - добавляем целиком
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

	class IMP_SET21_Pouch_Black_FIX : IMP_SET21_Pouch_Black
	{
		scope = 2;
		displayName = "Подсумки Megalith";
		descriptionShort = "Подсумки «Megalith», крепящиеся на бронежилет — увеличивают запас снаряжения под рукой.";
		itemSize[] = {3, 5};
		itemsCargoSize[] = {4, 5};
		weight = 250;

		// В оригинале у этой вещи вообще не было GlobalArmor - добавляем целиком
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Melee { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class Infected { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
				class FragGrenade { class Health { damage = 0.2; }; class Blood { damage = 0.2; }; class Shock { damage = 0.2; }; };
			};
		};
	};

};
