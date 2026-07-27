/*
	Apocalypse Weather
	------------------
	Принудительно устанавливает и удерживает "апокалиптическую" погоду
	по всей карте сервера: плотная облачность, ливень/гроза, туман и
	сильный ветер, без периодов ясного неба.

	Погода в DayZ - глобальный параметр карты (класс Weather, доступный
	через GetGame().GetWeather()), поэтому изменение применяется сразу
	ко всей карте, а не к отдельной зоне.

	Как это работает:
	1. При старте миссии (MissionServer::OnInit) выключаем встроенную
	   динамическую систему погоды (weather.MissionWeatherSuppress(true)),
	   чтобы сервер не "тянул" погоду обратно к ясной.
	2. Задаём целевые значения и допустимые диапазоны для облачности,
	   дождя, тумана и ветра.
	3. Каждые ApocalypseWeatherConfig.ENFORCE_INTERVAL секунд повторно
	   "прибиваем" погоду - на случай ручных админ-команд (#weather,
	   плагины админ-панелей) или рестарта отдельных систем.
*/

class ApocalypseWeatherConfig
{
	// Включить/выключить мод без пересборки PBO
	static const bool ENABLED = true;

	// Облачность: 0 = ясно, 1 = максимально плотные тучи
	static const float OVERCAST_MIN = 0.85;
	static const float OVERCAST_MAX = 1.0;

	// Дождь: 0 = нет дождя, 1 = ливень
	static const float RAIN_MIN = 0.6;
	static const float RAIN_MAX = 1.0;

	// Туман: 0 = нет тумана, 1 = максимальный (нулевая видимость)
	static const float FOG_MIN = 0.35;
	static const float FOG_MAX = 0.75;

	// Ветер: 0 = штиль, 1 = ураган
	static const float WIND_MIN = 0.4;
	static const float WIND_MAX = 0.85;

	// Время (сек), за которое погода "переходит" к целевому значению
	static const float TRANSITION_TIME = 5.0;

	// Как часто (сек) повторно применять погоду, чтобы она не сбилась
	static const float ENFORCE_INTERVAL = 60.0;
};

modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();

		if (!ApocalypseWeatherConfig.ENABLED)
			return;

		ApocalypseWeather_Apply();

		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(
			ApocalypseWeather_EnforceLoop,
			ApocalypseWeatherConfig.ENFORCE_INTERVAL * 1000,
			true
		);
	}
}

void ApocalypseWeather_Apply()
{
	Weather weather = GetGame().GetWeather();
	if (!weather)
		return;

	// Отключаем автоматическую (динамическую) погоду сервера,
	// иначе она со временем "перетянет" значения к ясному небу.
	weather.MissionWeatherSuppress(true);

	ApocalypseWeather_SetOvercast(weather);
	ApocalypseWeather_SetRain(weather);
	ApocalypseWeather_SetFog(weather);
	ApocalypseWeather_SetWind(weather);
}

void ApocalypseWeather_SetOvercast(Weather weather)
{
	WeatherPhenomenon overcast = weather.GetOvercast();
	overcast.SetLimits(ApocalypseWeatherConfig.OVERCAST_MIN, ApocalypseWeatherConfig.OVERCAST_MAX);
	overcast.SetForecastChangeLimits(0, 0.05);
	overcast.SetForecastTimeLimits(600, 1200);
	overcast.Set(ApocalypseWeatherConfig.OVERCAST_MAX, ApocalypseWeatherConfig.TRANSITION_TIME, 0);
}

void ApocalypseWeather_SetRain(Weather weather)
{
	WeatherPhenomenon rain = weather.GetRain();
	rain.SetLimits(ApocalypseWeatherConfig.RAIN_MIN, ApocalypseWeatherConfig.RAIN_MAX);
	rain.SetForecastChangeLimits(0, 0.1);
	rain.SetForecastTimeLimits(300, 900);
	rain.Set(ApocalypseWeatherConfig.RAIN_MAX * 0.8, ApocalypseWeatherConfig.TRANSITION_TIME, 0);
}

void ApocalypseWeather_SetFog(Weather weather)
{
	WeatherPhenomenon fog = weather.GetFog();
	fog.SetLimits(ApocalypseWeatherConfig.FOG_MIN, ApocalypseWeatherConfig.FOG_MAX);
	fog.SetForecastChangeLimits(0, 0.05);
	fog.SetForecastTimeLimits(300, 900);
	fog.Set(ApocalypseWeatherConfig.FOG_MAX * 0.7, ApocalypseWeatherConfig.TRANSITION_TIME, 0);
}

void ApocalypseWeather_SetWind(Weather weather)
{
	WeatherPhenomenon wind = weather.GetWind();
	wind.SetLimits(ApocalypseWeatherConfig.WIND_MIN, ApocalypseWeatherConfig.WIND_MAX);
	wind.SetForecastChangeLimits(0, 0.1);
	wind.SetForecastTimeLimits(120, 400);
	wind.Set(ApocalypseWeatherConfig.WIND_MAX * 0.7, ApocalypseWeatherConfig.TRANSITION_TIME, 0);
}

void ApocalypseWeather_EnforceLoop()
{
	ApocalypseWeather_Apply();
}
