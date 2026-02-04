#!/bin/bash
# build-sample.sh
# Builds a Zephyr sample

BOARD=${1:-native_sim}
SAMPLE=${2:-samples/basic/blinky}

# Assume in workspace root
echo "Building sample $SAMPLE for board $BOARD..."
west build -p always -b "$BOARD" "$SAMPLE"

echo "Build complete."