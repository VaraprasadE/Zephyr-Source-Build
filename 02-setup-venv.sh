#!/bin/bash
# setup-venv.sh
# Sets up Python virtual environment for Zephyr

VenvName=${1:-ZPE}
venvPath="./$VenvName"

if [ ! -d "$venvPath" ]; then
    echo "Creating virtual environment at $venvPath..."
    python3 -m venv "$venvPath"
else
    echo "Virtual environment already exists at $venvPath."
fi

echo "Activating virtual environment..."
source "$venvPath/bin/activate"

echo "Virtual environment activated. Run 'deactivate' to exit."