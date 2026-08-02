#include "Set22Config.hpp"

class CfgPatches
{
	class IMPSET22
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Gear_Medical", "DZ_Structures_Furniture", "DZ_Data", "DZ_Characters", "DZ_Scripts", "DZ_gear_food", "DZ_Gear_Consumables", "DZ_Characters_Vests", "DZ_Gear_Containers", "DZ_Weapons_Melee", "DZ_Weapons_Magazines", "DZ_Characters_Headgear"};
	};
};

class CfgMods {
	class IMPSET22 {
		dir = IMPSET22;
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = IMPSET22;
		credits = "IMPERIVM";
		author = "IMPERIVM";
		authorID = "0";
		version = 0.1;
		extra = 0;
		type = "mod";
		dependencies[] = {"World"};
		
		class defs {
			
			
			class worldScriptModule {
				value = "";
				files[] = {"IMPSET22\scripts\4_World"};
			};
		};
	};
};

class CfgVehicles
{
	class Man;
	
	class SurvivorBase: Man
    {
        class DayZPlayer
        {
            class P3DAttachments
            {
                P3DProxies[] +=
                {
                    "spine1",
					"righthand_dummy",
					"spine2",
					"head",
					"rightlegroll",
					"spine3",
					"lefthand",
					"LeftArm",
					"pelvis",
					"leftshoulder",
					"rightshoulder",
					"rightleg",
					"leftleg",
					"rightupleg",
					"leftupleg",
					"rightuplegroll",
					"lefttuplegroll",
					"LeftArmExtra",
					"leftwristextra"
                };
                BoneNames[] +=
                {
                    "Spine1",
					"RightHand_Dummy",
					"Spine2",
					"Head",
					"RightLegRoll",
					"Spine3",
					"LeftHand",
					"LeftArm",
					"Pelvis",
					"LeftShoulder",
					"RightShoulder",
					"RightLeg",
					"LeftLeg",
					"RightUpLeg",
					"LeftUpLeg",
					"RightUpLegRoll",
					"LeftUpLegRoll",
					"LeftArmExtra",
					"leftwristextra"
                };
            };        
        };    
    };

	class Clothing_Base;
	class Clothing: Clothing_Base {};

	// ---- Backpack ----
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

	// ---- Balaclava ----
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

	// ---- Boots ----
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

	// ---- Gloves ----
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

	// ---- Helmet ----
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

	// ---- Jacket ----
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

	// ---- Pants ----
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

	// ---- Vest ----
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
