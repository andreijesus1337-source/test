#define _ARMA_

class CfgPatches 
{
	class IMPSET22
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Gear_Medical", "DZ_Structures_Furniture", "DZ_Data", "DZ_Characters", "DZ_Scripts", "DZ_gear_food", "DZ_Gear_Consumables", "DZ_Characters_Vests", "DZ_Gear_Containers", "DZ_Weapons_Melee", "DZ_Weapons_Magazines"};
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
};