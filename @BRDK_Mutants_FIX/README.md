# BRDK_Mutants_FIX (патч-конфиг для мутантов BRDK)

Один конфиг на всех мутантов из присланного архива (`creatures`,
`dickerS`, `dickerXL`, `zmb` — 26 исходных PBO). Оригинальные файлы
мода **не трогаем** — переопределяем теми же именами классов (без
`:` и без forward declare), как патроны/магазины в оружейных фиксах:
правки применяются сразу к уже заспавненным/уже настроенным в
спавн-системе мутантам, ничего в территориях/евентах менять не нужно.

## Что настраивается на каждого мутанта

- **`CfgAmmo > MeleeИмя`** — урон рукопашной атаки:
  `Health.damage` (урон здоровью), `Health.armorDamage` (пробитие
  брони), `Blood.damage` (кровопотеря), `Shock.damage` (шок/сбивание
  с ног), `bleedThreshold` (шанс вызвать кровотечение).
- **`CfgVehicles > Имя > DamageSystem.GlobalHealth`** — общий "запас
  прочности" мутанта (`hitpoints`).
- **`CfgVehicles > Имя > DamageSystem.DamageZones`** — живучесть и
  бронирование **по 8 зонам тела** (голова, торс, обе руки, обе
  ноги, обе ступни): `hitpoints` зоны, `transferToGlobalCoef` (сколько
  урона зоны утекает в общий запас), `ArmorType.Projectile.Health.damage`
  (сколько огнестрельного урона реально проходит через броню зоны),
  `fatalInjuryCoef`.
- **`CfgVehicles > Имя > AttackActions`** — дальность/ширина/время/
  кулдаун атак — **только у тех мутантов, у кого это прописано в
  оригинале** (примерно половина). У остальных дальность атаки берётся
  из базового `ZombieMaleBase` самой игры и здесь не трогается (нечего
  переопределять).

## Про цветовые/экипировочные варианты

Часть вариантов (например `BRDK_BioSuit_GREEN_zmb`/`_RED_zmb`,
`BRDK_Scientist_02_zmb`) в оригинале — это просто перекрас, они сами
наследуют статы от базового варианта и не переопределяют их. Патчить
их отдельно не нужно — правка базового варианта (`BRDK_BioSuit_YELLOW_zmb`,
`BRDK_Scientist_01_zmb`) их тоже затронет.

А там, где оригинал **сам** дублирует статы под вариант (`AlienNomouth`
red/green, `Comrad2`/`Comrad3`) — такой вариант покрыт отдельным блоком
в этом патче тоже, иначе правка на них бы не подействовала.

## Полный список покрытых мутантов (30 классов)

**creatures/** — AlienNomouth (+ red, + green), Alienna, Cripple,
Cripple_2, Cripple_3, Hybrid, Swamper
**dickerS/** — Dikker20
**dickerXL/** — SelkhamDemon
**zmb/** — BioSuit (YELLOW), Brigadier, Buffed, Faceless, Giant,
LabAssistant, Lizard (mut), Mechanic, Mortimer, Mutagen, PoliceMan,
Priest, Scientist_01, Alien, FamSoldier (soldier2), Comrad, Comrad2,
Comrad3 (soldier), Witch

## Единственный файл

**`Source/BRDK_Mutants_FIX/config.cpp`**.

## Сборка PBO

1. Установите **DayZ Tools** (нужен `AddonBuilder`).
2. Соберите `Source/BRDK_Mutants_FIX` в
   `@BRDK_Mutants_FIX/Addons/BRDK_Mutants_FIX.pbo`.
3. На сервере подключите **после** всех 4 оригинальных PBO мода BRDK:
   ```
   -mod=@BRDK;@BRDK_Mutants_FIX
   ```
   (название `@BRDK` — как у тебя называется папка с оригиналом;
   порядок важен только относительно самого BRDK, остальные моды не
   влияют).

Пожалуйста, соберите и протестируйте перед использованием на живом
сервере.
