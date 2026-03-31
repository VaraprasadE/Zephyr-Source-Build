#!/bin/bash
# init-west.sh
# Initializes West workspace and installs Zephyr

WORKSPACE_NAME=${1:-ZWS}

# 1. Activate virtual environment
echo "Activating virtual environment..."
# Use absolute path or ensure script is run from the correct root
source "$(pwd)/ZPE/bin/activate"

echo "Installing West..."
pip install west

WORKSPACE_PATH="./$WORKSPACE_NAME"

if [ ! -d "$WORKSPACE_PATH" ]; then
    echo "Initializing West workspace..."
    west init "$WORKSPACE_PATH"
else
    echo "West workspace already exists."
fi

cd "$WORKSPACE_PATH"

echo "Updating repositories..."
west update

echo "Exporting Zephyr CMake package..."
west zephyr-export

# --- THE FIX STARTS HERE ---
echo "Installing Python dependencies via pip..."
# We install from the requirements file directly to avoid the 'jsonschema' crash
pip install -r zephyr/scripts/requirements.txt

# Now that dependencies are met, this command will work without crashing
echo "Finalizing packages..."
west packages pip --install
# --- THE FIX ENDS HERE ---

echo "West setup complete."