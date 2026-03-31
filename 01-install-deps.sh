#!/bin/bash
# install-deps.sh
# Installs required dependencies for Zephyr on Linux (Ubuntu/Debian)

echo "Updating package list..."
sudo apt update

echo "Installing dependencies..."
sudo apt install --no-install-recommends git cmake ninja-build gperf \
  ccache dfu-util device-tree-compiler wget python3-dev python3-venv python3-tk \
  xz-utils file make gcc gcc-multilib g++-multilib libsdl2-dev libmagic1

echo "Verifying installations..."
cmake --version
python3 --version
dtc --version

echo "Dependencies installed successfully."