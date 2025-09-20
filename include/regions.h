#ifndef GUARD_REGIONS_H
#define GUARD_REGIONS_H

#include "constants/regions.h"

// Global variable for current region selection in maps/UI
extern u32 gCurrentMapRegion;

u32 GetCurrentRegion(void);
void SetCurrentMapRegion(u32 region);

#endif // GUARD_REGIONS_H
