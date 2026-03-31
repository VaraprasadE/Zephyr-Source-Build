#!/bin/bash
# install-sdk.sh
# Installs Zephyr SDK on Linux via west

WORKSPACE_NAME=${1:-ZWS}
WORKSPACE_PATH="$(pwd)/${WORKSPACE_NAME}"
ZEPHYR_PATH="${WORKSPACE_PATH}/zephyr"

if ! command -v west >/dev/null 2>&1; then
	echo "Error: west is not available. Activate the virtual environment and run 03-init-west first."
	exit 1
fi

if [ ! -d "$ZEPHYR_PATH" ]; then
	echo "Error: Zephyr directory ${ZEPHYR_PATH} does not exist. Run from the repo root after initializing the workspace."
	exit 1
fi

echo "Installing Zephyr SDK via west from ${ZEPHYR_PATH}..."
cd "$ZEPHYR_PATH" || exit 1
west sdk install
echo "SDK installed. If builds still find an older SDK, unset ZEPHYR_SDK_INSTALL_DIR so Zephyr can use the registered SDK."