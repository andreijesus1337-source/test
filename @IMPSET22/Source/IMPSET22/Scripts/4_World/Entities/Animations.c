modded class ModItemRegisterCallbacks
{	
	override void RegisterOneHanded( DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior )
    {
		super.RegisterOneHanded( pType, pBehavior );	
		//Balaclava
		pType.AddItemInHandsProfileIK("IMP_Balaclava_SET22_ColorBase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, 						"dz/anims/anm/player/ik/gear/first_aid_kit.anm");
		//Helmet/Шлем
		pType.AddItemInHandsProfileIK("IMP_Helmet_SET22_ColorBase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, 						"dz/anims/anm/player/ik/gear/gorka_helmet.anm");
		
		//Jacket/куртки
		
		pType.AddItemInHandsProfileIK("IMP_Jacket_SET22_ColorBase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, 					"dz/anims/anm/player/ik/clothing/Skirt.anm");
		
		//Boots/Обувь
		
		pType.AddItemInHandsProfileIK("IMP_Boots_SET22_ColorBase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, 					"dz/anims/anm/player/ik/clothing/Skirt.anm");
		
		//Pants/штаны
		
		pType.AddItemInHandsProfileIK("IMP_Pants_SET22_ColorBase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, 					"dz/anims/anm/player/ik/clothing/Skirt.anm");
		//Gloves
		
		pType.AddItemInHandsProfileIK("IMP_Gloves_SET22_ColorBase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, 					"dz/anims/anm/player/ik/gear/TacticalGloves.anm");
	}
	
	override void RegisterTwoHanded( DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior )
    {
		super.RegisterTwoHanded( pType, pBehavior );	
		
		//Bulletproof Vest/Бронежилеты
		
		pType.AddItemInHandsProfileIK("IMP_Vest_SET22_ColorBase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior,					"dz/anims/anm/player/ik/two_handed/vest_ballistic.anm");
		//Bag/рюкзаки
		pType.AddItemInHandsProfileIK("IMP_Bag_SET22_ColorBase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, 					"dz/anims/anm/player/ik/two_handed/taloon_g.anm");
		
	};
};