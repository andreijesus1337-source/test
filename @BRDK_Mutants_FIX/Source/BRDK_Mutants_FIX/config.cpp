#define _ARMA_

// ============================================================
// Патч поверх BRDK (мутанты/зомби - creatures/dickerS/dickerXL/zmb).
// Оригинальные аддоны НЕ трогаем - переопределяем тем же именем
// класса (без ":" и без forward declare), как патроны/магазины в
// оружейных фиксах: правки применяются сразу к уже заспавненным
// мутантам, править спавн-листы/территории не нужно.
//
// На мутанта - три блока:
// - CfgAmmo > MeleeXXX - урон рукопашной атаки (Health/Blood/Shock,
//   bleedThreshold - шанс кровотечения).
// - CfgVehicles > Имя > DamageSystem.GlobalHealth - общий "запас
//   прочности" (общий hitpoints).
// - CfgVehicles > Имя > DamageSystem.DamageZones - прочность и
//   бронирование (ArmorType.Projectile) по 8 зонам тела (голова,
//   торс, руки, ноги, ступни).
// - CfgVehicles > Имя > AttackActions - дальность/ширина/кулдаун
//   атак (только у мутантов, где они прописаны в оригинале - у
//   остальных дальность атаки берётся из базового ZombieMaleBase
//   игры и тут не трогается).
//
// Некоторые цветовые/экипировочные варианты (GREEN/RED, _02 и т.д.)
// в оригинале просто наследуют статы от базового мутанта и здесь
// отдельно не продублированы - патч на базовый вариант их тоже
// затронет. Там же, где оригинал сам дублирует статы на вариант
// (AlienNomouth red/green, Comrad2/3) - здесь такой вариант тоже
// покрыт отдельным блоком.
// ============================================================

class CfgPatches
{
	class BRDK_Mutants_FIX
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"BRDK_AlienNomouth_crsModded","BRDK_Alienna_crsModded","BRDK_BioSuit_zmbModded","BRDK_Brigadier_zmbModded","BRDK_Buffed_zmbModded","BRDK_Cripple_2_crsModded","BRDK_Cripple_3_crsModded","BRDK_Cripple_crsModded","BRDK_Dikker20_crsModded","BRDK_Faceless_zmbModded","BRDK_Giant_zmbModded","BRDK_Hybrid_crsModded","BRDK_LabAssistant_zmbModded","BRDK_Mechanic_zmbModded","BRDK_Mortimer_zmbModded","BRDK_Mutagen_zmbModded","BRDK_PoliceMan_zmbModded","BRDK_Priest_zmbModded","BRDK_Scientist_zmbModded","BRDK_SelkhamDemon_crsModded","BRDK_Swamper_crsModded","BRDK_Witch_ZMBModded","BRDK_alien_zmbModded","BRDK_lizard_mutModded","BRDK_soldier2_zmbModded","BRDK_soldier_zmbModded"};
	};
};

class CfgAmmo
{
	class MeleeBRDK_AlienNomouth_crs
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeBRDK_Alienna_crs
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeBRDK_Cripple_2_crs
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeBRDK_Cripple_3_crs
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeBRDK_Cripple_crs
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeBRDK_Hybrid_crs
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 17.3;
				armorDamage = 1.6;
			};
			class Blood
			{
				damage = 23;
			};
			class Shock
			{
				damage = 35;
			};
		};
	};
	class MeleeBRDK_Swamper_crs
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.45;
			class Health
			{
				damage = 27.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 35;
			};
		};
	};
	class MeleeBRDK_Dikker20_crs
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeBRDK_SelkhamDemon_crs
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeBioSuit_zmb
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeBrigadier_zmb
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeBuffed_zmb
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeZombieFaceless
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.25;
			class Health
			{
				damage = 7.5;
				armorDamage = 0.8;
			};
			class Blood
			{
				damage = 10;
			};
			class Shock
			{
				damage = 10;
			};
		};
	};
	class MeleeZombieGiant
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeLabAssistant_zmb
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeZombielizard
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeMechanic_zmb
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeMortimer_zmb
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeZombieMutagen
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleePoliceMan_zmb
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeZombiePriest
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeBrdk_Scientist_zmb
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeZombieAlien
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeFamSoldier
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
	class MeleeZombieComrad
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 1.6;
			};
			class Blood
			{
				damage = 25;
			};
			class Shock
			{
				damage = 5;
			};
		};
	};
	class MeleeZombieWitch
	{
		class DamageApplied
		{
			type = "Infected";
			bleedThreshold = 0.23;
			class Health
			{
				damage = 7.3;
				armorDamage = 0.6;
			};
			class Blood
			{
				damage = 17;
			};
			class Shock
			{
				damage = 15;
			};
		};
	};
};

class CfgVehicles
{
	class BRDK_AlienNomouth_crs
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				ammoType = "MeleeBRDK_AlienNomouth_crs";
				minDistance = 0.75;
				distance = 1.75;
				time = 2.5;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 2.2;
				repeatable = 0;
				cooldown = 2.75;
			};
			class AttackRun
			{
				ammoType = "MeleeBRDK_AlienNomouth_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShort
			{
				ammoType = "MeleeBRDK_AlienNomouth_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShortLow
			{
				ammoType = "MeleeBRDK_AlienNomouth_crs";
				minDistance = 0;
				distance = 2;
				time = 1;
				yawAngle = 0;
				pitchAngle = -45;
				attackWidth = 2;
				repeatable = 1;
				cooldown = 1.25;
			};
			class CrawlAttackMove
			{
				ammoType = "MeleeBRDK_AlienNomouth_crs";
				distance = 2;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
			class CrawlAttackStill
			{
				ammoType = "MeleeBRDK_AlienNomouth_crs";
				distance = 2;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
		};
	};

	class BRDK_AlienNomouth_red_crs
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_AlienNomouth_Green_crs
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_Alienna_crs
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 12000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 12600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 12600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 12600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 12600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 12600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 12600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 12600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				ammoType = "MeleeBRDK_Alienna_crs";
				minDistance = 0.75;
				distance = 1.75;
				time = 2.5;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 2.2;
				repeatable = 0;
				cooldown = 2.75;
			};
			class AttackRun
			{
				ammoType = "MeleeBRDK_Alienna_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShort
			{
				ammoType = "MeleeBRDK_Alienna_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShortLow
			{
				ammoType = "MeleeBRDK_Alienna_crs";
				minDistance = 0;
				distance = 2;
				time = 1;
				yawAngle = 0;
				pitchAngle = -45;
				attackWidth = 2;
				repeatable = 1;
				cooldown = 1.25;
			};
			class CrawlAttackMove
			{
				ammoType = "MeleeBRDK_Alienna_crs";
				distance = 2;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
			class CrawlAttackStill
			{
				ammoType = "MeleeBRDK_Alienna_crs";
				distance = 2;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
		};
	};

	class BRDK_Cripple_2_crs
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				ammoType = "MeleeBRDK_Cripple_2_crs";
				minDistance = 0.75;
				distance = 1.75;
				time = 2.5;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 2.2;
				repeatable = 0;
				cooldown = 2.75;
			};
			class AttackRun
			{
				ammoType = "MeleeBRDK_Cripple_2_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShort
			{
				ammoType = "MeleeBRDK_Cripple_2_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShortLow
			{
				ammoType = "MeleeBRDK_Cripple_2_crs";
				minDistance = 0;
				distance = 2;
				time = 1;
				yawAngle = 0;
				pitchAngle = -45;
				attackWidth = 2;
				repeatable = 1;
				cooldown = 1.25;
			};
			class CrawlAttackMove
			{
				ammoType = "MeleeBRDK_Cripple_2_crs";
				distance = 2;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
			class CrawlAttackStill
			{
				ammoType = "MeleeBRDK_Cripple_2_crs";
				distance = 2;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
		};
	};

	class BRDK_Cripple_3_crs
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				ammoType = "MeleeBRDK_Cripple_3_crs";
				minDistance = 0.75;
				distance = 1.75;
				time = 2.5;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 2.2;
				repeatable = 0;
				cooldown = 2.75;
			};
			class AttackRun
			{
				ammoType = "MeleeBRDK_Cripple_3_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShort
			{
				ammoType = "MeleeBRDK_Cripple_3_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShortLow
			{
				ammoType = "MeleeBRDK_Cripple_3_crs";
				minDistance = 0;
				distance = 2;
				time = 1;
				yawAngle = 0;
				pitchAngle = -45;
				attackWidth = 2;
				repeatable = 1;
				cooldown = 1.25;
			};
			class CrawlAttackMove
			{
				ammoType = "MeleeBRDK_Cripple_3_crs";
				distance = 2;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
			class CrawlAttackStill
			{
				ammoType = "MeleeBRDK_Cripple_3_crs";
				distance = 2;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
		};
	};

	class BRDK_Cripple_crs
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				ammoType = "MeleeBRDK_Cripple_crs";
				minDistance = 0.75;
				distance = 1.75;
				time = 2.5;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 2.2;
				repeatable = 0;
				cooldown = 2.75;
			};
			class AttackRun
			{
				ammoType = "MeleeBRDK_Cripple_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShort
			{
				ammoType = "MeleeBRDK_Cripple_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShortLow
			{
				ammoType = "MeleeBRDK_Cripple_crs";
				minDistance = 0;
				distance = 2;
				time = 1;
				yawAngle = 0;
				pitchAngle = -45;
				attackWidth = 2;
				repeatable = 1;
				cooldown = 1.25;
			};
			class CrawlAttackMove
			{
				ammoType = "MeleeBRDK_Cripple_crs";
				distance = 2;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
			class CrawlAttackStill
			{
				ammoType = "MeleeBRDK_Cripple_crs";
				distance = 2;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
		};
	};

	class BRDK_Hybrid_crs
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				ammoType = "MeleeBRDK_Hybrid_crs";
				minDistance = 0.75;
				distance = 1.75;
				time = 2.5;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 2.2;
				repeatable = 0;
				cooldown = 2.75;
			};
			class AttackRun
			{
				ammoType = "MeleeBRDK_Hybrid_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShort
			{
				ammoType = "MeleeBRDK_Hybrid_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShortLow
			{
				ammoType = "MeleeBRDK_Hybrid_crs";
				minDistance = 0;
				distance = 2;
				time = 1;
				yawAngle = 0;
				pitchAngle = -45;
				attackWidth = 2;
				repeatable = 1;
				cooldown = 1.25;
			};
			class CrawlAttackMove
			{
				ammoType = "MeleeBRDK_Hybrid_crs";
				distance = 2;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
			class CrawlAttackStill
			{
				ammoType = "MeleeBRDK_Hybrid_crs";
				distance = 2;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
		};
	};

	class BRDK_Swamper_crs
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 4900;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				ammoType = "MeleeBRDK_Swamper_crs";
				minDistance = 0.75;
				distance = 1.75;
				time = 2.5;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 2.2;
				repeatable = 0;
				cooldown = 2.75;
			};
			class AttackRun
			{
				ammoType = "MeleeBRDK_Swamper_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShort
			{
				ammoType = "MeleeBRDK_Swamper_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShortLow
			{
				ammoType = "MeleeBRDK_Swamper_crs";
				minDistance = 0;
				distance = 2;
				time = 1;
				yawAngle = 0;
				pitchAngle = -45;
				attackWidth = 2;
				repeatable = 1;
				cooldown = 1.25;
			};
			class CrawlAttackMove
			{
				ammoType = "MeleeBRDK_Swamper_crs";
				distance = 2;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
			class CrawlAttackStill
			{
				ammoType = "MeleeBRDK_Swamper_crs";
				distance = 2;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
		};
	};

	class BRDK_Dikker20_crs
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_SelkhamDemon_crs
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				ammoType = "MeleeBRDK_SelkhamDemon_crs";
				minDistance = 0.75;
				distance = 1.75;
				time = 2.5;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 2.2;
				repeatable = 0;
				cooldown = 2.75;
			};
			class AttackRun
			{
				ammoType = "MeleeBRDK_SelkhamDemon_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShort
			{
				ammoType = "MeleeBRDK_SelkhamDemon_crs";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShortLow
			{
				ammoType = "MeleeBRDK_SelkhamDemon_crs";
				minDistance = 0;
				distance = 2;
				time = 1;
				yawAngle = 0;
				pitchAngle = -45;
				attackWidth = 2;
				repeatable = 1;
				cooldown = 1.25;
			};
			class CrawlAttackMove
			{
				ammoType = "MeleeBRDK_SelkhamDemon_crs";
				distance = 2;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
			class CrawlAttackStill
			{
				ammoType = "MeleeBRDK_SelkhamDemon_crs";
				distance = 2;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
		};
	};

	class BRDK_BioSuit_YELLOW_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_Brigadier_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_Buffed_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_Faceless_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_Giant_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				ammoType = "MeleeZombieGiant";
				minDistance = 0.75;
				distance = 1.75;
				time = 2.5;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 2.2;
				repeatable = 0;
				cooldown = 2.75;
			};
			class AttackRun
			{
				ammoType = "MeleeZombieGiant";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShort
			{
				ammoType = "MeleeZombieGiant";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShortLow
			{
				ammoType = "MeleeZombieGiant";
				minDistance = 0;
				distance = 2;
				time = 1;
				yawAngle = 0;
				pitchAngle = -45;
				attackWidth = 2;
				repeatable = 1;
				cooldown = 1.25;
			};
			class CrawlAttackMove
			{
				ammoType = "MeleeZombieGiant";
				distance = 2;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
			class CrawlAttackStill
			{
				ammoType = "MeleeZombieGiant";
				distance = 2;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
		};
	};

	class BRDK_LabAssistant_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_lizard_mut
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_Mechanic_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_Mortimer_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_Mutagen_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_PoliceMan_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_Priest_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_Scientist_01_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				ammoType = "MeleeBrdk_Scientist_zmb";
				minDistance = 0.75;
				distance = 1.75;
				time = 2.5;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 2.2;
				repeatable = 0;
				cooldown = 2.75;
			};
			class AttackRun
			{
				ammoType = "MeleeBrdk_Scientist_zmb";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShort
			{
				ammoType = "MeleeBrdk_Scientist_zmb";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShortLow
			{
				ammoType = "MeleeBrdk_Scientist_zmb";
				minDistance = 0;
				distance = 2;
				time = 1;
				yawAngle = 0;
				pitchAngle = -45;
				attackWidth = 2;
				repeatable = 1;
				cooldown = 1.25;
			};
			class CrawlAttackMove
			{
				ammoType = "MeleeBrdk_Scientist_zmb";
				distance = 2;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
			class CrawlAttackStill
			{
				ammoType = "MeleeBrdk_Scientist_zmb";
				distance = 2;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
		};
	};

	class BRDK_Alien_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_FamSoldier_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				ammoType = "MeleeFamSoldier";
				minDistance = 0.75;
				distance = 1.75;
				time = 2.5;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 2.2;
				repeatable = 0;
				cooldown = 2.75;
			};
			class AttackRun
			{
				ammoType = "MeleeFamSoldier";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShort
			{
				ammoType = "MeleeFamSoldier";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShortLow
			{
				ammoType = "MeleeFamSoldier";
				minDistance = 0;
				distance = 2;
				time = 1;
				yawAngle = 0;
				pitchAngle = -45;
				attackWidth = 2;
				repeatable = 1;
				cooldown = 1.25;
			};
			class CrawlAttackMove
			{
				ammoType = "MeleeFamSoldier";
				distance = 2;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
			class CrawlAttackStill
			{
				ammoType = "MeleeFamSoldier";
				distance = 2;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
		};
	};

	class BRDK_Comrad_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				ammoType = "MeleeZombieComrad";
				minDistance = 0.75;
				distance = 1.75;
				time = 2.5;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 2.2;
				repeatable = 0;
				cooldown = 2.75;
			};
			class AttackRun
			{
				ammoType = "MeleeZombieComrad";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShort
			{
				ammoType = "MeleeZombieComrad";
				minDistance = 0.5;
				distance = 1.3;
				time = 1;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.5;
				repeatable = 1;
				cooldown = 1.25;
			};
			class AttackShortLow
			{
				ammoType = "MeleeZombieComrad";
				minDistance = 0;
				distance = 2;
				time = 1;
				yawAngle = 0;
				pitchAngle = -45;
				attackWidth = 2;
				repeatable = 1;
				cooldown = 1.25;
			};
			class CrawlAttackMove
			{
				ammoType = "MeleeZombieComrad";
				distance = 2;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
			class CrawlAttackStill
			{
				ammoType = "MeleeZombieComrad";
				distance = 2;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 2;
				cooldown = 1.25;
			};
		};
	};

	class BRDK_Comrad2_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_Comrad3_zmb
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};

	class BRDK_Witch_ZMB
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2200;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = 0.1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.33;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 2600;
						transferToGlobalCoef = 0.1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 12;
							};
						};
					};
					fatalInjuryCoef = -1;
				};
			};
		};
	};
};
