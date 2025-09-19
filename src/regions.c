#include "global.h"
#include "regions.h"
#include "strings.h"

// Global variable to track current map region
u32 gCurrentMapRegion = REGION_HOENN;

// Available regions for map navigation (can be expanded)
static const u32 sAvailableRegions[] = {
    REGION_HOENN,
    // Future regions can be added here
};

static const u8 *const sRegionNames[] = {
    [REGION_NONE] = gText_EmptyString2,
    [REGION_KANTO] = gText_Kanto,
    [REGION_JOHTO] = gText_Johto,
    [REGION_HOENN] = gText_Hoenn,
    [REGION_SINNOH] = gText_Sinnoh,
    [REGION_UNOVA] = gText_Unova,
    [REGION_KALOS] = gText_Kalos,
    [REGION_ALOLA] = gText_Alola,
    [REGION_GALAR] = gText_Galar,
    [REGION_HISUI] = gText_Hisui,
    [REGION_PALDEA] = gText_Paldea,
};

u32 GetCurrentRegion(void)
{
    return gCurrentMapRegion;
}

void SetCurrentMapRegion(u32 region)
{
    if (region < REGIONS_COUNT)
        gCurrentMapRegion = region;
}

bool32 HasMultipleRegionsAvailable(void)
{
    return ARRAY_COUNT(sAvailableRegions) > 1;
}

u32 GetNextAvailableRegion(u32 currentRegion)
{
    u32 i;
    
    for (i = 0; i < ARRAY_COUNT(sAvailableRegions); i++)
    {
        if (sAvailableRegions[i] == currentRegion)
        {
            return sAvailableRegions[(i + 1) % ARRAY_COUNT(sAvailableRegions)];
        }
    }
    
    // If current region not found, return first available
    return sAvailableRegions[0];
}

u32 GetPrevAvailableRegion(u32 currentRegion)
{
    u32 i;
    
    for (i = 0; i < ARRAY_COUNT(sAvailableRegions); i++)
    {
        if (sAvailableRegions[i] == currentRegion)
        {
            return sAvailableRegions[i == 0 ? ARRAY_COUNT(sAvailableRegions) - 1 : i - 1];
        }
    }
    
    // If current region not found, return first available
    return sAvailableRegions[0];
}

const u8 *GetRegionName(u32 region)
{
    if (region >= ARRAY_COUNT(sRegionNames))
        return gText_EmptyString2;
        
    return sRegionNames[region];
}