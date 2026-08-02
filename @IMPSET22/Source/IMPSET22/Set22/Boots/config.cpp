#include "\IMPSET22\Set22Config.hpp"

class CfgPatches
{
	class IMP_Boots_SET22
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "DZ_Characters", "DZ_Scripts"};
	};
};

class cfgVehicles 
{
	class Clothing;
	
	class IMP_Boots_SET22_ColorBase : Clothing 
	{
		scope = 0;
		displayName = IMPSET22_BOOTS_NAME;
		descriptionShort = IMPSET22_BOOTS_DESC;
		model = "IMPSET22\SET22\Boots\models\Boots_g.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing", "Feet"};
		itemSize[] = {IMPSET22_BOOTS_SIZE_X, IMPSET22_BOOTS_SIZE_Y};
		weight = IMPSET22_BOOTS_WEIGHT;
		durability = IMPSET22_BOOTS_DURABILITY;
		varWetMax = 0.49;
		heatIsolation = IMPSET22_BOOTS_HEATISO;
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		soundAttType = "Boots";
		hiddenSelections[] = {"Hueta28"};
		hiddenSelectionsTextures[] = {"IMPSET22\SET22\data\ALLDATA\Hueta28_co.paa"};
		
		class ClothingTypes 
		{
			male = "IMPSET22\SET22\Boots\models\Boots_m.p3d";
			female = "IMPSET22\SET22\Boots\models\Boots_f.p3d";
		};

		class DamageSystem 
		{
			class GlobalHealth 
			{
				class Health 
				{
					hitpoints = IMPSET22_BOOTS_HITPOINTS;
					healthLevels[] = 
					{
						{1, {"IMPSET22\SET22\data\ALLDATA\Hueta28.rvmat"}}, 
						{0.7, {"IMPSET22\SET22\data\ALLDATA\Hueta28.rvmat"}}, 
						{0.5, {"IMPSET22\SET22\data\ALLDATA\Hueta28_damage.rvmat"}}, 
						{0.3, {"IMPSET22\SET22\data\ALLDATA\Hueta28_damage.rvmat"}}, 
						{0, {"IMPSET22\SET22\data\ALLDATA\Hueta28_destruct.rvmat"}}
					};
				};
			};
		};
		
		class AnimEvents {
			class SoundWeapon {
				class pickUpItem {
					soundSet = "AthleticShoes_pickup_SoundSet";
					id = 797;
				};
				
				class drop {
					soundset = "AthleticShoes_drop_SoundSet";
					id = 898;
				};
			};
		};
	};

	class IMP_Boots_SET22 : IMP_Boots_SET22_ColorBase 
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"IMPSET22\SET22\data\ALLDATA\Hueta28_co.paa"};
	};
	class IMP_Boots_SET22_2 : IMP_Boots_SET22_ColorBase 
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"IMPSET22\SET22\data\ALLDATA\Hueta58_co.paa"};
	};
};