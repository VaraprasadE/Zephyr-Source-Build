#!/bin/bash
# install-sdk.sh
# Installs Zephyr SDK on Linux

SDK_VERSION=${1:-0.17.4}

# Assume in zephyr directory
cd zephyr

echo "Installing Zephyr SDK..."
west sdk install

# Manual install if needed
# echo "Downloading SDK..."
# wget "https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v${SDK_VERSION}/zephyr-sdk-${SDK_VERSION}_linux-x86_64.tar.xz"
# tar xvf "zephyr-sdk-${SDK_VERSION}_linux-x86_64.tar.xz"
# cd "zephyr-sdk-${SDK_VERSION}"
# ./setup.sh

echo "SDK installed."