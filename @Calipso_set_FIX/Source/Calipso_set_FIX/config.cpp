#define _ARMA_

// ============================================================
// Патч поверх оригинального набора Calipso_set (Fruck_Calipso_*).
// Оригинальные аддоны НЕ трогаем - только наследуемся и
// переопределяем то, что реально изменено. Переустановите/обновите
// оригинал - этот патч продолжит работать поверх него.
//
// В оригинале у каждой вещи только один вариант (без цветов) -
// поэтому здесь по одному классу _FIX на вещь.
// ============================================================

class CfgPatches
{
	class Calipso_set_FIX
	{
		units[] = {"Fruck_Calipso_Shoes_FIX","Fruck_Calipso_gloves_FIX","Fruck_Calipso_Helmet_FIX","Fruck_Calipso_Jacket_FIX","Fruck_Calipso_Mask_FIX","Fruck_Calipso_Pants_FIX","Fruck_Calipso_Vest_FIX"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"Fruck_Calipso_Shoes","Fruck_Calipso_gloves","Fruck_Calipso_Helmet","Fruck_Calipso_Jacket","Fruck_Calipso_Mask","Fruck_Calipso_Pants","Fruck_Calipso_Vest"};
	};
};

class CfgVehicles
{
	class Fruck_Calipso_Shoes;
	class Fruck_Calipso_gloves;
	class Fruck_Calipso_Helmet;
	class Fruck_Calipso_Jacket;
	class Fruck_Calipso_Mask;
	class Fruck_Calipso_Pants;
	class Fruck_Calipso_Vest;

	// ================================================================
	// BOOTS
	// ================================================================
	class Fruck_Calipso_Shoes_FIX : Fruck_Calipso_Shoes
	{
		scope = 2;
		displayName = "Ботинки Calipso";
		descriptionShort = "Эти ботинки специально разработаны для экстремальных условий. Они защищают стопы гостя от повреждений и обеспечивают надежное сцепление с любой поверхностью.";
		itemSize[] = {3, 2};
		weight = 800;
		durability = 0.2;
		heatIsolation = 1;
		varWetMax = 0;

		// В оригинале hitpoints=100, значение сохранено, GlobalArmor стандартизирован на 80% защиты (0.2)
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
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
	class Fruck_Calipso_gloves_FIX : Fruck_Calipso_gloves
	{
		scope = 2;
		displayName = "Перчатки Calipso";
		descriptionShort = "Перчатки Calipso являются неотъемлемой частью его окружения на поле битвы.";
		itemSize[] = {2, 2};
		weight = 130;
		heatIsolation = 1;
		varWetMax = 0;

		class Protection
		{
			biological = 0.8;
			chemical = 0.8;
		};

		// В оригинале hitpoints=165, значение сохранено, GlobalArmor стандартизирован на 80% защиты (0.2)
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 165;
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
	class Fruck_Calipso_Helmet_FIX : Fruck_Calipso_Helmet
	{
		scope = 2;
		displayName = "Шлем Calipso";
		descriptionShort = "Шлем это защитный головной убор, который хорошо защищает голову от осколков и пуль.";
		itemSize[] = {2, 2};
		weight = 4500;
		heatIsolation = 1;
		varWetMax = 0;

		class Protection
		{
			biological = 0.8;
		};

		// В оригинале hitpoints=200, значение сохранено, GlobalArmor стандартизирован на 80% защиты (0.2)
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
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
	class Fruck_Calipso_Jacket_FIX : Fruck_Calipso_Jacket
	{
		scope = 2;
		displayName = "Куртка Calipso";
		descriptionShort = "Эта куртка была разработана специально для тех, кто ценит стиль и комфорт. Она имеет уникальный дизайн и обеспечивает защиту от холода и ветра.";
		itemSize[] = {4, 3};
		itemsCargoSize[] = {10, 8};
		weight = 2400;
		heatIsolation = 1;
		varWetMax = 0;

		// В оригинале hitpoints=140, значение сохранено, GlobalArmor стандартизирован на 80% защиты (0.2)
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 140;
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
	// MASK
	// ================================================================
	class Fruck_Calipso_Mask_FIX : Fruck_Calipso_Mask
	{
		scope = 2;
		displayName = "Маска Calipso";
		descriptionShort = "это защитный головной убор, который хорошо защищает голову и лицо";
		itemSize[] = {2, 2};
		weight = 4500;
		heatIsolation = 1;
		varWetMax = 0;

		class Protection
		{
			biological = 0.8;
		};

		// В оригинале hitpoints=200, значение сохранено, GlobalArmor стандартизирован на 80% защиты (0.2)
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
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
	class Fruck_Calipso_Pants_FIX : Fruck_Calipso_Pants
	{
		scope = 2;
		displayName = "Штаны Calipso";
		descriptionShort = "Эти штаны были разработаны для тех, кто активно двигается в любых погодных условиях. Они выполнены из прочных материалов и имеют уникальный дизайн, что обеспечивает комфорт и свободу движения.";
		itemSize[] = {4, 3};
		itemsCargoSize[] = {10, 8};
		weight = 830;
		heatIsolation = 1;
		varWetMax = 0;

		// В оригинале hitpoints=100, значение сохранено, GlobalArmor стандартизирован на 80% защиты (0.2)
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
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
	class Fruck_Calipso_Vest_FIX : Fruck_Calipso_Vest
	{
		scope = 2;
		displayName = "Бронежилет Calipso";
		descriptionShort = "это надежное средство защиты для вашей груди. Изготовленный из прочного материала, он обеспечивает превосходную защиту от ударов и повреждений. Он также легкий и удобный для ношения, позволяя вам свободно двигаться.";
		itemSize[] = {5, 4};
		itemsCargoSize[] = {8, 10};
		weight = 12000;
		heatIsolation = 1;
		varWetMax = 0;

		// В оригинале hitpoints=225, значение сохранено, GlobalArmor стандартизирован на 80% защиты (0.2)
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 225;
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
