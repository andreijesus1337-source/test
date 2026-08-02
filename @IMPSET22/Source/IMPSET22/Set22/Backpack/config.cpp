#include "\IMPSET22\Set22Config.hpp"

class CfgPatches
{
	class IMP_Bag_SET22
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Data", 
			"DZ_Characters", 
			"DZ_Scripts",
			"DZ_Characters_Vests"
		};
	};
};

class cfgVehicles 
{
	class Clothing_Base;
	class Clothing: Clothing_Base {};
	
	class IMP_Bag_SET22_ColorBase : Clothing 
	{
		scope = 0;
		displayName = IMPSET22_BACKPACK_NAME;
		descriptionShort = IMPSET22_BACKPACK_DESC;
		model = "IMPSET22\SET22\Backpack\models\Backpack_G.p3d";
		attachments[] = {};
		inventorySlot[] = {"Back", "Backpack1"};
		itemInfo[] = {"Clothing", "Back"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemSize[] = {IMPSET22_BACKPACK_SIZE_X, IMPSET22_BACKPACK_SIZE_Y};
		quickBarBonus = 1;
		rotationFlags=16;
		itemsCargoSize[] = {IMPSET22_BACKPACK_CARGO_X, IMPSET22_BACKPACK_CARGO_Y};
		weight = IMPSET22_BACKPACK_WEIGHT;
		varWetMax=0.249;
		heatIsolation = IMPSET22_BACKPACK_HEATISO;
		repairableWithKits[] = {5, 3};
		repairCosts[] = {30.0, 25.0};
		soundAttType = "Outdoor";
		randomQuantity = 4;
		canBeDigged = 0;	
		hiddenSelections[] = 
		{
			"Hueta13",
			"Hueta17",
			"Hueta20",
			"Hueta31",
			"Hueta54"
		};
		hiddenSelectionsTextures[] = 
		{
			"IMPSET22\SET22\data\ALLDATA\Hueta13_co.paa",
			"IMPSET22\SET22\data\ALLDATA\Hueta17_co.paa",
			"IMPSET22\SET22\data\ALLDATA\Hueta20_co.paa",
			"IMPSET22\SET22\data\ALLDATA\Hueta31_co.paa",
			"IMPSET22\SET22\data\ALLDATA\Hueta54_co.paa"
		};
		hiddenSelectionsMaterials[] = {"IMPSET22\SET22\data\ALLDATA\Hueta13.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta17.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta20.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta31.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta54.rvmat"};
		
		class ClothingTypes 
		{
			male = "IMPSET22\SET22\Backpack\models\Backpack.p3d";
			female = "IMPSET22\SET22\Backpack\models\Backpack_f.p3d";
		};
		
		class DamageSystem 
		{
			class GlobalHealth 
			{
				class Health 
				{
					hitpoints = IMPSET22_BACKPACK_HITPOINTS;
					transferToAttachmentsCoef = 0.5;
					healthLevels[] = 
					{
						{1, {"IMPSET22\SET22\data\ALLDATA\Hueta13.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta17.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta20.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta31.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta54.rvmat"}}, 
						{0.7, {"IMPSET22\SET22\data\ALLDATA\Hueta13.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta17.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta20.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta31.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta54.rvmat"}}, 
						{0.5, {"IMPSET22\SET22\data\ALLDATA\Hueta13_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta17_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta20_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta31_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta54_damage.rvmat"}}, 
						{0.3, {"IMPSET22\SET22\data\ALLDATA\Hueta13_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta17_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta20_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta31_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta54_damage.rvmat"}}, 
						{0, {"IMPSET22\SET22\data\ALLDATA\Hueta13_destruct.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta17_destruct.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta20_destruct.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta31_destruct.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta54_destruct.rvmat"}}
					};
				};
			};
		};
		
		class AnimEvents 
		{
			class SoundWeapon 
			{
				class pickUpItem_Light 
				{
					soundSet = "pickUpBackPack_Plastic_Light_SoundSet";
					id = 796;
				};
				
				class pickUpItem 
				{
					soundSet = "pickUpBackPack_Plastic_SoundSet";
					id = 797;
				};
				
				class drop 
				{
					soundset = "taloonbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	
	class IMP_Bag_SET22	: IMP_Bag_SET22_ColorBase 
	{
		scope = 2;
		hiddenSelectionsTextures[] = 
		{
			"IMPSET22\SET22\data\ALLDATA\Hueta13_co.paa",
			"IMPSET22\SET22\data\ALLDATA\Hueta17_co.paa",
			"IMPSET22\SET22\data\ALLDATA\Hueta20_co.paa",
			"IMPSET22\SET22\data\ALLDATA\Hueta31_co.paa",
			"IMPSET22\SET22\data\ALLDATA\Hueta54_co.paa"
		};
	};
	class IMP_Bag_SET22_2	: IMP_Bag_SET22_ColorBase 
	{
		scope = 2;
		hiddenSelectionsTextures[] = 
		{
			"IMPSET22\SET22\data\ALLDATA\Hueta56_co.paa",
			"IMPSET22\SET22\data\ALLDATA\Hueta17_co.paa",
			"IMPSET22\SET22\data\ALLDATA\Hueta20_co.paa",
			"IMPSET22\SET22\data\ALLDATA\Hueta31_co.paa",
			"IMPSET22\SET22\data\ALLDATA\Hueta54_co.paa"
		};
		hiddenSelectionsMaterials[] = {"IMPSET22\SET22\data\ALLDATA\Hueta56.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta17.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta20.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta31.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta54.rvmat"};
		class DamageSystem 
		{
			class GlobalHealth 
			{
				class Health 
				{
					hitpoints = IMPSET22_BACKPACK_HITPOINTS;
					transferToAttachmentsCoef = 0.5;
					healthLevels[] = 
					{
						{1, {"IMPSET22\SET22\data\ALLDATA\Hueta56.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta17.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta20.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta31.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta54.rvmat"}}, 
						{0.7, {"IMPSET22\SET22\data\ALLDATA\Hueta56.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta17.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta20.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta31.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta54.rvmat"}}, 
						{0.5, {"IMPSET22\SET22\data\ALLDATA\Hueta56_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta17_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta20_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta31_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta54_damage.rvmat"}}, 
						{0.3, {"IMPSET22\SET22\data\ALLDATA\Hueta56_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta17_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta20_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta31_damage.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta54_damage.rvmat"}}, 
						{0, {"IMPSET22\SET22\data\ALLDATA\Hueta56_destruct.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta17_destruct.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta20_destruct.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta31_destruct.rvmat", "IMPSET22\SET22\data\ALLDATA\Hueta54_destruct.rvmat"}}
					};
				};
			};
		};
	};
};
