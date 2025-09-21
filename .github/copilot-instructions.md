# Copilot Instructions for pokeemerald-expansion

## Repository Overview

This is **pokeemerald-expansion**, a comprehensive extension of the pokeemerald decompilation project that adds modern Pokémon mechanics, battle features, and development tools to the GBA Pokémon Emerald game. This is a fork of the RHH (Rom Hacking Hideout) pokeemerald-expansion with additional custom features.

**Key Details:**
- **Project Type:** Game Boy Advance ROM hack/decompilation project
- **Primary Language:** C (with assembly and build scripts)
- **Target:** Creates `pokeemerald.gba` ROM file (24-26MB final size)
- **Build System:** GNU Make with custom toolchain (arm-none-eabi)
- **Repo Size:** ~1,000+ source files, ~200MB with graphics assets
- **Features:** Modern battle mechanics (Gen 1-9), expanded movesets, testing framework

## Required Dependencies & Environment Setup

**ALWAYS install dependencies before building:**
```bash
sudo apt update
sudo apt install -y binutils-arm-none-eabi gcc-arm-none-eabi libnewlib-arm-none-eabi libpng-dev python3 build-essential
```

**Build Dependency Check:**
- ARM cross-compiler toolchain is MANDATORY - builds will fail without it
- libpng-dev is required for graphics processing tools
- python3 needed for data generation scripts

## Build Instructions & Validation

### Basic Build Process
**ALWAYS follow this exact sequence:**
1. `make clean` - Clean any existing artifacts
2. `make tools -j4` - Build development tools (must be done first)
3. `make -j4` - Build the ROM (use parallel jobs for speed)

### Build Validation Commands
```bash
# Standard ROM build (most common)
make clean && make tools -j4 && make -j4

# Link Time Optimization build (production)
make tidy && make LTO=1 -j4

# Debug build with symbols
make tidy && make debug -j4

# Check build success
file pokeemerald.gba  # Should show: "Game Boy Advance ROM image: 'POKEMON EMER'"
```

### Build Timing & Resources
- Tools compilation: ~30-60 seconds
- Full ROM build: 2-4 minutes (depending on system)
- LTO build: 4-6 minutes (slower but optimized)
- Test compilation: 8-15 minutes (avoid unless testing specific functionality)

### Common Build Issues & Solutions
- **"arm-none-eabi-gcc: command not found"** → Install ARM toolchain dependencies
- **"png.h: No such file or directory"** → Install libpng-dev
- **Graphics tool failures** → Always run `make tools` before main build
- **Link errors with undefined symbols** → Check if trying TEST=1 without complete test environment

## Testing Framework

### Test Commands
```bash
# Build test tools (required first)
make check-tools

# Run full test suite (WARNING: Takes 10+ minutes, often unnecessary)
make check -j4

# Build test ROM (may fail with undefined symbols - this is expected)
make TEST=1 -j4
```

**Important:** The testing system is comprehensive but slow. Only run full tests when validating specific battle mechanics or game logic. Most development work should use standard ROM builds and emulator testing.

## Project Architecture & Layout

### Core Directories
```
├── src/                    # Main C source code
├── include/                # Header files and constants
│   ├── config/            # Feature configuration files (CRITICAL)
│   └── constants/         # Game constants and definitions
├── data/                   # Game data files
│   ├── maps/              # Map data and events
│   ├── scripts/           # Game script files
│   └── tilesets/          # Tileset graphics and data
├── graphics/              # All game graphics assets
├── sound/                  # Audio files and music
├── test/                   # Testing framework and test cases
└── tools/                  # Build tools and utilities
```

### Configuration System (Key Feature)
The project uses a sophisticated config system in `include/config/`:
- `battle.h` - Battle system features and mechanics
- `pokemon.h` - Pokémon data and behavior settings
- `general.h` - General game features
- `debug.h` - Debug and development features
- **ALWAYS check these files when implementing new features**

### Critical Build Files
- `Makefile` - Main build configuration
- `make_tools.mk` - Tool building configuration
- `ld_script_modern.ld` - Linker script
- `rom.sha1` - ROM checksum validation

### Data Generation
Key Python scripts that generate game data:
- `tools/wild_encounters/wild_encounters_to_header.py`
- `tools/learnset_helpers/make_learnables.py`
- `tools/trainerproc/` - Trainer team data processing

## Development & Debugging

### Debug Features Available
- Battle debug menu (in-battle modifications)
- Overworld debug system (warping, flags, item generation)
- Pokémon sprite visualizer
- Test runner with battle recording

### Making Code Changes
1. **Configuration Changes:** Edit `include/config/*.h` files for feature toggles
2. **Battle Logic:** Modify `src/battle_*.c` files
3. **Pokémon Data:** Edit `src/data/pokemon/` JSON files
4. **Graphics:** Modify files in `graphics/` directory
5. **Always test build after changes:** `make -j4`

### Common Development Patterns
- Use existing config flags to enable/disable features
- Battle mechanics follow Gen 4+ damage calculation patterns
- Pokémon data uses modern structure with expanded information
- Scripts use both traditional `.inc` files and modern `.pory` format (Poryscript)

## GitHub Actions & CI

The repository has automated builds via `.github/workflows/build.yml`:
- Tests Ubuntu environment with proper dependencies
- Runs standard build, LTO build, and test suite
- Uses `UNUSED_ERROR=1` flag (treats unused warnings as errors)
- **Ensure your changes pass CI before merging**

## Validation Checklist

Before submitting changes:
1. **Build succeeds:** `make clean && make tools -j4 && make -j4`
2. **ROM file created:** `file pokeemerald.gba` shows valid GBA ROM
3. **LTO build works:** `make tidy && make LTO=1 -j4`
4. **No new warnings:** Check build output for warnings
5. **Test in emulator:** Load ROM in GBA emulator for basic functionality

## Critical Notes for Agents

**TRUST THESE INSTRUCTIONS:** This build process has been validated. Only search for additional information if these instructions are incomplete or incorrect.

**NEVER:**
- Skip the `make tools` step
- Try to build without ARM toolchain
- Assume TEST=1 builds will work (they often fail with missing symbols)
- Modify core Makefile structure without understanding dependencies

**ALWAYS:**
- Install dependencies first
- Use parallel builds (`-j4`) for reasonable compile times
- Test both standard and LTO builds for production changes
- Check `include/config/` files when adding new features
- Clean build artifacts between major changes

**ROM Memory Constraints:**
- EWRAM: ~256KB (~87% used typically)
- IWRAM: ~32KB (~87% used typically)  
- ROM: ~32MB (~74% used typically)
- Be mindful of memory usage when adding new features

This project represents a sophisticated game engine extension with modern development practices. The build system is reliable when dependencies are met and proper procedure is followed.