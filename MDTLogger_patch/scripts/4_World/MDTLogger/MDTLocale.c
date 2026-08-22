class MDTLocale
{
    static string GetString(string key)
    {
        MDTLoggerConfig cfg = MDTPlayerLogger.GetLoggerConfig();
        if (!cfg)
            return key;

        string lang = cfg.Language;
        if (lang == "RU")
            return GetRussianString(key);
        else
            return GetEnglishString(key);
    }

    static string GetEnglishString(string key)
    {
        switch (key)
        {
            case "CONNECT": return "CONNECT";
            case "DISCONNECT": return "DISCONNECT";
            case "DEATH": return "DEATH";
            case "PVP_DAMAGE": return "PVP_DAMAGE";
            case "ITEM_INVENTORY": return "ITEM_INVENTORY";
            case "BASE_BUILDING": return "BASE_BUILDING";
            case "ZOMBIE_KILL": return "ZOMBIE_KILL";
            case "ANIMAL_KILL": return "ANIMAL_KILL";
            case "MEDICINE_USE": return "MEDICINE_USE";
            case "CONTAINER_TRANSFER": return "CONTAINER_TRANSFER";
            case "DISEASE": return "DISEASE";
            case "DISEASE_CURED": return "DISEASE_CURED";
            case "UNCONSCIOUS": return "UNCONSCIOUS";
            case "BLEEDING": return "BLEEDING";
            case "VEHICLE_SPAWN": return "VEHICLE_SPAWN";
            case "VEHICLE_DESPAWN": return "VEHICLE_DESPAWN";
            case "FLAG_BUILD": return "FLAG_BUILD";
            case "FLAG_DISMANTLE": return "FLAG_DISMANTLE";
            case "OBJECT_DEPLOY": return "OBJECT_DEPLOY";
            case "CHAT": return "CHAT";
            case "FARMING": return "FARMING";
            case "CAMPING": return "CAMPING";
            case "SECURITY": return "SECURITY";
            case "CRAFTING": return "CRAFTING";
            case "FOOD_DRINK": return "FOOD_DRINK";
            case "STORM": return "STORM";

            case "Player": return "Player";
            case "SteamID": return "SteamID";
            case "Position": return "Position";
            case "Last_Position": return "Last Position";
            case "Name": return "Name";
            case "Health": return "Health";
            case "Blood": return "Blood";
            case "Killed_by": return "Killed by";
            case "Weapon": return "Weapon";
            case "Attacker": return "Attacker";
            case "Victim": return "Victim";
            case "Damage": return "Damage";
            case "Item": return "Item";
            case "Source": return "Source";
            case "Action": return "Action";
            case "Object": return "Object";
            case "Zombie": return "Zombie";
            case "Animal": return "Animal";
            case "Medicine": return "Medicine";
            case "Container": return "Container";
            case "From": return "From";
            case "To": return "To";
            case "Disease": return "Disease";
            case "State": return "State";
            case "Bleed_Sources": return "Bleed Sources";
            case "Vehicle": return "Vehicle";
            case "Flag": return "Flag";
            case "Channel": return "Channel";
            case "Message": return "Message";
            
            case "UNCONSCIOUS_STATE": return "UNCONSCIOUS";
            case "CONSCIOUS_STATE": return "CONSCIOUS";
            case "Unknown_Environment": return "Unknown/Environment";
            case "Fists_No_weapon": return "Fists/No weapon";
            
            case "Player_Connected": return "Player Connected";
            case "Player_Disconnected": return "Player Disconnected";
            case "Player_Death": return "Player Death";
            case "PvP_Damage": return "PvP Damage";
            case "Item_Left_Inventory": return "Item Left Inventory";
            case "Item_Entered_Inventory": return "Item Entered Inventory";
            case "Base_Building": return "Base Building";
            case "Zombie_Killed": return "Zombie Killed";
            case "Animal_Killed": return "Animal Killed";
            case "Medicine_Used": return "Medicine Used";
            case "Item_Transferred": return "Item Transferred";
            case "Disease_Contracted": return "Disease Contracted";
            case "Disease_Cured": return "Disease Cured";
            case "Unconscious_State": return "Unconscious State";
            case "Bleeding": return "Bleeding";
            case "Vehicle_Spawned": return "Vehicle Spawned";
            case "Vehicle_Despawned": return "Vehicle Despawned";
            case "Flag_Built": return "Flag Built";
            case "Flag_Dismantled": return "Flag Dismantled";
            case "Object_Deployed": return "Object Deployed";
            case "Chat_Message": return "Chat Message";
            case "Farming": return "Farming";
            case "Camping": return "Camping";
            case "Security": return "Security";
            case "Crafting": return "Crafting";
            case "Food_Drink": return "Food & Drink";
            case "Action_Type": return "Action Type";

            case "AT_BANDAGE_SELF": return "Bandage Self";
            case "AT_BANDAGE_TARGET": return "Bandage Target";
            case "AT_BANDAGE": return "Bandage";
            case "AT_SEW_SELF": return "Sew Wound Self";
            case "AT_SEW_TARGET": return "Sew Wound Target";
            case "AT_BURN_SEW_SELF": return "Cauterize Wound Self";
            case "AT_BURN_SEW_TARGET": return "Cauterize Wound Target";
            case "AT_SPLINT_SELF": return "Apply Splint Self";
            case "AT_SPLINT_TARGET": return "Apply Splint Target";
            case "AT_INJECT_EPINEPHRINE_SELF": return "Inject Epinephrine Self";
            case "AT_INJECT_EPINEPHRINE_TARGET": return "Inject Epinephrine Target";
            case "AT_INJECT_MORPHINE_SELF": return "Inject Morphine Self";
            case "AT_INJECT_MORPHINE_TARGET": return "Inject Morphine Target";
            case "AT_INJECT_SELF": return "Inject Self";
            case "AT_INJECT_TARGET": return "Inject Target";
            case "AT_DISINFECT_SELF": return "Disinfect Wound Self";
            case "AT_DISINFECT_TARGET": return "Disinfect Wound Target";
            case "AT_CPR": return "CPR";
            case "AT_DEFIB_SELF": return "Defibrillate Self";
            case "AT_DEFIB_TARGET": return "Defibrillate Target";
            case "AT_GIVE_BLOOD_SELF": return "Blood Transfusion Self";
            case "AT_GIVE_BLOOD_TARGET": return "Blood Transfusion Target";
            case "AT_GIVE_SALINE_SELF": return "Saline Drip Self";
            case "AT_GIVE_SALINE_TARGET": return "Saline Drip Target";
            case "AT_COLLECT_BLOOD_SELF": return "Collect Blood Sample Self";
            case "AT_COLLECT_BLOOD_TARGET": return "Collect Blood Sample Target";
            case "AT_COLLECT_SAMPLE_SELF": return "Collect Sample Self";
            case "AT_COLLECT_SAMPLE_TARGET": return "Collect Sample Target";
            case "AT_TEST_BLOOD_SELF": return "Test Blood Self";
            case "AT_TEST_BLOOD_TARGET": return "Test Blood Target";
            case "AT_CHECK_PULSE": return "Check Pulse";
            case "AT_MEASURE_TEMP_SELF": return "Measure Temperature Self";
            case "AT_MEASURE_TEMP_TARGET": return "Measure Temperature Target";
            case "AT_WASH_HANDS": return "Wash Hands";

            case "AT_BUILD_PART": return "Build Construction Part";
            case "AT_DISMANTLE_PART": return "Dismantle Construction Part";
            case "AT_DECONSTRUCT_SHELTER": return "Deconstruct Shelter";
            case "AT_DESTROY_PART": return "Destroy Construction Part";
            case "AT_REPAIR_PART": return "Repair Construction Part";
            case "AT_REPAIR_SHELTER": return "Repair Shelter";
            case "AT_UPGRADE": return "Upgrade Construction";
            case "AT_ATTACH_CONSTRUCTION": return "Attach to Construction";
            case "AT_DETACH_FROM_TARGET": return "Detach Item";
            case "AT_ATTACH_WHEELS": return "Attach Wheels";
            case "AT_BUILD_SHELTER": return "Build Shelter";

            case "AT_REPAIR_CAR_CHASSIS": return "Repair Car Chassis";
            case "AT_REPAIR_CAR_ENGINE": return "Repair Car Engine";
            case "AT_REPAIR_CAR_PART": return "Repair Car Part";
            case "AT_FILL_FUEL": return "Refuel Vehicle";
            case "AT_FILL_BRAKES": return "Fill Brake Fluid";
            case "AT_FILL_COOLANT": return "Fill Coolant";
            case "AT_FILL_OIL": return "Fill Engine Oil";
            case "AT_INSERT_SPARKPLUG": return "Insert Sparkplug";
            case "AT_START_ENGINE": return "Start Engine";
            case "AT_STOP_ENGINE": return "Stop Engine";

            case "AT_DIG_GARDEN": return "Dig Garden Plot";
            case "AT_DISMANTLE_GARDEN": return "Dismantle Garden Plot";
            case "AT_FERTILIZE": return "Fertilize Slot";
            case "AT_HARVEST_CROPS": return "Harvest Crops";
            case "AT_PLANT_SEED": return "Plant Seed";
            case "AT_REMOVE_PLANT": return "Remove Plant";
            case "AT_WATER_GARDEN": return "Water Garden";
            case "AT_WATER_PLANT": return "Water Plant";
            case "AT_DISINFECT_PLANT": return "Disinfect Plant";

            case "AT_PACK_TENT": return "Pack Tent";
            case "AT_REPACK_TENT": return "Repack Tent";
            case "AT_REPAIR_TENT_PART": return "Repair Tent Part";
            case "AT_REPAIR_TENT": return "Repair Tent";
            case "AT_TOGGLE_TENT": return "Toggle Tent Open/Close";
            case "AT_PLACE_FIREPLACE_INDOOR": return "Place Fireplace Indoor";
            case "AT_PLACE_FIREPLACE_BARREL": return "Place Fireplace in Barrel";
            case "AT_PLACE_OVEN_INDOOR": return "Place Oven Indoor";
            case "AT_CREATE_INDOOR_FIREPLACE": return "Create Indoor Fireplace";
            case "AT_CREATE_INDOOR_OVEN": return "Create Indoor Oven";
            case "AT_IGNITE_FIREPLACE": return "Ignite Fireplace";
            case "AT_EXTINGUISH_FIREPLACE_LIQUID": return "Extinguish Fireplace (Liquid)";
            case "AT_EXTINGUISH_FIREPLACE_EXTINGUISHER": return "Extinguish Fireplace (Extinguisher)";
            case "AT_TAKE_FIREPLACE_BARREL": return "Take Fireplace from Barrel";
            case "AT_TAKE_FIREPLACE_INDOOR": return "Take Fireplace Indoor";
            case "AT_TAKE_OVEN_INDOOR": return "Take Oven Indoor";
            case "AT_DIG_IN_STASH": return "Bury Stash";
            case "AT_DIG_OUT_STASH": return "Dig Out Stash";
            case "AT_BURY_BODY": return "Bury Body";
            case "AT_BURY_ASHES": return "Bury Ashes";

            case "AT_LOCK_DOORS": return "Lock Doors";
            case "AT_UNLOCK_DOORS": return "Unlock Doors";
            case "AT_DESTROY_LOCK": return "Destroy Combination Lock";
            case "AT_DIAL_LOCK": return "Dial Combination Lock";

            case "AT_CRAFT": return "Craft Item";
            case "AT_SAW_PLANKS": return "Saw Planks";
            case "AT_MINE_BUSH": return "Chop Bush";
            case "AT_MINE_ROCK": return "Mine Rock";
            case "AT_MINE_TREE": return "Chop Tree";
            case "AT_MINE_BARK": return "Strip Tree Bark";
            case "AT_BREAK_STICK": return "Break Wooden Stick";
            case "AT_SKINNING": return "Skin Animal";
            case "AT_FISHING": return "Fishing";
            case "AT_MOUNT_BARBED_WIRE": return "Mount Barbed Wire";
            case "AT_UNMOUNT_BARBED_WIRE": return "Remove Barbed Wire";
            case "AT_LOAD_MAGAZINE": return "Load Magazine";
            case "AT_EMPTY_MAGAZINE": return "Unload Magazine";
            case "AT_SORT_AMMO": return "Sort Ammo Pile";
            case "AT_WORLD_CRAFT": return "World Craft";

            case "AT_EAT_CAN": return "Eat from Can";
            case "AT_EAT_FRUIT": return "Eat Fruit";
            case "AT_EAT_MEAT": return "Eat Meat";
            case "AT_EAT_SMALL": return "Eat Small Portion";
            case "AT_EAT_CHARCOAL": return "Take Charcoal Tablets";
            case "AT_EAT_PAINKILLER": return "Take Painkiller Tablets";
            case "AT_EAT_PURIFICATION": return "Take Water Purification Tablets";
            case "AT_EAT_TETRACYCLINE": return "Take Tetracycline Antibiotics";
            case "AT_EAT_VITAMINS": return "Take Vitamins";
            case "AT_TAKE_BITE_CAN": return "Take Bite from Can";
            case "AT_TAKE_BITE": return "Take Bite";
            case "AT_FORCE_BITE_CAN": return "Force Feed from Can";
            case "AT_FORCE_BITE": return "Force Feed Bite";
            case "AT_DRINK_CAN": return "Drink from Can";
            case "AT_DRINK_COOKING_POT": return "Drink from Cooking Pot";
            case "AT_DRINK_DISINFECTANT": return "Drink Disinfectant";
            case "AT_DRINK_ALCOHOL": return "Drink Alcohol";
            case "AT_DRINK_POND": return "Drink from Pond";
            case "AT_DRINK_WELL": return "Drink from Well";
            case "AT_TAKE_SIP": return "Take Sip";
            case "AT_FORCE_SIP": return "Force Sip";
            case "AT_FORCE_DRINK": return "Force Drink";
            case "AT_FORCE_FEED": return "Force Feed";
            case "AT_FORCE_FEED_CAN": return "Force Feed from Can";
            case "AT_FORCE_FEED_MEAT": return "Force Feed Meat";
            case "AT_FORCE_CONSUME": return "Force Consume";
            case "AT_COOK_ON_STICK": return "Cook on Stick";
            case "AT_BITE_CHARCOAL": return "Bite Charcoal Tablets";
            case "AT_BITE_PAINKILLER": return "Bite Painkiller Tablets";
            case "AT_BITE_PURIFICATION": return "Bite Purification Tablets";
            case "AT_BITE_TETRACYCLINE": return "Bite Tetracycline";
            case "AT_BITE_VITAMINS": return "Bite Vitamins";

            case "AT_PICK_BERRY": return "Pick Berry";
            case "AT_DIG_WORMS": return "Dig for Worms";

            case "AT_WRING_CLOTHES": return "Wring Clothes";
            case "AT_READ_PAPER": return "Read Paper";
            case "AT_WRITE_PAPER": return "Write on Paper";
            case "AT_SHAVE": return "Shave";
            case "AT_MEASURE_BATTERY": return "Measure Battery";
            case "AT_TRANSFER_LIQUID": return "Transfer Liquid";
            case "AT_FILL_BOTTLE": return "Fill Bottle";
            case "AT_FILL_OBJECT": return "Fill Object";
            case "AT_EMPTY_BOTTLE": return "Empty Bottle";
            case "AT_EMPTY_COOKING_POT": return "Empty Cooking Pot";
            case "AT_EMPTY_SEEDS_PACK": return "Empty Seeds Pack";
            case "AT_UNPACK_BOX": return "Unpack Box";
            case "AT_UPGRADE_TORCH": return "Upgrade Torch";

            case "AT_DEPLOY_OBJECT": return "Deploy Object";
            case "AT_PLACE_ON_GROUND": return "Place on Ground";
            case "AT_DROP_ITEM": return "Drop Item";
            case "AT_TAKE_TO_HANDS": return "Take to Hands";
            case "AT_TAKE_ITEM": return "Take Item";
            case "AT_SWAP_TO_HANDS": return "Swap to Hands";
            case "AT_FOLD_OBJECT": return "Fold Object";
            case "AT_UNFOLD_ENTITY": return "Unfold Entity";
            case "AT_CLOSE_FENCE": return "Close Fence";
            case "AT_OPEN_FENCE": return "Open Fence";

            case "AT_RAISE_FLAG": return "Raise Flag";
            case "AT_LOWER_FLAG": return "Lower Flag";

            case "AT_GET_IN_TRANSPORT": return "Get In Transport";
            case "AT_PULL_BODY_TRANSPORT": return "Pull Body from Transport";
            case "AT_OPEN_CAR_DOORS_OUT": return "Open Car Doors (Outside)";
            case "AT_OPEN_CAR_DOORS": return "Open Car Doors";
            case "AT_CLOSE_CAR_DOORS_OUT": return "Close Car Doors (Outside)";
            case "AT_CLOSE_CAR_DOORS": return "Close Car Doors";
            case "AT_SWITCH_SEATS": return "Switch Seats";

            case "AT_LOCK": return "Lock";
            case "AT_UNLOCK": return "Unlock";
            case "AT_RESTRAIN": return "Restrain";
            case "AT_UNRESTRAIN": return "Unrestrain";
            case "AT_HANDCUFF": return "Handcuff";
            case "AT_GAG": return "Gag";
            case "AT_UNGAG": return "Ungag";
            case "AT_COVER_HEAD": return "Cover Head with Bag";
            case "AT_UNCOVER_HEAD": return "Remove Bag from Head";
            case "AT_FILL": return "Fill";
            case "AT_DRINK": return "Drink";
            case "AT_EAT": return "Eat";
            case "AT_REPAIR": return "Repair";
            case "AT_DESTROY": return "Destroy";
            case "AT_USED": return "Used";
            
            default: return key;
        }
        return key;
    }

    static string GetRussianString(string key)
    {
        switch (key)
        {
            case "CONNECT": return "ПОДКЛЮЧЕНИЕ";
            case "DISCONNECT": return "ОТКЛЮЧЕНИЕ";
            case "DEATH": return "СМЕРТЬ";
            case "PVP_DAMAGE": return "PVP_УРОН";
            case "ITEM_INVENTORY": return "ИНВЕНТАРЬ";
            case "BASE_BUILDING": return "СТРОИТЕЛЬСТВО";
            case "ZOMBIE_KILL": return "УБИЙСТВО_ЗОМБИ";
            case "ANIMAL_KILL": return "ОХОТА";
            case "MEDICINE_USE": return "ИСПОЛЬЗОВАНИЕ_МЕДИКАМЕНТОВ";
            case "CONTAINER_TRANSFER": return "ПЕРЕМЕЩЕНИЕ_ПРЕДМЕТА";
            case "DISEASE": return "ЗАБОЛЕВАНИЕ";
            case "DISEASE_CURED": return "ЗАБОЛЕВАНИЕ_ВЫЛЕЧЕНО";
            case "UNCONSCIOUS": return "БЕССОЗНАНИЕ";
            case "BLEEDING": return "КРОВОТЕЧЕНИЕ";
            case "VEHICLE_SPAWN": return "ПОЯВЛЕНИЕ_ТРАНСПОРТА";
            case "VEHICLE_DESPAWN": return "ИСЧЕЗНОВЕНИЕ_ТРАНСПОРТА";
            case "FLAG_BUILD": return "УСТАНОВКА_ФЛАГА";
            case "FLAG_DISMANTLE": return "СНЯТИЕ_ФЛАГА";
            case "OBJECT_DEPLOY": return "РАЗВЕРНУЛ_ПРЕДМЕТ";
            case "CHAT": return "ЧАТ";
            case "FARMING": return "ФЕРМЕРСТВО";
            case "CAMPING": return "ЛАГЕРЬ";
            case "SECURITY": return "БЕЗОПАСНОСТЬ";
            case "CRAFTING": return "КРАФТ";
            case "FOOD_DRINK": return "ЕДА_И_ПИТЬЁ";
            case "STORM": return "ШТОРМ";

            case "Player": return "Игрок";
            case "SteamID": return "SteamID";
            case "Position": return "Позиция";
            case "Last_Position": return "Последняя позиция";
            case "Name": return "Имя";
            case "Health": return "Здоровье";
            case "Blood": return "Кровь";
            case "Killed_by": return "Убит";
            case "Weapon": return "Оружие";
            case "Attacker": return "Атакующий";
            case "Victim": return "Жертва";
            case "Damage": return "Урон";
            case "Item": return "Предмет";
            case "Source": return "Источник";
            case "Action": return "Действие";
            case "Object": return "Объект";
            case "Zombie": return "Зомби";
            case "Animal": return "Животное";
            case "Medicine": return "Медикамент";
            case "Container": return "Контейнер";
            case "From": return "Из";
            case "To": return "В";
            case "Disease": return "Заболевание";
            case "State": return "Состояние";
            case "Bleed_Sources": return "Источники кровотечения";
            case "Vehicle": return "Транспорт";
            case "Flag": return "Флаг";
            case "Channel": return "Канал";
            case "Message": return "Сообщение";

            case "UNCONSCIOUS_STATE": return "БЕЗ СОЗНАНИЯ";
            case "CONSCIOUS_STATE": return "В СОЗНАНИИ";
            case "Unknown_Environment": return "Неизвестно/Окружение";
            case "Fists_No_weapon": return "Кулаки/Без оружия";

            case "Player_Connected": return "Игрок подключился";
            case "Player_Disconnected": return "Игрок отключился";
            case "Player_Death": return "Смерть игрока";
            case "PvP_Damage": return "PvP урон";
            case "Item_Left_Inventory": return "Предмет покинул инвентарь";
            case "Item_Entered_Inventory": return "Предмет попал в инвентарь";
            case "Base_Building": return "Строительство базы";
            case "Zombie_Killed": return "Зомби убит";
            case "Animal_Killed": return "Животное убито";
            case "Medicine_Used": return "Медикамент использован";
            case "Item_Transferred": return "Предмет перемещён";
            case "Disease_Contracted": return "Заболевание получено";
            case "Disease_Cured": return "Заболевание вылечено";
            case "Unconscious_State": return "Бессознательное состояние";
            case "Bleeding": return "Кровотечение";
            case "Vehicle_Spawned": return "Транспорт появился";
            case "Vehicle_Despawned": return "Транспорт исчез";
            case "Flag_Built": return "Флаг установлен";
            case "Flag_Dismantled": return "Флаг снят";
            case "Object_Deployed": return "Предмет развёрнут";
            case "Chat_Message": return "Сообщение в чате";
            case "Farming": return "Фермерство";
            case "Camping": return "Лагерь";
            case "Security": return "Безопасность";
            case "Crafting": return "Крафт";
            case "Food_Drink": return "Еда и питьё";
            case "Action_Type": return "Тип действия";

            case "AT_BANDAGE_SELF": return "Перевязал себя";
            case "AT_BANDAGE_TARGET": return "Перевязал цель";
            case "AT_BANDAGE": return "Перевязка";
            case "AT_SEW_SELF": return "Зашил рану себе";
            case "AT_SEW_TARGET": return "Зашил рану цели";
            case "AT_BURN_SEW_SELF": return "Прижёг рану себе";
            case "AT_BURN_SEW_TARGET": return "Прижёг рану цели";
            case "AT_SPLINT_SELF": return "Наложил шину себе";
            case "AT_SPLINT_TARGET": return "Наложил шину цели";
            case "AT_INJECT_EPINEPHRINE_SELF": return "Ввёл адреналин себе";
            case "AT_INJECT_EPINEPHRINE_TARGET": return "Ввёл адреналин цели";
            case "AT_INJECT_MORPHINE_SELF": return "Ввёл морфин себе";
            case "AT_INJECT_MORPHINE_TARGET": return "Ввёл морфин цели";
            case "AT_INJECT_SELF": return "Сделал инъекцию себе";
            case "AT_INJECT_TARGET": return "Сделал инъекцию цели";
            case "AT_DISINFECT_SELF": return "Продезинфицировал рану себе";
            case "AT_DISINFECT_TARGET": return "Продезинфицировал рану цели";
            case "AT_CPR": return "Непрямой массаж сердца (СЛР)";
            case "AT_DEFIB_SELF": return "Дефибрилляция себе";
            case "AT_DEFIB_TARGET": return "Дефибрилляция цели";
            case "AT_GIVE_BLOOD_SELF": return "Перелил кровь себе";
            case "AT_GIVE_BLOOD_TARGET": return "Перелил кровь цели";
            case "AT_GIVE_SALINE_SELF": return "Ввёл физраствор себе";
            case "AT_GIVE_SALINE_TARGET": return "Ввёл физраствор цели";
            case "AT_COLLECT_BLOOD_SELF": return "Собрал кровь у себя";
            case "AT_COLLECT_BLOOD_TARGET": return "Собрал кровь у цели";
            case "AT_COLLECT_SAMPLE_SELF": return "Взял образец у себя";
            case "AT_COLLECT_SAMPLE_TARGET": return "Взял образец у цели";
            case "AT_TEST_BLOOD_SELF": return "Анализ крови у себя";
            case "AT_TEST_BLOOD_TARGET": return "Анализ крови у цели";
            case "AT_CHECK_PULSE": return "Проверил пульс";
            case "AT_MEASURE_TEMP_SELF": return "Измерил температуру себе";
            case "AT_MEASURE_TEMP_TARGET": return "Измерил температуру цели";
            case "AT_WASH_HANDS": return "Помыл руки";

            case "AT_BUILD_PART": return "Построил часть конструкции";
            case "AT_DISMANTLE_PART": return "Разобрал часть конструкции";
            case "AT_DECONSTRUCT_SHELTER": return "Разобрал укрытие";
            case "AT_DESTROY_PART": return "Разрушил часть конструкции";
            case "AT_REPAIR_PART": return "Починил часть конструкции";
            case "AT_REPAIR_SHELTER": return "Починил укрытие";
            case "AT_UPGRADE": return "Улучшил конструкцию";
            case "AT_ATTACH_CONSTRUCTION": return "Прикрепил к конструкции";
            case "AT_DETACH_FROM_TARGET": return "Открепил предмет";
            case "AT_ATTACH_WHEELS": return "Установил колёса";
            case "AT_BUILD_SHELTER": return "Построил укрытие";

            case "AT_REPAIR_CAR_CHASSIS": return "Починил шасси автомобиля";
            case "AT_REPAIR_CAR_ENGINE": return "Починил двигатель автомобиля";
            case "AT_REPAIR_CAR_PART": return "Починил часть автомобиля";
            case "AT_FILL_FUEL": return "Заправил транспорт";
            case "AT_FILL_BRAKES": return "Залил тормозную жидкость";
            case "AT_FILL_COOLANT": return "Залил охлаждающую жидкость";
            case "AT_FILL_OIL": return "Залил моторное масло";
            case "AT_INSERT_SPARKPLUG": return "Установил свечу зажигания";
            case "AT_START_ENGINE": return "Завёл двигатель";
            case "AT_STOP_ENGINE": return "Заглушил двигатель";

            case "AT_DIG_GARDEN": return "Вскопал грядку";
            case "AT_DISMANTLE_GARDEN": return "Разобрал грядку";
            case "AT_FERTILIZE": return "Удобрить грядку";
            case "AT_HARVEST_CROPS": return "Собрал урожай";
            case "AT_PLANT_SEED": return "Посадил семена";
            case "AT_REMOVE_PLANT": return "Удалил растение";
            case "AT_WATER_GARDEN": return "Полил грядку";
            case "AT_WATER_PLANT": return "Полил растение";
            case "AT_DISINFECT_PLANT": return "Продезинфицировал растение";

            case "AT_PACK_TENT": return "Свернул палатку";
            case "AT_REPACK_TENT": return "Упаковал палатку";
            case "AT_REPAIR_TENT_PART": return "Починил часть палатки";
            case "AT_REPAIR_TENT": return "Починил палатку";
            case "AT_TOGGLE_TENT": return "Открыл/закрыл палатку";
            case "AT_PLACE_FIREPLACE_INDOOR": return "Поставил костёр в помещении";
            case "AT_PLACE_FIREPLACE_BARREL": return "Положил костёр в бочку";
            case "AT_PLACE_OVEN_INDOOR": return "Поставил печь в помещении";
            case "AT_CREATE_INDOOR_FIREPLACE": return "Создал костёр в помещении";
            case "AT_CREATE_INDOOR_OVEN": return "Создал печь в помещении";
            case "AT_IGNITE_FIREPLACE": return "Разжёг костёр";
            case "AT_EXTINGUISH_FIREPLACE_LIQUID": return "Потушил костёр жидкостью";
            case "AT_EXTINGUISH_FIREPLACE_EXTINGUISHER": return "Потушил костёр огнетушителем";
            case "AT_TAKE_FIREPLACE_BARREL": return "Достал костёр из бочки";
            case "AT_TAKE_FIREPLACE_INDOOR": return "Достал костёр из помещения";
            case "AT_TAKE_OVEN_INDOOR": return "Достал печь из помещения";
            case "AT_DIG_IN_STASH": return "Закопал тайник";
            case "AT_DIG_OUT_STASH": return "Откопал тайник";
            case "AT_BURY_BODY": return "Захоронил тело";
            case "AT_BURY_ASHES": return "Захоронил прах";

            case "AT_LOCK_DOORS": return "Запер двери";
            case "AT_UNLOCK_DOORS": return "Отпер двери";
            case "AT_DESTROY_LOCK": return "Сломал кодовый замок";
            case "AT_DIAL_LOCK": return "Набрал код на замке";

            case "AT_CRAFT": return "Скрафтил предмет";
            case "AT_SAW_PLANKS": return "Распилил доски";
            case "AT_MINE_BUSH": return "Срубил куст";
            case "AT_MINE_ROCK": return "Разбил камень";
            case "AT_MINE_TREE": return "Срубил дерево";
            case "AT_MINE_BARK": return "Содрал кору";
            case "AT_BREAK_STICK": return "Сломал деревянную палку";
            case "AT_SKINNING": return "Разделал тушу";
            case "AT_FISHING": return "Рыбалка";
            case "AT_MOUNT_BARBED_WIRE": return "Установил колючую проволоку";
            case "AT_UNMOUNT_BARBED_WIRE": return "Снял колючую проволоку";
            case "AT_LOAD_MAGAZINE": return "Зарядил магазин";
            case "AT_EMPTY_MAGAZINE": return "Разрядил магазин";
            case "AT_SORT_AMMO": return "Рассортировал патроны";
            case "AT_WORLD_CRAFT": return "Крафт на земле";

            case "AT_EAT_CAN": return "Ест из банки";
            case "AT_EAT_FRUIT": return "Съел фрукт";
            case "AT_EAT_MEAT": return "Съел мясо";
            case "AT_EAT_SMALL": return "Съел маленький кусок";
            case "AT_EAT_CHARCOAL": return "Принял активированный уголь";
            case "AT_EAT_PAINKILLER": return "Принял обезболивающее";
            case "AT_EAT_PURIFICATION": return "Принял таблетки очистки воды";
            case "AT_EAT_TETRACYCLINE": return "Принял тетрациклин";
            case "AT_EAT_VITAMINS": return "Принял витамины";
            case "AT_TAKE_BITE_CAN": return "Откусил из банки";
            case "AT_TAKE_BITE": return "Откусил кусок";
            case "AT_FORCE_BITE_CAN": return "Принудительно накормил из банки";
            case "AT_FORCE_BITE": return "Принудительно накормил";
            case "AT_DRINK_CAN": return "Пьёт из банки";
            case "AT_DRINK_COOKING_POT": return "Пьёт из котелка";
            case "AT_DRINK_DISINFECTANT": return "Выпил дезинфицирующее";
            case "AT_DRINK_ALCOHOL": return "Выпил алкоголь";
            case "AT_DRINK_POND": return "Пьёт из пруда";
            case "AT_DRINK_WELL": return "Пьёт из колодца";
            case "AT_TAKE_SIP": return "Отпил глоток";
            case "AT_FORCE_SIP": return "Принудительно напоил глотком";
            case "AT_FORCE_DRINK": return "Принудительно напоил";
            case "AT_FORCE_FEED": return "Принудительно накормил";
            case "AT_FORCE_FEED_CAN": return "Принудительно накормил из банки";
            case "AT_FORCE_FEED_MEAT": return "Принудительно накормил мясом";
            case "AT_FORCE_CONSUME": return "Принудительно употребил";
            case "AT_COOK_ON_STICK": return "Готовит на палке";
            case "AT_BITE_CHARCOAL": return "Укуш. табл. угля";
            case "AT_BITE_PAINKILLER": return "Укуш. табл. обезбол.";
            case "AT_BITE_PURIFICATION": return "Укуш. табл. очистки";
            case "AT_BITE_TETRACYCLINE": return "Укуш. табл. тетрациклина";
            case "AT_BITE_VITAMINS": return "Укуш. витамины";

            case "AT_PICK_BERRY": return "Собрал ягоду";
            case "AT_DIG_WORMS": return "Нарыл червей";

            case "AT_WRING_CLOTHES": return "Выжал одежду";
            case "AT_READ_PAPER": return "Прочитал бумагу";
            case "AT_WRITE_PAPER": return "Написал на бумаге";
            case "AT_SHAVE": return "Побрился";
            case "AT_MEASURE_BATTERY": return "Измерил заряд батареи";
            case "AT_TRANSFER_LIQUID": return "Перелил жидкость";
            case "AT_FILL_BOTTLE": return "Наполнил бутылку";
            case "AT_FILL_OBJECT": return "Наполнил объект";
            case "AT_EMPTY_BOTTLE": return "Опустил бутылку";
            case "AT_EMPTY_COOKING_POT": return "Опустил котелок";
            case "AT_EMPTY_SEEDS_PACK": return "Опустил упаковку семян";
            case "AT_UNPACK_BOX": return "Распаковал коробку";
            case "AT_UPGRADE_TORCH": return "Пропитал факел";

            case "AT_DEPLOY_OBJECT": return "Развернул объект";
            case "AT_PLACE_ON_GROUND": return "Положил на землю";
            case "AT_DROP_ITEM": return "Бросил предмет";
            case "AT_TAKE_TO_HANDS": return "Взял в руки";
            case "AT_TAKE_ITEM": return "Взял предмет";
            case "AT_SWAP_TO_HANDS": return "Переложил в руки";
            case "AT_FOLD_OBJECT": return "Сложил объект";
            case "AT_UNFOLD_ENTITY": return "Развернул объект";
            case "AT_CLOSE_FENCE": return "Закрыл калитку";
            case "AT_OPEN_FENCE": return "Открыл калитку";

            case "AT_RAISE_FLAG": return "Поднял флаг";
            case "AT_LOWER_FLAG": return "Опустил флаг";

            case "AT_GET_IN_TRANSPORT": return "Сел в транспорт";
            case "AT_PULL_BODY_TRANSPORT": return "Вытащил тело из транспорта";
            case "AT_OPEN_CAR_DOORS_OUT": return "Открыл двери (снаружи)";
            case "AT_OPEN_CAR_DOORS": return "Открыл двери автомобиля";
            case "AT_CLOSE_CAR_DOORS_OUT": return "Закрыл двери (снаружи)";
            case "AT_CLOSE_CAR_DOORS": return "Закрыл двери автомобиля";
            case "AT_SWITCH_SEATS": return "Переключил сиденье";

            case "AT_LOCK": return "Запер";
            case "AT_UNLOCK": return "Отпер";
            case "AT_RESTRAIN": return "Связал";
            case "AT_UNRESTRAIN": return "Освободил";
            case "AT_HANDCUFF": return "Надел наручники";
            case "AT_GAG": return "Надел кляп";
            case "AT_UNGAG": return "Снял кляп";
            case "AT_COVER_HEAD": return "Надел мешок на голову";
            case "AT_UNCOVER_HEAD": return "Снял мешок с головы";
            case "AT_FILL": return "Заправил";
            case "AT_DRINK": return "Выпил";
            case "AT_EAT": return "Съел";
            case "AT_REPAIR": return "Починил";
            case "AT_DESTROY": return "Разрушил";
            case "AT_USED": return "Использовал";

            default: return key;
        }
        return key;
    }
}
