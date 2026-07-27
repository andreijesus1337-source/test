class CfgPatches
{
	class ApocalypseWeather
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};

class CfgMods
{
	class ApocalypseWeather
	{
		dir = "ApocalypseWeather";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Apocalypse Weather";
		credits = "";
		author = "";
		authorID = "0";
		version = "1.0.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game", "World", "Mission"};

		class defs
		{
			class missionScriptModule
			{
				value = "";
				files[] = {"ApocalypseWeather/5_Mission"};
			};
		};
	};
};
