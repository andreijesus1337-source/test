/*
	IMPSET22 "Аль Катала" — единый файл параметров набора.

	Все настраиваемые значения для всех предметов набора (Backpack,
	Balaclava, Boots, Gloves, Helmet, Jacket, Pants, Vest) собраны здесь.
	Меняйте значения в этом файле — не нужно искать их по восьми разным
	config.cpp. После изменения пересоберите PBO каждого предмета.

	Пояснение по защите/урону (GlobalArmor.damage и Protection):
	значение — это доля урона, которая ПРОХОДИТ через предмет, т.е.
		0.0 = блокирует весь урон (максимальная защита)
		1.0 = защиты нет (весь урон проходит)
	Чем МЕНЬШЕ число — тем ЛУЧШЕ защита.
*/

// ============================================================
// Название мода / автор
// ============================================================
#define IMPSET22_AUTHOR				"IMPERIVM"

// ============================================================
// Название и лорное описание предметов
// ============================================================
#define IMPSET22_BACKPACK_NAME			"Рюкзак Аль Катала"
#define IMPSET22_BACKPACK_DESC			"Потрёпанный тактический рюкзак с нашивками «Аль Катала». В нём бойцы группировки таскают боеприпасы и трофеи, снятые с захваченных блокпостов."

#define IMPSET22_BALACLAVA_NAME			"Балаклава Аль Катала"
#define IMPSET22_BALACLAVA_DESC			"Плотная балаклава, скрывающая лицо бойца «Аль Катала». Не выдаёт разведчика в темноте и наводит страх на местных при свете дня."

#define IMPSET22_BOOTS_NAME				"Обувь Аль Катала"
#define IMPSET22_BOOTS_DESC				"Разношенные берцы, прошедшие не один рейд с «Аль Катала». Подошва почти стёрлась, но шнуровка всё ещё держит крепко."

#define IMPSET22_GLOVES_NAME			"Перчатки Аль Катала"
#define IMPSET22_GLOVES_DESC			"Тактические перчатки без пальцев из выкладки «Аль Катала» — не мешают целиться и быстро менять магазин."

#define IMPSET22_HELMET_NAME			"Шлем Аль Катала"
#define IMPSET22_HELMET_DESC			"Тактический шлем с креплением под ПНВ и фонарь — один из немногих трофеев «Аль Катала», добытых в бою с регулярной армией."

#define IMPSET22_JACKET_NAME			"Куртка Аль Катала"
#define IMPSET22_JACKET_DESC			"Полевая куртка «Аль Катала», сшитая из разномастных обрезков ткани. Греет слабо, зато не сковывает движений в бою."

#define IMPSET22_PANTS_NAME				"Штаны Аль Катала"
#define IMPSET22_PANTS_DESC				"Штаны с усиленными коленями и карманами под магазины — стандартная выкладка рядового бойца «Аль Катала»."

#define IMPSET22_VEST_NAME				"Бронежилет Аль Катала"
#define IMPSET22_VEST_DESC				"Тяжёлый бронежилет, снятый с убитого командира «Аль Катала». Многослойная защита давит на плечи, зато держит осколки и большинство пистолетных пуль."

// ============================================================
// Размеры в инвентаре (ширина x высота, в слотах)
// ============================================================
#define IMPSET22_BACKPACK_SIZE_X		4
#define IMPSET22_BACKPACK_SIZE_Y		4
#define IMPSET22_BACKPACK_CARGO_X		8
#define IMPSET22_BACKPACK_CARGO_Y		10

#define IMPSET22_BALACLAVA_SIZE_X		3
#define IMPSET22_BALACLAVA_SIZE_Y		2

#define IMPSET22_BOOTS_SIZE_X			3
#define IMPSET22_BOOTS_SIZE_Y			3

#define IMPSET22_GLOVES_SIZE_X			2
#define IMPSET22_GLOVES_SIZE_Y			2

#define IMPSET22_HELMET_SIZE_X			4
#define IMPSET22_HELMET_SIZE_Y			4

#define IMPSET22_JACKET_SIZE_X			4
#define IMPSET22_JACKET_SIZE_Y			4
#define IMPSET22_JACKET_CARGO_X			6
#define IMPSET22_JACKET_CARGO_Y			10

#define IMPSET22_PANTS_SIZE_X			4
#define IMPSET22_PANTS_SIZE_Y			4
#define IMPSET22_PANTS_CARGO_X			6
#define IMPSET22_PANTS_CARGO_Y			10

#define IMPSET22_VEST_SIZE_X			5
#define IMPSET22_VEST_SIZE_Y			5
#define IMPSET22_VEST_CARGO_X			6
#define IMPSET22_VEST_CARGO_Y			10

// ============================================================
// Вес (в граммах) и утепление (0 = не греет .. 1 = максимум)
// ============================================================
#define IMPSET22_BACKPACK_WEIGHT		1300
#define IMPSET22_BACKPACK_HEATISO		0.5

#define IMPSET22_BALACLAVA_WEIGHT		400
#define IMPSET22_BALACLAVA_HEATISO		1

#define IMPSET22_BOOTS_WEIGHT			400
#define IMPSET22_BOOTS_HEATISO			0.9

#define IMPSET22_GLOVES_WEIGHT			454
#define IMPSET22_GLOVES_HEATISO			0.5

#define IMPSET22_HELMET_WEIGHT			3000
#define IMPSET22_HELMET_HEATISO			1

#define IMPSET22_JACKET_WEIGHT			800
#define IMPSET22_JACKET_HEATISO			0.7

#define IMPSET22_PANTS_WEIGHT			530
#define IMPSET22_PANTS_HEATISO			0.8

#define IMPSET22_VEST_WEIGHT			10000
#define IMPSET22_VEST_HEATISO			1

// ============================================================
// Прочность предмета (очки здоровья, DamageSystem > Health > hitpoints)
// ============================================================
#define IMPSET22_BACKPACK_HITPOINTS		500
#define IMPSET22_BALACLAVA_HITPOINTS		500
#define IMPSET22_BOOTS_HITPOINTS		500
#define IMPSET22_GLOVES_HITPOINTS		500
#define IMPSET22_HELMET_HITPOINTS		500
#define IMPSET22_JACKET_HITPOINTS		500
#define IMPSET22_PANTS_HITPOINTS		500
#define IMPSET22_VEST_HITPOINTS		500

// Дополнительный общий множитель прочности (только у обуви в исходном моде)
#define IMPSET22_BOOTS_DURABILITY		0.5

// ============================================================
// Защита / урон
// ============================================================

// Биологическая защита (от заражения), 0 = нет защиты, 1 = полная защита
#define IMPSET22_BALACLAVA_BIO_PROTECTION	0.25
#define IMPSET22_HELMET_BIO_PROTECTION		1

// GlobalArmor.damage — доля урона, проходящая через предмет одинаково
// для Projectile/Melee/Infected/FragGrenade x Health/Blood/Shock.
// Меньше значение = лучше защита от пуль/ударов/зомби/гранат.
#define IMPSET22_HELMET_ARMOR_DAMAGE		0.35
#define IMPSET22_JACKET_ARMOR_DAMAGE		0.5
#define IMPSET22_PANTS_ARMOR_DAMAGE			0.5
#define IMPSET22_VEST_ARMOR_DAMAGE			0.5
