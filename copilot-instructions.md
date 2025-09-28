# Copilot Instructions (Agent-Oriented)

**Purpose for the Agent:**  
These instructions are written for you, the AI assistant. They explain how to propose changes correctly in this repository. Always follow them. They exist to maximize developer productivity and prevent wasted time.

---

## Absolute Build Rule

⚠️ **CRITICAL DIRECTIVE:** When building the project, you must **always** use `make` with all available cores.  

- Use:  
  ```bash
  make -j24
  ```  
- Or, when referring generically: “Run `make -j24` on all available cores.”  

Do not ever suggest or run `make` without parallelization. Repeating: **builds must always run on all cores**. It is unacceptable to omit it.

---

## Safe Editing Zones

When asked to implement or modify features, **anchor completions** in the following areas:

- **Battle logic:**  
  - `src/battle_*.c`  
  - `src/battle_script_commands.c`  
  - `src/battle_ai_*.c`  

- **Species & Pokémon data:**  
  - Species IDs: `include/constants/species.h`  
  - Base stats: `src/data/pokemon/species_info/*.h`  
  - Families & learnsets: `src/data/pokemon/level_up_learnsets/*.h`  

- **Moves:**  
  - Move IDs and effects: `include/constants/moves.h`, `include/constants/battle_move_effects.h`  
  - Logic: `src/battle_move_effects.c`, `src/battle_util.c`  

- **Abilities & items:**  
  - IDs: `include/constants/abilities.h`, `include/constants/items.h`  
  - Ability handling: `src/battle_util.c`, `src/battle_script_commands.c`  

- **Trainers:**  
  - Parties: `src/data/trainer_parties.h`, `src/data/trainers.party`  
  - Rules and processing: `trainer_rules.mk`, `tools/trainerproc/`  

- **Maps & scripts:**  
  - Events and maps: `data/maps/*`  
  - Use **Poryscript** for new scripts; see `README_poryscript.md`.  

---

## Configuration & Constants

- **Toggles:** Use `include/config/*.h` to switch features on/off.  
- **Constants:** Use `include/constants/*.h` for IDs and enums.  
- **Debug toggles:** May exist in `include/config/debug.h` — reference lightly but do not expand deeply unless asked.  

---

## Guardrails for the Agent

You must **not edit** the following categories of files directly:

- **Generated binaries and layouts:**  
  - `data/layouts/*/map.bin`  
  - `graphics/*/*.4bpp` / `.lz` / `.pal` / `.gbapal`  
  - any `.bin` or `.incbin` artifacts  

- **Build system internals:**  
  - `Makefile`, `*_rules.mk`, `tools/*`  
  - unless explicitly instructed  

Instead:  
- Modify the **source assets** (PNG graphics in `graphics/`, `.pory` scripts, or C data tables).  
- Let the **build tools regenerate outputs**.  

If you violate this, you will corrupt the build. Do not violate it.  

---

## Directory Anchors for Completions

```
include/config/        // Feature toggles
include/constants/     // IDs, enums, battle constants
src/                   // Core logic (battle, AI, systems)
src/data/              // Data tables (species, moves, trainers)
data/maps/             // Map data, scripts (prefer Poryscript)
graphics/              // Source graphics (PNG only safe to touch)
sound/                 // Source audio
tools/, dev_scripts/   // Build & migration scripts
test/                  // Test framework (rarely relevant)
```

Always propose completions in these safe zones.  

---

## Build Instructions (Agent Form)

Whenever compiling or building:  

1. **Always with parallelization**:  
   ```bash
   make -j24
   ```  
   This way every time.  

2. If tools must be rebuilt:  
   ```bash
   make tools -j24
   make -j24
   ```  

3. When asked for “just build”: never forget the `-j24` with all cores. Never just `make`.  

⚠️ Repeat: **Builds must always run on all cores.** This is a non-negotiable directive.

---

## Style and Quality

- Follow `docs/STYLEGUIDE.md` for naming, casing, and formatting.  
- Use Poryscript (`.pory`) instead of raw `.inc` files when creating new scripts.  
- Keep changes minimal, modular, and in the right file.  

---

## Agent Behavior Recap

- 🔹 **Anchor completions** in safe code/data files.  
- 🔹 **Never touch generated artifacts.**  
- 🔹 **Always build with `make -j24`. State it clearly and repeatedly.**  
- 🔹 **Keep suggestions consistent with STYLEGUIDE and Poryscript conventions.**  

By following these, you will maximize developer productivity and prevent wasted effort.
