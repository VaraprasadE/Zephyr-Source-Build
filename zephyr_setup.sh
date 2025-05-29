#!/bin/bash

echo "=== Zephyr Project Installation Script ==="
echo "Following official SDK installation instructions exactly..."

# 1. Installing Python Dependencies
sudo apt update
sudo apt upgrade
sudo apt install --no-install-recommends git cmake ninja-build gperf \
  ccache dfu-util device-tree-compiler wget \
  python3-dev python3-pip python3-setuptools python3-tk python3-wheel python3-venv xz-utils file \
  make gcc gcc-multilib g++-multilib libsdl2-dev libmagic1

cmake --version
python3 --version
dtc --version

# 2. Create Python virtual environment (ZPE)
echo "Creating Python virtual environment in ZPE..."
python3 -m venv ZPE
source ./ZPE/bin/activate

# 3. Install west
echo "Installing west..."
pip install west

# 4. Initialize workspace (ZWS)
echo "Initializing Zephyr workspace in ZWS..."
west init ZWS
cd ZWS
west update

# 5. Export Zephyr CMake package
west zephyr-export

# 6. Install Python dependencies using west
echo "Installing Python requirements via west packages..."
west packages pip --install

# 7. Install Zephyr SDK following official docs
cd ~
wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.17.0/zephyr-sdk-0.17.0_linux-x86_64.tar.xz
wget -O - https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.17.0/sha256.sum | shasum --check --ignore-missing
tar xvf zephyr-sdk-0.17.0_linux-x86_64.tar.xz
cd zephyr-sdk-0.17.0
./setup.sh

sudo cp ~/zephyr-sdk-0.17.0/sysroots/x86_64-pokysdk-linux/usr/share/openocd/contrib/60-openocd.rules /etc/udev/rules.d
sudo udevadm control --reload

# 8. Verify installation
echo "Verifying installation..."
west --version

echo -e "\n\033[1;32mZephyr installation complete!\033[0m"
