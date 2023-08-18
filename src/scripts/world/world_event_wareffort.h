/*
* Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
* Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
* Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
* Copyright (C) 2017- Light's Hope Project <https://github.com/LightsHope>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/**
    Include for all things War Effort related that do not belong on a Zone-level scope
*/

#pragma once

#include "scriptPCH.h"
#include "WorldStates.h"
#include <array>

#define NUM_FACTION_OBJECTIVES 10
#define NUM_SHARED_OBJECTIVES 5

enum WarEffortGameEvents
{
    EVENT_WAR_EFFORT_COLLECT_OBJ    = 22,

    EVENT_WAR_EFFORT_REP        = 52,
    EVENT_WAR_EFFORT_OFFICERS   = 53,

    EVENT_WAR_EFFORT_TRANSITION_DAY1 = 54,
    EVENT_WAR_EFFORT_TRANSITION_DAY2 = 55,
    EVENT_WAR_EFFORT_TRANSITION_DAY3 = 56,
    EVENT_WAR_EFFORT_TRANSITION_DAY4 = 57,
    EVENT_WAR_EFFORT_TRANSITION_DAY5 = 58,

    EVENT_WAR_EFFORT_CH_ATTACK  = 59,
    EVENT_WAR_EFFORT_TROOPS2    = 60,

    EVENT_WAR_EFFORT_FINALBATTLE    = 61,
    EVENT_WAR_EFFORT_BATTLE_ASHI    = 62,
    EVENT_WAR_EFFORT_BATTLE_REGAL   = 63,
    EVENT_WAR_EFFORT_BATTLE_ZORA    = 64,

    EVENT_WAR_EFFORT_WORLD_CRYSTALS = 65,

    EVENT_AQ_GATE               = 83,
    EVENT_WAR_EFFORT            = 84,
    EVENT_WAR_EFFORT_GONG       = 85,
    EVENT_WAR_EFFORT_POST_WAR   = 86,

    EVENT_WAR_EFFORT_TERMINATOR
};

enum WarEffortItemType
{
    WAREFFORT_BAR,
    WAREFFORT_HERBS,
    WAREFFORT_SKINS,
    WAREFFORT_COOKING,
    WAREFFORT_BANDAGES,
};

struct WarEffortData 
{
    uint32 itemId;
    uint32 required;
    uint32 currentVar;

    WorldStates wsCurrent;
    WorldStates wsRequired;
    WarEffortItemType type;
};

struct SharedWarEffortData 
{
    uint32 itemId;
    uint32 required;

    WorldStates wsHordeCurrent;
    WorldStates wsAllianceCurrent;
    WorldStates wsRequired;
    WarEffortItemType type;
};

struct WarEffortStockInfo 
{
    const ItemPrototype *proto;

    uint32 count;
    uint32 required;
    uint32 currentVar;
};

struct WarEffortGossip
{
    uint32 itemId;
    uint32 progressTextAlliance;
    uint32 progressTextHorde;
    uint32 completeTextAlliance;
    uint32 completeTextHorde;
};

static const WarEffortGossip WarEffortGossipText[NUM_SHARED_OBJECTIVES + 2*NUM_FACTION_OBJECTIVES] = 
{
    // Shared
    { 2840, 7824, 7866, 7823, 7867 },   // Copper Bars
    { 8831, 7835, 7907, 7836, 7908 },   // Purple Lotus
    { 4304, 7845, 7912, 7846, 7846 },   // Thick Leather
    { 6887, 7861, 7927, 7862, 7928 },   // Spotted Yellowtail
    { 14529, 7853, 7923, 7854, 7924 },  // Runecloth Bandages

    // Alliance
    { 3575, 7829, 0, 7830, 0 },         // Iron Bar
    { 12359, 7831, 0, 7832, 0 },        // Thorium Bar
    { 8836, 7837, 0, 7838, 0 },         // Arthas' Tear
    { 3820, 7833, 0, 7834, 0 },         // Stranglekelp
    { 2318, 7840, 0, 7842, 0 },         // Light Leather
    { 2319, 7843, 0, 7844, 0 },         // Medium Leather
    { 12210, 7859, 0, 7860, 0 },        // Roast Raptor
    { 5095, 7856, 0, 7857, 0 },         // Rainbow Fin Albacore
    { 1251, 7847, 0, 7848, 0 },         // Linen Bandage
    { 6450, 7851, 0, 7852, 0 },         // Silk Bandage

    // Horde
    { 3576, 0, 7870, 0, 7871 },         // Tin Bar
    { 3860, 0, 7876, 0, 7877 },         // Mithril Bar
    { 2447, 0, 7878, 0, 7879 },         // Peacebloom
    { 4625, 0, 7905, 0, 7906 },         // Firebloom
    { 4234, 0, 7909, 0, 7910 },         // Heavy Leather
    { 8170, 0, 7914, 0, 7915 },         // Rugged Leather
    { 12209, 0, 7925, 0, 7926 },        // Lean Wolf Steak
    { 13935, 0, 7929, 0, 7930 },        // Baked Salmon
    { 3530, 0, 7918, 0, 7919 },         // Wool Bandage
    { 8544, 0, 7920, 0, 7921 }          // Mageweave Bandage
};

static std::array<SharedWarEffortData, NUM_SHARED_OBJECTIVES> const SharedObjectives =
{{
    { 2840,  90000,  WS_WE_HORDE_COPPERBAR_CURRENT, WS_WE_ALLIANCE_COPPERBAR_CURRENT, WS_WE_SHARED_COPPERBAR_REQUIRE, WAREFFORT_BAR },
    { 8831,  26000,  WS_WE_HORDE_PURPLELOTUS_CURRENT, WS_WE_ALLIANCE_PURPLELOTUS_CURRENT, WS_WE_SHARED_PURPLELOTUS_REQUIRE, WAREFFORT_HERBS },
    { 4304,  80000,  WS_WE_HORDE_THICKLEATHER_CURRENT, WS_WE_ALLIANCE_THICKLEATHER_CURRENT, WS_WE_SHARED_THICKLEATHER_REQUIRE, WAREFFORT_SKINS },
    { 6887,  17000,  WS_WE_HORDE_SPOTYELLOW_CURRENT, WS_WE_ALLIANCE_SPOTYELLOW_CURRENT, WS_WE_SHARED_SPOTYELLOW_REQUIRE, WAREFFORT_COOKING },
    { 14529, 400000, WS_WE_HORDE_RUNEBANDAGE_CURRENT, WS_WE_ALLIANCE_RUNEBANDAGE_CURRENT, WS_WE_SHARED_RUNEBANDAGE_REQUIRE, WAREFFORT_BANDAGES }
}};

static std::array<WarEffortData, NUM_FACTION_OBJECTIVES> const AllianceObjectives =
{{
    { 3575,  28000,  3575,   WS_WE_ALLIANCE_IRONBAR_CURRENT, WS_WE_ALLIANCE_IRONBAR_REQUIRE, WAREFFORT_BAR },
    { 12359, 24000,  12359,  WS_WE_ALLIANCE_THORIUMBAR_CURRENT, WS_WE_ALLIANCE_THORIUMBAR_REQUIRE, WAREFFORT_BAR },
    { 8836,  20000,  8836,   WS_WE_ALLIANCE_ARTHASTEAR_CURRENT, WS_WE_ALLIANCE_ARTHASTEAR_REQUIRE, WAREFFORT_HERBS },
    { 3820,  33000,  3820,   WS_WE_ALLIANCE_STRANGLEKELP_CURRENT, WS_WE_ALLIANCE_STRANGLEKELP_REQUIRE, WAREFFORT_HERBS },
    { 2318,  180000, 2318,   WS_WE_ALLIANCE_LIGHTLEATHER_CURRENT, WS_WE_ALLIANCE_LIGHTLEATHER_REQUIRE, WAREFFORT_SKINS },
    { 2319,  110000, 2319,   WS_WE_ALLIANCE_MEDIUMLEATHER_CURRENT, WS_WE_ALLIANCE_MEDIUMLEATHER_REQUIRE, WAREFFORT_SKINS },
    { 12210, 20000,  12210,  WS_WE_ALLIANCE_ROASTRAPTOR_CURRENT, WS_WE_ALLIANCE_ROASTRAPTOR_REQUIRE, WAREFFORT_COOKING },
    { 5095,  14000,  5095,   WS_WE_ALLIANCE_RBOWALBA_CURRENT, WS_WE_ALLIANCE_RBOWALBA_REQUIRE, WAREFFORT_COOKING },
    { 1251,  800000, 1251,   WS_WE_ALLIANCE_LINENBANDAGE_CURRENT, WS_WE_ALLIANCE_LINENBANDAGE_REQUIRE, WAREFFORT_BANDAGES },
    { 6450,  600000, 6450,   WS_WE_ALLIANCE_SILKBANDAGE_CURRENT, WS_WE_ALLIANCE_SILKBANDAGE_REQUIRE, WAREFFORT_BANDAGES }
}};

static std::array<WarEffortData, NUM_FACTION_OBJECTIVES> const HordeObjectives =
{{
    { 3576,  22000,  3576,   WS_WE_HORDE_TINBAR_CURRENT, WS_WE_HORDE_TINBAR_REQUIRE, WAREFFORT_BAR },
    { 3860,  18000,  3860,   WS_WE_HORDE_MITHRILBAR_CURRENT, WS_WE_HORDE_MITRHILBAR_REQUIRE, WAREFFORT_BAR },
    { 2447,  96000,  2447,   WS_WE_HORDE_PEACEBLOOM_CURRENT, WS_WE_HORDE_PEACEBLOOM_REQUIRE, WAREFFORT_HERBS },
    { 4625,  19000,  4625,   WS_WE_HORDE_FIREBLOOM_CURRENT, WS_WE_HORDE_FIREBLOOM_REQUIRE, WAREFFORT_HERBS },
    { 4234,  60000,  4234,   WS_WE_HORDE_HEAVYLEATHER_CURRENT, WS_WE_HORDE_HEAVYLEATHER_REQUIRE, WAREFFORT_SKINS },
    { 8170,  60000,  8170,   WS_WE_HORDE_RUGGEDLEATHER_CURRENT, WS_WE_HORDE_RUGGEDLEATHER_REQUIRE, WAREFFORT_SKINS },
    { 12209, 10000,  12209,  WS_WE_HORDE_LEANWOLF_CURRENT, WS_WE_HORDE_LEANWOLF_REQUIRE, WAREFFORT_COOKING },
    { 13935, 10000,  13935,  WS_WE_HORDE_BAKEDSALMON_CURRENT, WS_WE_HORDE_BAKEDSALMON_REQUIRE, WAREFFORT_COOKING },
    { 3530,  250000, 3530,   WS_WE_HORDE_WOOLBANDAGE_CURRENT, WS_WE_HORDE_WOOLBANDAGE_REQUIRE, WAREFFORT_BANDAGES },
    { 8544,  250000, 8544,   WS_WE_HORDE_MAGEBANDAGE_CURRENT, WS_WE_HORDE_MAGEBANDAGE_REQUIRE, WAREFFORT_BANDAGES }
}};

struct GOWarEffort
{
    int tier;      // The tier of the gobj. range from 1-5
    uint32 GOEntry;
    int faction;    // = GetTeamId() // Alliance = 0 Horde = 1
};

static const GOWarEffort GOBars[10] =
{
    // Alliance
    { 1, 180780, 0 },
    { 2, 180781, 0 },
    { 3, 180782, 0 },
    { 4, 180783, 0 },
    { 5, 180784, 0 },
    // Horde
    { 1, 180839, 1 },
    { 2, 180840, 1 },
    { 3, 180841, 1 },
    { 4, 180842, 1 },
    { 5, 180843, 1 }
};

static const GOWarEffort GOCooking[10] =
{
    // Alliance
    { 1, 180800, 0 },
    { 2, 180806, 0 },
    { 3, 180807, 0 },
    { 4, 180808, 0 },
    { 5, 180809, 0 },
    // Horde
    { 1, 180833, 1 },
    { 2, 180834, 1 },
    { 3, 180835, 1 },
    { 4, 180836, 1 },
    { 5, 180837, 1 }
};

static const GOWarEffort GOHerbs[10] =
{
    // Alliance
    { 1, 180801, 0 },
    { 2, 180802, 0 },
    { 3, 180803, 0 },
    { 4, 180804, 0 },
    { 5, 180805, 0 },
    // Horde
    { 1, 180819, 1 },
    { 2, 180820, 1 },
    { 3, 180821, 1 },
    { 4, 180822, 1 },
    { 5, 180823, 1 }
};

static const GOWarEffort GOSkins[10] =
{
    // Alliance
    { 1, 180692, 0 },
    { 2, 180693, 0 },
    { 3, 180694, 0 },
    { 4, 180695, 0 },
    { 5, 180696, 0 },
    // Horde
    { 1, 180813, 1 },
    { 2, 180814, 1 },
    { 3, 180815, 1 },
    { 4, 180816, 1 },
    { 5, 180817, 1 }
};

static const GOWarEffort GOBandages[10] =
{
    // Alliance
    { 1, 180674, 0 },
    { 2, 180675, 0 },
    { 3, 180676, 0 },
    { 4, 180677, 0 },
    { 5, 180678, 0 },
    // Horde
    { 1, 180827, 1 },
    { 2, 180828, 1 },
    { 3, 180829, 1 },
    { 4, 180830, 1 },
    { 5, 180831, 1 }
};


uint32 BuildWarEffortWorldStates(WorldPacket &data);

void AutoCompleteWarEffortProgress();
void AutoCompleteWarEffortResource(uint32 resourceId, uint32 required, uint32 savedVar, float rate, TeamId team);

uint32 GetTeamStock(uint32 item, TeamId team);
uint32 GetSharedSavedVar(uint32 item, TeamId team);
const WarEffortGossip& GetWarEffortGossip(uint32 item);
bool GetWarEffortStockInfo(uint32 resourceId, WarEffortStockInfo &info, TeamId team = TEAM_ALLIANCE);
uint32 GetWarEffortGossipTextId(uint32 item, TeamId team, bool objectiveReached);
WarEffortGameEvents GetActiveTransportEvent();
