#define _ARMA_

// ============================================================
// Патч поверх оригинального IMPSET22 "Аль Катала" (IMP_*_SET22).
// Оригинальные аддоны НЕ трогаем - только наследуемся и
// переопределяем то, что реально изменено. Переустановите/обновите
// оригинал - этот патч продолжит работать поверх него.
// ============================================================

class CfgPatches
{
	class IMPSET22_FIX
	{
		units[] = {"IMP_Bag_SET22_FIX","IMP_Balaclava_SET22_FIX","IMP_Boots_SET22_FIX","IMP_Gloves_SET22_FIX","IMP_Helmet_SET22_FIX","IMP_Jacket_SET22_FIX","IMP_Pants_SET22_1_FIX","IMP_Vest_SET22_1_FIX"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"IMP_Bag_SET22","IMP_Balaclava_SET22","IMP_Boots_SET22","IMP_Gloves_SET22","IMP_Helmet_SET22","IMP_Jacket_SET22","IMP_Pants_SET22","IMP_Vest_SET22"};
	};
};

class CfgVehicles
{
	class IMP_Bag_SET22;
	class IMP_Balaclava_SET22;
	class IMP_Boots_SET22;
	class IMP_Gloves_SET22;
	class IMP_Helmet_SET22;
	class IMP_Jacket_SET22;
	class IMP_Pants_SET22_1;
	class IMP_Vest_SET22_1;

	// ================================================================
	// BACKPACK
	// ================================================================
	class IMP_Bag_SET22_FIX : IMP_Bag_SET22
	{
		scope = 2;
		displayName = "Рюкзак Аль Катала";
		descriptionShort = "Потрёпанный тактический рюкзак с нашивками «Аль Катала». В нём бойцы группировки таскают боеприпасы и трофеи, снятые с захваченных блокпостов.";
		itemSize[] = {4, 4};
		itemsCargoSize[] = {8, 10};
		weight = 1300;
		heatIsolation = 0.5;
		varWetMax = 0;

		// В оригинале у Backpack вообще не было GlobalArmor - добавляем целиком
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
	class IMP_Balaclava_SET22_FIX : IMP_Balaclava_SET22
	{
		scope = 2;
		displayName = "Балаклава Аль Катала";
		descriptionShort = "Плотная балаклава, скрывающая лицо бойца «Аль Катала». Не выдаёт разведчика в темноте и наводит страх на местных при свете дня.";
		itemSize[] = {3, 2};
		weight = 400;
		heatIsolation = 1;
		varWetMax = 0;

		class Protection
		{
			biological = 0.8;
		};

		// В оригинале у Balaclava вообще не было GlobalArmor - добавляем целиком
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
	class IMP_Boots_SET22_FIX : IMP_Boots_SET22
	{
		scope = 2;
		displayName = "Обувь Аль Катала";
		descriptionShort = "Разношенные берцы, прошедшие не один рейд с «Аль Катала». Подошва почти стёрлась, но шнуровка всё ещё держит крепко.";
		itemSize[] = {3, 3};
		weight = 400;
		durability = 0.5;
		heatIsolation = 0.9;
		varWetMax = 0;

		// В оригинале у Boots вообще не было GlobalArmor - добавляем целиком
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
	// GLOVES
	// ================================================================
	class IMP_Gloves_SET22_FIX : IMP_Gloves_SET22
	{
		scope = 2;
		displayName = "Перчатки Аль Катала";
		descriptionShort = "Тактические перчатки без пальцев из выкладки «Аль Катала» — не мешают целиться и быстро менять магазин.";
		itemSize[] = {2, 2};
		weight = 454;
		heatIsolation = 0.5;
		varWetMax = 0;

		// В оригинале у Gloves вообще не было GlobalArmor - добавляем целиком
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
	class IMP_Helmet_SET22_FIX : IMP_Helmet_SET22
	{
		scope = 2;
		displayName = "Шлем Аль Катала";
		descriptionShort = "Тактический шлем с креплением под ПНВ и фонарь — один из немногих трофеев «Аль Катала», добытых в бою с регулярной армией.";
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
	class IMP_Jacket_SET22_FIX : IMP_Jacket_SET22
	{
		scope = 2;
		displayName = "Куртка Аль Катала";
		descriptionShort = "Полевая куртка «Аль Катала», сшитая из разномастных обрезков ткани. Греет слабо, зато не сковывает движений в бою.";
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
	class IMP_Pants_SET22_1_FIX : IMP_Pants_SET22_1
	{
		scope = 2;
		displayName = "Штаны Аль Катала";
		descriptionShort = "Штаны с усиленными коленями и карманами под магазины — стандартная выкладка рядового бойца «Аль Катала».";
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
	class IMP_Vest_SET22_1_FIX : IMP_Vest_SET22_1
	{
		scope = 2;
		displayName = "Бронежилет Аль Катала";
		descriptionShort = "Тяжёлый бронежилет, снятый с убитого командира «Аль Катала». Многослойная защита давит на плечи, зато держит осколки и большинство пистолетных пуль.";
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
};
