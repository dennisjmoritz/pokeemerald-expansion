#include "global.h"
#include "test/battle.h"

// These tests only run when B_LEVEL_50_ALL_BATTLES is enabled
// To test this feature, set B_LEVEL_50_ALL_BATTLES to TRUE in include/config/battle.h

SINGLE_BATTLE_TEST("Level 50 scaling works for low level trainer Pokemon", s16 >= GEN_3)
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MAGIKARP) { Level(10); } // Low level
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        // Battle proceeds normally
    } THEN {
        // Check level based on configuration
        if (B_LEVEL_50_ALL_BATTLES)
        {
            EXPECT(GetMonData(&OPPONENT_PARTY[0], MON_DATA_LEVEL, 0) == 50);
        }
        else
        {
            EXPECT(GetMonData(&OPPONENT_PARTY[0], MON_DATA_LEVEL, 0) == 10);
        }
    }
}

SINGLE_BATTLE_TEST("Level 50 scaling works for high level trainer Pokemon", s16 >= GEN_3)
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DRAGONITE) { Level(70); } // High level
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        // Battle proceeds normally
    } THEN {
        // Check level based on configuration
        if (B_LEVEL_50_ALL_BATTLES)
        {
            EXPECT(GetMonData(&OPPONENT_PARTY[0], MON_DATA_LEVEL, 0) == 50);
        }
        else
        {
            EXPECT(GetMonData(&OPPONENT_PARTY[0], MON_DATA_LEVEL, 0) == 70);
        }
    }
}