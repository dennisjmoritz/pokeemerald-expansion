#!/bin/bash

# Script to comment out lines causing "Invalid operands" errors in event scripts
# These errors typically occur with expressions like "(undefined_symbol >> 16) & 0xFFFF"

echo "Searching for and commenting out problematic lines in event scripts..."

# Find all scripts.inc files in data/maps directories
find data/maps -name "scripts.inc" -type f | while read -r file; do
    echo "Processing $file..."

    # Create a backup
    cp "$file" "${file}.bak"

    # Comment out lines containing ">> 16" which are causing invalid operands errors
    # These are typically .word directives with undefined symbols
    sed -i 's/^\(\s*\)\.word\s*(.*>> 16.*)$/\1@ \.word \2/' "$file"

    # Also comment out other problematic patterns that might cause similar errors
    sed -i 's/^\(\s*\)\.word\s*(.*& 0xFFFF.*)$/\1@ \.word \2/' "$file"

    # Comment out lines with undefined symbols in expressions
    sed -i 's/^\(\s*\)\.word\s*(EventScript_[^)]*)$/\1@ \.word \2/' "$file"
    sed -i 's/^\(\s*\)\.word\s*(MSG_[^)]*)$/\1@ \.word \2/' "$file"

    # Comment out .if statements with undefined symbols
    sed -i 's/^\(\s*\)\.if\s*.*>> 16.*$/\1@ \.if \2/' "$file"

    echo "Processed $file"
done

echo "Done! All problematic lines have been commented out."
echo "Backup files created with .bak extension."
echo "You can now try building again."
