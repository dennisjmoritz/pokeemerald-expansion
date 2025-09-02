#include "global.h"
#include "test/test.h"
#include "battle.h"
#include "battle_main.h"
#include "data.h"
#include "malloc.h"
#include "pokemon.h"
#include "constants/abilities.h"
#include "constants/battle.h"
#include "constants/battle_frontier.h"
#include "constants/trainers.h"

// Test trainer data with different levels
static const struct TrainerMon sTestMons[] = {
    {
        .species = SPECIES_TORCHIC,
        .lvl = 10,  // Low level - should scale up to 50
        .ability = ABILITY_BLAZE,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EMBER, MOVE_SCRATCH, MOVE_NONE, MOVE_NONE},
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .nature = NATURE_ADAMANT,
    },
    {
        .species = SPECIES_RAYQUAZA,
        .lvl = 70,  // High level - should scale down to 50
        .ability = ABILITY_AIR_LOCK,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRAGON_CLAW, MOVE_FLY, MOVE_NONE, MOVE_NONE},
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .nature = NATURE_ADAMANT,
    },
    {
        .species = SPECIES_PIKACHU,
        .lvl = 50,  // Already level 50 - should stay the same
        .ability = ABILITY_STATIC,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDERBOLT, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE},
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .nature = NATURE_MODEST,
    },
};

static const struct Trainer sTestTrainer = {
    .party = sTestMons,
    .partySize = ARRAY_COUNT(sTestMons),
    .trainerClass = TRAINER_CLASS_YOUNGSTER,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
    .trainerPic = TRAINER_PIC_YOUNGSTER,
    .trainerName = _("TEST"),
    .items = {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    .aiFlags = 0,
    .battleType = TRAINER_BATTLE_TYPE_SINGLES,
};

TEST("B_LEVEL_50_ALL_BATTLES scales trainer Pokemon to level 50")
{
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    
    // Test with level 50 scaling enabled (should be TRUE based on our config)
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainer, TRUE, BATTLE_TYPE_TRAINER);
    
    // Check that all Pokemon are scaled to level 50
    EXPECT(GetMonData(&testParty[0], MON_DATA_LEVEL, 0) == FRONTIER_MAX_LEVEL_50);  // Was level 10
    EXPECT(GetMonData(&testParty[1], MON_DATA_LEVEL, 0) == FRONTIER_MAX_LEVEL_50);  // Was level 70
    EXPECT(GetMonData(&testParty[2], MON_DATA_LEVEL, 0) == FRONTIER_MAX_LEVEL_50);  // Was level 50
    
    // Verify species are preserved
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPECIES, 0) == SPECIES_TORCHIC);
    EXPECT(GetMonData(&testParty[1], MON_DATA_SPECIES, 0) == SPECIES_RAYQUAZA);
    EXPECT(GetMonData(&testParty[2], MON_DATA_SPECIES, 0) == SPECIES_PIKACHU);
    
    Free(testParty);
}

TEST("B_LEVEL_50_ALL_BATTLES does not affect frontier battles")
{
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    
    // Test with frontier battle type - levels should not be scaled
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainer, TRUE, BATTLE_TYPE_TRAINER | BATTLE_TYPE_FRONTIER);
    
    // Original levels should be preserved for frontier battles
    EXPECT(GetMonData(&testParty[0], MON_DATA_LEVEL, 0) == 10);   // Original level 10
    EXPECT(GetMonData(&testParty[1], MON_DATA_LEVEL, 0) == 70);   // Original level 70
    EXPECT(GetMonData(&testParty[2], MON_DATA_LEVEL, 0) == 50);   // Original level 50
    
    Free(testParty);
}