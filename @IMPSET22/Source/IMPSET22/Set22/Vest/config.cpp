#include "\IMPSET22\Set22Config.hpp"

class CfgPatches
{
	class IMP_Vest_SET22
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "DZ_Characters", "DZ_Scripts"};
	};
};

class cfgVehicles 
{
	class Clothing_Base;
	class Clothing: Clothing_Base {};
	
	class IMP_Vest_SET22_ColorBase : Clothing 
	{
		scope = 0;
		displayName=IMPSET22_VEST_NAME;
		descriptionShort = IMPSET22_VEST_DESC;
		model = "IMPSET22\SET22\Vest\models\Vest_g.p3d";
		attachments[] = {};
		inventorySlot[] = {"Vest", "Vest1"};
		itemInfo[] = {"Clothing", "Vest"};
		weight = IMPSET22_VEST_WEIGHT;
		noUNLVest = 1;
		itemSize[] = {IMPSET22_VEST_SIZE_X, IMPSET22_VEST_SIZE_Y};
		itemsCargoSize[] = {IMPSET22_VEST_CARGO_X, IMPSET22_VEST_CARGO_Y};
		quickBarBonus = 2;
		varWetMax=0.048999999;
		heatIsolation=IMPSET22_VEST_HEATISO;
		repairableWithKits[] = {3, 8};
		repairCosts[] = {75.0, 50.0};
		hiddenSelections[] = 
		{
			"Hueta10",
			"Hueta14",
			"Hueta15",
			"Hueta24"
		};
		
		class ClothingTypes 
		{
			male = "IMPSET22\SET22\Vest\models\Vest_m.p3d";
			female = "IMPSET22\SET22\Vest\models\Vest_f.p3d";
		};
		
		class DamageSystem 
		{
			class GlobalHealth 
			{
				class Health 
				{
					hitpoints = IMPSET22_VEST_HITPOINTS;
					healthLevels[] = 
					{
						{1.0, {"impSET22\SET22\data\alldata\Hueta10.rvmat", "impSET22\SET22\data\alldata\Hueta14.rvmat", "impSET22\SET22\data\alldata\Hueta15.rvmat", "impSET22\SET22\data\alldata\Hueta24.rvmat"}}, 
						{0.7, {"impSET22\SET22\data\alldata\Hueta10.rvmat", "impSET22\SET22\data\alldata\Hueta14.rvmat", "impSET22\SET22\data\alldata\Hueta15.rvmat", "impSET22\SET22\data\alldata\Hueta24.rvmat"}}, 
						{0.5, {"impSET22\SET22\data\alldata\Hueta10_damage.rvmat", "impSET22\SET22\data\alldata\Hueta14_damage.rvmat", "impSET22\SET22\data\alldata\Hueta15_damage.rvmat", "impSET22\SET22\data\alldata\Hueta24_damage.rvmat"}}, 
						{0.3, {"impSET22\SET22\data\alldata\Hueta10_damage.rvmat", "impSET22\SET22\data\alldata\Hueta14_damage.rvmat", "impSET22\SET22\data\alldata\Hueta15_damage.rvmat", "impSET22\SET22\data\alldata\Hueta24_damage.rvmat"}}, 
						{0.0, {"impSET22\SET22\data\alldata\Hueta10_destruct.rvmat", "impSET22\SET22\data\alldata\Hueta14_destruct.rvmat", "impSET22\SET22\data\alldata\Hueta15_destruct.rvmat", "impSET22\SET22\data\alldata\Hueta24_destruct.rvmat"}}
					};
				};
			};
			
			class GlobalArmor {
				class Projectile {
					class Health {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
				};
				
				class Melee {
					class Health {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
				};
				
				class Infected {
					class Health {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
				};
				
				class FragGrenade 
				{
					class Health 
					{
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
						
					class Blood 
					{
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
						
					class Shock 
					{
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
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
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop 
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	
	class IMP_Vest_SET22_1 : IMP_Vest_SET22_ColorBase 
	{
		scope = 2;
		hiddenSelectionsTextures[] = 
		{
			"impSET22\SET22\data\alldata\Hueta10_co.paa",
			"impSET22\SET22\data\alldata\Hueta14_co.paa",
			"impSET22\SET22\data\alldata\Hueta15_co.paa",
			"impSET22\SET22\data\alldata\Hueta24_co.paa"
		};
	};
	class IMP_Vest_SET22_2 : IMP_Vest_SET22_ColorBase 
	{
		scope = 2;
		model = "IMPSET22\SET22\Vest\models\Vest2_g.p3d";
		hiddenSelections[] = 
		{
			"Hueta10",
			"Hueta14",
			"Hueta15",
			"Hueta24",
			"Hueta64",
			"Hueta38"
		};
		hiddenSelectionsTextures[] = 
		{
			"impSET22\SET22\data\alldata\Hueta10_co.paa",
			"impSET22\SET22\data\alldata\Hueta14_co.paa",
			"impSET22\SET22\data\alldata\Hueta65_co.paa",
			"impSET22\SET22\data\alldata\Hueta24_co.paa",
			"impSET22\SET22\data\alldata\Hueta64_co.paa",
			"impSET22\SET22\data\alldata\Hueta38_co.paa"
		};
		hiddenSelectionsMaterials[] = {"impSET22\SET22\data\alldata\Hueta10.rvmat", "impSET22\SET22\data\alldata\Hueta14.rvmat", "impSET22\SET22\data\alldata\Hueta65.rvmat", "impSET22\SET22\data\alldata\Hueta24.rvmat", "impSET22\SET22\data\alldata\Hueta64.rvmat", "impSET22\SET22\data\alldata\Hueta38.rvmat"};
		class ClothingTypes 
		{
			male = "IMPSET22\SET22\Vest\models\Vest2_m.p3d";
			female = "IMPSET22\SET22\Vest\models\Vest2_f.p3d";
		};
		
		class DamageSystem 
		{
			class GlobalHealth 
			{
				class Health 
				{
					hitpoints = IMPSET22_VEST_HITPOINTS;
					healthLevels[] = 
					{
						{1.0, {"impSET22\SET22\data\alldata\Hueta10.rvmat", "impSET22\SET22\data\alldata\Hueta14.rvmat", "impSET22\SET22\data\alldata\Hueta65.rvmat", "impSET22\SET22\data\alldata\Hueta24.rvmat", "impSET22\SET22\data\alldata\Hueta64.rvmat", "impSET22\SET22\data\alldata\Hueta38.rvmat"}}, 
						{0.7, {"impSET22\SET22\data\alldata\Hueta10.rvmat", "impSET22\SET22\data\alldata\Hueta14.rvmat", "impSET22\SET22\data\alldata\Hueta65.rvmat", "impSET22\SET22\data\alldata\Hueta24.rvmat", "impSET22\SET22\data\alldata\Hueta64.rvmat", "impSET22\SET22\data\alldata\Hueta38.rvmat"}}, 
						{0.5, {"impSET22\SET22\data\alldata\Hueta10_damage.rvmat", "impSET22\SET22\data\alldata\Hueta14_damage.rvmat", "impSET22\SET22\data\alldata\Hueta65_damage.rvmat", "impSET22\SET22\data\alldata\Hueta24_damage.rvmat", "impSET22\SET22\data\alldata\Hueta64_damage.rvmat", "impSET22\SET22\data\alldata\Hueta38_damage.rvmat"}}, 
						{0.3, {"impSET22\SET22\data\alldata\Hueta10_damage.rvmat", "impSET22\SET22\data\alldata\Hueta14_damage.rvmat", "impSET22\SET22\data\alldata\Hueta65_damage.rvmat", "impSET22\SET22\data\alldata\Hueta24_damage.rvmat", "impSET22\SET22\data\alldata\Hueta64_damage.rvmat", "impSET22\SET22\data\alldata\Hueta38_damage.rvmat"}}, 
						{0.0, {"impSET22\SET22\data\alldata\Hueta10_destruct.rvmat", "impSET22\SET22\data\alldata\Hueta14_destruct.rvmat", "impSET22\SET22\data\alldata\Hueta65_destruct.rvmat", "impSET22\SET22\data\alldata\Hueta24_destruct.rvmat", "impSET22\SET22\data\alldata\Hueta64_destruct.rvmat", "impSET22\SET22\data\alldata\Hueta38_destruct.rvmat"}}
					};
				};
			};
			
			class GlobalArmor {
				class Projectile {
					class Health {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
				};
				
				class Melee {
					class Health {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
				};
				
				class Infected {
					class Health {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
				};
				
				class FragGrenade 
				{
					class Health 
					{
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
						
					class Blood 
					{
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
					};
						
					class Shock 
					{
						damage = IMPSET22_VEST_ARMOR_DAMAGE;
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
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop 
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};