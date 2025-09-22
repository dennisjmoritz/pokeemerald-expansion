import os
import re
import argparse

MAPS_DIR = "data/maps"

# Regex for script labels in .inc (e.g., FooScript::)
INC_LABEL_RE = re.compile(r"^(\w+)::")
# Regex for script blocks in .pory (e.g., script FooScript { ... })
PORY_SCRIPT_RE = re.compile(r"script\s+(\w+)")

def get_script_labels_from_inc(inc_path):
    labels = set()
    with open(inc_path, "r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            m = INC_LABEL_RE.match(line.strip())
            if m:
                labels.add(m.group(1))
    return labels

def get_script_labels_from_pory(pory_path):
    labels = set()
    with open(pory_path, "r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            m = PORY_SCRIPT_RE.search(line)
            if m:
                labels.add(m.group(1))
    return labels

def remove_ported_scripts(inc_path, ported_labels):
    output_lines = []
    skip = False
    current_label = None
    with open(inc_path, "r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            m = INC_LABEL_RE.match(line.strip())
            if m:
                current_label = m.group(1)
                skip = current_label in ported_labels
            if not skip:
                output_lines.append(line)
    return output_lines

def main():
    parser = argparse.ArgumentParser(description="Generate scripts.inc.todo for all maps.")
    parser.add_argument('--dry-run', action='store_true', help='Print what would be written, do not create files')
    args = parser.parse_args()

    for map_name in os.listdir(MAPS_DIR):
        map_dir = os.path.join(MAPS_DIR, map_name)
        if not os.path.isdir(map_dir):
            continue
        inc_path = os.path.join(map_dir, "scripts.inc.orig")
        pory_path = os.path.join(map_dir, "scripts.pory")
        todo_path = os.path.join(map_dir, "scripts.inc.todo")
        if os.path.exists(inc_path) and os.path.exists(pory_path):
            inc_labels = get_script_labels_from_inc(inc_path)
            pory_labels = get_script_labels_from_pory(pory_path)
            ported_labels = pory_labels & inc_labels
            todo_lines = remove_ported_scripts(inc_path, ported_labels)
            if args.dry_run:
                print(f"--- DRY RUN: {todo_path} ({len(todo_lines)} lines) ---")
                for line in todo_lines:
                    print(line, end='')
                print(f"--- END {todo_path} ---\n")
            else:
                with open(todo_path, "w", encoding="utf-8") as f:
                    f.writelines(todo_lines)
                print(f"Wrote {todo_path} ({len(todo_lines)} lines)")

if __name__ == "__main__":
    main()
