#!/bin/bash

# Test script to demonstrate the parsing logic for invalid operands errors

echo "Testing parsing logic..."

# Test the parsing with sample error lines
test_lines="data/maps/FiveIsland_Harbor/scripts.inc:160: Error: invalid operands (*UND* and *ABS* sections) for \`>>'
data/maps/FourIsland_Harbor/scripts.inc:11: Error: invalid operands (*UND* and *ABS* sections) for \`>>'
data/maps/ThreeIsland_Harbor/scripts.inc:133: Error: invalid operands (*UND* and *ABS* sections) for \`&'"

echo "Test input lines:"
echo "$test_lines"
echo ""

# Extract file:line combinations (same logic as targeted_fix.sh)
problem_lines=$(echo "$test_lines" | sed 's/: Error.*$//' | sort | uniq)

echo "Extracted file:line combinations:"
echo "$problem_lines"
echo ""

# Process each line (same logic as targeted_fix.sh)
echo "$problem_lines" | while read -r line_info; do
    if [[ -n "$line_info" ]]; then
        file=$(echo "$line_info" | cut -d: -f1)
        line_num=$(echo "$line_info" | cut -d: -f2)

        echo "Parsed:"
        echo "  File: $file"
        echo "  Line: $line_num"
        echo "  Would comment line $line_num in $file"
        echo ""
    fi
done

echo "Parsing logic test complete."
