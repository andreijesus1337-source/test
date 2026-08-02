#include "\IMPSET22\Set22Config.hpp"

class CfgPatches
{
	class IMP_Jacket_SET22
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
	
	class IMP_Jacket_SET22_ColorBase : Clothing 
	{
		scope = 0;
		displayName=IMPSET22_JACKET_NAME;
		descriptionShort = IMPSET22_JACKET_DESC;
		model = "IMPSET22\SET22\Jacket\models\Jacket_g.p3d";
		inventorySlot[] = {"Body"};
		itemInfo[] = {"Clothing", "Body"};
		weight = IMPSET22_JACKET_WEIGHT;
		itemSize[] = {IMPSET22_JACKET_SIZE_X, IMPSET22_JACKET_SIZE_Y};
		itemsCargoSize[] = {IMPSET22_JACKET_CARGO_X, IMPSET22_JACKET_CARGO_Y};
		quickBarBonus = 3;
		varWetMax = 0.79;
		heatIsolation = IMPSET22_JACKET_HEATISO;
		ragQuantity = 4;
		noVest = 0;
		noUNLVest = 0;
		repairableWithKits[] = {5, 2};
		repairCosts[] = {30.0, 25.0};
		soundAttType = "WoolShirt";
		hiddenSelections[] = 
		{
			"Hueta1"
		};
		hiddenSelectionsMaterials[] = {"impSET22\SET22\data\alldata\Hueta1.rvmat"};
		
		class ClothingTypes 
		{
			male = "IMPSET22\SET22\Jacket\models\Jacket_m.p3d";
			female = "IMPSET22\SET22\Jacket\models\Jacket_f.p3d";
		};
		
		class DamageSystem 
		{
			class GlobalHealth 
			{
				class Health 
				{
					hitpoints = IMPSET22_JACKET_HITPOINTS;
					healthLevels[] = 
					{
						{1.0, {"impSET22\SET22\data\alldata\Hueta1.rvmat"}}, 
						{0.7, {"impSET22\SET22\data\alldata\Hueta1.rvmat"}}, 
						{0.5, {"impSET22\SET22\data\alldata\Hueta1_damage.rvmat"}}, 
						{0.3, {"impSET22\SET22\data\alldata\Hueta1_damage.rvmat"}}, 
						{0.0, {"impSET22\SET22\data\alldata\Hueta1_destruct.rvmat"}}
					};
				};
			};
			
			class GlobalArmor {
				class Projectile {
					class Health {
						damage = IMPSET22_JACKET_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_JACKET_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_JACKET_ARMOR_DAMAGE;
					};
				};
				
				class Melee {
					class Health {
						damage = IMPSET22_JACKET_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_JACKET_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_JACKET_ARMOR_DAMAGE;
					};
				};
				
				class Infected {
					class Health {
						damage = IMPSET22_JACKET_ARMOR_DAMAGE;
					};
					
					class Blood {
						damage = IMPSET22_JACKET_ARMOR_DAMAGE;
					};
					
					class Shock {
						damage = IMPSET22_JACKET_ARMOR_DAMAGE;
					};
				};
				
				class FragGrenade 
				{
					class Health 
					{
						damage = IMPSET22_JACKET_ARMOR_DAMAGE;
					};
						
					class Blood 
					{
						damage = IMPSET22_JACKET_ARMOR_DAMAGE;
					};
						
					class Shock 
					{
						damage = IMPSET22_JACKET_ARMOR_DAMAGE;
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
	
	class IMP_Jacket_SET22 : IMP_Jacket_SET22_ColorBase 
	{
		scope = 2;
	};
};