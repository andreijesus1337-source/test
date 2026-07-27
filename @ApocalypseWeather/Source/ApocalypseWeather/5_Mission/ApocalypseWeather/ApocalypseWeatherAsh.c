/*
	Apocalypse Weather - Ash
	------------------------
	Постоянно летящий пепел вокруг игрока (particle-эффект "50521",
	определён в config.cpp -> CfgCloudlets) + плотная объёмная дымка,
	усиливающая эффект "красного апокалиптического неба" из CfgWorlds.

	Частица привязывается к игроку в EEInit() (вызывается один раз на
	каждую жизнь персонажа) и живёт вместе с ним. На выделенном сервере
	без рендера (dedicated server) частицы не создаются - только клиенты
	видят визуальные эффекты.
*/

class ApocalypseWeatherAshConfig
{
	static const bool ENABLED = true;

	// ID кастомного particle-эффекта пепла, см. config.cpp -> CfgCloudlets -> class 50521
	static const int ASH_PARTICLE_ID = 50521;
};

modded class PlayerBase
{
	protected Particle m_ApocalypseAshFx;

	override void EEInit()
	{
		super.EEInit();

		if (!ApocalypseWeatherConfig.ENABLED || !ApocalypseWeatherAshConfig.ENABLED)
			return;

		if (GetGame().IsDedicatedServer())
			return;

		ApocalypseWeather_AttachAsh();
	}

	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		ApocalypseWeather_DetachAsh();
	}

	void ApocalypseWeather_AttachAsh()
	{
		if (m_ApocalypseAshFx)
			return;

		m_ApocalypseAshFx = Particle.PlayOnObject(ApocalypseWeatherAshConfig.ASH_PARTICLE_ID, this, "");
	}

	void ApocalypseWeather_DetachAsh()
	{
		if (!m_ApocalypseAshFx)
			return;

		m_ApocalypseAshFx.Stop();
		m_ApocalypseAshFx = null;
	}
}
