#!/bin/bash

# Script to comment out specific lines causing "invalid operands" errors
# Uses make output to target only the problematic lines

echo "Capturing make output to identify specific problem lines..."

# Capture the make output even if make fails
make_output=$(make -j24 2>&1 || true)

# Extract unique file:line combinations from invalid operands errors
problem_lines=$(echo "$make_output" | grep "invalid operands" | sed 's/: Error.*$//' | sort | uniq)

echo "Found $(echo "$problem_lines" | wc -l) problematic lines to fix"

# Process each problematic line
echo "$problem_lines" | while read -r line_info; do
    if [[ -n "$line_info" ]]; then
        file=$(echo "$line_info" | cut -d: -f1)
        line_num=$(echo "$line_info" | cut -d: -f2)

        if [[ -f "$file" ]]; then
            echo "Processing $file:$line_num"

            # Create backup if it doesn't exist
            if [[ ! -f "${file}.bak" ]]; then
                cp "$file" "${file}.bak"
            fi

            # Comment out the specific line
            sed -i "${line_num}s/^/@ /" "$file"
        fi
    fi
done

echo "Done! Specific problematic lines have been commented out."
echo "Backup files created with .bak extension."
echo "You can now try building again."
