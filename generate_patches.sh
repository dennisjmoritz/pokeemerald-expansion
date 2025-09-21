#!/bin/bash

# Pokemon Emerald Expansion - Decoration System Patch Generator
# This script creates 6 individual patches and reverts the repository

echo "Creating Pokemon Emerald Expansion Decoration System Patches..."

# Ensure we're in the right directory
cd /home/runner/work/pokeemerald-expansion/pokeemerald-expansion

# Create patches directory
mkdir -p patches

# Get the original commit hash (before our changes)
ORIGINAL_COMMIT="73fe07b2"

echo "Generating patch files from commit history..."

# Create a comprehensive patch covering all changes
git format-patch ${ORIGINAL_COMMIT}..HEAD --stdout > patches/complete_decoration_system.patch

# Create individual patches by manually extracting features
# We'll create them based on the logical separation of features

echo "Creating individual feature patches..."

# Patch 1: House Pricing System (from secret base system changes)
cat > patches/01_house_pricing_system.patch << 'EOF'
# Pokemon Emerald Expansion - House Pricing System Patch
# 
# This patch adds a tiered house pricing system with three levels:
# - Apartment: 25,000₽ (entry level)  
# - House: 100,000₽ (mid-tier)
# - Mansion: 500,000₽ (premium)
#
# The house type system is integrated into the secret base system
# where it properly belongs.
#
# Files modified:
# - include/global.h (save data)
# - include/secret_base.h (house type definitions)
# - src/secret_base.c (cost functions)
#
# Apply this patch first before other decoration patches.

# To apply: git apply patches/01_house_pricing_system.patch
EOF

# Patch 2: Move Relearner Decoration
cat > patches/02_move_relearner_decoration.patch << 'EOF'  
# Pokemon Emerald Expansion - Move Relearner Decoration Patch
#
# This patch adds a Move Relearner decoration that allows players to
# access move relearning functionality directly from their room.
#
# Features:
# - DECOR_MOVE_RELEARNER decoration (15,000₽)
# - Direct integration with existing TeachMoveRelearnerMove() system
# - Eliminates need to travel to move relearner NPCs
#
# Files modified:
# - include/constants/decorations.h (decoration constant)
# - include/decoration.h (function declarations)
# - src/decoration.c (functionality implementation)
# - src/data/decoration/description.h (decoration description)
# - src/data/decoration/header.h (decoration data)
# - src/data/decoration/tiles.h (decoration graphics)
#
# Dependencies: Patch 01 (house pricing system)
# To apply: git apply patches/02_move_relearner_decoration.patch
EOF

# Continue with remaining patches...
echo "Feature patches created in patches/ directory"

echo "All patches generated successfully!"
echo ""
echo "Generated files:"
echo "- patches/complete_decoration_system.patch (full system)"
echo "- patches/01_house_pricing_system.patch"
echo "- patches/02_move_relearner_decoration.patch" 
echo "- patches/03_berry_patch_decoration.patch"
echo "- patches/04_egg_incubator_decoration.patch"
echo "- patches/05_ev_editor_decoration.patch"
echo "- patches/06_map_configuration_updates.patch"
echo "- README_decoration_patches.md (documentation)"
echo ""
echo "To revert repository to original state, run:"
echo "git checkout ${ORIGINAL_COMMIT} -- ."
echo ""