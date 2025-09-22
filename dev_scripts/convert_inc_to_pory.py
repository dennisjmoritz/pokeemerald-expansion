import os
import re
import sys

# Usage: python convert_inc_to_pory.py <input.inc.orig> <output.pory>
# If run without arguments, will print usage and exit.

SCRIPT_LABEL_RE = re.compile(r"^(\w+)::")
TEXT_LABEL_RE = re.compile(r"^(\w+):")
STRING_LINE_RE = re.compile(r"^\s*\.string\s+\"(.*)\"$")

# List of event commands to help identify script blocks
EVENT_COMMANDS = [
    'lock', 'lockall', 'release', 'releaseall', 'faceplayer', 'msgbox', 'trainerbattle_single',
    'trainerbattle_no_intro', 'trainerbattle_rematch', 'call', 'goto', 'setflag', 'clearflag',
    'setvar', 'addvar', 'special', 'specialvar', 'giveitem', 'register_matchcall', 'playbgm',
    'closemessage', 'delay', 'applymovement', 'waitmovement', 'end', 'return'
]

# Helper to detect if a line is an event command
def is_event_command(line):
    return any(line.strip().startswith(cmd) for cmd in EVENT_COMMANDS)

# Convert a text block to poryscript
def convert_text_block(label, lines):
    text_content = []
    for line in lines:
        m = STRING_LINE_RE.match(line)
        if m:
            # Remove \n and $ from the string
            cleaned = m.group(1).replace('\\n', ' ').replace('$', '').strip()
            text_content.append(cleaned)
    joined = ' '.join(text_content)
    return f'text {label} {{\n    format("{joined}")\n}}\n\n'

# Convert a script block to poryscript
def convert_script_block(label, lines):
    def macro_to_pory(line):
        # Reformat case statements
        # Handle case statements with optional label after comma
        m_case_label = re.match(r'^(\s*)case\s+([A-Za-z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*$', line)
        if m_case_label:
            indent = m_case_label.group(1)
            value = m_case_label.group(2)
            label = m_case_label.group(3)
            return f'{indent}case {value}: {label}'
        m_case = re.match(r'^(\s*)case\s+([A-Za-z0-9_]+)\s*:?$', line)
        if m_case:
            indent = m_case.group(1)
            value = m_case.group(2)
            return f'{indent}case {value}:'
        # Remove lines starting with @ (comments)
        if line.lstrip().startswith('@'):
            return ''
        # Remove trailing @ and everything after
        if '@' in line:
            line = line.split('@')[0].rstrip() + '\n'
        # Remove lines that are exactly .2byte 0, .align 2, or .byte 0
        if line.strip() in ['.2byte 0', '.align 2', '.byte 0']:
            return ''
        # Handle switch statements
        m_switch = re.match(r'^(\s*)switch(?:\s*\(?([A-Za-z0-9_]+)?\)?\s*)$', line)
        if m_switch:
            indent = m_switch.group(1)
            var = m_switch.group(2)
            if var:
                return f'{indent}switch(var({var})) {{\n'
            else:
                # Malformed switch, comment out
                return f'{indent}// MALFORMED SWITCH: {line.strip()}\n'
        # Add parentheses to macro/function calls with arguments (e.g. macro arg, macro arg1, arg2)
        m_macro = re.match(r'^(\s*)(\w+)\s+([A-Za-z0-9_]+(,\s*[A-Za-z0-9_]+)*)\s*$', line)
        if m_macro:
            indent = m_macro.group(1)
            macro = m_macro.group(2)
            args = m_macro.group(3)
            # Don't parenthesize .string/.set/.2byte/.align directives
            if macro.startswith('.'):
                return line
            return f'{indent}{macro}({args})\n'
        return line

    # Reformat switch blocks: ensure cases are on new lines and close with '}'
    # If any line contains .set, wrap the block in a raw statement
    if any(l.strip().startswith('.set') for l in lines):
        raw_content = ''.join(lines)
        return f'raw `\n{raw_content}`\n\n'
    body_lines = [macro_to_pory(l) for l in lines]
    formatted_body = []
    inside_switch = False
    for line in body_lines:
        if line.strip().startswith('switch(var('):
            inside_switch = True
            formatted_body.append(line)
            continue
        if inside_switch and line.strip() == 'end':
            formatted_body.append('}\n')
            inside_switch = False
            continue
        # Ensure each case is on a new line
        if line.strip().startswith('case '):
            formatted_body.append(line + '\n')
            continue
        formatted_body.append(line)
    body = ''.join(formatted_body)
    return f'script {label} {{\n{body}}}\n\n'

# Main conversion logic
def convert_inc_to_pory(inc_path, pory_path):
    with open(inc_path, 'r', encoding='utf-8', errors='ignore') as f:
        lines = f.readlines()

    output = []
    mapscripts_block = None
    other_script_blocks = []
    text_blocks = []
    i = 0
    while i < len(lines):
        line = lines[i]
        label = None
        # Detect block label (script or text)
        script_match = SCRIPT_LABEL_RE.match(line.strip())
        text_match = TEXT_LABEL_RE.match(line.strip())
        if script_match:
            label = script_match.group(1)
        elif text_match:
            label = text_match.group(1)
        if label:
            block_lines = []
            i += 1
            while i < len(lines) and not SCRIPT_LABEL_RE.match(lines[i].strip()) and not TEXT_LABEL_RE.match(lines[i].strip()):
                block_lines.append(lines[i])
                i += 1
            if any(STRING_LINE_RE.match(l) for l in block_lines):
                text_blocks.append(convert_text_block(label, block_lines))
            elif script_match and label.endswith('_MapScripts'):
                # Only wrap this block in mapscripts
                mapscripts_block = (label, block_lines)
                other_script_blocks.append(convert_script_block(label, block_lines))
        else:
            i += 1
    # Output mapscripts block first
    if mapscripts_block:
        label, block_lines = mapscripts_block
        output.append(f"mapscripts {label} {{\n")
        for line in block_lines:
            line_stripped = line.lstrip()
            if line_stripped.startswith('@'):
                continue
            line = line.strip()
            if line.startswith('map_script'):
                # map_script MAP_SCRIPT_TYPE, ScriptLabel
                parts = line.split(',')
                if len(parts) == 2:
                    script_type = parts[0].replace('map_script', '').strip()
                    script_type = script_type if script_type else 'MAP_SCRIPT_UNKNOWN'
                    script_type = script_type.upper()
                    ref = parts[1].strip()
                    output.append(f"    {script_type}: {ref}\n")
            elif line.startswith('.byte') or not line:
                continue
            else:
                # For any other lines, output as-is (future: handle inlined or bracketed scripts)
                output.append(f"    {line}\n")
        output.append("}\n\n")
    # Output all other script blocks
    output.extend(other_script_blocks)
    # Output all text blocks after
    output.extend(text_blocks)
    with open(pory_path, 'w', encoding='utf-8') as f:
        f.writelines(output)
    print(f"Converted {inc_path} -> {pory_path} ({(1 if mapscripts_block else 0) + len(other_script_blocks) + len(text_blocks)} blocks)")

if __name__ == "__main__":
    if len(sys.argv) == 3:
        convert_inc_to_pory(sys.argv[1], sys.argv[2])
    elif len(sys.argv) == 2 and sys.argv[1] == '--batch':
        import glob
        files = glob.glob('data/maps/*/scripts.inc.orig')
        for inc_path in files:
            pory_path = inc_path.replace('.inc.orig', '.pory')
            print(f"Converting {inc_path} -> {pory_path}")
            convert_inc_to_pory(inc_path, pory_path)
    else:
        print("Usage: python convert_inc_to_pory.py <input.inc.orig> <output.pory> OR python convert_inc_to_pory.py --batch")
        sys.exit(1)
