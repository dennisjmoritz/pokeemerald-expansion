#!/bin/bash
error_log="pory_compile_errors.txt"
> "$error_log"

echo "Error summary written to $error_log"


for f in data/maps/*/scripts.pory; do
    out="${f%.pory}.inc"
    err=$(./tools/poryscript/poryscript -i "$f" -o "$out" -cc tools/poryscript/command_config.json -fc tools/poryscript/font_config.json 2>&1)
    if [ $? -ne 0 ]; then
        echo "$err" | grep -i 'error' | while read -r errline; do
            lineno=$(echo "$errline" | grep -o 'line [0-9]*' | awk '{print $2}')
            if [ -n "$lineno" ]; then
                fileline=$(sed -n "${lineno}p" "$f")
                echo "$f:$lineno: $fileline" >> "$error_log"
            fi
        done
    fi
done
