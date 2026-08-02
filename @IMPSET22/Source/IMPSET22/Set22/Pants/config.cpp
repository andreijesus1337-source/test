#include "\IMPSET22\Set22Config.hpp"

class CfgPatches
{
	class IMP_Pants_SET22
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
	
	class IMP_Pants_SET22_ColorBase : Clothing 
	{
		scope = 0;
		displayName = IMPSET22_PANTS_NAME;
		descriptionShort = IMPSET22_PANTS_DESC;
		model = "IMPSET22\SET22\Pants\models\Pants_G.p3d";
		inventorySlot[] = {"Legs"};
		attachments[] = {};
		simulation = "clothing";
		itemInfo[] = {"Clothing", "Legs"};
		itemSize[] = {IMPSET22_PANTS_SIZE_X, IMPSET22_PANTS_SIZE_Y};
		itemsCargoSize[] = {IMPSET22_PANTS_CARGO_X, IMPSET22_PANTS_CARGO_Y};
		weight = IMPSET22_PANTS_WEIGHT;
		ragQuantity = 3;
		varWetMax = 1.0;
		heatIsolation = IMPSET22_PANTS_HEATISO;
		repairableWithKits[] = {5, 2};
		repairCosts[] = {30.0, 25.0};
		quickBarBonus = 3;
		hiddenSelections[] = 
		{
			"Hueta7",
			"personality"
		};
		hiddenSelectionsTextures[] = {"impSET22\SET22\data\alldata\Hueta7_co.paa"};
		hiddenSelectionsMaterials[] = {"impSET22\SET22\data\alldata\Hueta7.rvmat"};
		
		class ClothingTypes 
		{
			male = "IMPSET22\SET22\Pants\models\Pants_M.p3d";
			female = "IMPSET22\SET22\Pants\models\Pants_F.p3d";
		};
		
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = IMPSET22_PANTS_HITPOINTS;
					healthLevels[] = 
					{
						{1.0,{"impSET22\SET22\data\alldata\Hueta7.rvmat"}},
						{0.7,{"impSET22\SET22\data\alldata\Hueta7.rvmat"}},
						{0.5,{"impSET22\SET22\data\alldata\Hueta7_damage.rvmat"}},
						{0.3,{"impSET22\SET22\data\alldata\Hueta7_damage.rvmat"}},
						{0.0,{"impSET22\SET22\data\alldata\Hueta7_destruct.rvmat"}}
					};
				};
			};
			
			class GlobalArmor {
				class Projectile {
					class Health {
						damage = IMPSET22_PANTS_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_PANTS_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_PANTS_ARMOR_DAMAGE;
					};
				};
				
				class Melee {
					class Health {
						damage = IMPSET22_PANTS_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_PANTS_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_PANTS_ARMOR_DAMAGE;
					};
				};
				
				class Infected {
					class Health {
						damage = IMPSET22_PANTS_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_PANTS_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_PANTS_ARMOR_DAMAGE;
					};
				};
				
				class FragGrenade 
				{
					class Health 
					{
						damage = IMPSET22_PANTS_ARMOR_DAMAGE;
					};
						
					class Blood 
					{
						damage = IMPSET22_PANTS_ARMOR_DAMAGE;
					};
						
					class Shock 
					{
						damage = IMPSET22_PANTS_ARMOR_DAMAGE;
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
	
	class IMP_Pants_SET22_1 : IMP_Pants_SET22_ColorBase 
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"impSET22\SET22\data\alldata\Hueta7_co.paa"};
	};
	class IMP_Pants_SET22_2 : IMP_Pants_SET22_ColorBase 
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"impSET22\SET22\data\alldata\Hueta62_co.paa"};
	};
};