#!/bin/bash
# install-sdk.sh
# Installs Zephyr SDK on Linux

SDK_VERSION=${1:-0.17.4}

# Assume in zephyr directory
# cd zephyr

echo "Updating West and Python dependencies..."
# west packages pip --install

cd ..

echo "Installing Zephyr SDK..."
# west sdk install

# Manual install
echo "Downloading SDK..."
wget -P /tmp "https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v${SDK_VERSION}/zephyr-sdk-${SDK_VERSION}_linux-x86_64.tar.xz"
sudo tar xvf "/tmp/zephyr-sdk-${SDK_VERSION}_linux-x86_64.tar.xz" -C /opt
cd "/opt/zephyr-sdk-${SDK_VERSION}"
sudo ./setup.sh
rm "/tmp/zephyr-sdk-${SDK_VERSION}_linux-x86_64.tar.xz"

echo "SDK installed."