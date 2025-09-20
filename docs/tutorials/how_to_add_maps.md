# How to Add Maps

This tutorial will guide you through the process of adding new maps (areas, towns, routes, buildings) to your pokeemerald-expansion ROM hack. Maps are the foundation of your game world and understanding how to create them is essential for expanding your game.

## Content
* [Quick Summary](#quick-summary)
* [Understanding the Map System](#understanding-the-map-system)
* [File Structure](#file-structure)
* [Creating a New Map](#creating-a-new-map)
  * [1. Preparing Map Graphics](#1-preparing-map-graphics)
  * [2. Creating the Map Data](#2-creating-the-map-data)
  * [3. Adding Map Scripts](#3-adding-map-scripts)
  * [4. Registering the Map](#4-registering-the-map)
  * [5. Testing Your Map](#5-testing-your-map)
* [Advanced Topics](#advanced-topics)
* [Troubleshooting](#troubleshooting)

## Quick Summary

If you've done this before and just need a quick lookup, here's what you need to do:

1. Create map graphics (tileset, border, layout) with mapping tools like Porymap
2. Create `data/maps/YourMapName/map.json` with map configuration
3. Create `data/maps/YourMapName/scripts.inc` with map scripts and events
4. Add map constant to `include/constants/maps.h`
5. Add layout to `data/layouts/` folder
6. Register layout in `data/layouts/layouts.json`
7. Test and debug your map

## Understanding the Map System

The pokeemerald-expansion map system consists of several interconnected components:

- **Layouts**: The actual tile arrangement and collision data
- **Maps**: Configuration and metadata (connections, warps, events)
- **Scripts**: Interactive elements, NPCs, signs, and triggers
- **Graphics**: Tilesets, borders, and visual assets

### Map Types

Maps can be one of several types defined in `include/constants/map_types.h`:

- `MAP_TYPE_TOWN` - Towns and cities
- `MAP_TYPE_ROUTE` - Outdoor routes
- `MAP_TYPE_INDOOR` - Buildings and caves
- `MAP_TYPE_UNDERWATER` - Underwater areas
- `MAP_TYPE_SECRET_BASE` - Secret bases

## File Structure

Each map consists of multiple files organized in specific directories:

```
data/
├── maps/YourMapName/
│   ├── map.json          # Map configuration and events
│   └── scripts.inc       # Scripts for NPCs, signs, triggers
├── layouts/YourMapName/
│   ├── map.bin          # Layout tile arrangement
│   └── border.bin       # Border tiles
└── tilesets/            # Tileset graphics and data
```

## Creating a New Map

### 1. Preparing Map Graphics

First, you'll need to create the visual layout of your map. The recommended tool is **Porymap**, which provides a graphical interface for map editing.

#### Using Porymap
1. Download and install Porymap from [GitHub](https://github.com/huderlem/porymap)
2. Open your pokeemerald-expansion project in Porymap
3. Create a new map using an existing tileset or create a custom one
4. Design your map layout, placing tiles and collision data
5. Save the map - Porymap will generate the necessary files

#### Manual Method (Advanced)
If creating maps manually:
1. Design your layout as a grid of 16x16 pixel tiles
2. Create collision and elevation data
3. Convert to binary format using the provided tools

### 2. Creating the Map Data

Create the map configuration file at `data/maps/YourMapName/map.json`:

```json
{
  "id": "MAP_YOUR_MAP_NAME",
  "name": "YourMapName",
  "layout": "LAYOUT_YOUR_MAP_NAME",
  "music": "MUS_ROUTE101",
  "region_map_section": "MAPSEC_ROUTE_101",
  "requires_flash": false,
  "weather": "WEATHER_SUNNY",
  "map_type": "MAP_TYPE_ROUTE",
  "allow_cycling": true,
  "allow_escaping": true,
  "allow_running": true,
  "show_map_name": true,
  "battle_scene": "MAP_BATTLE_SCENE_NORMAL",
  "connections": [],
  "object_events": [],
  "warp_events": [],
  "coord_events": [],
  "bg_events": []
}
```

#### Key Configuration Options:

- **id**: Unique identifier for the map (use MAP_ prefix)
- **layout**: Reference to the layout data 
- **music**: Background music track
- **region_map_section**: Where it appears on the region map
- **weather**: Default weather condition
- **map_type**: Type of area (affects encounters, etc.)
- **connections**: Links to adjacent maps
- **object_events**: NPCs and interactive objects
- **warp_events**: Doors, stairs, cave entrances
- **coord_events**: Trigger events at specific coordinates
- **bg_events**: Signs, hidden items, background interactions

### 3. Adding Map Scripts

Create scripts for interactive elements. You can use either assembly or Poryscript:

#### Assembly Version (`data/maps/YourMapName/scripts.inc`)
```assembly
YourMapName_MapScripts::
	map_script_on_load YourMapName_OnLoad
	map_script_on_transition YourMapName_OnTransition
	.byte 0

YourMapName_OnLoad::
	# Code to run when map loads
	end

YourMapName_OnTransition::
	# Code to run during map transition
	end

# Example NPC script
YourMapName_EventScript_NPC::
	msgbox YourMapName_Text_Greeting, MSGBOX_NPC
	end

# Text definitions
YourMapName_Text_Greeting:
	.string "Hello! Welcome to this new area!$"
```

#### Poryscript Version (`data/maps/YourMapName/scripts.pory`)
```poryscript
mapscripts YourMapName_MapScripts {
    MAP_SCRIPT_ON_LOAD: YourMapName_OnLoad
    MAP_SCRIPT_ON_TRANSITION: YourMapName_OnTransition
}

script YourMapName_OnLoad {
    // Code to run when map loads
}

script YourMapName_OnTransition {
    // Code to run during map transition
}

// Example NPC script
script YourMapName_EventScript_NPC {
    msgbox("Hello! Welcome to this new area!", MSGBOX_NPC)
}
```

#### Adding NPCs to Your Map

In your `map.json`, add object events for NPCs:

```json
"object_events": [
  {
    "graphics_id": "OBJ_EVENT_GFX_BOY_1",
    "x": 10,
    "y": 5,
    "elevation": 3,
    "movement_type": "MOVEMENT_TYPE_WANDER_AROUND",
    "movement_range_x": 1,
    "movement_range_y": 1,
    "trainer_type": "TRAINER_TYPE_NONE",
    "trainer_sight_or_berry_tree_id": "0",
    "script": "YourMapName_EventScript_NPC",
    "flag": "0"
  }
]
```

### 4. Registering the Map

#### Add Map Constant
Edit `include/constants/maps.h` and add your map:

```c
#define MAP_YOUR_MAP_NAME (MAP_GROUPS_COUNT + 123)
```

Choose an unused number or add it to the appropriate map group.

#### Register Layout
Add your layout to `data/layouts/layouts.json`:

```json
{
  "id": "LAYOUT_YOUR_MAP_NAME",
  "name": "YourMapName",
  "width": 20,
  "height": 15,
  "primary_tileset": "gTileset_General",
  "secondary_tileset": "gTileset_General",
  "border_filepath": "data/layouts/YourMapName/border.bin",
  "blockdata_filepath": "data/layouts/YourMapName/map.bin",
  "has_secondary_header": false
}
```

#### Update Build Files
The map needs to be included in the build process. Add your scripts to `data/event_scripts.s`:

```assembly
.include "data/maps/YourMapName/scripts.inc"
```

### 5. Testing Your Map

#### Building the ROM
```bash
make -j$(nproc)
```

#### Testing Methods
1. **Use map warp debug feature** - Enable debugging and warp to your map
2. **Create a connection** - Link your map to an existing map for easy access
3. **Add a warp** - Place a door or entrance in an existing map that leads to yours

#### Debug Commands
If debug mode is enabled, you can use these features:
- Warp to map directly
- Display collision data
- Show map information

## Advanced Topics

### Map Connections
Link your map to adjacent areas:

```json
"connections": [
  {
    "map": "MAP_ROUTE_101",
    "offset": 0,
    "direction": "up"
  },
  {
    "map": "MAP_OLDALE_TOWN",
    "offset": -3,
    "direction": "down"
  }
]
```

### Dynamic Weather
Change weather based on story flags:

```assembly
YourMapName_OnTransition::
	call_if_set FLAG_WEATHER_CHANGED, YourMapName_SetRainyWeather
	end

YourMapName_SetRainyWeather::
	setweather WEATHER_RAIN
	return
```

### Custom Events
Add special triggers and interactions:

```json
"coord_events": [
  {
    "type": "trigger",
    "x": 12,
    "y": 8,
    "elevation": 3,
    "var": "VAR_MAP_SCENE_YOUR_MAP",
    "var_value": "0",
    "script": "YourMapName_EventScript_SpecialTrigger"
  }
]
```

### Wild Pokémon Encounters
Add wild encounters in `src/data/wild_encounters.json`:

```json
{
  "map": "MAP_YOUR_MAP_NAME",
  "base_label": "gYourMapName",
  "land_encounters": {
    "encounter_rate": 20,
    "mons": [
      {
        "min_level": 3,
        "max_level": 5,
        "species": "SPECIES_POOCHYENA"
      }
    ]
  }
}
```

## Troubleshooting

### Common Issues

**Map doesn't appear/crashes game:**
- Check that all file paths are correct
- Ensure map constant is properly defined
- Verify layout dimensions match the actual map data

**NPCs not appearing:**
- Check object_events in map.json
- Verify scripts are properly included
- Ensure graphics_id exists

**Warps not working:**
- Check destination map and warp_id exist
- Verify coordinates are within map bounds
- Ensure elevation matches

**Graphics corruption:**
- Verify tileset references are correct
- Check that graphics files exist and are properly formatted
- Ensure palette data is valid

### Debugging Tips

1. **Start simple** - Create a basic map first, then add complexity
2. **Use existing maps as reference** - Copy and modify working examples
3. **Test incrementally** - Build and test after each major change
4. **Check console output** - Look for error messages during build
5. **Use map debugging tools** - Enable debug features to inspect map data

### Performance Considerations

- Keep map sizes reasonable (larger maps use more memory)
- Optimize object event count and scripting
- Use appropriate tilesets for your map type
- Consider loading times for complex maps

## Related Tutorials

- [How to Add NPCs](how_to_add_npcs.md) - Adding characters to your maps
- [How to Add Trainers](how_to_add_trainers.md) - Creating trainer battles
- [How to Add Wild Encounters](how_to_add_wild_encounters.md) - Setting up wild Pokémon

---

*Happy mapping! Remember to backup your work and test thoroughly.*