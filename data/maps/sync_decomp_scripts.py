import os
import shutil

# Paths
DECOMP_MAPS = '/home/dj/Documents/Projects/PokemonMultiRegion/decomps/pokefirered/data/maps'
TARGET_MAPS = os.path.abspath(os.path.dirname(__file__))

for map_name in os.listdir(DECOMP_MAPS):
    map_dir = os.path.join(DECOMP_MAPS, map_name)
    if not os.path.isdir(map_dir):
        continue
    scripts_path = os.path.join(map_dir, 'scripts.inc')
    text_path = os.path.join(map_dir, 'text.inc')
    target_path = os.path.join(TARGET_MAPS, map_name, 'scripts.inc.orig')
    if not os.path.exists(scripts_path):
        continue
    # Ensure target directory exists
    os.makedirs(os.path.join(TARGET_MAPS, map_name), exist_ok=True)
    # Copy scripts.inc to scripts.inc.orig
    shutil.copyfile(scripts_path, target_path)
    # If text.inc exists, append it to scripts.inc.orig
    if os.path.exists(text_path):
        with open(target_path, 'a') as out_f, open(text_path, 'r') as text_f:
            out_f.write('\n')
            out_f.write(text_f.read())
print('Sync complete.')
