#!/bin/bash
for file in data/maps/Route110_TrickHouse*/map.json; do
    echo "Processing $file"
    jq '.object_events = []' "$file" > tmp.json && mv tmp.json "$file"
done
