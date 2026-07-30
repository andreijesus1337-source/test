class CfgPatches
{
	class AP_kamikaze_ammos
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Weapons_Explosives",
			"AP_kamikaze"
		};
	};
};
class CfgAmmo
{
	class DefaultAmmo;
	class KmkzJihad_light_Ammo: DefaultAmmo
	{
		indirectHit=50;
		indirectHitRange=50;
		indirectHitRangeMultiplier=1;
		explosive=1;
		typicalSpeed=2;
		initSpeed=2;
		simulation="shotShell";
		simulationStep=0.050000001;
		soundSetExplosion[]=
		{
			"Grenade_explosion_SoundSet",
			"Grenade_Tail_SoundSet"
		};
		class DamageApplied
		{
			type="FragGrenade";
			class Health
			{
				damage=334;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=800;
			};
		};
		class NoiseExplosion
		{
			strength=200;
			type="shot";
		};
	};
	class KmkzJihad_medium_Ammo: DefaultAmmo
	{
		indirectHit=50;
		indirectHitRange=50;
		indirectHitRangeMultiplier=1;
		explosive=1;
		typicalSpeed=3;
		initSpeed=3;
		simulation="shotShell";
		simulationStep=0.050000001;
		soundSetExplosion[]=
		{
			"Grenade_explosion_SoundSet",
			"Grenade_Tail_SoundSet"
		};
		class DamageApplied
		{
			type="FragGrenade";
			class Health
			{
				damage=334;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=800;
			};
		};
		class NoiseExplosion
		{
			strength=200;
			type="shot";
		};
	};
	class KmkzJihad_hard_Ammo: DefaultAmmo
	{
		indirectHit=50;
		indirectHitRange=50;
		indirectHitRangeMultiplier=1;
		explosive=1;
		typicalSpeed=3;
		initSpeed=3;
		simulation="shotShell";
		simulationStep=0.050000001;
		soundSetExplosion[]=
		{
			"Grenade_explosion_SoundSet",
			"Grenade_Tail_SoundSet"
		};
		class DamageApplied
		{
			type="FragGrenade";
			class Health
			{
				damage=334;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=800;
			};
		};
		class NoiseExplosion
		{
			strength=200;
			type="shot";
		};
	};
};
