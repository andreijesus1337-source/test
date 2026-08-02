#include "\IMPSET22\Set22Config.hpp"

class CfgPatches
{
	class IMP_Helmet_SET22
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "DZ_Characters", "DZ_Scripts", "DZ_Characters_Headgear"};
	};
};

class cfgVehicles 
{
	class Clothing_Base;
	class Clothing: Clothing_Base {};
	
	class IMP_Helmet_SET22_ColorBase : Clothing {
		scope = 0;
		displayName = IMPSET22_HELMET_NAME;
		descriptionShort = IMPSET22_HELMET_DESC;
		model = "IMPSET22\SET22\Helmet\models\Helmet_g.p3d";
		attachments[] = {"NVG", "helmetFlashlight"};
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Headgear", "Helmet1", "Helmet2"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing", "Headgear"};
		weight = IMPSET22_HELMET_WEIGHT;
		quickBarBonus=3;
		itemSize[] = {IMPSET22_HELMET_SIZE_X, IMPSET22_HELMET_SIZE_Y};
		noMask = 0;
		noNVStrap = 0;
		noEyewear = 1;
		varWetMax=0.048999999;
		heatIsolation=IMPSET22_HELMET_HEATISO;
		hiddenSelections[] = 
		{
			"Glass",
			"Hueta16",
			"Hueta18",
			"Hueta26",
			"Hueta37",
			"Hueta40",
			"Hueta45",
			"Hueta46"
		};
		headSelectionsToHide[]=
		{
			"Clipping_headCover_improvised"
		};
		
		class Protection
		{
			biological=IMPSET22_HELMET_BIO_PROTECTION;
		};
				
		class ClothingTypes 
		{
			male = "IMPSET22\SET22\Helmet\models\Helmet_m.p3d";
			female = "IMPSET22\SET22\Helmet\models\Helmet_f.p3d";
		};
		
		class DamageSystem 
		{
			class GlobalHealth 
			{
				class Health 
				{
					hitpoints = IMPSET22_HELMET_HITPOINTS;
					healthLevels[] = 
					{
						{1.0, {"IMPSET22\SET22\data\Glass\GlassTest.rvmat", "impSET22\SET22\data\alldata\Hueta16.rvmat", "impSET22\SET22\data\alldata\Hueta18.rvmat", "impSET22\SET22\data\alldata\Hueta26.rvmat", "impSET22\SET22\data\alldata\Hueta37.rvmat", "impSET22\SET22\data\alldata\Hueta40.rvmat", "impSET22\SET22\data\alldata\Hueta45.rvmat", "impSET22\SET22\data\alldata\Hueta46.rvmat"}}, 
						{0.7, {"IMPSET22\SET22\data\Glass\GlassTest.rvmat", "impSET22\SET22\data\alldata\Hueta16.rvmat", "impSET22\SET22\data\alldata\Hueta18.rvmat", "impSET22\SET22\data\alldata\Hueta26.rvmat", "impSET22\SET22\data\alldata\Hueta37.rvmat", "impSET22\SET22\data\alldata\Hueta40.rvmat", "impSET22\SET22\data\alldata\Hueta45.rvmat", "impSET22\SET22\data\alldata\Hueta46.rvmat"}}, 
						{0.5, {"IMPSET22\SET22\data\Glass\GlassTest.rvmat", "impSET22\SET22\data\alldata\Hueta16_damage.rvmat", "impSET22\SET22\data\alldata\Hueta18_damage.rvmat", "impSET22\SET22\data\alldata\Hueta26_damage.rvmat", "impSET22\SET22\data\alldata\Hueta37_damage.rvmat", "impSET22\SET22\data\alldata\Hueta40_damage.rvmat", "impSET22\SET22\data\alldata\Hueta45_damage.rvmat", "impSET22\SET22\data\alldata\Hueta46_damage.rvmat"}}, 
						{0.3, {"IMPSET22\SET22\data\Glass\GlassTest.rvmat", "impSET22\SET22\data\alldata\Hueta16_damage.rvmat", "impSET22\SET22\data\alldata\Hueta18_damage.rvmat", "impSET22\SET22\data\alldata\Hueta26_damage.rvmat", "impSET22\SET22\data\alldata\Hueta37_damage.rvmat", "impSET22\SET22\data\alldata\Hueta40_damage.rvmat", "impSET22\SET22\data\alldata\Hueta45_damage.rvmat", "impSET22\SET22\data\alldata\Hueta46_damage.rvmat"}}, 
						{0.0, {"IMPSET22\SET22\data\Glass\GlassTest.rvmat", "impSET22\SET22\data\alldata\Hueta16_destruct.rvmat", "impSET22\SET22\data\alldata\Hueta18_damage.rvmat", "impSET22\SET22\data\alldata\Hueta26_damage.rvmat", "impSET22\SET22\data\alldata\Hueta37_damage.rvmat", "impSET22\SET22\data\alldata\Hueta40_damage.rvmat", "impSET22\SET22\data\alldata\Hueta45_damage.rvmat", "impSET22\SET22\data\alldata\Hueta46_damage.rvmat"}}
					};
				};
			};
			
			class GlobalArmor {
				class Projectile {
					class Health {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
				};
				
				class Melee {
					class Health {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
				};
				
				class Infected {
					class Health {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
				};
				
				class FragGrenade 
				{
					class Health 
					{
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
						
					class Blood 
					{
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
						
					class Shock 
					{
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
				};
			};	
		};
		
		class AnimEvents 
		{
			class SoundWeapon 
			{
				class pickUpItem 
				{
					soundSet = "pickUpPot_SoundSet";
					id = 797;
				};
				
				class drop 
				{
					soundset = "BallisticHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	
	class IMP_Helmet_SET22 : IMP_Helmet_SET22_ColorBase 
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"IMPSET22\SET22\data\Glass\Glass_Black_ca_new.paa", "impSET22\SET22\data\alldata\Hueta16_co.paa","impSET22\SET22\data\alldata\Hueta18_co.paa", "impSET22\SET22\data\alldata\Hueta26_co.paa","impSET22\SET22\data\alldata\Hueta37_co.paa", "impSET22\SET22\data\alldata\Hueta40_co.paa", "impSET22\SET22\data\alldata\Hueta45_co.paa", "impSET22\SET22\data\alldata\Hueta46_co.paa"};
	};
	class IMP_Helmet_SET22_2 : IMP_Helmet_SET22_ColorBase 
	{
		scope = 2;
		model = "IMPSET22\SET22\Helmet\models\Helmet2_g.p3d";
		noMask = 0;
		noNVStrap = 0;
		noEyewear = 0;
		attachments[] = {};
		hiddenSelections[] = 
		{
			"Hueta60",
			"Hueta61"
		};
		class ClothingTypes 
		{
			male = "IMPSET22\SET22\Helmet\models\Helmet2_m.p3d";
			female = "IMPSET22\SET22\Helmet\models\Helmet2_f.p3d";
		};
		hiddenSelectionsTextures[] = {"impSET22\SET22\data\alldata\Hueta60_co.paa", "impSET22\SET22\data\alldata\Hueta61_co.paa"};
		class DamageSystem 
		{
			class GlobalHealth 
			{
				class Health 
				{
					hitpoints = IMPSET22_HELMET_HITPOINTS;
					healthLevels[] = 
					{
						{1.0, {"impSET22\SET22\data\alldata\Hueta60.rvmat", "impSET22\SET22\data\alldata\Hueta61.rvmat"}}, 
						{0.7, {"impSET22\SET22\data\alldata\Hueta60.rvmat", "impSET22\SET22\data\alldata\Hueta61.rvmat"}}, 
						{0.5, {"impSET22\SET22\data\alldata\Hueta60_damage.rvmat", "impSET22\SET22\data\alldata\Hueta61_damage.rvmat"}}, 
						{0.3, {"impSET22\SET22\data\alldata\Hueta60_damage.rvmat", "impSET22\SET22\data\alldata\Hueta61_damage.rvmat"}}, 
						{0.0, {"impSET22\SET22\data\alldata\Hueta60_destruct.rvmat", "impSET22\SET22\data\alldata\Hueta61_damage.rvmat"}}
					};
				};
			};
			
			class GlobalArmor {
				class Projectile {
					class Health {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
				};
				
				class Melee {
					class Health {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
				};
				
				class Infected {
					class Health {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
				};
				
				class FragGrenade 
				{
					class Health 
					{
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
						
					class Blood 
					{
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
						
					class Shock 
					{
						damage = IMPSET22_HELMET_ARMOR_DAMAGE;
					};
				};
			};	
		};
		
		class AnimEvents 
		{
			class SoundWeapon 
			{
				class pickUpItem 
				{
					soundSet = "pickUpPot_SoundSet";
					id = 797;
				};
				
				class drop 
				{
					soundset = "BallisticHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};