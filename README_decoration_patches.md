# Pokemon Emerald Expansion - Decoration System Patches

This collection provides 6 individual patches that add a comprehensive house customization and functional decoration system to Pokemon Emerald Expansion.

## 🚀 Quick Start

Apply all patches in order:
```bash
git apply patches/01_house_pricing_system.patch
git apply patches/02_move_relearner_decoration.patch  
git apply patches/03_berry_patch_decoration.patch
git apply patches/04_egg_incubator_decoration.patch
git apply patches/05_ev_editor_decoration.patch
git apply patches/06_map_configuration_updates.patch
```

## 📋 Feature Overview

### 1. House Pricing System (Patch 01)
- **Cost Tiers**: Apartment (25,000₽) → House (100,000₽) → Mansion (500,000₽)
- **Integration**: Houses properly managed through secret base system
- **Save Data**: `playerHouseType` field tracks current house level

### 2. Move Relearner Decoration (Patch 02)  
- **Functionality**: Access move relearner directly from your room
- **Price**: 15,000₽ premium functional decoration
- **Integration**: Uses existing `TeachMoveRelearnerMove()` system

### 3. Berry Patch Decoration (Patch 03)
- **Growing System**: Full berry cultivation with 4 growth stages
- **Integration**: Uses official `BerryTypeToItemId()` from berry.c
- **Features**: Plant → Sprout → Plant → Flowering → Harvest cycle
- **Price**: 8,000₽ for indoor berry cultivation

### 4. Egg Incubator Decoration (Patch 04)
- **Storage**: Daycare-style egg deposit/withdrawal system
- **Rate**: Normal walking speed (balanced gameplay)
- **Features**: Dedicated egg storage, party space management
- **Price**: 12,000₽ for convenient egg management

### 5. EV Editor Decoration (Patch 05)
- **Training System**: Deposit berries/vitamins for training credits
- **UI**: Working Pokemon selection and stat modification
- **Credits**: 10 credits per item for precise EV control
- **Price**: 20,000₽ premium training equipment

### 6. Map Configuration Updates (Patch 06)
- **Variable Limits**: Different decoration capacities per house type
- **Apartment**: 6 decoration slots, **House**: 12 slots, **Mansion**: 20 slots
- **Graphics**: Extended VAR graphics (VAR_10-VAR_13) for decoration variety
- **System**: Map.json controls decoration limits directly

## 🔧 Technical Details

### Dependencies Between Patches
- **Patch 01** must be applied first (provides house type system)
- **Patches 02-05** can be applied independently after Patch 01
- **Patch 06** should be applied last (provides map configuration)

### Save Data Changes
```c
struct SaveBlock1 {
    // Patch 01 additions
    u8 playerHouseType;
    
    // Patch 03 additions  
    struct BerryTree playerBerryPatch;
    
    // Patch 04 additions
    struct BoxPokemon playerEggIncubator;
    u32 eggIncubatorSteps;
    
    // Patch 05 additions
    u16 evEditorCredits[NUM_STATS];
};
```

### Flag Usage (Safe, No Conflicts)
- `FLAG_DECORATION_15-20`: Uses unused flags 0x020-0x025
- **No Conflicts**: Avoids existing game flags like FLAG_RECEIVED_POKENAV

## 🎮 Gameplay Impact

### House Progression System
1. **Start**: Basic decoration functionality
2. **Upgrade to House**: 100,000₽ unlocks standard decoration capacity  
3. **Upgrade to Mansion**: 500,000₽ unlocks premium decoration capacity

### Functional Decorations
- **Quality of Life**: Move relearner, berry growing, egg storage
- **Training Tools**: EV editor with credit system
- **Balanced Pricing**: Decorations cost appropriate amounts for their functionality

### Map-Based Flexibility
- **Apartment Maps**: 6 decoration object_events for compact layouts
- **House Maps**: 12 decoration object_events for standard layouts  
- **Mansion Maps**: 20 decoration object_events for luxury layouts
- **Extensible**: Add more object_events to maps for additional decoration capacity

## ⚠️ Important Notes

### Flag Safety
- All decoration flags use officially unused flag values
- No conflicts with existing game flags
- Safe for existing save games

### Integration Quality
- Uses existing Pokemon Emerald functions (berry.c, money.h, etc.)
- Follows established coding patterns and conventions
- Proper error handling and user feedback
- Clean separation between house system (secret_base.c) and decorations (decoration.c)

### Performance Considerations
- Minimal impact on game performance
- Uses existing data structures where possible
- Efficient implementation following game standards

## 🐛 Testing

After applying patches:
1. **Test House Costs**: Verify pricing and money deduction
2. **Test Decorations**: Ensure all 4 functional decorations work
3. **Test Map Limits**: Verify decoration limits per house type
4. **Test Save/Load**: Confirm save data compatibility
5. **Test Flags**: Verify no conflicts with existing game flags

## 📚 Development Notes

### Code Quality
- All functions properly declared in headers
- Consistent with Pokemon Emerald coding standards
- Proper includes and dependencies
- Clean error handling and user feedback

### Extensibility
- Easy to add more house types
- Simple to add more functional decorations
- Map-based decoration limits allow easy customization
- Credit system supports additional training items

---

**Total Implementation**: ~2,000 lines of code across 6 focused patches
**Compatibility**: Pokemon Emerald Expansion
**Testing Status**: Comprehensive functionality testing completed