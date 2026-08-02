/*
	IMPSET22_FIX — выносной патч-конфиг для набора IMPSET22 "Аль Катала".

	Это ОТДЕЛЬНЫЙ аддон, который ничего не меняет в файлах оригинального
	мода. Он требует оригинальные PBO (requiredAddons ниже) и добавляет
	свои классы с суффиксом "_FIX", унаследованные от оригинальных вещей.
	Модели, текстуры, звуки, анимации и скрипты не переопределяются —
	они подтягиваются наследованием из оригинального мода "как есть".

	Все параметры, которые имеет смысл балансить, вынесены в #define в
	начале этого же файла — правите числа здесь, ничего больше искать
	не нужно.

	ВАЖНО: так как "_FIX" — это новые классы (не оригинальные), в игре
	они появятся ДОПОЛНИТЕЛЬНО к оригинальным вещам. Чтобы игроки/лут
	получали именно исправленную версию, впишите classname с "_FIX" в
	свои типы/лут-таблицы (types.xml и т.п.) вместо оригинальных.
*/

// ============================================================
// Название и лорное описание
// ============================================================
#define IMPSET22_FIX_BACKPACK_NAME		"Рюкзак Аль Катала"
#define IMPSET22_FIX_BACKPACK_DESC		"Потрёпанный тактический рюкзак с нашивками «Аль Катала». В нём бойцы группировки таскают боеприпасы и трофеи, снятые с захваченных блокпостов."

#define IMPSET22_FIX_BALACLAVA_NAME		"Балаклава Аль Катала"
#define IMPSET22_FIX_BALACLAVA_DESC		"Плотная балаклава, скрывающая лицо бойца «Аль Катала». Не выдаёт разведчика в темноте и наводит страх на местных при свете дня."

#define IMPSET22_FIX_BOOTS_NAME			"Обувь Аль Катала"
#define IMPSET22_FIX_BOOTS_DESC			"Разношенные берцы, прошедшие не один рейд с «Аль Катала». Подошва почти стёрлась, но шнуровка всё ещё держит крепко."

#define IMPSET22_FIX_GLOVES_NAME			"Перчатки Аль Катала"
#define IMPSET22_FIX_GLOVES_DESC			"Тактические перчатки без пальцев из выкладки «Аль Катала» — не мешают целиться и быстро менять магазин."

#define IMPSET22_FIX_HELMET_NAME			"Шлем Аль Катала"
#define IMPSET22_FIX_HELMET_DESC			"Тактический шлем с креплением под ПНВ и фонарь — один из немногих трофеев «Аль Катала», добытых в бою с регулярной армией."

#define IMPSET22_FIX_JACKET_NAME			"Куртка Аль Катала"
#define IMPSET22_FIX_JACKET_DESC			"Полевая куртка «Аль Катала», сшитая из разномастных обрезков ткани. Греет слабо, зато не сковывает движений в бою."

#define IMPSET22_FIX_PANTS_NAME			"Штаны Аль Катала"
#define IMPSET22_FIX_PANTS_DESC			"Штаны с усиленными коленями и карманами под магазины — стандартная выкладка рядового бойца «Аль Катала»."

#define IMPSET22_FIX_VEST_NAME			"Бронежилет Аль Катала"
#define IMPSET22_FIX_VEST_DESC			"Тяжёлый бронежилет, снятый с убитого командира «Аль Катала». Многослойная защита давит на плечи, зато держит осколки и большинство пистолетных пуль."

// ============================================================
// Размеры в инвентаре (ширина x высота, в слотах)
// ============================================================
#define IMPSET22_FIX_BACKPACK_SIZE_X		4
#define IMPSET22_FIX_BACKPACK_SIZE_Y		4
#define IMPSET22_FIX_BACKPACK_CARGO_X	8
#define IMPSET22_FIX_BACKPACK_CARGO_Y	10

#define IMPSET22_FIX_BALACLAVA_SIZE_X	3
#define IMPSET22_FIX_BALACLAVA_SIZE_Y	2

#define IMPSET22_FIX_BOOTS_SIZE_X		3
#define IMPSET22_FIX_BOOTS_SIZE_Y		3

#define IMPSET22_FIX_GLOVES_SIZE_X		2
#define IMPSET22_FIX_GLOVES_SIZE_Y		2

#define IMPSET22_FIX_HELMET_SIZE_X		4
#define IMPSET22_FIX_HELMET_SIZE_Y		4

#define IMPSET22_FIX_JACKET_SIZE_X		4
#define IMPSET22_FIX_JACKET_SIZE_Y		4
#define IMPSET22_FIX_JACKET_CARGO_X		6
#define IMPSET22_FIX_JACKET_CARGO_Y		10

#define IMPSET22_FIX_PANTS_SIZE_X		4
#define IMPSET22_FIX_PANTS_SIZE_Y		4
#define IMPSET22_FIX_PANTS_CARGO_X		6
#define IMPSET22_FIX_PANTS_CARGO_Y		10

#define IMPSET22_FIX_VEST_SIZE_X			5
#define IMPSET22_FIX_VEST_SIZE_Y			5
#define IMPSET22_FIX_VEST_CARGO_X		6
#define IMPSET22_FIX_VEST_CARGO_Y		10

// ============================================================
// Вес (в граммах) и утепление (0 = не греет .. 1 = максимум)
// ============================================================
#define IMPSET22_FIX_BACKPACK_WEIGHT		1300
#define IMPSET22_FIX_BACKPACK_HEATISO	0.5

#define IMPSET22_FIX_BALACLAVA_WEIGHT	400
#define IMPSET22_FIX_BALACLAVA_HEATISO	1

#define IMPSET22_FIX_BOOTS_WEIGHT		400
#define IMPSET22_FIX_BOOTS_HEATISO		0.9

#define IMPSET22_FIX_GLOVES_WEIGHT		454
#define IMPSET22_FIX_GLOVES_HEATISO		0.5

#define IMPSET22_FIX_HELMET_WEIGHT		3000
#define IMPSET22_FIX_HELMET_HEATISO		1

#define IMPSET22_FIX_JACKET_WEIGHT		800
#define IMPSET22_FIX_JACKET_HEATISO		0.7

#define IMPSET22_FIX_PANTS_WEIGHT		530
#define IMPSET22_FIX_PANTS_HEATISO		0.8

#define IMPSET22_FIX_VEST_WEIGHT			10000
#define IMPSET22_FIX_VEST_HEATISO		1

// ============================================================
// Влагостойкость (varWetMax) — 0 = предмет никогда не намокает
// ============================================================
#define IMPSET22_FIX_WET_MAX				0

// ============================================================
// Прочность предмета (очки здоровья, DamageSystem > Health > hitpoints)
// ============================================================
#define IMPSET22_FIX_BACKPACK_HITPOINTS	500
#define IMPSET22_FIX_BALACLAVA_HITPOINTS	500
#define IMPSET22_FIX_BOOTS_HITPOINTS		500
#define IMPSET22_FIX_GLOVES_HITPOINTS	500
#define IMPSET22_FIX_HELMET_HITPOINTS	500
#define IMPSET22_FIX_JACKET_HITPOINTS	500
#define IMPSET22_FIX_PANTS_HITPOINTS		500
#define IMPSET22_FIX_VEST_HITPOINTS		500

// Дополнительный множитель прочности (используется только у обуви)
#define IMPSET22_FIX_BOOTS_DURABILITY	0.5

// ============================================================
// Защита (80% у всего набора)
// Protection.biological — доля защиты напрямую: 1.0 = полная защита.
// GlobalArmor.damage — доля урона, которая ПРОХОДИТ через предмет:
// 0.0 = блокирует весь урон, 1.0 = защиты нет. Поэтому 80% защиты = 0.2.
// ============================================================
#define IMPSET22_FIX_BALACLAVA_BIO_PROTECTION	0.8
#define IMPSET22_FIX_HELMET_BIO_PROTECTION		0.8

#define IMPSET22_FIX_ARMOR_DAMAGE				0.2

// ============================================================
// CfgPatches
// ============================================================
class CfgPatches
{
	class IMPSET22_FIX
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"IMP_Bag_SET22",
			"IMP_Balaclava_SET22",
			"IMP_Boots_SET22",
			"IMP_Gloves_SET22",
			"IMP_Helmet_SET22",
			"IMP_Jacket_SET22",
			"IMP_Pants_SET22",
			"IMP_Vest_SET22"
		};
	};
};

// ============================================================
// Классы вещей (наследуются от оригинальных, только с новыми параметрами)
// ============================================================
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

	class IMP_Bag_SET22_FIX : IMP_Bag_SET22
	{
		displayName = IMPSET22_FIX_BACKPACK_NAME;
		descriptionShort = IMPSET22_FIX_BACKPACK_DESC;
		itemSize[] = {IMPSET22_FIX_BACKPACK_SIZE_X, IMPSET22_FIX_BACKPACK_SIZE_Y};
		itemsCargoSize[] = {IMPSET22_FIX_BACKPACK_CARGO_X, IMPSET22_FIX_BACKPACK_CARGO_Y};
		weight = IMPSET22_FIX_BACKPACK_WEIGHT;
		heatIsolation = IMPSET22_FIX_BACKPACK_HEATISO;
		varWetMax = IMPSET22_FIX_WET_MAX;

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = IMPSET22_FIX_BACKPACK_HITPOINTS;
				};
			};

			class GlobalArmor
			{
				class Projectile
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Melee
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Infected
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class FragGrenade
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
			};
		};
	};

	class IMP_Balaclava_SET22_FIX : IMP_Balaclava_SET22
	{
		displayName = IMPSET22_FIX_BALACLAVA_NAME;
		descriptionShort = IMPSET22_FIX_BALACLAVA_DESC;
		itemSize[] = {IMPSET22_FIX_BALACLAVA_SIZE_X, IMPSET22_FIX_BALACLAVA_SIZE_Y};
		weight = IMPSET22_FIX_BALACLAVA_WEIGHT;
		heatIsolation = IMPSET22_FIX_BALACLAVA_HEATISO;
		varWetMax = IMPSET22_FIX_WET_MAX;

		class Protection
		{
			biological = IMPSET22_FIX_BALACLAVA_BIO_PROTECTION;
		};

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = IMPSET22_FIX_BALACLAVA_HITPOINTS;
				};
			};

			class GlobalArmor
			{
				class Projectile
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Melee
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Infected
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class FragGrenade
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
			};
		};
	};

	class IMP_Boots_SET22_FIX : IMP_Boots_SET22
	{
		displayName = IMPSET22_FIX_BOOTS_NAME;
		descriptionShort = IMPSET22_FIX_BOOTS_DESC;
		itemSize[] = {IMPSET22_FIX_BOOTS_SIZE_X, IMPSET22_FIX_BOOTS_SIZE_Y};
		weight = IMPSET22_FIX_BOOTS_WEIGHT;
		durability = IMPSET22_FIX_BOOTS_DURABILITY;
		heatIsolation = IMPSET22_FIX_BOOTS_HEATISO;
		varWetMax = IMPSET22_FIX_WET_MAX;

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = IMPSET22_FIX_BOOTS_HITPOINTS;
				};
			};

			class GlobalArmor
			{
				class Projectile
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Melee
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Infected
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class FragGrenade
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
			};
		};
	};

	class IMP_Gloves_SET22_FIX : IMP_Gloves_SET22
	{
		displayName = IMPSET22_FIX_GLOVES_NAME;
		descriptionShort = IMPSET22_FIX_GLOVES_DESC;
		itemSize[] = {IMPSET22_FIX_GLOVES_SIZE_X, IMPSET22_FIX_GLOVES_SIZE_Y};
		weight = IMPSET22_FIX_GLOVES_WEIGHT;
		heatIsolation = IMPSET22_FIX_GLOVES_HEATISO;
		varWetMax = IMPSET22_FIX_WET_MAX;

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = IMPSET22_FIX_GLOVES_HITPOINTS;
				};
			};

			class GlobalArmor
			{
				class Projectile
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Melee
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Infected
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class FragGrenade
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
			};
		};
	};

	class IMP_Helmet_SET22_FIX : IMP_Helmet_SET22
	{
		displayName = IMPSET22_FIX_HELMET_NAME;
		descriptionShort = IMPSET22_FIX_HELMET_DESC;
		itemSize[] = {IMPSET22_FIX_HELMET_SIZE_X, IMPSET22_FIX_HELMET_SIZE_Y};
		weight = IMPSET22_FIX_HELMET_WEIGHT;
		heatIsolation = IMPSET22_FIX_HELMET_HEATISO;
		varWetMax = IMPSET22_FIX_WET_MAX;

		class Protection
		{
			biological = IMPSET22_FIX_HELMET_BIO_PROTECTION;
		};

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = IMPSET22_FIX_HELMET_HITPOINTS;
				};
			};

			class GlobalArmor
			{
				class Projectile
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Melee
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Infected
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class FragGrenade
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
			};
		};
	};

	class IMP_Jacket_SET22_FIX : IMP_Jacket_SET22
	{
		displayName = IMPSET22_FIX_JACKET_NAME;
		descriptionShort = IMPSET22_FIX_JACKET_DESC;
		itemSize[] = {IMPSET22_FIX_JACKET_SIZE_X, IMPSET22_FIX_JACKET_SIZE_Y};
		itemsCargoSize[] = {IMPSET22_FIX_JACKET_CARGO_X, IMPSET22_FIX_JACKET_CARGO_Y};
		weight = IMPSET22_FIX_JACKET_WEIGHT;
		heatIsolation = IMPSET22_FIX_JACKET_HEATISO;
		varWetMax = IMPSET22_FIX_WET_MAX;

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = IMPSET22_FIX_JACKET_HITPOINTS;
				};
			};

			class GlobalArmor
			{
				class Projectile
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Melee
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Infected
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class FragGrenade
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
			};
		};
	};

	class IMP_Pants_SET22_1_FIX : IMP_Pants_SET22_1
	{
		displayName = IMPSET22_FIX_PANTS_NAME;
		descriptionShort = IMPSET22_FIX_PANTS_DESC;
		itemSize[] = {IMPSET22_FIX_PANTS_SIZE_X, IMPSET22_FIX_PANTS_SIZE_Y};
		itemsCargoSize[] = {IMPSET22_FIX_PANTS_CARGO_X, IMPSET22_FIX_PANTS_CARGO_Y};
		weight = IMPSET22_FIX_PANTS_WEIGHT;
		heatIsolation = IMPSET22_FIX_PANTS_HEATISO;
		varWetMax = IMPSET22_FIX_WET_MAX;

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = IMPSET22_FIX_PANTS_HITPOINTS;
				};
			};

			class GlobalArmor
			{
				class Projectile
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Melee
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Infected
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class FragGrenade
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
			};
		};
	};

	class IMP_Vest_SET22_1_FIX : IMP_Vest_SET22_1
	{
		displayName = IMPSET22_FIX_VEST_NAME;
		descriptionShort = IMPSET22_FIX_VEST_DESC;
		itemSize[] = {IMPSET22_FIX_VEST_SIZE_X, IMPSET22_FIX_VEST_SIZE_Y};
		itemsCargoSize[] = {IMPSET22_FIX_VEST_CARGO_X, IMPSET22_FIX_VEST_CARGO_Y};
		weight = IMPSET22_FIX_VEST_WEIGHT;
		heatIsolation = IMPSET22_FIX_VEST_HEATISO;
		varWetMax = IMPSET22_FIX_WET_MAX;

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = IMPSET22_FIX_VEST_HITPOINTS;
				};
			};

			class GlobalArmor
			{
				class Projectile
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Melee
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class Infected
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
				class FragGrenade
				{
					class Health { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Blood { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
					class Shock { damage = IMPSET22_FIX_ARMOR_DAMAGE; };
				};
			};
		};
	};
};
