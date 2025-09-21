#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_setup.h"
#include "decoration.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "link.h"
#include "list_menu.h"
#include "main.h"
#include "map_name_popup.h"
#include "menu.h"
#include "menu_helpers.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "palette.h"
#include "script.h"
#include "secret_base.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "tv.h"
#include "window.h"
#include "constants/event_bg.h"
#include "constants/decorations.h"
#include "constants/event_objects.h"
#include "constants/field_specials.h"
#include "constants/items.h"
#include "constants/metatile_behaviors.h"
#include "constants/metatile_labels.h"
#include "constants/moves.h"
#include "constants/secret_bases.h"
#include "constants/songs.h"
#include "constants/trainers.h"

#define TAG_SCROLL_ARROW 5112

struct SecretBaseEntranceMetatiles
{
    u16 closedMetatileId;
    u16 openMetatileId;
};

static EWRAM_DATA u8 sCurSecretBaseId = 0;
static EWRAM_DATA bool8 sInFriendSecretBase = FALSE;



static const struct SecretBaseEntranceMetatiles sSecretBaseEntranceMetatiles[] =
{
    {.closedMetatileId = METATILE_General_SecretBase_TreeLeft,  .openMetatileId = METATILE_General_SecretBase_VineLeft},
    {.closedMetatileId = METATILE_General_SecretBase_TreeRight, .openMetatileId = METATILE_General_SecretBase_VineRight},
    {.closedMetatileId = METATILE_General_RedCaveIndent,        .openMetatileId = METATILE_General_RedCaveOpen},
    {.closedMetatileId = METATILE_General_YellowCaveIndent,     .openMetatileId = METATILE_General_YellowCaveOpen},
    {.closedMetatileId = METATILE_General_BlueCaveIndent,       .openMetatileId = METATILE_General_BlueCaveOpen},
    {.closedMetatileId = METATILE_Fallarbor_BrownCaveIndent,    .openMetatileId = METATILE_Fallarbor_BrownCaveOpen},
    {.closedMetatileId = METATILE_Fortree_SecretBase_Shrub,     .openMetatileId = METATILE_Fortree_SecretBase_ShrubOpen},
};

// mapNum, warpId, x, y
// x, y positions are for when the player warps in for the first time (in front of the computer)
static const u8 sSecretBaseEntrancePositions[NUM_SECRET_BASE_GROUPS * 4] =
{
    [SECRET_BASE_APARTMENT1]    = MAP_NUM(MAP_SECRET_BASE_APARTMENT1),    0,  1,  3,
    [SECRET_BASE_HOUSE1]        = MAP_NUM(MAP_SECRET_BASE_HOUSE1),        0,  2,  3,
    [SECRET_BASE_MANSION1]      = MAP_NUM(MAP_SECRET_BASE_MANSION1),      0,  3,  3,
};

#define GET_BASE_MAP_NUM(group)    (sSecretBaseEntrancePositions[(group) + 0])
#define GET_BASE_WARP_ID(group)    (sSecretBaseEntrancePositions[(group) + 1])
#define GET_BASE_COMPUTER_X(group) (sSecretBaseEntrancePositions[(group) + 2])
#define GET_BASE_COMPUTER_Y(group) (sSecretBaseEntrancePositions[(group) + 3])

static void ClearSecretBase(struct SecretBase *secretBase)
{
    u16 i;
    CpuFastFill16(0, secretBase, sizeof(struct SecretBase));
    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
        secretBase->trainerName[i] = EOS;
}

void ClearSecretBases(void)
{
    u16 i;
    for (i = 0; i < SECRET_BASES_COUNT; i++)
        ClearSecretBase(&gSaveBlock1Ptr->secretBases[i]);
}

static void SetCurSecretBaseId(void)
{
    sCurSecretBaseId = gSpecialVar_0x8004;
}

void TrySetCurSecretBaseIndex(void)
{
    u16 i;

    gSpecialVar_Result = FALSE;
    for (i = 0; i < SECRET_BASES_COUNT; i++)
    {
        if (sCurSecretBaseId == gSaveBlock1Ptr->secretBases[i].secretBaseId)
        {
            gSpecialVar_Result = TRUE;
            VarSet(VAR_CURRENT_SECRET_BASE, i);
            break;
        }
    }
}

void CheckPlayerHasSecretBase(void)
{
    // The player's secret base is always the first in the array.
    if (gSaveBlock1Ptr->secretBases[0].secretBaseId)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

static u8 GetSecretBaseTypeInFrontOfPlayer_(void)
{
    s16 x, y;
    s16 behavior;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    behavior = MapGridGetMetatileBehaviorAt(x, y) & 0xFFF;
    if (behavior == MB_SECRET_BASE_SPOT_RED_CAVE || behavior == MB_SECRET_BASE_SPOT_RED_CAVE_OPEN
     || behavior == MB_SECRET_BASE_SPOT_BROWN_CAVE || behavior == MB_SECRET_BASE_SPOT_BROWN_CAVE_OPEN
     || behavior == MB_SECRET_BASE_SPOT_BLUE_CAVE || behavior == MB_SECRET_BASE_SPOT_BLUE_CAVE_OPEN
     || behavior == MB_SECRET_BASE_SPOT_YELLOW_CAVE || behavior == MB_SECRET_BASE_SPOT_YELLOW_CAVE_OPEN)
        return SECRET_BASE_APARTMENT;

    if (behavior == MB_SECRET_BASE_SPOT_TREE_LEFT  || behavior == MB_SECRET_BASE_SPOT_TREE_LEFT_OPEN
     || behavior == MB_SECRET_BASE_SPOT_TREE_RIGHT || behavior == MB_SECRET_BASE_SPOT_TREE_RIGHT_OPEN)
        return SECRET_BASE_HOUSE;

    if (behavior == MB_SECRET_BASE_SPOT_SHRUB || behavior == MB_SECRET_BASE_SPOT_SHRUB_OPEN)
        return SECRET_BASE_MANSION;

    return 0;
}

void GetSecretBaseTypeInFrontOfPlayer(void)
{
    gSpecialVar_0x8007 = GetSecretBaseTypeInFrontOfPlayer_();
}

static void FindMetatileIdMapCoords(s16 *x, s16 *y, u16 metatileId)
{
    s16 i, j;
    const struct MapLayout *mapLayout = gMapHeader.mapLayout;

    for (j = 0; j < mapLayout->height; j++)
    {
        for (i = 0; i < mapLayout->width; i++)
        {
            if ((mapLayout->map[j * mapLayout->width + i] & MAPGRID_METATILE_ID_MASK) == metatileId)
            {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

// Opens or closes the secret base entrance metatile in front of the player.
void ToggleSecretBaseEntranceMetatile(void)
{
    u16 i;
    s16 x, y;
    s16 metatileId;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    metatileId = MapGridGetMetatileIdAt(x, y);

    // Look for entrance metatiles to open
    for (i = 0; i < ARRAY_COUNT(sSecretBaseEntranceMetatiles); i++)
    {
        if (sSecretBaseEntranceMetatiles[i].closedMetatileId == metatileId)
        {
            MapGridSetMetatileIdAt(x, y, sSecretBaseEntranceMetatiles[i].openMetatileId | MAPGRID_IMPASSABLE);
            CurrentMapDrawMetatileAt(x, y);
            return;
        }
    }

    // Look for entrance metatiles to close
    for (i = 0; i < ARRAY_COUNT(sSecretBaseEntranceMetatiles); i++)
    {
        if (sSecretBaseEntranceMetatiles[i].openMetatileId == metatileId)
        {
            MapGridSetMetatileIdAt(x, y, sSecretBaseEntranceMetatiles[i].closedMetatileId | MAPGRID_IMPASSABLE);
            CurrentMapDrawMetatileAt(x, y);
            return;
        }
    }
}

static u8 GetNameLength(const u8 *secretBaseOwnerName)
{
    u8 i;
    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
    {
        if (secretBaseOwnerName[i] == EOS)
            return i;
    }

    return PLAYER_NAME_LENGTH;
}

void SetPlayerSecretBase(void)
{
    u16 i;

    gSaveBlock1Ptr->secretBases[0].secretBaseId = sCurSecretBaseId;
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        gSaveBlock1Ptr->secretBases[0].trainerId[i] = gSaveBlock2Ptr->playerTrainerId[i];

    VarSet(VAR_CURRENT_SECRET_BASE, 0);
    StringCopyN(gSaveBlock1Ptr->secretBases[0].trainerName, gSaveBlock2Ptr->playerName, GetNameLength(gSaveBlock2Ptr->playerName));
    gSaveBlock1Ptr->secretBases[0].gender = gSaveBlock2Ptr->playerGender;
    gSaveBlock1Ptr->secretBases[0].language = GAME_LANGUAGE;
    VarSet(VAR_SECRET_BASE_MAP, gMapHeader.regionMapSectionId);
    
    // Enable the secret base registry system
    FlagSet(FLAG_SECRET_BASE_REGISTRY_ENABLED);
}

// Set the 'open' entrance metatile for any occupied secret base on this map
void SetOccupiedSecretBaseEntranceMetatiles(struct MapEvents const *events)
{
    u16 bgId;
    u16 i, j;

    for (bgId = 0; bgId < events->bgEventCount; bgId++)
    {
        if (events->bgEvents[bgId].kind == BG_EVENT_SECRET_BASE)
        {
            for (j = 0; j < SECRET_BASES_COUNT; j++)
            {
                if (gSaveBlock1Ptr->secretBases[j].secretBaseId == events->bgEvents[bgId].bgUnion.secretBaseId)
                {
                    s16 x = events->bgEvents[bgId].x + MAP_OFFSET;
                    s16 y = events->bgEvents[bgId].y + MAP_OFFSET;
                    s16 tile_id = MapGridGetMetatileIdAt(x, y);
                    for (i = 0; i < ARRAY_COUNT(sSecretBaseEntranceMetatiles); i++)
                    {
                        if (sSecretBaseEntranceMetatiles[i].closedMetatileId == tile_id)
                        {
                            MapGridSetMetatileIdAt(x, y, sSecretBaseEntranceMetatiles[i].openMetatileId | MAPGRID_IMPASSABLE);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}

static void SetSecretBaseWarpDestination(void)
{
    s8 secretBaseGroup = SECRET_BASE_ID_TO_GROUP(sCurSecretBaseId);
    SetWarpDestinationToMapWarp(MAP_GROUP(MAP_SECRET_BASE_APARTMENT1), GET_BASE_MAP_NUM(secretBaseGroup), GET_BASE_WARP_ID(secretBaseGroup));
}

#define tState data[0]

static void Task_EnterSecretBase(u8 taskId)
{
    u16 secretBaseIdx;

    switch (gTasks[taskId].tState)
    {
    case 0:
        if (!gPaletteFade.active)
            gTasks[taskId].tState = 1;
        break;
    case 1:
        secretBaseIdx = VarGet(VAR_CURRENT_SECRET_BASE);
        if (gSaveBlock1Ptr->secretBases[secretBaseIdx].numTimesEntered < 255)
            gSaveBlock1Ptr->secretBases[secretBaseIdx].numTimesEntered++;

        SetSecretBaseWarpDestination();
        WarpIntoMap();
        gFieldCallback = FieldCB_ContinueScriptHandleMusic;
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(taskId);
        break;
    }
}

#undef tState

void EnterSecretBase(void)
{
    CreateTask(Task_EnterSecretBase, 0);
    FadeScreen(FADE_TO_BLACK, 0);
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

bool8 SecretBaseMapPopupEnabled(void)
{
    if (gMapHeader.mapType == MAP_TYPE_SECRET_BASE && VarGet(VAR_INIT_SECRET_BASE) == 0)
        return FALSE;

    return TRUE;
}

static void EnterNewlyCreatedSecretBase_WaitFadeIn(u8 taskId)
{
    ObjectEventTurn(&gObjectEvents[gPlayerAvatar.objectEventId], DIR_NORTH);
    if (IsWeatherNotFadingIn() == TRUE)
    {
        ScriptContext_Enable();
        DestroyTask(taskId);
    }
}

static void EnterNewlyCreatedSecretBase_StartFadeIn(void)
{
    s16 x = 0, y = 0;

    LockPlayerFieldControls();
    HideMapNamePopUpWindow();
    FindMetatileIdMapCoords(&x, &y, METATILE_SecretBase_PC);
    x += MAP_OFFSET;
    y += MAP_OFFSET;
    MapGridSetMetatileIdAt(x, y, METATILE_SecretBase_PC | MAPGRID_IMPASSABLE);
    CurrentMapDrawMetatileAt(x, y);
    FadeInFromBlack();
    CreateTask(EnterNewlyCreatedSecretBase_WaitFadeIn, 0);
}

static void Task_EnterNewlyCreatedSecretBase(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        s8 secretBaseGroup = SECRET_BASE_ID_TO_GROUP(sCurSecretBaseId);
        SetWarpDestination(
            gSaveBlock1Ptr->location.mapGroup,
            gSaveBlock1Ptr->location.mapNum,
            WARP_ID_NONE,
            GET_BASE_COMPUTER_X(secretBaseGroup),
            GET_BASE_COMPUTER_Y(secretBaseGroup));
        WarpIntoMap();
        gFieldCallback = EnterNewlyCreatedSecretBase_StartFadeIn;
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(taskId);
    }
}

void EnterNewlyCreatedSecretBase(void)
{
    CreateTask(Task_EnterNewlyCreatedSecretBase, 0);
    FadeScreen(FADE_TO_BLACK, 0);
}

bool8 CurMapIsSecretBase(void)
{
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_SECRET_BASE_APARTMENT1)
     && (u8)gSaveBlock1Ptr->location.mapNum <= MAP_NUM(MAP_SECRET_BASE_MANSION1))
        return TRUE;
    else
        return FALSE;
}

void InitSecretBaseAppearance(bool8 hidePC)
{
    u16 secretBaseIdx;
    s16 x, y = 0;
    u8 *decorations;
    u8 *decorPos;

    if (CurMapIsSecretBase())
    {
        secretBaseIdx = VarGet(VAR_CURRENT_SECRET_BASE);
        decorations = gSaveBlock1Ptr->secretBases[secretBaseIdx].decorations;
        decorPos = gSaveBlock1Ptr->secretBases[secretBaseIdx].decorationPositions;
        for (x = 0; x < DECOR_MAX_SECRET_BASE; x++)
        {
            if (decorations[x] > 0 && decorations[x] <= NUM_DECORATIONS && gDecorations[decorations[x]].permission != DECORPERM_SPRITE)
                ShowDecorationOnMap((decorPos[x] >> 4) + MAP_OFFSET, (decorPos[x] & 0xF) + MAP_OFFSET, decorations[x]);
        }

        if (hidePC == TRUE && VarGet(VAR_SECRET_BASE_INITIALIZED) == 1)
        {
            // Change PC to regular ground tile.
            FindMetatileIdMapCoords(&x, &y, METATILE_SecretBase_PC);
            MapGridSetMetatileIdAt(x + MAP_OFFSET, y + MAP_OFFSET, METATILE_SecretBase_Ground | MAPGRID_IMPASSABLE);
        }
    }
}

void InitSecretBaseDecorationSprites(void)
{
    u8 i;
    u8 *decorations;
    u8 *decorationPositions;
    u8 objectEventId;
    u8 metatileBehavior;
    u8 category;
    u8 permission;
    u8 numDecorations;

    objectEventId = 0;
    if (!CurMapIsSecretBase())
    {
        decorations = gSaveBlock1Ptr->playerRoomDecorations;
        decorationPositions = gSaveBlock1Ptr->playerRoomDecorationPositions;
        numDecorations = DECOR_MAX_PLAYERS_HOUSE;
    }
    else
    {
        u16 secretBaseIdx = VarGet(VAR_CURRENT_SECRET_BASE);
        decorations = gSaveBlock1Ptr->secretBases[secretBaseIdx].decorations;
        decorationPositions = gSaveBlock1Ptr->secretBases[secretBaseIdx].decorationPositions;
        numDecorations = DECOR_MAX_SECRET_BASE;
    }

    for (i = 0; i < numDecorations; i++)
    {
        if (decorations[i] == DECOR_NONE)
            continue;

        permission = gDecorations[decorations[i]].permission;
        category = gDecorations[decorations[i]].category;
        if (permission == DECORPERM_SPRITE)
        {
            for (objectEventId = 0; objectEventId < gMapHeader.events->objectEventCount; objectEventId++)
            {
                if (gMapHeader.events->objectEvents[objectEventId].flagId == FLAG_DECORATION_1 + gSpecialVar_0x8004)
                    break;
            }

            if (objectEventId == gMapHeader.events->objectEventCount)
                continue;

            gSpecialVar_0x8006 = decorationPositions[i] >> 4;
            gSpecialVar_0x8007 = decorationPositions[i] & 0xF;
            metatileBehavior = MapGridGetMetatileBehaviorAt(gSpecialVar_0x8006 + MAP_OFFSET, gSpecialVar_0x8007 + MAP_OFFSET);
            if (MetatileBehavior_HoldsSmallDecoration(metatileBehavior) == TRUE
             || MetatileBehavior_HoldsLargeDecoration(metatileBehavior) == TRUE)
            {
                gSpecialVar_Result = VAR_OBJ_GFX_ID_0 + (gMapHeader.events->objectEvents[objectEventId].graphicsId - OBJ_EVENT_GFX_VAR_0);
                VarSet(gSpecialVar_Result, gDecorations[decorations[i]].tiles[0]);
                gSpecialVar_Result = gMapHeader.events->objectEvents[objectEventId].localId;
                FlagClear(FLAG_DECORATION_1 + gSpecialVar_0x8004);
                TrySpawnObjectEvent(gSpecialVar_Result, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
                TryMoveObjectEventToMapCoords(gSpecialVar_Result, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, gSpecialVar_0x8006, gSpecialVar_0x8007);
                TryOverrideObjectEventTemplateCoords(gSpecialVar_Result, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
                if (CurMapIsSecretBase() == TRUE && VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                {
                    if (category == DECORCAT_DOLL)
                    {
                        OverrideSecretBaseDecorationSpriteScript(
                            gSpecialVar_Result,
                            gSaveBlock1Ptr->location.mapNum,
                            gSaveBlock1Ptr->location.mapGroup,
                            DECORCAT_DOLL);
                    }
                    else if (category == DECORCAT_CUSHION)
                    {
                        OverrideSecretBaseDecorationSpriteScript(
                            gSpecialVar_Result,
                            gSaveBlock1Ptr->location.mapNum,
                            gSaveBlock1Ptr->location.mapGroup,
                            DECORCAT_CUSHION);
                    }
                }

                gSpecialVar_0x8004++;
            }
        }
    }
}

void HideSecretBaseDecorationSprites(void)
{
    u8 objectEventId;
    u16 flag;

    for (objectEventId = 0; objectEventId < gMapHeader.events->objectEventCount; objectEventId++)
    {
        flag = gMapHeader.events->objectEvents[objectEventId].flagId;
        if (flag >= FLAG_DECORATION_1 && flag <= FLAG_DECORATION_14)
        {
            RemoveObjectEventByLocalIdAndMap(
                gMapHeader.events->objectEvents[objectEventId].localId,
                gSaveBlock1Ptr->location.mapNum,
                gSaveBlock1Ptr->location.mapGroup);
            FlagSet(flag);
        }
    }
}

void SetCurSecretBaseIdFromPosition(const struct MapPosition *position, const struct MapEvents *events)
{
    s16 i;
    for (i = 0; i < events->bgEventCount; i++)
    {
        if (events->bgEvents[i].kind == BG_EVENT_SECRET_BASE
          && position->x == events->bgEvents[i].x + MAP_OFFSET
          && position->y == events->bgEvents[i].y + MAP_OFFSET)
        {
            sCurSecretBaseId = events->bgEvents[i].bgUnion.secretBaseId;
            break;
        }
    }
}

void WarpIntoSecretBase(const struct MapPosition *position, const struct MapEvents *events)
{
    SetCurSecretBaseIdFromPosition(position, events);
    TrySetCurSecretBaseIndex();
    ScriptContext_SetupScript(SecretBase_EventScript_Enter);
}

bool8 TrySetCurSecretBase(void)
{
    SetCurSecretBaseId();
    TrySetCurSecretBaseIndex();
    if (gSpecialVar_Result == TRUE)
        return FALSE;

    return TRUE;
}

static void Task_WarpOutOfSecretBase(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        LockPlayerFieldControls();
        gTasks[taskId].data[0] = 1;
        break;
    case 1:
        if (!gPaletteFade.active)
            gTasks[taskId].data[0] = 2;
        break;
    case 2:
        SetWarpDestinationToDynamicWarp(WARP_ID_SECRET_BASE);
        WarpIntoMap();
        gFieldCallback = FieldCB_DefaultWarpExit;
        SetMainCallback2(CB2_LoadMap);
        UnlockPlayerFieldControls();
        DestroyTask(taskId);
        break;
    }
}

static void WarpOutOfSecretBase(void)
{
    CreateTask(Task_WarpOutOfSecretBase, 0);
    FadeScreen(FADE_TO_BLACK, 0);
}

void IsCurSecretBaseOwnedByAnotherPlayer(void)
{
    if (gSaveBlock1Ptr->secretBases[0].secretBaseId != sCurSecretBaseId)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

static u8 *GetSecretBaseName(u8 *dest, u8 secretBaseIdx)
{
    *StringCopyN(dest, gSaveBlock1Ptr->secretBases[secretBaseIdx].trainerName, GetNameLength(gSaveBlock1Ptr->secretBases[secretBaseIdx].trainerName)) = EOS;
    ConvertInternationalString(dest, gSaveBlock1Ptr->secretBases[secretBaseIdx].language);
    return StringAppend(dest, gText_ApostropheSBase);
}

u8 *GetSecretBaseMapName(u8 *dest)
{
    return GetSecretBaseName(dest, VarGet(VAR_CURRENT_SECRET_BASE));
}

void CopyCurSecretBaseOwnerName_StrVar1(void)
{
    u8 secretBaseIdx;
    const u8 *name;

    secretBaseIdx = VarGet(VAR_CURRENT_SECRET_BASE);
    name = gSaveBlock1Ptr->secretBases[secretBaseIdx].trainerName;
    *StringCopyN(gStringVar1, name, GetNameLength(name)) = EOS;
    ConvertInternationalString(gStringVar1, gSaveBlock1Ptr->secretBases[secretBaseIdx].language);
}

static bool8 IsSecretBaseRegistered(u8 secretBaseIdx)
{
    return gSaveBlock1Ptr->secretBases[secretBaseIdx].toRegister ? TRUE : FALSE;
}

static u8 GetAverageEVs(struct Pokemon *pokemon)
{
    u16 evTotal;
    evTotal  = GetMonData(pokemon, MON_DATA_HP_EV);
    evTotal += GetMonData(pokemon, MON_DATA_ATK_EV);
    evTotal += GetMonData(pokemon, MON_DATA_DEF_EV);
    evTotal += GetMonData(pokemon, MON_DATA_SPEED_EV);
    evTotal += GetMonData(pokemon, MON_DATA_SPATK_EV);
    evTotal += GetMonData(pokemon, MON_DATA_SPDEF_EV);
    return evTotal / 6;
}

void SetPlayerSecretBaseParty(void)
{
    u16 i;
    u16 moveIndex;
    u16 partyId;
    struct SecretBaseParty *party;

    partyId = 0;
    party = &gSaveBlock1Ptr->secretBases[0].party;
    if (gSaveBlock1Ptr->secretBases[0].secretBaseId)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
                party->moves[i * MAX_MON_MOVES + moveIndex] = MOVE_NONE;

            party->species[i] = SPECIES_NONE;
            party->heldItems[i] = ITEM_NONE;
            party->levels[i] = 0;
            party->personality[i] = 0;
            party->EVs[i] = 0;

            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE
            && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            {
                for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
                    party->moves[partyId * MAX_MON_MOVES + moveIndex] = GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + moveIndex);

                party->species[partyId] = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
                party->heldItems[partyId] = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);
                party->levels[partyId] = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
                party->personality[partyId] = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
                party->EVs[partyId] = GetAverageEVs(&gPlayerParty[i]);
                partyId++;
            }
        }
    }
}

void ClearAndLeaveSecretBase(void)
{
    u16 temp = gSaveBlock1Ptr->secretBases[0].numSecretBasesReceived;
    ClearSecretBase(&gSaveBlock1Ptr->secretBases[0]);
    gSaveBlock1Ptr->secretBases[0].numSecretBasesReceived = temp;
    WarpOutOfSecretBase();
}

void MoveOutOfSecretBase(void)
{
    IncrementGameStat(GAME_STAT_MOVED_SECRET_BASE);
    ClearAndLeaveSecretBase();
}

static void ClosePlayerSecretBaseEntrance(void)
{
    u16 i;
    u16 j;
    s16 metatileId;
    const struct MapEvents *events = gMapHeader.events;

    for (i = 0; i < events->bgEventCount; i++)
    {
        if (events->bgEvents[i].kind == BG_EVENT_SECRET_BASE
         && gSaveBlock1Ptr->secretBases[0].secretBaseId == events->bgEvents[i].bgUnion.secretBaseId)
        {
            metatileId = MapGridGetMetatileIdAt(events->bgEvents[i].x + MAP_OFFSET, events->bgEvents[i].y + MAP_OFFSET);
            for (j = 0; j < ARRAY_COUNT(sSecretBaseEntranceMetatiles); j++)
            {
                if (sSecretBaseEntranceMetatiles[j].openMetatileId == metatileId)
                {
                    MapGridSetMetatileIdAt(events->bgEvents[i].x + MAP_OFFSET,
                                           events->bgEvents[i].y + MAP_OFFSET,
                                           sSecretBaseEntranceMetatiles[j].closedMetatileId | MAPGRID_IMPASSABLE);
                    break;
                }
            }

            DrawWholeMapView();
            break;
        }
    }
}

// When the player moves to a new secret base by interacting with a new secret base
// entrance in the overworld.
void MoveOutOfSecretBaseFromOutside(void)
{
    u16 temp;

    ClosePlayerSecretBaseEntrance();
    IncrementGameStat(GAME_STAT_MOVED_SECRET_BASE);
    temp = gSaveBlock1Ptr->secretBases[0].numSecretBasesReceived;
    ClearSecretBase(&gSaveBlock1Ptr->secretBases[0]);
    gSaveBlock1Ptr->secretBases[0].numSecretBasesReceived = temp;
}

static u8 GetNumRegisteredSecretBases(void)
{
    s16 i;
    u8 count = 0;
    for (i = 1; i < SECRET_BASES_COUNT; i++)
    {
        if (IsSecretBaseRegistered(i) == TRUE)
            count++;
    }

    return count;
}

void GetCurSecretBaseRegistrationValidity(void)
{
    if (IsSecretBaseRegistered(VarGet(VAR_CURRENT_SECRET_BASE)) == TRUE)
        gSpecialVar_Result = 1;
    else if (GetNumRegisteredSecretBases() >= 10)
        gSpecialVar_Result = 2;
    else
        gSpecialVar_Result = 0;
}

void ToggleCurSecretBaseRegistry(void)
{
    u8 curSecretBase = VarGet(VAR_CURRENT_SECRET_BASE);
    gSaveBlock1Ptr->secretBases[curSecretBase].toRegister = !gSaveBlock1Ptr->secretBases[curSecretBase].toRegister;
}

void ShowSecretBaseDecorationMenu(void)
{
    CreateTask(DoSecretBaseDecorationMenu, 0);
}

void ShowSecretBaseRegistryMenu(void)
{
    // Registry functionality removed
}

#define tNumBases       data[0]
#define tSelectedRow    data[1]
#define tScrollOffset   data[2]
#define tMaxShownItems  data[3]
#define tSelectedBaseId data[4]
#define tListTaskId     data[5]
#define tMainWindowId   data[6]
#define tActionWindowId data[7]
#define tArrowTaskId    data[8]

#undef tNumBases
#undef tSelectedRow
#undef tScrollOffset
#undef tMaxShownItems
#undef tSelectedBaseId
#undef tListTaskId
#undef tMainWindowId
#undef tActionWindowId
#undef tArrowTaskId

#define tStepCb  data[0] // See Task_RunPerStepCallback
#define tState   data[1]
#define tPlayerX data[2]
#define tPlayerY data[3]
#define tFldEff  data[4]

void SecretBasePerStepCallback(u8 taskId)
{
    s16 x;
    s16 y;
    u8 behavior;
    u16 tileId;
    s16 *data;

    data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
        if (VarGet(VAR_CURRENT_SECRET_BASE))
            sInFriendSecretBase = TRUE;
        else
            sInFriendSecretBase = FALSE;

        PlayerGetDestCoords(&tPlayerX, &tPlayerY);
        tState = 1;
        break;
    case 1:
        // End if player hasn't moved
        PlayerGetDestCoords(&x, &y);
        if (x == tPlayerX && y == tPlayerY)
            return;

        tPlayerX = x;
        tPlayerY = y;
        VarSet(VAR_SECRET_BASE_STEP_COUNTER, VarGet(VAR_SECRET_BASE_STEP_COUNTER) + 1);
        behavior = MapGridGetMetatileBehaviorAt(x, y);
        tileId = MapGridGetMetatileIdAt(x, y);
        if (tileId == METATILE_SecretBase_SolidBoard_Top || tileId == METATILE_SecretBase_SolidBoard_Bottom)
        {
            if (sInFriendSecretBase == TRUE)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | SECRET_BASE_USED_SOLID_BOARD);
        }
        else if (tileId == METATILE_SecretBase_SmallChair
              || tileId == METATILE_SecretBase_PokemonChair
              || tileId == METATILE_SecretBase_HeavyChair
              || tileId == METATILE_SecretBase_PrettyChair
              || tileId == METATILE_SecretBase_ComfortChair
              || tileId == METATILE_SecretBase_RaggedChair
              || tileId == METATILE_SecretBase_BrickChair
              || tileId == METATILE_SecretBase_CampChair
              || tileId == METATILE_SecretBase_HardChair)
        {
            if (sInFriendSecretBase == TRUE)
                VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | SECRET_BASE_USED_CHAIR);
        }
        else if (tileId == METATILE_SecretBase_RedTent_DoorTop
              || tileId == METATILE_SecretBase_RedTent_Door
              || tileId == METATILE_SecretBase_BlueTent_DoorTop
              || tileId == METATILE_SecretBase_BlueTent_Door)
        {
            if (sInFriendSecretBase == TRUE)
                VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | SECRET_BASE_USED_TENT);
        }
        else if ((behavior == MB_IMPASSABLE_NORTHEAST && tileId == METATILE_SecretBase_Stand_CornerRight)
              || (behavior == MB_IMPASSABLE_NORTHWEST && MapGridGetMetatileIdAt(x, y) == METATILE_SecretBase_Stand_CornerLeft))
        {
            if (sInFriendSecretBase == TRUE)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | SECRET_BASE_USED_STAND);
        }
        else if (behavior == MB_IMPASSABLE_WEST_AND_EAST && tileId == METATILE_SecretBase_Slide_StairLanding)
        {
            if (sInFriendSecretBase == TRUE)
            {
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) ^ SECRET_BASE_USED_SLIDE);
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | SECRET_BASE_DECLINED_SLIDE);
            }
        }
        else if (behavior == MB_SLIDE_SOUTH && tileId == METATILE_SecretBase_Slide_SlideTop)
        {
            if (sInFriendSecretBase == TRUE)
            {
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | SECRET_BASE_USED_SLIDE);
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) ^ SECRET_BASE_DECLINED_SLIDE);
            }
        }
        else if (MetatileBehavior_IsSecretBaseGlitterMat(behavior) == TRUE)
        {
            if (sInFriendSecretBase == TRUE)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | SECRET_BASE_USED_GLITTER_MAT);
        }
        else if (MetatileBehavior_IsSecretBaseBalloon(behavior) == TRUE)
        {
            PopSecretBaseBalloon(MapGridGetMetatileIdAt(x, y), x, y);
            if (sInFriendSecretBase == TRUE)
            {
                switch ((int)MapGridGetMetatileIdAt(x, y))
                {
                case METATILE_SecretBase_RedBalloon:
                case METATILE_SecretBase_BlueBalloon:
                case METATILE_SecretBase_YellowBalloon:
                    VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | SECRET_BASE_USED_BALLOON);
                    break;
                case METATILE_SecretBase_MudBall:
                    VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | SECRET_BASE_USED_MUD_BALL);
                    break;
                }
            }
        }
        else if (MetatileBehavior_IsSecretBaseBreakableDoor(behavior) == TRUE)
        {
            if (sInFriendSecretBase == TRUE)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | SECRET_BASE_USED_BREAKABLE_DOOR);

            ShatterSecretBaseBreakableDoor(x, y);
        }
        else if (MetatileBehavior_IsSecretBaseSoundMat(behavior) == TRUE){
            if (sInFriendSecretBase == TRUE)
                VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | SECRET_BASE_USED_NOTE_MAT);
        }
        else if (MetatileBehavior_IsSecretBaseJumpMat(behavior) == TRUE)
        {
            if (sInFriendSecretBase == TRUE)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | SECRET_BASE_USED_JUMP_MAT);
        }
        else if (MetatileBehavior_IsSecretBaseSpinMat(behavior) == TRUE)
        {
            if (sInFriendSecretBase == TRUE)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | SECRET_BASE_USED_SPIN_MAT);
        }
        break;
    case 2:
        // This state is never reached, and tFldEff is never set
        if (!FieldEffectActiveListContains(tFldEff))
            tState = 1;
        break;
    }
}

#undef tStepCb
#undef tState
#undef tPlayerX
#undef tPlayerY
#undef tFldEff

void InitSecretBaseVars(void)
{
    VarSet(VAR_SECRET_BASE_STEP_COUNTER, 0);
    VarSet(VAR_SECRET_BASE_LAST_ITEM_USED, 0);
    VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, 0);
    VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, 0);
    if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
        VarSet(VAR_SECRET_BASE_IS_NOT_LOCAL, TRUE);
    else
        VarSet(VAR_SECRET_BASE_IS_NOT_LOCAL, FALSE);

    sInFriendSecretBase = FALSE;
}