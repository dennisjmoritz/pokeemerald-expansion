# Multi-Region Map Support Implementation

## Summary
This implementation adds support for navigating between multiple region maps in the PokeNav, Fly menu, and Pokedex area screen. The changes are designed to be minimal, extensible, and backward compatible.

## Files Modified
- `include/regions.h` - Updated to support dynamic region selection
- `include/region_map.h` - Extended RegionMap struct, added L_BUTTON input
- `include/strings.h` - Added region name string declarations
- `src/strings.c` - Added region name string definitions
- `src/region_map.c` - Added region switching to fly map, L_BUTTON handling
- `src/pokenav_region_map.c` - Added region switching to PokeNav
- `src/pokedex_area_screen.c` - Added region switching to Pokedex
- `src/regions.c` - NEW: Centralized region management

## New Features

### 1. PokeNav Region Map
- **L Button**: Switch to previous region
- Cursor resets to safe position when switching regions
- Map section info updates for new region

### 2. Fly Map  
- **L Button**: Switch to previous region
- **R Button**: Switch to next region (when multiple regions available)
- Maintains existing fly logic per region

### 3. Pokedex Area Screen
- **SELECT + L**: Switch to previous region
- **SELECT + R**: Switch to next region
- Uses SELECT modifier to avoid conflict with existing navigation
- Area display updates for new region

## Architecture

### Region Management (src/regions.c)
- `gCurrentMapRegion` - Global current region state
- `sAvailableRegions[]` - Array of available regions for navigation
- `GetCurrentRegion()` - Get current region
- `SetCurrentMapRegion()` - Set current region  
- `HasMultipleRegionsAvailable()` - Check if region switching is possible
- `GetNext/PrevAvailableRegion()` - Navigate available regions

### RegionMap Structure Extension
```c
struct RegionMap {
    // ... existing fields ...
    u8 currentRegion;    // NEW: Current region being displayed
    // ... rest of structure ...
};
```

### Input Handling
- Added `MAP_INPUT_L_BUTTON` to input enumeration
- L_BUTTON handling in both full and zoomed input processing
- Region switching integrated into existing input callback system

## Installation/Usage
1. The implementation is ready to use with HOENN region by default
2. Multiple regions can be enabled by adding them to `sAvailableRegions[]` in `src/regions.c`
3. Additional regions require:
   - Region map layout data
   - Region graphics assets  
   - Region-specific encounter data for Pokedex

## Backward Compatibility
- Defaults to HOENN region (existing behavior)
- Existing save files continue to work normally
- No changes to save data structure required
- New features only activate when multiple regions are available

## Testing Status
- Implementation follows existing code patterns
- Uses standard Pokemon Emerald input handling
- Minimal changes to existing functionality
- Ready for integration testing in full build environment

## Future Extensions
To add a new region (e.g., JOHTO):
1. Add `REGION_JOHTO` to `sAvailableRegions[]` in `src/regions.c`
2. Create region map layout data (similar to `region_map_layout.h`)
3. Add region-specific graphics
4. Add region-specific wild encounter data
5. Update map section data for new region

The architecture is designed to make these additions straightforward while maintaining compatibility with existing regions.