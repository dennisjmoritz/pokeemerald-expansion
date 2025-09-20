# How to Add Tilesets

This tutorial will guide you through adding and customizing tilesets in your pokeemerald-expansion ROM hack. Tilesets are collections of graphical tiles that define how your maps look and behave, including collision, elevation, and visual appearance.

## Content
* [Quick Summary](#quick-summary)
* [Understanding Tilesets](#understanding-tilesets)
* [Tileset Structure](#tileset-structure)
* [Creating New Tilesets](#creating-new-tilesets)
  * [1. Preparing Graphics](#1-preparing-graphics)
  * [2. Creating Metatiles](#2-creating-metatiles)
  * [3. Setting Attributes](#3-setting-attributes)
  * [4. Registering Tileset](#4-registering-tileset)
* [Tileset Types](#tileset-types)
* [Advanced Features](#advanced-features)
* [Troubleshooting](#troubleshooting)

## Quick Summary

If you've done this before and just need a quick reference:

1. Create tileset graphics (tiles.png) - 8x8 or 16x16 tiles
2. Design metatiles (16x16 arrangements of tiles)
3. Set metatile attributes (collision, elevation, behavior)
4. Add tileset data to `data/tilesets/`
5. Register tileset in tileset headers
6. Update maps to use new tileset
7. Test collision and visual appearance

## Understanding Tilesets

Tilesets in pokeemerald-expansion consist of several components:

- **Tiles**: 8x8 pixel graphics that are the basic building blocks
- **Metatiles**: 16x16 pixel combinations of 4 tiles (2x2)
- **Attributes**: Properties like collision, elevation, and special behaviors
- **Palettes**: Color data for the tiles
- **Animations**: Optional animated tile effects

### Tileset Hierarchy
- **Primary Tileset**: Basic terrain and common elements (shared across many maps)
- **Secondary Tileset**: Specific elements for certain map types (buildings, caves, etc.)

## Tileset Structure

```
data/tilesets/
├── primary/
│   └── general/                    # Common outdoor tileset
│       ├── tiles.png              # Raw tile graphics
│       ├── metatiles.bin          # Metatile arrangements
│       ├── metatile_attributes.bin # Collision and behavior data
│       ├── palettes/              # Color palettes
│       │   ├── 00.gbapal
│       │   ├── 01.gbapal
│       │   └── ...
│       └── anim/                  # Animated tiles (optional)
└── secondary/
    ├── building/                  # Indoor building tileset
    ├── cave/                      # Cave environment tileset
    └── your_custom_tileset/       # Your custom tileset
```

## Creating New Tilesets

### 1. Preparing Graphics

#### Creating Tiles
Design your tileset graphics as individual 8x8 pixel tiles:

- **Dimensions**: Each tile is 8x8 pixels
- **Format**: PNG with indexed colors
- **Palette**: Maximum 16 colors per 4bpp tile, 256 colors per 8bpp tile
- **Arrangement**: Place tiles in a grid (usually 16 tiles wide)

#### Example Tileset Layout
```
[Grass1] [Grass2] [Grass3] [Flower]
[Path1]  [Path2]  [Path3]  [Rock1]
[Tree1]  [Tree2]  [Water1] [Water2]
[House1] [House2] [Roof1]  [Roof2]
```

#### Graphics Requirements
- **Size limits**: Primary tilesets max 512 tiles, secondary max 512 tiles
- **Color depth**: 4bpp (16 colors) or 8bpp (256 colors) per tile
- **Transparency**: First color in palette is transparent
- **Consistency**: Maintain consistent art style and color usage

### 2. Creating Metatiles

Metatiles are 16x16 pixel combinations of four 8x8 tiles arranged in a 2x2 grid.

#### Metatile Design Process
1. **Plan combinations**: Decide which tiles form logical 16x16 blocks
2. **Create variety**: Make multiple variations of similar terrain
3. **Consider transitions**: Create tiles that connect smoothly
4. **Test patterns**: Ensure tiles tile seamlessly when repeated

#### Metatile Data Format
The `metatiles.bin` file stores metatile arrangements:
```
Metatile 0: [TileID_TopLeft][TileID_TopRight][TileID_BottomLeft][TileID_BottomRight]
Metatile 1: [TileID_TopLeft][TileID_TopRight][TileID_BottomLeft][TileID_BottomRight]
...
```

#### Example Metatile Arrangement
```c
// Grass metatile (ID 0)
.byte 0x00, 0x01  // Top row: Grass tiles 0, 1  
.byte 0x10, 0x11  // Bottom row: Grass tiles 16, 17

// Tree metatile (ID 1) 
.byte 0x08, 0x09  // Top row: Tree top tiles
.byte 0x18, 0x19  // Bottom row: Tree trunk tiles
```

### 3. Setting Attributes

Each metatile has attributes that define its behavior:

#### Collision Types
- `METATILE_COLLISION_NORMAL`: Walkable terrain
- `METATILE_COLLISION_IMPASSABLE`: Solid objects (walls, trees)
- `METATILE_COLLISION_WATER`: Water tiles (requires Surf)
- `METATILE_COLLISION_LEDGE`: Ledges (can jump down)

#### Elevation Levels
- `0`: Sea level / basement
- `1`: Ground level
- `2`: Second floor  
- `3`: Standard walking height
- Higher values for elevated terrain

#### Special Behaviors
- `METATILE_BEHAVIOR_TALL_GRASS`: Wild Pokémon encounters
- `METATILE_BEHAVIOR_WATER`: Surfing, fishing
- `METATILE_BEHAVIOR_DOOR`: Automatic door opening
- `METATILE_BEHAVIOR_COUNTER`: Can be interacted with from front

#### Creating Attributes File
```c
// Example metatile_attributes.bin content
.byte METATILE_COLLISION_NORMAL,   0x00, 0x03, METATILE_BEHAVIOR_NORMAL      // Grass
.byte METATILE_COLLISION_IMPASSABLE, 0x00, 0x03, METATILE_BEHAVIOR_NORMAL    // Tree  
.byte METATILE_COLLISION_WATER,    0x00, 0x00, METATILE_BEHAVIOR_WATER       // Water
.byte METATILE_COLLISION_NORMAL,   0x00, 0x03, METATILE_BEHAVIOR_TALL_GRASS  // Tall grass
```

### 4. Registering Tileset

#### Create Tileset Data Structure
Add your tileset to the tileset headers:

```c
// In tileset header file
const struct Tileset gTileset_YourCustomTileset = 
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,  // TRUE for secondary tilesets
    .tiles = gTilesetTiles_YourCustomTileset,
    .palettes = gTilesetPalettes_YourCustomTileset,
    .metatiles = gTilesetMetatiles_YourCustomTileset,
    .metatileAttributes = gTilesetMetatileAttributes_YourCustomTileset,
    .callback = InitTilesetAnim_YourCustomTileset,  // NULL if no animations
};
```

#### Graphics Data Registration
Register the graphics data:

```c
// In graphics file
const u32 gTilesetTiles_YourCustomTileset[] = INCBIN_U32("data/tilesets/your_custom_tileset/tiles.4bpp.lz");
const u16 gTilesetPalettes_YourCustomTileset[] = INCBIN_U16("data/tilesets/your_custom_tileset/palettes/00.gbapal");
const u16 gTilesetMetatiles_YourCustomTileset[] = INCBIN_U16("data/tilesets/your_custom_tileset/metatiles.bin");
const u32 gTilesetMetatileAttributes_YourCustomTileset[] = INCBIN_U32("data/tilesets/your_custom_tileset/metatile_attributes.bin");
```

#### Tileset Constants
Define constants for your tileset:

```c
// In tileset constants header
#define TILESET_YOUR_CUSTOM_TILESET 50  // Use available ID

// Metatile constants for easy reference
#define METATILE_YourCustomTileset_Grass       0x000
#define METATILE_YourCustomTileset_Tree        0x001
#define METATILE_YourCustomTileset_Water       0x002
#define METATILE_YourCustomTileset_TallGrass   0x003
```

## Tileset Types

### Primary Tilesets

Primary tilesets contain basic terrain elements shared across many maps:

#### General Outdoor Tileset
- Grass, dirt, stone paths
- Basic trees and rocks
- Water and shoreline tiles
- Common decorative elements

```c
const struct Tileset gTileset_General = 
{
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_General,
    .palettes = gTilesetPalettes_General,
    // ... other data
};
```

#### Creating Custom Primary Tileset
```c
const struct Tileset gTileset_YourPrimaryTileset = 
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_YourPrimaryTileset,
    .palettes = gTilesetPalettes_YourPrimaryTileset,
    .metatiles = gTilesetMetatiles_YourPrimaryTileset,
    .metatileAttributes = gTilesetMetatileAttributes_YourPrimaryTileset,
    .callback = NULL,
};
```

### Secondary Tilesets

Secondary tilesets add specific elements for certain map types:

#### Building Interior Tileset
- Wall and floor tiles
- Furniture and decorations
- Doors and windows
- Indoor-specific objects

#### Cave Tileset  
- Rock walls and formations
- Cave floors and paths
- Underground water
- Crystal formations

#### Custom Secondary Tileset
```c
const struct Tileset gTileset_YourSecondaryTileset = 
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,  // This is a secondary tileset
    .tiles = gTilesetTiles_YourSecondaryTileset,
    .palettes = gTilesetPalettes_YourSecondaryTileset,
    .metatiles = gTilesetMetatiles_YourSecondaryTileset,
    .metatileAttributes = gTilesetMetatileAttributes_YourSecondaryTileset,
    .callback = NULL,
};
```

### Using Tilesets in Maps

Assign tilesets to your maps in the map JSON:

```json
{
  "id": "MAP_YOUR_CUSTOM_AREA",
  "name": "YourCustomArea", 
  "layout": "LAYOUT_YOUR_CUSTOM_AREA",
  "music": "MUS_ROUTE101",
  "primary_tileset": "gTileset_General",
  "secondary_tileset": "gTileset_YourCustomTileset"
}
```

## Advanced Features

### Animated Tiles

Add movement and life to your tilesets with animations:

#### Creating Animation Frames
1. Create multiple versions of animated tiles
2. Place them sequentially in your tileset
3. Set up animation callback function

#### Animation Callback
```c
void InitTilesetAnim_YourCustomTileset(void)
{
    // Animate water tiles (frames 0x20-0x23)
    StartTilesetAnimation(0x20, 0x23, 30, TRUE);  // 30 frame delay, loop
    
    // Animate flower tiles (frames 0x30-0x31)
    StartTilesetAnimation(0x30, 0x31, 120, TRUE); // Slower animation
}
```

#### Animation Types
- **Water effects**: Flowing water, ripples
- **Nature elements**: Swaying grass, rustling leaves
- **Mechanical objects**: Spinning gears, blinking lights
- **Weather effects**: Falling rain, snow accumulation

### Palette Animation

Change colors over time for dynamic effects:

```c
void UpdateTilesetPalette_YourCustomTileset(void)
{
    // Cycle through colors for animated elements
    if (++sPaletteAnimFrame > 60)
    {
        sPaletteAnimFrame = 0;
        CyclePaletteColors(PAL_BG_0, 1, 3);  // Rotate colors 1-3 in palette 0
    }
}
```

### Terrain Tags

Add special terrain properties:

```c
// Terrain tag definitions
#define TERRAIN_GRASS          0
#define TERRAIN_SAND          1  
#define TERRAIN_SNOW          2
#define TERRAIN_YOUR_CUSTOM   10

// Set terrain tags in metatile attributes
.byte METATILE_COLLISION_NORMAL, TERRAIN_YOUR_CUSTOM, 0x03, METATILE_BEHAVIOR_NORMAL
```

Use terrain tags for:
- Different footstep sounds
- Weather interactions  
- Move effects (like Camouflage)
- Environmental storytelling

## Troubleshooting

### Common Issues

**Tileset not appearing:**
- Check file paths and names match exactly
- Verify graphics are properly included in build
- Ensure tileset constants are defined correctly
- Check map assignment of primary/secondary tilesets

**Collision problems:**
- Verify metatile attributes are set correctly
- Check collision constants are used properly
- Test walkable areas thoroughly
- Ensure elevation values are consistent

**Graphics corruption:**
- Check tile dimensions (must be 8x8 pixels)
- Verify palette limits (16 colors for 4bpp)
- Ensure graphics conversion is working
- Check for palette conflicts between tilesets

**Animation issues:**
- Verify animation callback is registered
- Check frame sequence and timing
- Ensure animated tiles are placed correctly
- Test animation performance impact

### Debug Tips

1. **Start with simple tilesets** - Basic colors and shapes first
2. **Test incrementally** - Add metatiles one at a time
3. **Use existing tilesets as reference** - Study working examples
4. **Check memory usage** - Monitor ROM space consumption
5. **Test on actual hardware** - Verify performance and appearance

### Performance Optimization

#### Graphics Optimization
- **Compress tileset graphics** to save ROM space
- **Reuse tiles** where possible to reduce redundancy
- **Optimize palette usage** across primary/secondary tilesets
- **Limit animation complexity** to maintain performance

#### Memory Management
- Keep tileset sizes reasonable
- Consider loading times for complex tilesets
- Monitor VRAM usage during gameplay
- Use compressed graphics when possible

## Related Tutorials

- [How to Add Maps](how_to_add_maps.md) - Using tilesets in maps
- [Graphics System](graphics_system.md) - Understanding game graphics
- [Animation System](animation_system.md) - Creating animated effects
- [Performance Optimization](performance_optimization.md) - Optimizing graphics

---

*Well-designed tilesets are the foundation of beautiful maps. Take time to create cohesive, functional tile collections that enhance your world's atmosphere!*