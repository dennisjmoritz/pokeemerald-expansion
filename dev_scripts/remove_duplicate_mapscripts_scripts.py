import re
import sys

def remove_duplicate_mapscripts_scripts(filepath):
    with open(filepath, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    output = []
    mapscripts_names = set()
    i = 0
    while i < len(lines):
        line = lines[i]
        # Detect mapscripts block
        m_map = re.match(r'\s*mapscripts\s+(\w+)\s*{', line)
        if m_map:
            name = m_map.group(1)
            mapscripts_names.add(name)
            output.append(line)
            i += 1
            # Copy block until closing }
            while i < len(lines):
                output.append(lines[i])
                if lines[i].strip() == '}':
                    i += 1
                    break
                i += 1
            continue
        # Detect script block
        m_script = re.match(r'\s*script\s+(\w+)\s*{', line)
        if m_script and m_script.group(1) in mapscripts_names:
            # Skip this script block
            i += 1
            # Skip block until closing }
            while i < len(lines):
                if lines[i].strip() == '}':
                    i += 1
                    break
                i += 1
            continue
        # Otherwise, copy line
        output.append(line)
        i += 1

    with open(filepath, 'w', encoding='utf-8') as f:
        f.writelines(output)

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python remove_duplicate_mapscripts_scripts.py <file.pory>")
        sys.exit(1)
    remove_duplicate_mapscripts_scripts(sys.argv[1])
