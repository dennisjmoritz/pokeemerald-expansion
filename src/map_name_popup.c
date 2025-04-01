#include "global.h"
#include "battle_pyramid.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "menu.h"
#include "map_name_popup.h"
#include "palette.h"
#include "region_map.h"
#include "start_menu.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/weather.h"

// enums
enum MapPopUp_Themes
{
    MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_MARBLE,
    MAPPOPUP_THEME_STONE,
    MAPPOPUP_THEME_BRICK,
    MAPPOPUP_THEME_UNDERWATER,
    MAPPOPUP_THEME_STONE2,
};

// static functions
static void Task_MapNamePopUpWindow(u8 taskId);
static void ShowMapNamePopUpWindow(void);
static void LoadMapNamePopUpWindowBg(void);

// EWRAM
static EWRAM_DATA u8 sPopupTaskId = 0;

// .rodata
static const u8 sMapPopUp_Table[][960] =
{
    [MAPPOPUP_THEME_WOOD]       = INCBIN_U8("graphics/map_popup/wood.4bpp"),
    [MAPPOPUP_THEME_MARBLE]     = INCBIN_U8("graphics/map_popup/marble.4bpp"),
    [MAPPOPUP_THEME_STONE]      = INCBIN_U8("graphics/map_popup/stone.4bpp"),
    [MAPPOPUP_THEME_BRICK]      = INCBIN_U8("graphics/map_popup/brick.4bpp"),
    [MAPPOPUP_THEME_UNDERWATER] = INCBIN_U8("graphics/map_popup/underwater.4bpp"),
    [MAPPOPUP_THEME_STONE2]     = INCBIN_U8("graphics/map_popup/stone2.4bpp"),
};

static const u8 sMapPopUp_OutlineTable[][960] =
{
    [MAPPOPUP_THEME_WOOD]       = INCBIN_U8("graphics/map_popup/wood_outline.4bpp"),
    [MAPPOPUP_THEME_MARBLE]     = INCBIN_U8("graphics/map_popup/marble_outline.4bpp"),
    [MAPPOPUP_THEME_STONE]      = INCBIN_U8("graphics/map_popup/stone_outline.4bpp"),
    [MAPPOPUP_THEME_BRICK]      = INCBIN_U8("graphics/map_popup/brick_outline.4bpp"),
    [MAPPOPUP_THEME_UNDERWATER] = INCBIN_U8("graphics/map_popup/underwater_outline.4bpp"),
    [MAPPOPUP_THEME_STONE2]     = INCBIN_U8("graphics/map_popup/stone2_outline.4bpp"),
};

static const u16 sMapPopUp_PaletteTable[][16] =
{
    [MAPPOPUP_THEME_WOOD]       = INCBIN_U16("graphics/map_popup/wood.gbapal"),
    [MAPPOPUP_THEME_MARBLE]     = INCBIN_U16("graphics/map_popup/marble_outline.gbapal"),
    [MAPPOPUP_THEME_STONE]      = INCBIN_U16("graphics/map_popup/stone_outline.gbapal"),
    [MAPPOPUP_THEME_BRICK]      = INCBIN_U16("graphics/map_popup/brick_outline.gbapal"),
    [MAPPOPUP_THEME_UNDERWATER] = INCBIN_U16("graphics/map_popup/underwater_outline.gbapal"),
    [MAPPOPUP_THEME_STONE2]     = INCBIN_U16("graphics/map_popup/stone2_outline.gbapal"),
};

static const u16 sMapPopUp_Palette_Underwater[16] = INCBIN_U16("graphics/map_popup/underwater.gbapal");

static const u8 sRegionMapSectionId_To_PopUpThemeIdMapping[] =
{
    [MAPSEC_LITTLEROOT_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_OLDALE_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_DEWFORD_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_LAVARIDGE_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_FALLARBOR_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_VERDANTURF_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_PACIFIDLOG_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_PETALBURG_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_SLATEPORT_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_MAUVILLE_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_RUSTBORO_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_FORTREE_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_LILYCOVE_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_MOSSDEEP_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_SOOTOPOLIS_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_EVER_GRANDE_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_ROUTE_101] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_102] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_103] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_104] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_105] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_106] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_107] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_108] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_109] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_110] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_111] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_112] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_113] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_114] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_115] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_116] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_117] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_118] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_119] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_120] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_121] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_122] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_123] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_124] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_125] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_126] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_127] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_128] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_129] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_130] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_131] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_132] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_133] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_134] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_UNDERWATER_124] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_126] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_127] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_128] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_SOOTOPOLIS] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_GRANITE_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MT_CHIMNEY] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SAFARI_ZONE] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_BATTLE_FRONTIER] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_PETALBURG_WOODS] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_RUSTURF_TUNNEL] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ABANDONED_SHIP] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_NEW_MAUVILLE] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_METEOR_FALLS] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MT_PYRE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_AQUA_HIDEOUT_OLD] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SHOAL_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SEAFLOOR_CAVERN] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_SEAFLOOR_CAVERN] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_VICTORY_ROAD] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MIRAGE_ISLAND] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_CAVE_OF_ORIGIN] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SOUTHERN_ISLAND] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_FIERY_PATH] = MAPPOPUP_THEME_STONE,
    [MAPSEC_JAGGED_PASS] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_SEALED_CHAMBER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_SEALED_CHAMBER] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_SCORCHED_SLAB] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ISLAND_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_DESERT_RUINS] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ANCIENT_TOMB] = MAPPOPUP_THEME_STONE,
    [MAPSEC_INSIDE_OF_TRUCK] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_SKY_PILLAR] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SECRET_BASE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_DYNAMIC] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_PALLET_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_VIRIDIAN_CITY] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_PEWTER_CITY] = MAPPOPUP_THEME_STONE,
    [MAPSEC_CERULEAN_CITY] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_LAVENDER_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_VERMILION_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_CELADON_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_FUCHSIA_CITY] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_CINNABAR_ISLAND] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_INDIGO_PLATEAU] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_SAFFRON_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_ROUTE_1] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_2] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_3] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_4] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_5] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_6] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_ROUTE_7] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_8] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_9] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_10] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_11] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_12] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_13] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_14] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_15] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_16] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_17] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_18] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_19] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_20] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_21] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_22] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_23] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_24] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_25] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_VIRIDIAN_FOREST] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_MT_MOON] = MAPPOPUP_THEME_STONE,
    [MAPSEC_S_S_ANNE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERGROUND_PATH] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERGROUND_PATH_2] = MAPPOPUP_THEME_STONE,
    [MAPSEC_DIGLETTS_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_KANTO_VICTORY_ROAD] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_ROCKET_HIDEOUT] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_SILPH_CO] = MAPPOPUP_THEME_STONE,
    [MAPSEC_POKEMON_MANSION] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_KANTO_SAFARI_ZONE] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_POKEMON_LEAGUE] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_ROCK_TUNNEL] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SEAFOAM_ISLANDS] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_POKEMON_TOWER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_CERULEAN_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_POWER_PLANT] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_ONE_ISLAND] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_TWO_ISLAND] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_THREE_ISLAND] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_FOUR_ISLAND] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_FIVE_ISLAND] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_SEVEN_ISLAND] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_SIX_ISLAND] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_KINDLE_ROAD] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_TREASURE_BEACH] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_CAPE_BRINK] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_BOND_BRIDGE] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_THREE_ISLE_PORT] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_SEVII_ISLE_6] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_SEVII_ISLE_7] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_SEVII_ISLE_8] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_SEVII_ISLE_9] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_RESORT_GORGEOUS] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_WATER_LABYRINTH] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_FIVE_ISLE_MEADOW] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_MEMORIAL_PILLAR] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_OUTCAST_ISLAND] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GREEN_PATH] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_WATER_PATH] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_RUIN_VALLEY] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_TRAINER_TOWER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_CANYON_ENTRANCE] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_SEVAULT_CANYON] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_TANOBY_RUINS] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_MT_EMBER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_BERRY_FOREST] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ICEFALL_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ROCKET_WAREHOUSE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_TRAINER_TOWER_2] = MAPPOPUP_THEME_STONE,
    [MAPSEC_DOTTED_HOLE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_LOST_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_PATTERN_BUSH] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ALTERING_CAVE_FRLG] = MAPPOPUP_THEME_STONE,
    [MAPSEC_TANOBY_CHAMBERS] = MAPPOPUP_THEME_STONE,
    [MAPSEC_THREE_ISLE_PATH] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_TANOBY_KEY] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_MONEAN_CHAMBER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_LIPTOO_CHAMBER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_WEEPTH_CHAMBER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_DILFORD_CHAMBER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SCUFIB_CHAMBER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_RIXY_CHAMBER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_VIAPOIS_CHAMBER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_EMBER_SPA] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SPECIAL_AREA] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_AQUA_HIDEOUT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MAGMA_HIDEOUT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MIRAGE_TOWER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_BIRTH_ISLAND] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_FARAWAY_ISLAND] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ARTISAN_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MARINE_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_MARINE_CAVE] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_TERRA_CAVE] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_UNDERWATER_105] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_UNDERWATER_125] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_UNDERWATER_129] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_DESERT_UNDERPASS] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ALTERING_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_NAVEL_ROCK] = MAPPOPUP_THEME_STONE,
    [MAPSEC_TRAINER_HILL] = MAPPOPUP_THEME_STONE,
    [MAPSEC_NEW_BARK_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_CHERRYGROVE_CITY] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_30] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_ROUTE_31] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_32] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_33] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_34] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_UNION_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ILEX_FOREST] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_GOLDENROD_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_AZALEA_TOWN] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_VIOLET_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_ECRUTEAK_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_OLIVINE_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_CIANWOOD_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_MAHOGANY_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_BLACKTHORN_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_ROUTE_26] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_27] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_28] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_29] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_35] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_36] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_37] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_38] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_39] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_40] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_41] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_42] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_43] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_44] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_45] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_46] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_RUINS_OF_ALPH] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SLOWPOKE_WELL] = MAPPOPUP_THEME_STONE,
    [MAPSEC_RADIO_TOWER] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_NATIONAL_PARK] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_TIN_TOWER] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_BELL_TOWER] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_BURNED_TOWER] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_SPROUT_TOWER] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_WHIRL_ISLANDS] = MAPPOPUP_THEME_STONE,
    [MAPSEC_DARK_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MT_MORTAR] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ICE_PATH] = MAPPOPUP_THEME_STONE,
    [MAPSEC_LAKE_OF_RAGE] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_DRAGONS_DEN] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_TOHJO_FALLS] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_MT_SILVER] = MAPPOPUP_THEME_BRICK,
};

static const u8 gText_PyramidFloor1[] = _("PYRAMID FLOOR 1");
static const u8 gText_PyramidFloor2[] = _("PYRAMID FLOOR 2");
static const u8 gText_PyramidFloor3[] = _("PYRAMID FLOOR 3");
static const u8 gText_PyramidFloor4[] = _("PYRAMID FLOOR 4");
static const u8 gText_PyramidFloor5[] = _("PYRAMID FLOOR 5");
static const u8 gText_PyramidFloor6[] = _("PYRAMID FLOOR 6");
static const u8 gText_PyramidFloor7[] = _("PYRAMID FLOOR 7");
static const u8 gText_Pyramid[] = _("PYRAMID");

static const u8 * const gBattlePyramid_MapHeaderStrings[] =
{
    gText_PyramidFloor1,
    gText_PyramidFloor2,
    gText_PyramidFloor3,
    gText_PyramidFloor4,
    gText_PyramidFloor5,
    gText_PyramidFloor6,
    gText_PyramidFloor7,
    gText_Pyramid,
};

// Unused
static bool8 StartMenu_ShowMapNamePopup(void)
{
    HideStartMenu();
    ShowMapNamePopup();
    return TRUE;
}

void ShowMapNamePopup(void)
{
    if (FlagGet(FLAG_HIDE_MAP_NAME_POPUP) != TRUE)
    {
        if (!FuncIsActiveTask(Task_MapNamePopUpWindow))
        {
            sPopupTaskId = CreateTask(Task_MapNamePopUpWindow, 90);
            SetGpuReg(REG_OFFSET_BG0VOFS, 40);
            gTasks[sPopupTaskId].data[0] = 6;
            gTasks[sPopupTaskId].data[2] = 40;
        }
        else
        {
            if (gTasks[sPopupTaskId].data[0] != 2)
                gTasks[sPopupTaskId].data[0] = 2;
            gTasks[sPopupTaskId].data[3] = 1;
        }
    }
}

static void Task_MapNamePopUpWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 6:
        task->data[4]++;
        if (task->data[4] > 30)
        {
            task->data[0] = 0;
            task->data[4] = 0;
            ShowMapNamePopUpWindow();
        }
        break;
    case 0:
        task->data[2] -= 2;
        if (task->data[2] <= 0 )
        {
            task->data[2] = 0;
            task->data[0] = 1;
            gTasks[sPopupTaskId].data[1] = 0;
        }
        break;
    case 1:
        task->data[1]++;
        if (task->data[1] > 120 )
        {
            task->data[1] = 0;
            task->data[0] = 2;
        }
        break;
    case 2:
        task->data[2] += 2;
        if (task->data[2] > 39)
        {
            task->data[2] = 40;
            if (task->data[3])
            {
                task->data[0] = 6;
                task->data[4] = 0;
                task->data[3] = 0;
            }
            else
            {
                task->data[0] = 4;
                return;
            }
        }
        break;
    case 4:
        ClearStdWindowAndFrame(GetMapNamePopUpWindowId(), TRUE);
        task->data[0] = 5;
        break;
    case 5:
        HideMapNamePopUpWindow();
        return;
    }
    SetGpuReg(REG_OFFSET_BG0VOFS, task->data[2]);
}

void HideMapNamePopUpWindow(void)
{
    if (FuncIsActiveTask(Task_MapNamePopUpWindow))
    {
        ClearStdWindowAndFrame(GetMapNamePopUpWindowId(), TRUE);
        RemoveMapNamePopUpWindow();
        SetGpuReg_ForcedBlank(REG_OFFSET_BG0VOFS, 0);
        DestroyTask(sPopupTaskId);
    }
}

static void ShowMapNamePopUpWindow(void)
{
    u8 mapDisplayHeader[24];
    u8 *withoutPrefixPtr;
    u8 x;
    const u8* mapDisplayHeaderSource;

    if (InBattlePyramid())
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP)
        {
            withoutPrefixPtr = &(mapDisplayHeader[3]);
            mapDisplayHeaderSource = gBattlePyramid_MapHeaderStrings[7];
        }
        else
        {
            withoutPrefixPtr = &(mapDisplayHeader[3]);
            mapDisplayHeaderSource = gBattlePyramid_MapHeaderStrings[gSaveBlock2Ptr->frontier.curChallengeBattleNum];
        }
        StringCopy(withoutPrefixPtr, mapDisplayHeaderSource);
    }
    else
    {
        withoutPrefixPtr = &(mapDisplayHeader[3]);
        GetMapName(withoutPrefixPtr, gMapHeader.regionMapSectionId, 0);
    }
    AddMapNamePopUpWindow();
    LoadMapNamePopUpWindowBg();
    x = GetStringCenterAlignXOffset(FONT_NARROW, withoutPrefixPtr, 80);
    mapDisplayHeader[0] = EXT_CTRL_CODE_BEGIN;
    mapDisplayHeader[1] = EXT_CTRL_CODE_HIGHLIGHT;
    mapDisplayHeader[2] = TEXT_COLOR_TRANSPARENT;
    AddTextPrinterParameterized(GetMapNamePopUpWindowId(), FONT_NARROW, mapDisplayHeader, x, 3, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(GetMapNamePopUpWindowId(), COPYWIN_FULL);
}

#define TILE_TOP_EDGE_START 0x21D
#define TILE_TOP_EDGE_END   0x228
#define TILE_LEFT_EDGE_TOP  0x229
#define TILE_RIGHT_EDGE_TOP 0x22A
#define TILE_LEFT_EDGE_MID  0x22B
#define TILE_RIGHT_EDGE_MID 0x22C
#define TILE_LEFT_EDGE_BOT  0x22D
#define TILE_RIGHT_EDGE_BOT 0x22E
#define TILE_BOT_EDGE_START 0x22F
#define TILE_BOT_EDGE_END   0x23A

static void DrawMapNamePopUpFrame(u8 bg, u8 x, u8 y, u8 deltaX, u8 deltaY, u8 unused)
{
    s32 i;

    // Draw top edge
    for (i = 0; i < 1 + TILE_TOP_EDGE_END - TILE_TOP_EDGE_START; i++)
        FillBgTilemapBufferRect(bg, TILE_TOP_EDGE_START + i, i - 1 + x, y - 1, 1, 1, 14);

    // Draw sides
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_TOP,       x - 1,     y, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_TOP, deltaX + x,     y, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_MID,       x - 1, y + 1, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_MID, deltaX + x, y + 1, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_BOT,       x - 1, y + 2, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_BOT, deltaX + x, y + 2, 1, 1, 14);

    // Draw bottom edge
    for (i = 0; i < 1 + TILE_BOT_EDGE_END - TILE_BOT_EDGE_START; i++)
        FillBgTilemapBufferRect(bg, TILE_BOT_EDGE_START + i, i - 1 + x, y + deltaY, 1, 1, 14);
}

static void LoadMapNamePopUpWindowBg(void)
{
    u8 popUpThemeId;
    u8 popupWindowId = GetMapNamePopUpWindowId();
    u16 regionMapSectionId = gMapHeader.regionMapSectionId;

    // if (regionMapSectionId >= KANTO_MAPSEC_START)
    // {
    //     if (regionMapSectionId > KANTO_MAPSEC_END)
    //         regionMapSectionId -= KANTO_MAPSEC_COUNT;
    //     else
    //         regionMapSectionId = 0; // Discard kanto region sections;
    // }
    popUpThemeId = sRegionMapSectionId_To_PopUpThemeIdMapping[regionMapSectionId];

    LoadBgTiles(GetWindowAttribute(popupWindowId, WINDOW_BG), sMapPopUp_OutlineTable[popUpThemeId], 0x400, 0x21D);
    CallWindowFunction(popupWindowId, DrawMapNamePopUpFrame);
    PutWindowTilemap(popupWindowId);
    if (gMapHeader.weather == WEATHER_UNDERWATER_BUBBLES)
        LoadPalette(&sMapPopUp_Palette_Underwater, 0xE0, sizeof(sMapPopUp_Palette_Underwater));
    else
        LoadPalette(sMapPopUp_PaletteTable[popUpThemeId], 0xE0, sizeof(sMapPopUp_PaletteTable[0]));
    BlitBitmapToWindow(popupWindowId, sMapPopUp_Table[popUpThemeId], 0, 0, 80, 24);
}
