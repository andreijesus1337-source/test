#include "\IMPSET22\Set22Config.hpp"

class CfgPatches
{
	class IMP_Balaclava_SET22
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
	
	class IMP_Balaclava_SET22_ColorBase : Clothing 
	{
		scope = 0;
		displayName = IMPSET22_BALACLAVA_NAME;
		descriptionShort = IMPSET22_BALACLAVA_DESC;
		model = "IMPSET22\SET22\Balaclava\models\BalaclavaMask_g.p3d";
		inventorySlot[] = {"Mask"};
		itemInfo[] = {"Clothing", "Mask"};
		rotationFlags = 1;
		weight = IMPSET22_BALACLAVA_WEIGHT;
		itemSize[] = {IMPSET22_BALACLAVA_SIZE_X, IMPSET22_BALACLAVA_SIZE_Y};
		ragQuantity = 1;
		varWetMax=0.048999999;
		heatIsolation = IMPSET22_BALACLAVA_HEATISO;
		repairableWithKits[] = {5, 2};
		repairCosts[] = {30.0, 25.0};
		headSelectionsToHide[]=
		{
			"Clipping_headCover_improvised"
		};
		hiddenSelections[] = {"Hueta25"};
		
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = IMPSET22_BALACLAVA_HITPOINTS;
					healthLevels[] = 
					{
						{1.0, {"impSET22\SET22\data\alldata\Hueta25.rvmat"}}, 
						{0.7, {"impSET22\SET22\data\alldata\Hueta25.rvmat"}}, 
						{0.5, {"impSET22\SET22\data\alldata\Hueta25_damage.rvmat"}}, 
						{0.3, {"impSET22\SET22\data\alldata\Hueta25_damage.rvmat"}}, 
						{0.0, {"impSET22\SET22\data\alldata\Hueta25_destruct.rvmat"}}
					};
				};
			};
		};
		
		class ClothingTypes 
		{
			male = "IMPSET22\SET22\Balaclava\models\BalaclavaMask_m.p3d";
			female = "IMPSET22\SET22\Balaclava\models\BalaclavaMask_f.p3d";
		};
		
		class Protection 
		{
			biological = IMPSET22_BALACLAVA_BIO_PROTECTION;
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
	
	class IMP_Balaclava_SET22 : IMP_Balaclava_SET22_ColorBase 
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"impSET22\SET22\data\alldata\Hueta25_co.paa"};
	};
	class IMP_Balaclava_SET22_2 : IMP_Balaclava_SET22_ColorBase 
	{
		scope = 2;
		model = "IMPSET22\SET22\Balaclava\models\BalaclavaMask2_g.p3d";
		hiddenSelections[] = {"Hueta57"};
		hiddenSelectionsTextures[] = {"impSET22\SET22\data\alldata\Hueta57_co.paa"};
		class ClothingTypes 
		{
			male = "IMPSET22\SET22\Balaclava\models\BalaclavaMask2_m.p3d";
			female = "IMPSET22\SET22\Balaclava\models\BalaclavaMask2_f.p3d";
		};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = IMPSET22_BALACLAVA_HITPOINTS;
					healthLevels[] = 
					{
						{1.0, {"impSET22\SET22\data\alldata\Hueta57.rvmat"}}, 
						{0.7, {"impSET22\SET22\data\alldata\Hueta57.rvmat"}}, 
						{0.5, {"impSET22\SET22\data\alldata\Hueta57_damage.rvmat"}}, 
						{0.3, {"impSET22\SET22\data\alldata\Hueta57_damage.rvmat"}}, 
						{0.0, {"impSET22\SET22\data\alldata\Hueta57_destruct.rvmat"}}
					};
				};
			};
		};
	};
};
