#!/bin/bash
# setup-venv.sh
# Sets up Python virtual environment for Zephyr

VENV_NAME=${1:-zephyr-venv}
VENV_PATH="./$VENV_NAME"

if [ ! -d "$VENV_PATH" ]; then
    echo "Creating virtual environment at $VENV_PATH..."
    python3 -m venv "$VENV_PATH"
else
    echo "Virtual environment already exists at $VENV_PATH."
fi

echo "Activating virtual environment..."
source "$VENV_PATH/bin/activate"

echo "Virtual environment activated. Run 'deactivate' to exit."