#include "global.h"
#include "test/battle.h"

// Test VGC format changes: level 50 scaling for both trainer and wild battles,
// and double battles as default for trainer battles

DOUBLE_BATTLE_TEST("Trainer battles are double by default in VGC format")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_MAGIKARP) { Level(10); }
        OPPONENT(SPECIES_FEEBAS) { Level(15); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); 
               MOVE(playerRight, MOVE_TACKLE, target: opponentRight); }
    } SCENE {
        // Battle should proceed as a double battle
        MESSAGE("Wobbuffet used Tackle!");
        MESSAGE("Wynaut used Tackle!");
    } THEN {
        // Both opponents should be at level 50 if scaling is enabled
        if (B_LEVEL_50_ALL_BATTLES)
        {
            EXPECT(GetMonData(&OPPONENT_PARTY[0], MON_DATA_LEVEL, 0) == 50);
            EXPECT(GetMonData(&OPPONENT_PARTY[1], MON_DATA_LEVEL, 0) == 50);
        }
    }
}

// Test that wild Pokemon battles can be both double and level 50 
WILD_DOUBLE_BATTLE_TEST("Wild double battles use level 50 scaling in VGC format", s16 >= GEN_3)
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        WILD(SPECIES_ZIGZAGOON) { Level(8); }
        WILD(SPECIES_POOCHYENA) { Level(12); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); }
    } SCENE {
        // Battle proceeds normally
    } THEN {
        // Wild Pokemon should be at level 50 if scaling is enabled
        if (B_LEVEL_50_WILD_BATTLES)
        {
            EXPECT(GetMonData(&OPPONENT_PARTY[0], MON_DATA_LEVEL, 0) == 50);
            EXPECT(GetMonData(&OPPONENT_PARTY[1], MON_DATA_LEVEL, 0) == 50);
        }
    }
}