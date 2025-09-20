#include "global.h"
#include "ev_editor.h"
#include "battle.h"
#include "bg.h"
#include "decompress.h"
#include "field_message_box.h"
#include "gpu_regs.h"
#include "item.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "window.h"
#include "event_data.h"
#include "constants/party_menu.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/vars.h"

#define EV_POINTS_PER_VITAMIN 10
#define EV_POINTS_PER_BERRY 10
#define MAX_EV_PER_STAT 252
#define MAX_TOTAL_EVS 510

struct EVEditorMenu
{
    MainCallback savedCallback;
    u8 selectedMon;
    u8 selectedStat;
    u16 availableCredits;
    u8 originalEVs[NUM_STATS];
    u8 windowIds[4];
    u8 listMenuId;
};

enum {
    STAT_HP,
    STAT_ATK,
    STAT_DEF,
    STAT_SPATK,
    STAT_SPDEF,
    STAT_SPEED,
    NUM_STATS
};

static EWRAM_DATA struct EVEditorMenu *sEVEditor = NULL;

// Menu strings
static const u8 sText_SelectStat[] = _("Select stat to modify:");
static const u8 sText_HPEVs[] = _("HP EVs: {STR_VAR_1}/252");
static const u8 sText_AtkEVs[] = _("Attack EVs: {STR_VAR_1}/252");
static const u8 sText_DefEVs[] = _("Defense EVs: {STR_VAR_1}/252");
static const u8 sText_SpAtkEVs[] = _("Sp. Atk EVs: {STR_VAR_1}/252");
static const u8 sText_SpDefEVs[] = _("Sp. Def EVs: {STR_VAR_1}/252");
static const u8 sText_SpeedEVs[] = _("Speed EVs: {STR_VAR_1}/252");
static const u8 sText_TotalEVs[] = _("Total: {STR_VAR_1}/510");
static const u8 sText_CreditsLeft[] = _("EV Points: {STR_VAR_1}");
static const u8 sText_IncreaseStat[] = _("+ Increase");
static const u8 sText_DecreaseStat[] = _("- Decrease");
static const u8 sText_Reset[] = _("Reset");
static const u8 sText_Done[] = _("Done");
static const u8 sText_Cancel[] = _("Cancel");

static const struct ListMenuItem sEVStatMenuItems[] =
{
    {sText_HPEVs, STAT_HP},
    {sText_AtkEVs, STAT_ATK},
    {sText_DefEVs, STAT_DEF},
    {sText_SpAtkEVs, STAT_SPATK},
    {sText_SpDefEVs, STAT_SPDEF},
    {sText_SpeedEVs, STAT_SPEED},
    {sText_Done, NUM_STATS},
    {sText_Cancel, NUM_STATS + 1},
};

static const struct ListMenuItem sEVActionMenuItems[] =
{
    {sText_IncreaseStat, 0},
    {sText_DecreaseStat, 1},
    {sText_Reset, 2},
    {sText_Cancel, 3},
};

static const struct ListMenuTemplate sEVStatMenuTemplate =
{
    .items = sEVStatMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sEVStatMenuItems),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static void CB2_EVEditor(void);
static void EVEditor_RunMenus(void);
static void EVEditor_HandleInput(u8 taskId);
static u16 EVEditor_GetCurrentEV(u8 stat);
static void EVEditor_SetCurrentEV(u8 stat, u16 value);
static u16 EVEditor_GetTotalEVs(void);
static void EVEditor_RefreshDisplay(void);
static void EVEditor_ExitToField(void);
static void EVEditor_ApplyChanges(void);

bool8 EVEditor_LoadCreditsFromBag(void)
{
    u16 creditsToAdd = 0;
    
    // Check for vitamins and convert them to credits
    u16 vitamins[] = {
        ITEM_HP_UP, ITEM_PROTEIN, ITEM_IRON, ITEM_CALCIUM, ITEM_ZINC, ITEM_CARBOS
    };
    
    // Check for EV-reducing berries and convert them to credits
    u16 evBerries[] = {
        ITEM_POMEG_BERRY, ITEM_KELPSY_BERRY, ITEM_QUALOT_BERRY,
        ITEM_HONDEW_BERRY, ITEM_GREPA_BERRY, ITEM_TAMATO_BERRY
    };
    
    // Process vitamins (10 credits each)
    u32 i;
    for (i = 0; i < ARRAY_COUNT(vitamins); i++)
    {
        u16 quantity = GetBagItemQuantity(vitamins[i]);
        if (quantity > 0)
        {
            creditsToAdd += quantity * EV_POINTS_PER_VITAMIN;
            RemoveBagItem(vitamins[i], quantity);
        }
    }
    
    // Process EV berries (10 credits each)
    for (i = 0; i < ARRAY_COUNT(evBerries); i++)
    {
        u16 quantity = GetBagItemQuantity(evBerries[i]);
        if (quantity > 0)
        {
            creditsToAdd += quantity * EV_POINTS_PER_BERRY;
            RemoveBagItem(evBerries[i], quantity);
        }
    }
    
    if (creditsToAdd == 0)
        return FALSE;
        
    // Store credits in the EV editor system (capped at 999 for display purposes)
    u16 currentCredits = VarGet(VAR_EV_EDITOR_CREDITS);
    u16 newTotal = currentCredits + creditsToAdd;
    if (newTotal > 999)
        newTotal = 999;
    
    VarSet(VAR_EV_EDITOR_CREDITS, newTotal);
    
    return TRUE;
}

bool8 EVEditor_HasEVItems(void)
{
    u16 vitamins[] = {
        ITEM_HP_UP, ITEM_PROTEIN, ITEM_IRON, ITEM_CALCIUM, ITEM_ZINC, ITEM_CARBOS
    };
    
    u16 evBerries[] = {
        ITEM_POMEG_BERRY, ITEM_KELPSY_BERRY, ITEM_QUALOT_BERRY,
        ITEM_HONDEW_BERRY, ITEM_GREPA_BERRY, ITEM_TAMATO_BERRY
    };
    
    u32 i;
    for (i = 0; i < ARRAY_COUNT(vitamins); i++)
    {
        if (GetBagItemQuantity(vitamins[i]) > 0)
            return TRUE;
    }
    
    for (i = 0; i < ARRAY_COUNT(evBerries); i++)
    {
        if (GetBagItemQuantity(evBerries[i]) > 0)
            return TRUE;
    }
    
    return FALSE;
}

u16 EVEditor_GetAvailableCredits(void)
{
    return VarGet(VAR_EV_EDITOR_CREDITS);
}
{
    return VarGet(VAR_EV_EDITOR_CREDITS);
}

void EVEditor_ConsumeCredits(u16 amount)
{
    u16 current = VarGet(VAR_EV_EDITOR_CREDITS);
    if (current >= amount)
        VarSet(VAR_EV_EDITOR_CREDITS, current - amount);
}

void EVEditor_OpenFromPartyMenu(u8 monIndex)
{
    if (EVEditor_GetAvailableCredits() == 0)
    {
        ShowFieldMessage(gText_NoEVCredits);
        return;
    }
    
    sEVEditor = AllocZeroed(sizeof(struct EVEditorMenu));
    sEVEditor->selectedMon = monIndex;
    sEVEditor->selectedStat = 0;
    sEVEditor->availableCredits = EVEditor_GetAvailableCredits();
    sEVEditor->savedCallback = CB2_ReturnToPartyMenuFromFieldMove;
    
    // Store original EVs for cancel functionality
    sEVEditor->originalEVs[STAT_HP] = GetMonData(&gPlayerParty[monIndex], MON_DATA_HP_EV);
    sEVEditor->originalEVs[STAT_ATK] = GetMonData(&gPlayerParty[monIndex], MON_DATA_ATK_EV);
    sEVEditor->originalEVs[STAT_DEF] = GetMonData(&gPlayerParty[monIndex], MON_DATA_DEF_EV);
    sEVEditor->originalEVs[STAT_SPATK] = GetMonData(&gPlayerParty[monIndex], MON_DATA_SPATK_EV);
    sEVEditor->originalEVs[STAT_SPDEF] = GetMonData(&gPlayerParty[monIndex], MON_DATA_SPDEF_EV);
    sEVEditor->originalEVs[STAT_SPEED] = GetMonData(&gPlayerParty[monIndex], MON_DATA_SPEED_EV);
    
    SetMainCallback2(CB2_EVEditor);
}

static void CB2_EVEditor(void)
{
    EVEditor_RunMenus();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void EVEditor_RunMenus(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        // Handle menu selection based on current state
        PlaySE(SE_SELECT);
        // Implementation would continue here...
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        EVEditor_ExitToField();
    }
}

static u16 EVEditor_GetCurrentEV(u8 stat)
{
    u32 monDataIndex;
    switch (stat)
    {
    case STAT_HP: monDataIndex = MON_DATA_HP_EV; break;
    case STAT_ATK: monDataIndex = MON_DATA_ATK_EV; break;
    case STAT_DEF: monDataIndex = MON_DATA_DEF_EV; break;
    case STAT_SPATK: monDataIndex = MON_DATA_SPATK_EV; break;
    case STAT_SPDEF: monDataIndex = MON_DATA_SPDEF_EV; break;
    case STAT_SPEED: monDataIndex = MON_DATA_SPEED_EV; break;
    default: return 0;
    }
    
    return GetMonData(&gPlayerParty[sEVEditor->selectedMon], monDataIndex);
}

static void EVEditor_SetCurrentEV(u8 stat, u16 value)
{
    u32 monDataIndex;
    u8 evValue = (u8)value;
    
    switch (stat)
    {
    case STAT_HP: monDataIndex = MON_DATA_HP_EV; break;
    case STAT_ATK: monDataIndex = MON_DATA_ATK_EV; break;
    case STAT_DEF: monDataIndex = MON_DATA_DEF_EV; break;
    case STAT_SPATK: monDataIndex = MON_DATA_SPATK_EV; break;
    case STAT_SPDEF: monDataIndex = MON_DATA_SPDEF_EV; break;
    case STAT_SPEED: monDataIndex = MON_DATA_SPEED_EV; break;
    default: return;
    }
    
    SetMonData(&gPlayerParty[sEVEditor->selectedMon], monDataIndex, &evValue);
}

static u16 EVEditor_GetTotalEVs(void)
{
    u16 total = 0;
    u8 i;
    
    for (i = 0; i < NUM_STATS; i++)
        total += EVEditor_GetCurrentEV(i);
        
    return total;
}

static void EVEditor_ApplyChanges(void)
{
    CalculateMonStats(&gPlayerParty[sEVEditor->selectedMon]);
    GetMonData(&gPlayerParty[sEVEditor->selectedMon], MON_DATA_NICKNAME, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_EVsModified);
    ShowFieldMessage(gStringVar4);
}

static void EVEditor_ExitToField(void)
{
    FREE_AND_SET_NULL(sEVEditor);
    SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
}