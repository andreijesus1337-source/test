#include "\IMPSET22\Set22Config.hpp"

class CfgPatches
{
	class IMP_Gloves_SET22
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
	
	class IMP_Gloves_SET22_ColorBase : Clothing 
	{
		scope = 0;
		RankLevel = 3;
		displayName = IMPSET22_GLOVES_NAME;
		descriptionShort = IMPSET22_GLOVES_DESC;
		model = "IMPSET22\Set22\Gloves\models\Gloves_g.p3d";
		inventorySlot[] = {"Gloves", "Gloves1"};
		simulation="clothing";
		itemInfo[] = {"Clothing", "Gloves"};
		rotationFlags=34;
		weight=IMPSET22_GLOVES_WEIGHT;
		itemSize[]={IMPSET22_GLOVES_SIZE_X,IMPSET22_GLOVES_SIZE_Y};
		varWetMax=0.048999999;
		heatIsolation=IMPSET22_GLOVES_HEATISO;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		hiddenSelections[] = {"Hueta6", "personality"};
		hiddenSelectionsTextures[] = {"IMPSET22\Set22\data\ALLDATA\Hueta6_co.paa"};
		
		class ClothingTypes 
		{
			male = "IMPSET22\Set22\Gloves\models\Gloves_m.p3d";
			female = "IMPSET22\Set22\Gloves\models\Gloves_f.p3d";
		};
		
		class DamageSystem 
		{
			class GlobalHealth 
			{
				class Health 
				{
					hitpoints = IMPSET22_GLOVES_HITPOINTS;
					healthLevels[] = 
					{
						{1.00, {"IMPSET22\Set22\data\ALLDATA\Hueta6.rvmat"}}, 
						{0.7, {"IMPSET22\Set22\data\ALLDATA\Hueta6.rvmat"}}, 
						{0.5, {"IMPSET22\Set22\data\ALLDATA\Hueta6_damage.rvmat"}}, 
						{0.3, {"IMPSET22\Set22\data\ALLDATA\Hueta6_damage.rvmat"}}, 
						{0.0, {"IMPSET22\Set22\data\ALLDATA\Hueta6_destruct.rvmat"}}
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
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				
				class drop 
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	
	class IMP_Gloves_SET22 : IMP_Gloves_SET22_ColorBase 
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"IMPSET22\Set22\data\ALLDATA\Hueta6_co.paa"};
	};
};
