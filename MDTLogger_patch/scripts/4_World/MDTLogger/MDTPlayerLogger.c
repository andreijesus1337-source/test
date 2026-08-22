class MDTLoggerConfig
{
    int Version = 1;
    
    string Language = "RU";
    
    bool EnableConnectLog = true;
    bool EnableDisconnectLog = true;
    bool EnableDeathLog = true;
    bool EnablePvPDamageLog = true;
    bool EnableItemInventoryLog = true;
    bool EnableBaseBuildingLog = true;
    bool EnableZombieKillLog = true;
    bool EnableAnimalKillLog = true;
    bool EnableMedicineUseLog = true;
    bool EnableDiseaseLog = true;
    bool EnableUnconsciousLog = true;
    bool EnableBleedingLog = true;
    bool EnableVehicleSpawnLog = true;
    bool EnableVehicleDespawnLog = true;
    bool EnableFlagBuildLog = true;
    bool EnableFlagDismantleLog = true;
    bool EnableChatLog = true;
    bool EnableFarmingLog = true;
    bool EnableCampingLog = true;
    bool EnableSecurityLog = true;
    bool EnableCraftingLog = true;
    bool EnableFoodDrinkLog = true;
    
    bool IncludeSteamID = true;
    bool IncludePosition = true;

    int VehicleStartupSuppressSec = 120;
}

class MDTDiscordConfig
{
    string WebhookUrl = "";
    string BotName = "MDT Logger";
    string AvatarUrl = "";
}

class MDTDiscordConfigs
{
    ref MDTDiscordConfig ConnectConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig DisconnectConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig DeathConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig PvPDamageConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig ItemInventoryConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig BaseBuildingConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig ZombieKillConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig AnimalKillConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig MedicineUseConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig DiseaseConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig UnconsciousConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig BleedingConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig VehicleSpawnConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig VehicleDespawnConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig FlagBuildConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig FlagDismantleConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig ChatLogConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig FarmingConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig CampingConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig SecurityConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig CraftingConfig = new MDTDiscordConfig();
    ref MDTDiscordConfig FoodDrinkConfig = new MDTDiscordConfig();
}

class MDTDiscordPayload
{
    string username;
    string content;
}

class MDTDiscordPayloadAvatar
{
    string username;
    string avatar_url;
    string content;
}

class MDTDiscordCallback : RestCallback
{
    override void OnError(int errorCode)
    {
        Print("[MDTLogger][Discord] Error code: " + errorCode.ToString());
    }

    override void OnTimeout()
    {
        Print("[MDTLogger][Discord] Timeout");
    }

    override void OnSuccess(string data, int dataSize)
    {
        Print("[MDTLogger][Discord] Sent OK");
    }
}

class MDTDisconnectEntry
{
    string PlainID;
    int TimeSec;
}

class MDTChatEntry
{
    string PlayerName;
    string Message;
    int TimeSec;
}

class MDTPlayerLogger
{
    static int DISCONNECT_DEDUPE_SEC = 30;
    static int VEHICLE_STARTUP_SUPPRESS_SEC = 120;
    static int CHAT_DEDUPE_SEC = 2;

    protected static bool m_Initialized;
    protected static bool m_ConfigLoaded;
    protected static ref MDTLoggerConfig m_LoggerConfig;
    protected static ref MDTDiscordConfigs m_DiscordConfigs;
    protected static ref MDTDiscordCallback m_DiscordCallback;
    protected static ref array<ref MDTDisconnectEntry> m_DisconnectEntries;
    protected static ref array<ref MDTChatEntry> m_ChatEntries;
    protected static int m_InitTimeSec = -1;

    static string GetBaseFolder()
    {
        return "$profile:MDT";
    }

    static string GetDiscordFolder()
    {
        return "$profile:MDT/MDTDiscord";
    }

    static string GetLoggerConfigFile()
    {
        return "$profile:MDT/MDTDiscord/logger_config.json";
    }

    static string GetDiscordConfigFile()
    {
        return "$profile:MDT/MDTDiscord/discord_configs.json";
    }

    static string GetPlayerLogFile()
    {
        return "$profile:MDT/MDTDiscord/players.log";
    }

    static string GetDeathLogFile()
    {
        return "$profile:MDT/MDTDiscord/deaths.log";
    }

    static string GetPvPLogFile()
    {
        return "$profile:MDT/MDTDiscord/pvp_damage.log";
    }

    static string GetItemLogFile()
    {
        return "$profile:MDT/MDTDiscord/items.log";
    }

    static string GetBuildingLogFile()
    {
        return "$profile:MDT/MDTDiscord/buildings.log";
    }

    static string GetKillLogFile()
    {
        return "$profile:MDT/MDTDiscord/kills.log";
    }

    static string GetContainerLogFile()
    {
        return "$profile:MDT/MDTDiscord/containers.log";
    }

    static string GetHealthLogFile()
    {
        return "$profile:MDT/MDTDiscord/health.log";
    }

    static string GetVehicleLogFile()
    {
        return "$profile:MDT/MDTDiscord/vehicles.log";
    }

    static string GetFlagLogFile()
    {
        return "$profile:MDT/MDTDiscord/flags.log";
    }

    static string GetChatLogFile()
    {
        return "$profile:MDT/MDTDiscord/chat.log";
    }

    static string GetFarmingLogFile()
    {
        return "$profile:MDT/MDTDiscord/farming.log";
    }

    static string GetCampingLogFile()
    {
        return "$profile:MDT/MDTDiscord/camping.log";
    }

    static string GetSecurityLogFile()
    {
        return "$profile:MDT/MDTDiscord/security.log";
    }

    static string GetCraftingLogFile()
    {
        return "$profile:MDT/MDTDiscord/crafting.log";
    }

    static string GetFoodDrinkLogFile()
    {
        return "$profile:MDT/MDTDiscord/food_drink.log";
    }

    static void InitOnce()
    {
        if (m_Initialized)
            return;

        if (!GetGame() || !GetGame().IsServer())
            return;

        m_Initialized = true;
        m_InitTimeSec = GetNowSeconds();
        
        MakeDirectory(GetBaseFolder());
        MakeDirectory(GetDiscordFolder());
        
        GetLoggerConfig();
        GetDiscordConfigs();

        string ts = GetTimestamp();
        
        AppendToFile(GetPlayerLogFile(), "");
        AppendToFile(GetPlayerLogFile(), "========================================");
        AppendToFile(GetPlayerLogFile(), "  MDT Player Logger STARTED: " + ts);
        AppendToFile(GetPlayerLogFile(), "========================================");

        Print("[MDTLogger] Initialized. Folder: " + GetBaseFolder());
    }

    static int GetNowSeconds()
    {
        int hour;
        int minute;
        int second;
        GetHourMinuteSecond(hour, minute, second);
        return hour * 3600 + minute * 60 + second;
    }

    static bool IsDuplicateDisconnect(string plainID)
    {
        if (!m_DisconnectEntries)
            m_DisconnectEntries = new array<ref MDTDisconnectEntry>();

        int now = GetNowSeconds();

        for (int i = m_DisconnectEntries.Count() - 1; i >= 0; i--)
        {
            MDTDisconnectEntry entry = m_DisconnectEntries[i];
            if (!entry || now - entry.TimeSec > DISCONNECT_DEDUPE_SEC || now - entry.TimeSec < 0)
            {
                m_DisconnectEntries.Remove(i);
                continue;
            }

            if (entry.PlainID == plainID)
                return true;
        }

        MDTDisconnectEntry newEntry = new MDTDisconnectEntry();
        newEntry.PlainID = plainID;
        newEntry.TimeSec = now;
        m_DisconnectEntries.Insert(newEntry);
        return false;
    }

    static bool IsServerStarting()
    {
        int suppressSec = VEHICLE_STARTUP_SUPPRESS_SEC;
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg)
            suppressSec = cfg.VehicleStartupSuppressSec;

        if (suppressSec <= 0)
            return false;

        if (m_InitTimeSec < 0)
            return true;

        int elapsed = GetNowSeconds() - m_InitTimeSec;
        if (elapsed < 0)
            elapsed += 86400;

        return elapsed < suppressSec;
    }

    static PlayerBase FindPlayerByName(string playerName)
    {
        array<Man> players = new array<Man>();
        GetGame().GetPlayers(players);

        foreach (Man man : players)
        {
            PlayerBase pb = PlayerBase.Cast(man);
            if (pb && pb.GetIdentity() && pb.GetIdentity().GetName() == playerName)
                return pb;
        }

        string cleanName = playerName;
        int idx = cleanName.IndexOf("]");
        if (idx != -1 && cleanName.IndexOf("[") != -1)
            cleanName = cleanName.Substring(idx + 1, cleanName.Length() - idx - 1);
        cleanName = cleanName.Trim();

        foreach (Man man2 : players)
        {
            PlayerBase pb2 = PlayerBase.Cast(man2);
            if (pb2 && pb2.GetIdentity())
            {
                string n = pb2.GetIdentity().GetName();
                if (n != "" && cleanName != "" && cleanName.IndexOf(n) != -1)
                    return pb2;
            }
        }

        return null;
    }

    static bool IsDuplicateChat(string playerName, string message)
    {
        if (!m_ChatEntries)
            m_ChatEntries = new array<ref MDTChatEntry>();

        int now = GetNowSeconds();

        for (int i = m_ChatEntries.Count() - 1; i >= 0; i--)
        {
            MDTChatEntry entry = m_ChatEntries[i];
            if (!entry || now - entry.TimeSec > CHAT_DEDUPE_SEC || now - entry.TimeSec < 0)
            {
                m_ChatEntries.Remove(i);
                continue;
            }

            if (entry.PlayerName == playerName && entry.Message == message)
                return true;
        }

        MDTChatEntry newEntry = new MDTChatEntry();
        newEntry.PlayerName = playerName;
        newEntry.Message = message;
        newEntry.TimeSec = now;
        m_ChatEntries.Insert(newEntry);
        return false;
    }

    static void HandleChatMessage(string playerName, string message)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        if (message == "" || message == " ")
            return;

        if (IsDuplicateChat(playerName, message))
            return;

        PlayerBase player = FindPlayerByName(playerName);
        if (!player)
            return;

        LogChat(player, message);
    }

    static MDTLoggerConfig GetLoggerConfig()
    {
        if (m_ConfigLoaded && m_LoggerConfig)
            return m_LoggerConfig;

        m_ConfigLoaded = true;
        MakeDirectory(GetBaseFolder());

        m_LoggerConfig = new MDTLoggerConfig();

        if (FileExist(GetLoggerConfigFile()))
        {
            JsonFileLoader<MDTLoggerConfig>.JsonLoadFile(GetLoggerConfigFile(), m_LoggerConfig);
            if (!m_LoggerConfig)
                m_LoggerConfig = new MDTLoggerConfig();
        }
        else
        {
            JsonFileLoader<MDTLoggerConfig>.JsonSaveFile(GetLoggerConfigFile(), m_LoggerConfig);
            Print("[MDTLogger] Created default config: " + GetLoggerConfigFile());
        }

        return m_LoggerConfig;
    }

    static MDTDiscordConfigs GetDiscordConfigs()
    {
        if (m_DiscordConfigs)
            return m_DiscordConfigs;

        MakeDirectory(GetDiscordFolder());

        m_DiscordConfigs = new MDTDiscordConfigs();

        if (FileExist(GetDiscordConfigFile()))
        {
            JsonFileLoader<MDTDiscordConfigs>.JsonLoadFile(GetDiscordConfigFile(), m_DiscordConfigs);
            if (!m_DiscordConfigs)
                m_DiscordConfigs = new MDTDiscordConfigs();
        }
        else
        {
            JsonFileLoader<MDTDiscordConfigs>.JsonSaveFile(GetDiscordConfigFile(), m_DiscordConfigs);
            Print("[MDTLogger] Created default Discord configs: " + GetDiscordConfigFile());
        }

        return m_DiscordConfigs;
    }

    static bool IsLogEnabled(string logType)
    {
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (!cfg)
            return false;

        switch (logType)
        {
            case "connect": return cfg.EnableConnectLog;
            case "disconnect": return cfg.EnableDisconnectLog;
            case "death": return cfg.EnableDeathLog;
            case "pvp_damage": return cfg.EnablePvPDamageLog;
            case "item_inventory": return cfg.EnableItemInventoryLog;
            case "base_building": return cfg.EnableBaseBuildingLog;
            case "zombie_kill": return cfg.EnableZombieKillLog;
            case "animal_kill": return cfg.EnableAnimalKillLog;
            case "medicine_use": return cfg.EnableMedicineUseLog;
            case "disease": return cfg.EnableDiseaseLog;
            case "unconscious": return cfg.EnableUnconsciousLog;
            case "bleeding": return cfg.EnableBleedingLog;
            case "vehicle_spawn": return cfg.EnableVehicleSpawnLog;
            case "vehicle_despawn": return cfg.EnableVehicleDespawnLog;
            case "flag_build": return cfg.EnableFlagBuildLog;
            case "flag_dismantle": return cfg.EnableFlagDismantleLog;
            case "chat": return cfg.EnableChatLog;
            case "farming": return cfg.EnableFarmingLog;
            case "camping": return cfg.EnableCampingLog;
            case "security": return cfg.EnableSecurityLog;
            case "crafting": return cfg.EnableCraftingLog;
            case "food_drink": return cfg.EnableFoodDrinkLog;
        }

        return false;
    }

    static MDTDiscordConfig GetDiscordConfigForType(string logType)
    {
        MDTDiscordConfigs configs = GetDiscordConfigs();
        if (!configs)
            return null;

        switch (logType)
        {
            case "connect": return configs.ConnectConfig;
            case "disconnect": return configs.DisconnectConfig;
            case "death": return configs.DeathConfig;
            case "pvp_damage": return configs.PvPDamageConfig;
            case "item_inventory": return configs.ItemInventoryConfig;
            case "base_building": return configs.BaseBuildingConfig;
            case "zombie_kill": return configs.ZombieKillConfig;
            case "animal_kill": return configs.AnimalKillConfig;
            case "medicine_use": return configs.MedicineUseConfig;
            case "disease": return configs.DiseaseConfig;
            case "unconscious": return configs.UnconsciousConfig;
            case "bleeding": return configs.BleedingConfig;
            case "vehicle_spawn": return configs.VehicleSpawnConfig;
            case "vehicle_despawn": return configs.VehicleDespawnConfig;
            case "flag_build": return configs.FlagBuildConfig;
            case "flag_dismantle": return configs.FlagDismantleConfig;
            case "chat": return configs.ChatLogConfig;
            case "farming": return configs.FarmingConfig;
            case "camping": return configs.CampingConfig;
            case "security": return configs.SecurityConfig;
            case "crafting": return configs.CraftingConfig;
            case "food_drink": return configs.FoodDrinkConfig;
        }

        return null;
    }

    static bool IsDiscordEnabledForType(string logType)
    {
        MDTDiscordConfig cfg = GetDiscordConfigForType(logType);
        if (!cfg)
            return false;

        if (cfg.WebhookUrl == "")
            return false;

        if (cfg.WebhookUrl.IndexOf("WEBHOOK") != -1)
            return false;

        if (cfg.WebhookUrl.Length() < 50)
            return false;

        return true;
    }

    static void SendDiscordMessage(string logType, string content)
    {
        if (!IsDiscordEnabledForType(logType))
            return;

        MDTDiscordConfig cfg = GetDiscordConfigForType(logType);
        if (!cfg)
            return;

        RestApi restApi = GetRestApi();
        if (!restApi)
            restApi = CreateRestApi();

        if (!restApi)
        {
            Print("[MDTLogger][Discord] RestApi unavailable");
            return;
        }

        if (!m_DiscordCallback)
            m_DiscordCallback = new MDTDiscordCallback();

        RestContext ctx = restApi.GetRestContext(cfg.WebhookUrl);
        if (!ctx)
        {
            Print("[MDTLogger][Discord] Cannot create RestContext");
            return;
        }

        ctx.SetHeader("application/json");

        if (content.Length() > 1850)
            content = content.Substring(0, 1850) + "...";

        string payload;

        if (cfg.AvatarUrl != "")
        {
            MDTDiscordPayloadAvatar payloadAvatar = new MDTDiscordPayloadAvatar();
            payloadAvatar.username = cfg.BotName;
            payloadAvatar.avatar_url = cfg.AvatarUrl;
            payloadAvatar.content = content;
            payload = JsonFileLoader<MDTDiscordPayloadAvatar>.JsonMakeData(payloadAvatar);
        }
        else
        {
            MDTDiscordPayload payloadSimple = new MDTDiscordPayload();
            payloadSimple.username = cfg.BotName;
            payloadSimple.content = content;
            payload = JsonFileLoader<MDTDiscordPayload>.JsonMakeData(payloadSimple);
        }

        if (payload == "")
        {
            Print("[MDTLogger][Discord] Empty JSON payload");
            return;
        }

        ctx.POST(m_DiscordCallback, "", payload);
    }

    static bool m_MDT_MissionStarted;

    static void LogConnect(PlayerBase player)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("connect"))
            return;

        if (!player)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string steamID = identity.GetPlainId();
        string playerName = identity.GetName();
        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());

        string logLine = "[" + MDTLocale.GetString("CONNECT") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("SteamID") + ": " + steamID + " | ";
        logLine += MDTLocale.GetString("Name") + ": " + playerName + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetPlayerLogFile(), logLine);

        string discordMsg = ":green_circle: **" + MDTLocale.GetString("Player_Connected") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + playerName + "`\n";
        discordMsg += MDTLocale.GetString("SteamID") + ": `" + steamID + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("connect", discordMsg);

        Print("[MDTLogger] Connect: " + playerName + " (" + steamID + ")");
    }

    static void LogDisconnect(PlayerBase player)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("disconnect"))
            return;

        if (!player)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string steamID = identity.GetPlainId();
        string playerName = identity.GetName();
        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());

        if (IsDuplicateDisconnect(steamID))
            return;

        string logLine = "[" + MDTLocale.GetString("DISCONNECT") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("SteamID") + ": " + steamID + " | ";
        logLine += MDTLocale.GetString("Name") + ": " + playerName + " | ";
        logLine += MDTLocale.GetString("Last_Position") + ": " + posStr;
        AppendToFile(GetPlayerLogFile(), logLine);

        string discordMsg = ":red_circle: **" + MDTLocale.GetString("Player_Disconnected") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + playerName + "`\n";
        discordMsg += MDTLocale.GetString("SteamID") + ": `" + steamID + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Last_Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("disconnect", discordMsg);

        Print("[MDTLogger] Disconnect: " + playerName + " (" + steamID + ")");
    }

    static void LogDeath(PlayerBase victim, Object killer)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("death"))
            return;

        if (!victim)
            return;

        PlayerIdentity identity = victim.GetIdentity();
        if (!identity)
            return;

        string steamID = identity.GetPlainId();
        string playerName = identity.GetName();
        string ts = GetTimestamp();
        string posStr = VectorToMapString(victim.GetPosition());

        int hp = Math.Round(victim.GetHealth("GlobalHealth", "Health"));
        int blood = Math.Round(victim.GetHealth("GlobalHealth", "Blood"));

        string killerStr = GetKillerString(killer);
        string weaponStr = GetKillerWeaponString(killer, victim);

        AppendToFile(GetDeathLogFile(), "");
        AppendToFile(GetDeathLogFile(), "============================================");
        AppendToFile(GetDeathLogFile(), "[" + MDTLocale.GetString("DEATH") + "] " + ts);
        AppendToFile(GetDeathLogFile(), "  " + MDTLocale.GetString("Player") + "   : " + playerName);
        AppendToFile(GetDeathLogFile(), "  " + MDTLocale.GetString("SteamID") + "  : " + steamID);
        AppendToFile(GetDeathLogFile(), "  " + MDTLocale.GetString("Position") + " : " + posStr);
        AppendToFile(GetDeathLogFile(), "  " + MDTLocale.GetString("Health") + "   : " + hp.ToString() + " HP");
        AppendToFile(GetDeathLogFile(), "  " + MDTLocale.GetString("Blood") + "    : " + blood.ToString() + " ml");
        AppendToFile(GetDeathLogFile(), "  " + MDTLocale.GetString("Killed_by") + ": " + killerStr);
        AppendToFile(GetDeathLogFile(), "  " + MDTLocale.GetString("Weapon") + "   : " + weaponStr);
        AppendToFile(GetDeathLogFile(), "============================================");

        string discordMsg = ":skull_crossbones: **" + MDTLocale.GetString("Player_Death") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + playerName + "`\n";
        discordMsg += MDTLocale.GetString("SteamID") + ": `" + steamID + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        discordMsg += "\n" + MDTLocale.GetString("Killed_by") + ": `" + GetKillerDiscordString(killer) + "`";
        discordMsg += "\n" + MDTLocale.GetString("Weapon") + ": `" + weaponStr + "`";
        
        SendDiscordMessage("death", discordMsg);

        Print("[MDTLogger] Death: " + playerName);
    }

    static void LogPvPDamage(PlayerBase victim, PlayerBase attacker, float damage, string weapon)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("pvp_damage"))
            return;

        if (!victim || !attacker)
            return;

        PlayerIdentity victimID = victim.GetIdentity();
        PlayerIdentity attackerID = attacker.GetIdentity();
        if (!victimID || !attackerID)
            return;

        string ts = GetTimestamp();
        string victimPos = VectorToMapString(victim.GetPosition());

        string logLine = "[" + MDTLocale.GetString("PVP_DAMAGE") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Attacker") + ": " + attackerID.GetName() + " (" + attackerID.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Victim") + ": " + victimID.GetName() + " (" + victimID.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Damage") + ": " + damage.ToString() + " | ";
        logLine += MDTLocale.GetString("Weapon") + ": " + weapon + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + victimPos;
        AppendToFile(GetPvPLogFile(), logLine);

        string discordMsg = ":crossed_swords: **" + MDTLocale.GetString("PvP_Damage") + "**\n";
        discordMsg += MDTLocale.GetString("Attacker") + ": `" + attackerID.GetName() + "` (`" + attackerID.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Victim") + ": `" + victimID.GetName() + "` (`" + victimID.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Damage") + ": `" + damage.ToString() + "`\n";
        discordMsg += MDTLocale.GetString("Weapon") + ": `" + weapon + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\nPosition: `" + victimPos + "`";
        
        SendDiscordMessage("pvp_damage", discordMsg);

        Print("[MDTLogger] PvP Damage: " + attackerID.GetName() + " -> " + victimID.GetName());
    }

    static void LogItemLeftInventory(PlayerBase player, EntityAI item, notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("item_inventory"))
            return;

        if (!player || !item)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());
        string itemInfo = GetItemInfo(item);
        string fromType = GetLocationName(oldLoc);
        string toType = GetLocationName(newLoc);

        string logLine = "[" + MDTLocale.GetString("ITEM_LEFT_INVENTORY") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Item") + ": " + itemInfo + " | ";
        logLine += MDTLocale.GetString("From") + ": " + fromType + " | ";
        logLine += MDTLocale.GetString("To") + ": " + toType + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetItemLogFile(), logLine);

        string discordMsg = ":outbox_tray: **" + MDTLocale.GetString("Item_Left_Inventory") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Item") + ": `" + itemInfo + "`\n";
        discordMsg += MDTLocale.GetString("From") + ": `" + fromType + "`\n";
        discordMsg += MDTLocale.GetString("To") + ": `" + toType + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("item_inventory", discordMsg);
    }

    static void LogItemEnteredInventory(PlayerBase player, EntityAI item, notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("item_inventory"))
            return;

        if (!player || !item)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());
        string itemInfo = GetItemInfo(item);
        string fromType = GetLocationName(oldLoc);
        string toType = GetLocationName(newLoc);

        string logLine = "[" + MDTLocale.GetString("ITEM_ENTERED_INVENTORY") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Item") + ": " + itemInfo + " | ";
        logLine += MDTLocale.GetString("From") + ": " + fromType + " | ";
        logLine += MDTLocale.GetString("To") + ": " + toType + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetItemLogFile(), logLine);

        string discordMsg = ":inbox_tray: **" + MDTLocale.GetString("Item_Entered_Inventory") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Item") + ": `" + itemInfo + "`\n";
        discordMsg += MDTLocale.GetString("From") + ": `" + fromType + "`\n";
        discordMsg += MDTLocale.GetString("To") + ": `" + toType + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("item_inventory", discordMsg);
    }

    static void LogBaseBuilding(PlayerBase player, EntityAI object, string action)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("base_building"))
            return;

        if (!player || !object)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(object.GetPosition());
        string objectInfo = GetItemInfo(object);

        string logLine = "[" + MDTLocale.GetString("BASE_BUILDING") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Action_Type") + ": " + GetActionType(action) + " | ";
        logLine += MDTLocale.GetString("Object") + ": " + objectInfo + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetBuildingLogFile(), logLine);

        string discordMsg = ":hammer: **" + MDTLocale.GetString("Base_Building") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Action_Type") + ": `" + GetActionType(action) + "`\n";
        discordMsg += MDTLocale.GetString("Object") + ": `" + objectInfo + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("base_building", discordMsg);
    }

    static void LogZombieKill(PlayerBase player, EntityAI zombie)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("zombie_kill"))
            return;

        if (!player || !zombie)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(zombie.GetPosition());
        string zombieInfo = GetItemInfo(zombie);
        string weaponStr = GetKillerWeaponString(player, null);

        string logLine = "[" + MDTLocale.GetString("ZOMBIE_KILL") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Zombie") + ": " + zombieInfo + " | ";
        logLine += MDTLocale.GetString("Weapon") + ": " + weaponStr + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetKillLogFile(), logLine);

        string discordMsg = ":zombie: **" + MDTLocale.GetString("Zombie_Killed") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Zombie") + ": `" + zombieInfo + "`\n";
        discordMsg += MDTLocale.GetString("Weapon") + ": `" + weaponStr + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("zombie_kill", discordMsg);
    }

    static void LogAnimalKill(PlayerBase player, EntityAI animal)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("animal_kill"))
            return;

        if (!player || !animal)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(animal.GetPosition());
        string animalInfo = GetItemInfo(animal);
        string weaponStr = GetKillerWeaponString(player, null);

        string logLine = "[" + MDTLocale.GetString("ANIMAL_KILL") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Animal") + ": " + animalInfo + " | ";
        logLine += MDTLocale.GetString("Weapon") + ": " + weaponStr + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetKillLogFile(), logLine);

        string discordMsg = ":deer: **" + MDTLocale.GetString("Animal_Killed") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Animal") + ": `" + animalInfo + "`\n";
        discordMsg += MDTLocale.GetString("Weapon") + ": `" + weaponStr + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("animal_kill", discordMsg);
    }

    static void LogMedicineUse(PlayerBase player, EntityAI medicine, string action)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("medicine_use"))
            return;

        if (!player || !medicine)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());
        string medicineInfo = GetItemInfo(medicine);

        string logLine = "[" + MDTLocale.GetString("MEDICINE_USE") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Action_Type") + ": " + GetActionType(action) + " | ";
        logLine += MDTLocale.GetString("Medicine") + ": " + medicineInfo + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetPlayerLogFile(), logLine);

        string discordMsg = ":syringe: **" + MDTLocale.GetString("Medicine_Used") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Action_Type") + ": `" + GetActionType(action) + "`\n";
        discordMsg += MDTLocale.GetString("Medicine") + ": `" + medicineInfo + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("medicine_use", discordMsg);
    }

    static void LogContainerTransfer(PlayerBase player, EntityAI item, EntityAI fromContainer, EntityAI toContainer)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("item_inventory"))
            return;

        if (!player || !item)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());
        string itemInfo = GetItemInfo(item);
        
        string fromType = "Hands";
        string fromInfo = "";
        if (fromContainer)
        {
            fromType = GetContainerTypeName(fromContainer);
            fromInfo = GetItemInfo(fromContainer);
        }
        
        string toType = "Hands";
        string toInfo = "";
        if (toContainer)
        {
            toType = GetContainerTypeName(toContainer);
            toInfo = GetItemInfo(toContainer);
        }

        string logLine = "[" + MDTLocale.GetString("CONTAINER_TRANSFER") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Item") + ": " + itemInfo + " | ";
        logLine += MDTLocale.GetString("From") + ": " + fromType + " (" + fromInfo + ") | ";
        logLine += MDTLocale.GetString("To") + ": " + toType + " (" + toInfo + ") | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetItemLogFile(), logLine);

        string discordMsg = ":arrows_counterclockwise: **" + MDTLocale.GetString("Item_Transferred") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Item") + ": `" + itemInfo + "`\n";
        discordMsg += MDTLocale.GetString("From") + ": `" + fromType + "`\n";
        discordMsg += MDTLocale.GetString("To") + ": `" + toType + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("item_inventory", discordMsg);
    }

    static string GetLocationName(InventoryLocation loc)
    {
        if (!loc)
            return "Ground";

        EntityAI parent = loc.GetParent();
        if (!parent)
            return "Ground";

        return GetContainerTypeName(parent);
    }

    static string GetContainerTypeName(EntityAI container)
    {
        if (!container)
            return "Ground";

        if (container.IsInherited(PlayerBase))
            return "Player Inventory";
        
        if (container.IsKindOf("CarScript") || container.IsKindOf("VehicleBase"))
        {
            string vehType = container.GetType();
            if (vehType.IndexOf("Truck") >= 0 || vehType.IndexOf("Bus") >= 0)
                return "Vehicle (Truck/Bus)";
            return "Vehicle";
        }
        
        if (container.IsKindOf("SurvivorBase") || container.IsKindOf("DayZCreature"))
            return "Corpse";
        
        if (container.IsKindOf("TentBase") || container.IsKindOf("MMTentBase"))
            return "Tent";
        
        if (container.IsKindOf("Barrel_Base"))
            return "Barrel";
        
        if (container.IsKindOf("SeaChest"))
            return "Sea Chest";
        
        if (container.IsKindOf("WoodenCrate"))
            return "Wooden Crate";
        
        if (container.IsKindOf("Container_Base"))
            return "Container";
        
        if (container.IsKindOf("BuildingSuper") || container.IsKindOf("House"))
            return "Building";
        
        if (container.IsKindOf("Bag_Base") || container.IsKindOf("Backpack_Base"))
            return "Backpack";
        
        if (container.IsKindOf("Clothing") || container.IsKindOf("Clothing_Base"))
            return "Clothing";
        
        return container.GetType();
    }

    static string GetKillerString(Object killer)
    {
        if (!killer)
            return "Unknown/Environment";

        PlayerBase killerPlayer = PlayerBase.Cast(killer);
        if (killerPlayer)
        {
            PlayerIdentity killerID = killerPlayer.GetIdentity();
            if (killerID)
                return killerID.GetName() + " | SteamID: " + killerID.GetPlainId();

            return "Player without identity: " + killer.GetType();
        }

        EntityAI killerEntity = EntityAI.Cast(killer);
        if (killerEntity)
            return "AI/Object: " + killerEntity.GetType();

        return "Object: " + killer.GetType();
    }

    static string GetKillerDiscordString(Object killer)
    {
        if (!killer)
            return "Unknown/Environment";

        PlayerBase killerPlayer = PlayerBase.Cast(killer);
        if (killerPlayer)
        {
            PlayerIdentity killerID = killerPlayer.GetIdentity();
            if (killerID)
                return killerID.GetName();

            return "Player";
        }

        EntityAI killerEntity = EntityAI.Cast(killer);
        if (killerEntity)
            return "AI/Object: " + killerEntity.GetType();

        return "Object: " + killer.GetType();
    }

    static string GetKillerWeaponString(Object killer, PlayerBase victim)
    {
        PlayerBase killerPlayer = PlayerBase.Cast(killer);
        if (!killerPlayer)
            return "-";

        if (killerPlayer == victim)
            return "Self";

        if (!killerPlayer.GetHumanInventory())
            return "-";

        EntityAI heldItem = killerPlayer.GetHumanInventory().GetEntityInHands();
        if (heldItem)
            return heldItem.GetType();

        return "Fists/No weapon";
    }

    static void AppendToFile(string filePath, string content)
    {
        MakeDirectory(GetBaseFolder());
        MakeDirectory(GetDiscordFolder());

        FileHandle fh = OpenFile(filePath, FileMode.APPEND);
        if (fh == 0)
            fh = OpenFile(filePath, FileMode.WRITE);

        if (fh != 0)
        {
            FPrintln(fh, content);
            CloseFile(fh);
        }
        else
        {
            Print("[MDTLogger] ERROR: Cannot open file: " + filePath);
        }
    }

    static void LogDisease(PlayerBase player, string diseaseName)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("disease"))
            return;

        if (!player)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());

        string logLine = "[" + MDTLocale.GetString("DISEASE") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Disease") + ": " + diseaseName + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetHealthLogFile(), logLine);

        string discordMsg = ":microbe: **" + MDTLocale.GetString("Disease_Contracted") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Disease") + ": `" + diseaseName + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("disease", discordMsg);

        Print("[MDTLogger] Disease: " + identity.GetName() + " - " + diseaseName);
    }

    static void LogDiseaseCured(PlayerBase player, string diseaseName)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("disease"))
            return;

        if (!player)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());

        string logLine = "[" + MDTLocale.GetString("DISEASE_CURED") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Disease") + ": " + diseaseName + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetHealthLogFile(), logLine);

        string discordMsg = ":white_check_mark: **" + MDTLocale.GetString("Disease_Cured") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Disease") + ": `" + diseaseName + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";

        SendDiscordMessage("disease", discordMsg);

        Print("[MDTLogger] Disease Cured: " + identity.GetName() + " - " + diseaseName);
    }

    static void LogUnconscious(PlayerBase player, bool state)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("unconscious"))
            return;

        if (!player)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());
        string stateStr;
        if (state)
            stateStr = MDTLocale.GetString("UNCONSCIOUS_STATE");
        else
            stateStr = MDTLocale.GetString("CONSCIOUS_STATE");

        string logLine = "[" + MDTLocale.GetString("UNCONSCIOUS") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("State") + ": " + stateStr + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetHealthLogFile(), logLine);

        string emoji;
        if (state)
            emoji = ":sleeping:";
        else
            emoji = ":eyes:";
        string discordMsg = emoji + " **" + MDTLocale.GetString("Unconscious_State") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("State") + ": `" + stateStr + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("unconscious", discordMsg);

        Print("[MDTLogger] Unconscious: " + identity.GetName() + " - " + stateStr);
    }

    static void LogBleeding(PlayerBase player, int sourceCount)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("bleeding"))
            return;

        if (!player)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());

        string logLine = "[" + MDTLocale.GetString("BLEEDING") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Bleed_Sources") + ": " + sourceCount.ToString() + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetHealthLogFile(), logLine);

        string discordMsg = ":pushpin: **" + MDTLocale.GetString("Bleeding") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Bleed_Sources") + ": `" + sourceCount.ToString() + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("bleeding", discordMsg);

        Print("[MDTLogger] Bleeding: " + identity.GetName() + " - " + sourceCount.ToString() + " sources");
    }

    static void LogVehicleSpawn(EntityAI vehicle)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("vehicle_spawn"))
            return;

        if (IsServerStarting())
            return;

        if (!vehicle)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(vehicle.GetPosition());
        string vehicleInfo = GetItemInfo(vehicle);

        string logLine = "[" + MDTLocale.GetString("VEHICLE_SPAWN") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Vehicle") + ": " + vehicleInfo + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetVehicleLogFile(), logLine);

        string discordMsg = ":blue_car: **" + MDTLocale.GetString("Vehicle_Spawned") + "**\n";
        discordMsg += MDTLocale.GetString("Vehicle") + ": `" + vehicleInfo + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("vehicle_spawn", discordMsg);

        Print("[MDTLogger] Vehicle Spawn: " + vehicleInfo);
    }

    static void LogVehicleDespawn(EntityAI vehicle)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("vehicle_despawn"))
            return;

        if (IsServerStarting())
            return;

        if (!vehicle)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(vehicle.GetPosition());
        string vehicleInfo = GetItemInfo(vehicle);

        string logLine = "[" + MDTLocale.GetString("VEHICLE_DESPAWN") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Vehicle") + ": " + vehicleInfo + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetVehicleLogFile(), logLine);

        string discordMsg = ":blue_car: **" + MDTLocale.GetString("Vehicle_Despawned") + "**\n";
        discordMsg += MDTLocale.GetString("Vehicle") + ": `" + vehicleInfo + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("vehicle_despawn", discordMsg);

        Print("[MDTLogger] Vehicle Despawn: " + vehicleInfo);
    }

    static void LogObjectDeploy(PlayerBase player, EntityAI object)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("flag_build"))
            return;

        if (!player || !object)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(object.GetPosition());
        string objectInfo = GetItemInfo(object);

        string logLine = "[" + MDTLocale.GetString("OBJECT_DEPLOY") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Object") + ": " + objectInfo + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetFlagLogFile(), logLine);

        string discordMsg = ":triangular_flag_on_post: **" + MDTLocale.GetString("Object_Deployed") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Object") + ": `" + objectInfo + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("flag_build", discordMsg);

        Print("[MDTLogger] Object Deploy: " + identity.GetName() + " - " + objectInfo);
    }

    static void LogFlagBuild(PlayerBase player, EntityAI flag)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("flag_build"))
            return;

        if (!player || !flag)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(flag.GetPosition());
        string flagInfo = GetItemInfo(flag);

        string logLine = "[" + MDTLocale.GetString("FLAG_BUILD") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Flag") + ": " + flagInfo + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetFlagLogFile(), logLine);

        string discordMsg = ":triangular_flag_on_post: **" + MDTLocale.GetString("Flag_Built") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Flag") + ": `" + flagInfo + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("flag_build", discordMsg);

        Print("[MDTLogger] Flag Build: " + identity.GetName() + " - " + flagInfo);
    }

    static void LogFlagDismantle(PlayerBase player, EntityAI flag)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("flag_dismantle"))
            return;

        if (!player || !flag)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(flag.GetPosition());
        string flagInfo = GetItemInfo(flag);

        string logLine = "[" + MDTLocale.GetString("FLAG_DISMANTLE") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Flag") + ": " + flagInfo + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetFlagLogFile(), logLine);

        string discordMsg = ":checkered_flag: **" + MDTLocale.GetString("Flag_Dismantled") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Flag") + ": `" + flagInfo + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("flag_dismantle", discordMsg);

        Print("[MDTLogger] Flag Dismantle: " + identity.GetName() + " - " + flagInfo);
    }

    static void LogChat(PlayerBase player, string message)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("chat"))
            return;

        if (!player)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());

        string logLine = "[" + MDTLocale.GetString("CHAT") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Message") + ": " + message + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetChatLogFile(), logLine);

        // ФИКС: раньше в Discord уходили SteamID, лейбл "Сообщение:" и
        // позиция игрока - теперь только ник и сам текст сообщения, как
        // просили. В файловый лог (logLine выше) это не трогаем - там
        // вся информация (SteamID/позиция) остаётся для модерации.
        string discordMsg = ":speech_balloon: **" + identity.GetName() + "**: " + message;

        SendDiscordMessage("chat", discordMsg);

        Print("[MDTLogger] Chat: " + identity.GetName() + " - " + message);
    }

    static void LogFarming(PlayerBase player, EntityAI item, string action)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("farming"))
            return;

        if (!player)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());
        string itemInfo = "N/A";
        if (item)
            itemInfo = GetItemInfo(item);

        string logLine = "[" + MDTLocale.GetString("FARMING") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Action_Type") + ": " + GetActionType(action) + " | ";
        logLine += MDTLocale.GetString("Item") + ": " + itemInfo + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetFarmingLogFile(), logLine);

        string discordMsg = ":seedling: **" + MDTLocale.GetString("Farming") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Action_Type") + ": `" + GetActionType(action) + "`\n";
        discordMsg += MDTLocale.GetString("Item") + ": `" + itemInfo + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("farming", discordMsg);
    }

    static void LogCamping(PlayerBase player, EntityAI item, string action)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("camping"))
            return;

        if (!player)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());
        string itemInfo = "N/A";
        if (item)
            itemInfo = GetItemInfo(item);

        string logLine = "[" + MDTLocale.GetString("CAMPING") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Action_Type") + ": " + GetActionType(action) + " | ";
        logLine += MDTLocale.GetString("Item") + ": " + itemInfo + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetCampingLogFile(), logLine);

        string discordMsg = ":tent: **" + MDTLocale.GetString("Camping") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Action_Type") + ": `" + GetActionType(action) + "`\n";
        discordMsg += MDTLocale.GetString("Item") + ": `" + itemInfo + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("camping", discordMsg);
    }

    static void LogSecurity(PlayerBase player, EntityAI item, string action)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("security"))
            return;

        if (!player)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());
        string itemInfo = "N/A";
        if (item)
            itemInfo = GetItemInfo(item);

        string logLine = "[" + MDTLocale.GetString("SECURITY") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Action_Type") + ": " + GetActionType(action) + " | ";
        logLine += MDTLocale.GetString("Item") + ": " + itemInfo + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetSecurityLogFile(), logLine);

        string discordMsg = ":lock: **" + MDTLocale.GetString("Security") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Action_Type") + ": `" + GetActionType(action) + "`\n";
        discordMsg += MDTLocale.GetString("Item") + ": `" + itemInfo + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("security", discordMsg);
    }

    static void LogCrafting(PlayerBase player, EntityAI item, string action)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("crafting"))
            return;

        if (!player)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());
        string itemInfo = "N/A";
        if (item)
            itemInfo = GetItemInfo(item);

        string logLine = "[" + MDTLocale.GetString("CRAFTING") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Action_Type") + ": " + GetActionType(action) + " | ";
        logLine += MDTLocale.GetString("Item") + ": " + itemInfo + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetCraftingLogFile(), logLine);

        string discordMsg = ":hammer_and_pick: **" + MDTLocale.GetString("Crafting") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Action_Type") + ": `" + GetActionType(action) + "`\n";
        discordMsg += MDTLocale.GetString("Item") + ": `" + itemInfo + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("crafting", discordMsg);
    }

    static void LogFoodDrink(PlayerBase player, EntityAI item, string action)
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        InitOnce();

        if (!IsLogEnabled("food_drink"))
            return;

        if (!player)
            return;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return;

        string ts = GetTimestamp();
        string posStr = VectorToMapString(player.GetPosition());
        string itemInfo = "N/A";
        if (item)
            itemInfo = GetItemInfo(item);

        string logLine = "[" + MDTLocale.GetString("FOOD_DRINK") + "] | " + ts + " | ";
        logLine += MDTLocale.GetString("Player") + ": " + identity.GetName() + " (" + identity.GetPlainId() + ") | ";
        logLine += MDTLocale.GetString("Action_Type") + ": " + GetActionType(action) + " | ";
        logLine += MDTLocale.GetString("Item") + ": " + itemInfo + " | ";
        logLine += MDTLocale.GetString("Position") + ": " + posStr;
        AppendToFile(GetFoodDrinkLogFile(), logLine);

        string discordMsg = ":fork_and_knife: **" + MDTLocale.GetString("Food_Drink") + "**\n";
        discordMsg += MDTLocale.GetString("Player") + ": `" + identity.GetName() + "` (`" + identity.GetPlainId() + "`)\n";
        discordMsg += MDTLocale.GetString("Action_Type") + ": `" + GetActionType(action) + "`\n";
        discordMsg += MDTLocale.GetString("Item") + ": `" + itemInfo + "`";
        MDTLoggerConfig cfg = GetLoggerConfig();
        if (cfg.IncludePosition)
            discordMsg += "\n" + MDTLocale.GetString("Position") + ": `" + posStr + "`";
        
        SendDiscordMessage("food_drink", discordMsg);
    }

    static string GetTimestamp()
    {
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;

        GetYearMonthDay(year, month, day);
        GetHourMinuteSecond(hour, minute, second);

        return year.ToString() + "-" + TwoDigits(month) + "-" + TwoDigits(day) + " " + TwoDigits(hour) + ":" + TwoDigits(minute) + ":" + TwoDigits(second);
    }

    static string GetItemInfo(EntityAI item)
    {
        if (!item)
            return "Unknown";

        string displayName = item.GetDisplayName();
        if (displayName && displayName != "")
            return displayName;

        return item.GetType();
    }

    static string TwoDigits(int value)
    {
        if (value < 10)
            return "0" + value.ToString();

        return value.ToString();
    }

    static string VectorToMapString(vector pos)
    {
        return Math.Round(pos[0]).ToString() + " / " + Math.Round(pos[1]).ToString() + " / " + Math.Round(pos[2]).ToString();
    }

    static string GetActionType(string actionName)
    {
        // === МЕДИКАМЕНТЫ ===
        if (actionName.IndexOf("BandageSelf") != -1)
            return MDTLocale.GetString("AT_BANDAGE_SELF");
        if (actionName.IndexOf("BandageTarget") != -1)
            return MDTLocale.GetString("AT_BANDAGE_TARGET");
        if (actionName.IndexOf("BandageBase") != -1 || actionName.IndexOf("BandageDressing") != -1)
            return MDTLocale.GetString("AT_BANDAGE");
        if (actionName.IndexOf("SewSelf") != -1)
            return MDTLocale.GetString("AT_SEW_SELF");
        if (actionName.IndexOf("SewTarget") != -1)
            return MDTLocale.GetString("AT_SEW_TARGET");
        if (actionName.IndexOf("BurnSewSelf") != -1)
            return MDTLocale.GetString("AT_BURN_SEW_SELF");
        if (actionName.IndexOf("BurnSewTarget") != -1)
            return MDTLocale.GetString("AT_BURN_SEW_TARGET");
        if (actionName.IndexOf("SplintSelf") != -1)
            return MDTLocale.GetString("AT_SPLINT_SELF");
        if (actionName.IndexOf("SplintTarget") != -1)
            return MDTLocale.GetString("AT_SPLINT_TARGET");
        if (actionName.IndexOf("InjectEpinephrineSelf") != -1)
            return MDTLocale.GetString("AT_INJECT_EPINEPHRINE_SELF");
        if (actionName.IndexOf("InjectEpinephrineTarget") != -1)
            return MDTLocale.GetString("AT_INJECT_EPINEPHRINE_TARGET");
        if (actionName.IndexOf("InjectMorphineSelf") != -1)
            return MDTLocale.GetString("AT_INJECT_MORPHINE_SELF");
        if (actionName.IndexOf("InjectMorphineTarget") != -1)
            return MDTLocale.GetString("AT_INJECT_MORPHINE_TARGET");
        if (actionName.IndexOf("InjectSelf") != -1)
            return MDTLocale.GetString("AT_INJECT_SELF");
        if (actionName.IndexOf("InjectTarget") != -1)
            return MDTLocale.GetString("AT_INJECT_TARGET");
        if (actionName.IndexOf("DisinfectSelf") != -1)
            return MDTLocale.GetString("AT_DISINFECT_SELF");
        if (actionName.IndexOf("DisinfectTarget") != -1)
            return MDTLocale.GetString("AT_DISINFECT_TARGET");
        if (actionName.IndexOf("CPR") != -1)
            return MDTLocale.GetString("AT_CPR");
        if (actionName.IndexOf("DefibrilateSelf") != -1)
            return MDTLocale.GetString("AT_DEFIB_SELF");
        if (actionName.IndexOf("DefibrilateTarget") != -1)
            return MDTLocale.GetString("AT_DEFIB_TARGET");
        if (actionName.IndexOf("GiveBloodSelf") != -1)
            return MDTLocale.GetString("AT_GIVE_BLOOD_SELF");
        if (actionName.IndexOf("GiveBloodTarget") != -1)
            return MDTLocale.GetString("AT_GIVE_BLOOD_TARGET");
        if (actionName.IndexOf("GiveSalineSelf") != -1)
            return MDTLocale.GetString("AT_GIVE_SALINE_SELF");
        if (actionName.IndexOf("GiveSalineTarget") != -1)
            return MDTLocale.GetString("AT_GIVE_SALINE_TARGET");
        if (actionName.IndexOf("CollectBloodSelf") != -1)
            return MDTLocale.GetString("AT_COLLECT_BLOOD_SELF");
        if (actionName.IndexOf("CollectBloodTarget") != -1)
            return MDTLocale.GetString("AT_COLLECT_BLOOD_TARGET");
        if (actionName.IndexOf("CollectSampleSelf") != -1)
            return MDTLocale.GetString("AT_COLLECT_SAMPLE_SELF");
        if (actionName.IndexOf("CollectSampleTarget") != -1)
            return MDTLocale.GetString("AT_COLLECT_SAMPLE_TARGET");
        if (actionName.IndexOf("TestBloodSelf") != -1)
            return MDTLocale.GetString("AT_TEST_BLOOD_SELF");
        if (actionName.IndexOf("TestBloodTarget") != -1)
            return MDTLocale.GetString("AT_TEST_BLOOD_TARGET");
        if (actionName.IndexOf("CheckPulse") != -1)
            return MDTLocale.GetString("AT_CHECK_PULSE");
        if (actionName.IndexOf("MeasureTemperatureSelf") != -1)
            return MDTLocale.GetString("AT_MEASURE_TEMP_SELF");
        if (actionName.IndexOf("MeasureTemperatureTarget") != -1)
            return MDTLocale.GetString("AT_MEASURE_TEMP_TARGET");
        if (actionName.IndexOf("WashHands") != -1)
            return MDTLocale.GetString("AT_WASH_HANDS");

        // === СТРОИТЕЛЬСТВО ===
        if (actionName.IndexOf("BuildPart") != -1)
            return MDTLocale.GetString("AT_BUILD_PART");
        if (actionName.IndexOf("DismantlePart") != -1)
            return MDTLocale.GetString("AT_DISMANTLE_PART");
        if (actionName.IndexOf("DeconstructShelter") != -1)
            return MDTLocale.GetString("AT_DECONSTRUCT_SHELTER");
        if (actionName.IndexOf("DestroyPart") != -1)
            return MDTLocale.GetString("AT_DESTROY_PART");
        if (actionName.IndexOf("RepairPart") != -1)
            return MDTLocale.GetString("AT_REPAIR_PART");
        if (actionName.IndexOf("RepairShelter") != -1)
            return MDTLocale.GetString("AT_REPAIR_SHELTER");
        if (actionName.IndexOf("Upgrade") != -1)
            return MDTLocale.GetString("AT_UPGRADE");
        if (actionName.IndexOf("AttachToConstruction") != -1)
            return MDTLocale.GetString("AT_ATTACH_CONSTRUCTION");
        if (actionName.IndexOf("DetachFromTarget") != -1)
            return MDTLocale.GetString("AT_DETACH_FROM_TARGET");
        if (actionName.IndexOf("AttachWheels") != -1)
            return MDTLocale.GetString("AT_ATTACH_WHEELS");
        if (actionName.IndexOf("BuildShelter") != -1)
            return MDTLocale.GetString("AT_BUILD_SHELTER");

        // === ТРАНСПОРТ ===
        if (actionName.IndexOf("RepairCarChassis") != -1)
            return MDTLocale.GetString("AT_REPAIR_CAR_CHASSIS");
        if (actionName.IndexOf("RepairCarEngine") != -1)
            return MDTLocale.GetString("AT_REPAIR_CAR_ENGINE");
        if (actionName.IndexOf("RepairCarPart") != -1)
            return MDTLocale.GetString("AT_REPAIR_CAR_PART");
        if (actionName.IndexOf("FillFuel") != -1)
            return MDTLocale.GetString("AT_FILL_FUEL");
        if (actionName.IndexOf("FillBrakes") != -1)
            return MDTLocale.GetString("AT_FILL_BRAKES");
        if (actionName.IndexOf("FillCoolant") != -1)
            return MDTLocale.GetString("AT_FILL_COOLANT");
        if (actionName.IndexOf("FillOil") != -1)
            return MDTLocale.GetString("AT_FILL_OIL");
        if (actionName.IndexOf("InsertSparkplug") != -1)
            return MDTLocale.GetString("AT_INSERT_SPARKPLUG");
        if (actionName.IndexOf("StartEngine") != -1)
            return MDTLocale.GetString("AT_START_ENGINE");
        if (actionName.IndexOf("StopEngine") != -1)
            return MDTLocale.GetString("AT_STOP_ENGINE");

        // === ФЕРМЕРСТВО ===
        if (actionName.IndexOf("DigGardenPlot") != -1)
            return MDTLocale.GetString("AT_DIG_GARDEN");
        if (actionName.IndexOf("DismantleGardenPlot") != -1)
            return MDTLocale.GetString("AT_DISMANTLE_GARDEN");
        if (actionName.IndexOf("FertilizeSlot") != -1)
            return MDTLocale.GetString("AT_FERTILIZE");
        if (actionName.IndexOf("HarvestCrops") != -1)
            return MDTLocale.GetString("AT_HARVEST_CROPS");
        if (actionName.IndexOf("PlantSeed") != -1)
            return MDTLocale.GetString("AT_PLANT_SEED");
        if (actionName.IndexOf("RemovePlant") != -1)
            return MDTLocale.GetString("AT_REMOVE_PLANT");
        if (actionName.IndexOf("WaterGardenSlot") != -1)
            return MDTLocale.GetString("AT_WATER_GARDEN");
        if (actionName.IndexOf("WaterPlant") != -1)
            return MDTLocale.GetString("AT_WATER_PLANT");
        if (actionName.IndexOf("DisinfectPlant") != -1)
            return MDTLocale.GetString("AT_DISINFECT_PLANT");

        // === ЛАГЕРЬ ===
        if (actionName.IndexOf("PackTent") != -1)
            return MDTLocale.GetString("AT_PACK_TENT");
        if (actionName.IndexOf("RepackTent") != -1)
            return MDTLocale.GetString("AT_REPACK_TENT");
        if (actionName.IndexOf("RepairTentPart") != -1)
            return MDTLocale.GetString("AT_REPAIR_TENT_PART");
        if (actionName.IndexOf("RepairTent") != -1)
            return MDTLocale.GetString("AT_REPAIR_TENT");
        if (actionName.IndexOf("ToggleTentOpen") != -1)
            return MDTLocale.GetString("AT_TOGGLE_TENT");
        if (actionName.IndexOf("PlaceFireplaceIndoor") != -1)
            return MDTLocale.GetString("AT_PLACE_FIREPLACE_INDOOR");
        if (actionName.IndexOf("PlaceFireplaceIntoBarrel") != -1)
            return MDTLocale.GetString("AT_PLACE_FIREPLACE_BARREL");
        if (actionName.IndexOf("PlaceOvenIndoor") != -1)
            return MDTLocale.GetString("AT_PLACE_OVEN_INDOOR");
        if (actionName.IndexOf("CreateIndoorFireplace") != -1)
            return MDTLocale.GetString("AT_CREATE_INDOOR_FIREPLACE");
        if (actionName.IndexOf("CreateIndoorOven") != -1)
            return MDTLocale.GetString("AT_CREATE_INDOOR_OVEN");
        if (actionName.IndexOf("IgniteFireplace") != -1)
            return MDTLocale.GetString("AT_IGNITE_FIREPLACE");
        if (actionName.IndexOf("ExtinguishFireplaceByLiquid") != -1)
            return MDTLocale.GetString("AT_EXTINGUISH_FIREPLACE_LIQUID");
        if (actionName.IndexOf("ExtinguishFireplaceByExtinguisher") != -1)
            return MDTLocale.GetString("AT_EXTINGUISH_FIREPLACE_EXTINGUISHER");
        if (actionName.IndexOf("TakeFireplaceFromBarrel") != -1)
            return MDTLocale.GetString("AT_TAKE_FIREPLACE_BARREL");
        if (actionName.IndexOf("TakeFireplaceIndoor") != -1)
            return MDTLocale.GetString("AT_TAKE_FIREPLACE_INDOOR");
        if (actionName.IndexOf("TakeOvenIndoor") != -1)
            return MDTLocale.GetString("AT_TAKE_OVEN_INDOOR");
        if (actionName.IndexOf("DigInStash") != -1)
            return MDTLocale.GetString("AT_DIG_IN_STASH");
        if (actionName.IndexOf("DigOutStash") != -1)
            return MDTLocale.GetString("AT_DIG_OUT_STASH");
        if (actionName.IndexOf("BuryBody") != -1)
            return MDTLocale.GetString("AT_BURY_BODY");
        if (actionName.IndexOf("BuryAshes") != -1)
            return MDTLocale.GetString("AT_BURY_ASHES");

        // === БЕЗОПАСНОСТЬ ===
        if (actionName.IndexOf("LockDoors") != -1)
            return MDTLocale.GetString("AT_LOCK_DOORS");
        if (actionName.IndexOf("UnlockDoors") != -1)
            return MDTLocale.GetString("AT_UNLOCK_DOORS");
        if (actionName.IndexOf("DestroyCombinationLock") != -1)
            return MDTLocale.GetString("AT_DESTROY_LOCK");
        if (actionName.IndexOf("NextCombinationLockDial") != -1)
            return MDTLocale.GetString("AT_DIAL_LOCK");
        if (actionName.IndexOf("HandcuffTarget") != -1)
            return MDTLocale.GetString("AT_HANDCUFF");
        if (actionName.IndexOf("RestrainTarget") != -1)
            return MDTLocale.GetString("AT_RESTRAIN");
        if (actionName.IndexOf("UnrestrainTarget") != -1)
            return MDTLocale.GetString("AT_UNRESTRAIN");
        if (actionName.IndexOf("GagTarget") != -1)
            return MDTLocale.GetString("AT_GAG");
        if (actionName.IndexOf("UngagTarget") != -1)
            return MDTLocale.GetString("AT_UNGAG");
        if (actionName.IndexOf("CoverHeadTarget") != -1)
            return MDTLocale.GetString("AT_COVER_HEAD");
        if (actionName.IndexOf("UncoverHeadTarget") != -1)
            return MDTLocale.GetString("AT_UNCOVER_HEAD");

        // === КРАФТ ===
        if (actionName.IndexOf("Craft") != -1)
            return MDTLocale.GetString("AT_CRAFT");
        if (actionName.IndexOf("SawPlanks") != -1)
            return MDTLocale.GetString("AT_SAW_PLANKS");
        if (actionName.IndexOf("MineBush") != -1)
            return MDTLocale.GetString("AT_MINE_BUSH");
        if (actionName.IndexOf("MineRock") != -1)
            return MDTLocale.GetString("AT_MINE_ROCK");
        if (actionName.IndexOf("MineTree") != -1)
            return MDTLocale.GetString("AT_MINE_TREE");
        if (actionName.IndexOf("MineTreeBark") != -1)
            return MDTLocale.GetString("AT_MINE_BARK");
        if (actionName.IndexOf("BreakLongWoodenStick") != -1)
            return MDTLocale.GetString("AT_BREAK_STICK");
        if (actionName.IndexOf("Skinning") != -1)
            return MDTLocale.GetString("AT_SKINNING");
        if (actionName.IndexOf("FishingNew") != -1)
            return MDTLocale.GetString("AT_FISHING");
        if (actionName.IndexOf("MountBarbedWire") != -1)
            return MDTLocale.GetString("AT_MOUNT_BARBED_WIRE");
        if (actionName.IndexOf("UnmountBarbedWire") != -1)
            return MDTLocale.GetString("AT_UNMOUNT_BARBED_WIRE");
        if (actionName.IndexOf("LoadMagazine") != -1)
            return MDTLocale.GetString("AT_LOAD_MAGAZINE");
        if (actionName.IndexOf("EmptyMagazine") != -1)
            return MDTLocale.GetString("AT_EMPTY_MAGAZINE");
        if (actionName.IndexOf("SortAmmoPile") != -1)
            return MDTLocale.GetString("AT_SORT_AMMO");
        if (actionName.IndexOf("WorldCraft") != -1)
            return MDTLocale.GetString("AT_WORLD_CRAFT");

        // === ЕДА И ПИТЬЁ ===
        if (actionName.IndexOf("EatCan") != -1)
            return MDTLocale.GetString("AT_EAT_CAN");
        if (actionName.IndexOf("EatFruit") != -1)
            return MDTLocale.GetString("AT_EAT_FRUIT");
        if (actionName.IndexOf("EatMeat") != -1)
            return MDTLocale.GetString("AT_EAT_MEAT");
        if (actionName.IndexOf("EatSmall") != -1)
            return MDTLocale.GetString("AT_EAT_SMALL");
        if (actionName.IndexOf("EatCharcoalTablets") != -1)
            return MDTLocale.GetString("AT_EAT_CHARCOAL");
        if (actionName.IndexOf("EatPainkillerTablets") != -1)
            return MDTLocale.GetString("AT_EAT_PAINKILLER");
        if (actionName.IndexOf("EatPurificationTablets") != -1)
            return MDTLocale.GetString("AT_EAT_PURIFICATION");
        if (actionName.IndexOf("EatTetracyclineAntibiotics") != -1)
            return MDTLocale.GetString("AT_EAT_TETRACYCLINE");
        if (actionName.IndexOf("EatVitaminBottle") != -1)
            return MDTLocale.GetString("AT_EAT_VITAMINS");
        if (actionName.IndexOf("TakeABiteCan") != -1)
            return MDTLocale.GetString("AT_TAKE_BITE_CAN");
        if (actionName.IndexOf("TakeABite") != -1)
            return MDTLocale.GetString("AT_TAKE_BITE");
        if (actionName.IndexOf("ForceABiteCan") != -1)
            return MDTLocale.GetString("AT_FORCE_BITE_CAN");
        if (actionName.IndexOf("ForceABite") != -1)
            return MDTLocale.GetString("AT_FORCE_BITE");
        if (actionName.IndexOf("DrinkCan") != -1)
            return MDTLocale.GetString("AT_DRINK_CAN");
        if (actionName.IndexOf("DrinkCookingPot") != -1)
            return MDTLocale.GetString("AT_DRINK_COOKING_POT");
        if (actionName.IndexOf("DrinkDisinfectant") != -1)
            return MDTLocale.GetString("AT_DRINK_DISINFECTANT");
        if (actionName.IndexOf("DrinkAlcohol") != -1)
            return MDTLocale.GetString("AT_DRINK_ALCOHOL");
        if (actionName.IndexOf("DrinkPondContinuous") != -1)
            return MDTLocale.GetString("AT_DRINK_POND");
        if (actionName.IndexOf("DrinkWellContinuous") != -1)
            return MDTLocale.GetString("AT_DRINK_WELL");
        if (actionName.IndexOf("TakeASip") != -1)
            return MDTLocale.GetString("AT_TAKE_SIP");
        if (actionName.IndexOf("ForceASip") != -1)
            return MDTLocale.GetString("AT_FORCE_SIP");
        if (actionName.IndexOf("ForceDrink") != -1)
            return MDTLocale.GetString("AT_FORCE_DRINK");
        if (actionName.IndexOf("ForceFeed") != -1)
            return MDTLocale.GetString("AT_FORCE_FEED");
        if (actionName.IndexOf("ForceFeedCan") != -1)
            return MDTLocale.GetString("AT_FORCE_FEED_CAN");
        if (actionName.IndexOf("ForceFeedMeat") != -1)
            return MDTLocale.GetString("AT_FORCE_FEED_MEAT");
        if (actionName.IndexOf("ForceConsume") != -1)
            return MDTLocale.GetString("AT_FORCE_CONSUME");
        if (actionName.IndexOf("CookOnStick") != -1)
            return MDTLocale.GetString("AT_COOK_ON_STICK");
        if (actionName.IndexOf("BiteCharcoalTablets") != -1)
            return MDTLocale.GetString("AT_BITE_CHARCOAL");
        if (actionName.IndexOf("BitePainkillerTablets") != -1)
            return MDTLocale.GetString("AT_BITE_PAINKILLER");
        if (actionName.IndexOf("BitePurificationTablets") != -1)
            return MDTLocale.GetString("AT_BITE_PURIFICATION");
        if (actionName.IndexOf("BiteTetracyclineAntibiotics") != -1)
            return MDTLocale.GetString("AT_BITE_TETRACYCLINE");
        if (actionName.IndexOf("BiteVitaminBottle") != -1)
            return MDTLocale.GetString("AT_BITE_VITAMINS");

        // === ПОДБОР ЯГОД / ЧЕРВЕЙ ===
        if (actionName.IndexOf("PickBerry") != -1)
            return MDTLocale.GetString("AT_PICK_BERRY");
        if (actionName.IndexOf("DigWorms") != -1)
            return MDTLocale.GetString("AT_DIG_WORMS");

        // === ПИТАНИЕ / УПОТРЕБЛЕНИЕ ===
        if (actionName.IndexOf("WringClothes") != -1)
            return MDTLocale.GetString("AT_WRING_CLOTHES");
        if (actionName.IndexOf("ReadPaper") != -1)
            return MDTLocale.GetString("AT_READ_PAPER");
        if (actionName.IndexOf("WritePaper") != -1)
            return MDTLocale.GetString("AT_WRITE_PAPER");
        if (actionName.IndexOf("Shave") != -1)
            return MDTLocale.GetString("AT_SHAVE");
        if (actionName.IndexOf("MeasureBattery") != -1)
            return MDTLocale.GetString("AT_MEASURE_BATTERY");
        if (actionName.IndexOf("TransferLiquid") != -1)
            return MDTLocale.GetString("AT_TRANSFER_LIQUID");
        if (actionName.IndexOf("FillBottleBase") != -1)
            return MDTLocale.GetString("AT_FILL_BOTTLE");
        if (actionName.IndexOf("FillObject") != -1)
            return MDTLocale.GetString("AT_FILL_OBJECT");
        if (actionName.IndexOf("EmptyBottleBase") != -1)
            return MDTLocale.GetString("AT_EMPTY_BOTTLE");
        if (actionName.IndexOf("EmptyCookingPot") != -1)
            return MDTLocale.GetString("AT_EMPTY_COOKING_POT");
        if (actionName.IndexOf("EmptySeedsPack") != -1)
            return MDTLocale.GetString("AT_EMPTY_SEEDS_PACK");
        if (actionName.IndexOf("UnpackBox") != -1)
            return MDTLocale.GetString("AT_UNPACK_BOX");
        if (actionName.IndexOf("UpgradeTorch") != -1)
            return MDTLocale.GetString("AT_UPGRADE_TORCH");

        // === ОБЪЕКТЫ И ПРЕДМЕТЫ ===
        if (actionName.IndexOf("DeployObject") != -1 || actionName.IndexOf("PlaceObject") != -1)
            return MDTLocale.GetString("AT_DEPLOY_OBJECT");
        if (actionName.IndexOf("PlaceOnGround") != -1)
            return MDTLocale.GetString("AT_PLACE_ON_GROUND");
        if (actionName.IndexOf("DropItem") != -1)
            return MDTLocale.GetString("AT_DROP_ITEM");
        if (actionName.IndexOf("TakeItemToHands") != -1)
            return MDTLocale.GetString("AT_TAKE_TO_HANDS");
        if (actionName.IndexOf("TakeItem") != -1)
            return MDTLocale.GetString("AT_TAKE_ITEM");
        if (actionName.IndexOf("SwapItemToHands") != -1)
            return MDTLocale.GetString("AT_SWAP_TO_HANDS");
        if (actionName.IndexOf("FoldObject") != -1)
            return MDTLocale.GetString("AT_FOLD_OBJECT");
        if (actionName.IndexOf("UnfoldEntity") != -1)
            return MDTLocale.GetString("AT_UNFOLD_ENTITY");
        if (actionName.IndexOf("CloseFence") != -1)
            return MDTLocale.GetString("AT_CLOSE_FENCE");
        if (actionName.IndexOf("OpenFence") != -1)
            return MDTLocale.GetString("AT_OPEN_FENCE");

        // === ФЛАГ ===
        if (actionName.IndexOf("RaiseFlag") != -1)
            return MDTLocale.GetString("AT_RAISE_FLAG");
        if (actionName.IndexOf("LowerFlag") != -1)
            return MDTLocale.GetString("AT_LOWER_FLAG");

        // === ТРАНСПОРТ (ДВЕРИ / СИДЕНЬЯ) ===
        if (actionName.IndexOf("GetInTransport") != -1)
            return MDTLocale.GetString("AT_GET_IN_TRANSPORT");
        if (actionName.IndexOf("PullBodyFromTransport") != -1)
            return MDTLocale.GetString("AT_PULL_BODY_TRANSPORT");
        if (actionName.IndexOf("OpenCarDoorsOutside") != -1)
            return MDTLocale.GetString("AT_OPEN_CAR_DOORS_OUT");
        if (actionName.IndexOf("OpenCarDoors") != -1)
            return MDTLocale.GetString("AT_OPEN_CAR_DOORS");
        if (actionName.IndexOf("CloseCarDoorsOutside") != -1)
            return MDTLocale.GetString("AT_CLOSE_CAR_DOORS_OUT");
        if (actionName.IndexOf("CloseCarDoors") != -1)
            return MDTLocale.GetString("AT_CLOSE_CAR_DOORS");
        if (actionName.IndexOf("SwitchSeats") != -1)
            return MDTLocale.GetString("AT_SWITCH_SEATS");

        // === ОБЩЕЕ ===
        if (actionName.IndexOf("Lock") != -1)
            return MDTLocale.GetString("AT_LOCK");
        if (actionName.IndexOf("Unlock") != -1)
            return MDTLocale.GetString("AT_UNLOCK");
        if (actionName.IndexOf("Restrain") != -1)
            return MDTLocale.GetString("AT_RESTRAIN");
        if (actionName.IndexOf("Unrestrain") != -1)
            return MDTLocale.GetString("AT_UNRESTRAIN");
        if (actionName.IndexOf("Handcuff") != -1)
            return MDTLocale.GetString("AT_HANDCUFF");
        if (actionName.IndexOf("Gag") != -1)
            return MDTLocale.GetString("AT_GAG");
        if (actionName.IndexOf("Ungag") != -1)
            return MDTLocale.GetString("AT_UNGAG");
        if (actionName.IndexOf("Craft") != -1)
            return MDTLocale.GetString("AT_CRAFT");
        if (actionName.IndexOf("Fill") != -1)
            return MDTLocale.GetString("AT_FILL");
        if (actionName.IndexOf("Drink") != -1)
            return MDTLocale.GetString("AT_DRINK");
        if (actionName.IndexOf("Eat") != -1)
            return MDTLocale.GetString("AT_EAT");
        if (actionName.IndexOf("Bandage") != -1)
            return MDTLocale.GetString("AT_BANDAGE");
        if (actionName.IndexOf("Repair") != -1)
            return MDTLocale.GetString("AT_REPAIR");
        if (actionName.IndexOf("Destroy") != -1)
            return MDTLocale.GetString("AT_DESTROY");

        return MDTLocale.GetString("AT_USED");
    }
}
