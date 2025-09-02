# Level 50 Battle Scaling

This feature allows all trainer battles to automatically scale Pokemon levels to 50, similar to what's done in competitive Battle Frontier battles.

## How to Enable

1. Open `include/config/battle.h`
2. Change `#define B_LEVEL_50_ALL_BATTLES FALSE` to `#define B_LEVEL_50_ALL_BATTLES TRUE`
3. Recompile the game

## What It Does

When enabled, all trainer Pokemon will have their levels set to 50 during battle, regardless of their original level in the trainer data. This includes:

- **Up-scaling**: Low-level Pokemon (e.g., level 10) become level 50
- **Down-scaling**: High-level Pokemon (e.g., level 70) become level 50  
- **Preservation**: Pokemon already at level 50 stay at level 50

## What It Doesn't Affect

- **Wild Pokemon battles**: Still use original encounter levels
- **Battle Frontier**: Already has its own level scaling system
- **E-Reader battles**: Excluded from scaling
- **Trainer Hill battles**: Excluded from scaling
- **Pokemon properties**: All other properties (moves, items, abilities, etc.) are preserved

## Examples

Before enabling:
- Youngster Joey's Rattata: Level 5
- Elite Four Lance's Dragonite: Level 67

After enabling:
- Youngster Joey's Rattata: Level 50
- Elite Four Lance's Dragonite: Level 50

This creates a competitive environment where strategy and team building matter more than level differences, similar to modern competitive Pokemon formats.

## Technical Details

The implementation modifies the `CreateNPCTrainerPartyFromTrainer` function in `src/battle_main.c` to use `FRONTIER_MAX_LEVEL_50` (50) instead of the original trainer's level when the configuration is enabled.

The change is made only for regular trainer battles by checking that the battle type flags don't include frontier, e-reader, or trainer hill battles.