import json
import re

# Load region_map_sections.json
with open('/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion/src/data/region_map/region_map_sections.json', 'r') as f:
    data = json.load(f)

all_names = {entry['id'][7:] for entry in data['map_sections']}  # Remove 'MAPSEC_' prefix

# Read map_name_popup.c
with open('/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion/src/map_name_popup.c', 'r') as f:
    content = f.read()

# Find present names for sMapSectionToThemeId
match = re.search(r'static const u8 sMapSectionToThemeId\[.*?\] =\s*\{(.*?)\};', content, re.DOTALL)
if match:
    block = match.group(1)
    present_sMapSection = set(re.findall(r'\[MAPSEC_(\w+)\]', block))
else:
    present_sMapSection = set()

# Find present names for sRegionMapSectionId_To_PopUpThemeIdMapping_BW
match = re.search(r'static const u8 sRegionMapSectionId_To_PopUpThemeIdMapping_BW\[\] =\s*\{(.*?)\};', content, re.DOTALL)
if match:
    block = match.group(1)
    present_BW = set(re.findall(r'\[MAPSEC_(\w+)\]', block))
else:
    present_BW = set()

missing_sMapSection = all_names - present_sMapSection
missing_BW = all_names - present_BW

print("Missing in sMapSectionToThemeId:", sorted(missing_sMapSection))
print("Missing in sRegionMapSectionId_To_PopUpThemeIdMapping_BW:", sorted(missing_BW))

# Now, add the missing ones
# For sMapSectionToThemeId, add [MAPSEC_NAME] = MAPPOPUP_THEME_WOOD,
# Find the }; for sMapSectionToThemeId
match = re.search(r'(static const u8 sMapSectionToThemeId\[.*?\] =\s*\{.*?)(\};)', content, re.DOTALL)
if match and missing_sMapSection:
    prefix = match.group(1)
    suffix = match.group(2)
    additions = '\n'.join(f'    [MAPSEC_{name}] = MAPPOPUP_THEME_WOOD,' for name in sorted(missing_sMapSection))
    new_block = prefix + additions + '\n' + suffix
    content = content.replace(match.group(0), new_block)

# For BW
match = re.search(r'(static const u8 sRegionMapSectionId_To_PopUpThemeIdMapping_BW\[\] =\s*\{.*?)(\};)', content, re.DOTALL)
if match and missing_BW:
    prefix = match.group(1)
    suffix = match.group(2)
    additions = '\n'.join(f'    [MAPSEC_{name}] = MAPPOPUP_THEME_BW_DEFAULT,' for name in sorted(missing_BW))
    new_block = prefix + additions + '\n' + suffix
    content = content.replace(match.group(0), new_block)

# Write back
with open('/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion/src/map_name_popup.c', 'w') as f:
    f.write(content)

print("Done.")
