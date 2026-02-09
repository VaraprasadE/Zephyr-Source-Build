#!/bin/bash
# init-west.sh
# Initializes West workspace and installs Zephyr

WORKSPACE_NAME=${1:-ZWS}

echo "Activating virtual environment..."
source "../ZPE/bin/activate"

# Assume venv is activated
echo "Installing West..."
pip install west

WORKSPACE_PATH="../$WORKSPACE_NAME"

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

echo "Installing Python dependencies..."
west packages pip --install

echo "West setup complete."