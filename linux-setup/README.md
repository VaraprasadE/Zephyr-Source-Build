# Linux/WSL Setup for Zephyr

This guide covers setting up Zephyr RTOS on Linux or Windows Subsystem for Linux (WSL).

## Table of Contents

1. [WSL-2 Installation](#wsl-installation)
2. [USB Passthrough to WSL](#usb-passthrough)
3. [Zephyr Environment Setup](#zephyr-setup)
4. [Shell Scripts](#shell-scripts)

---

<a id="wsl-installation"></a>
## 1. WSL-2 Installation

For detailed instructions, see the [official WSL Installation Guide](https://learn.microsoft.com/en-us/windows/wsl/install).

### Common WSL Commands

| Command | Description |
|---------|-------------|
| `wsl --list` | List installed distros |
| `wsl --shutdown` | Shutdown all WSL instances |
| `wsl --install -d Ubuntu-24.04 --location D:\WSL` | Install to specific drive |
| `wsl --setdefault "Ubuntu-24.04"` | Set default distro |
| `wsl --export "Ubuntu-24.04" "D:\wsl\Ubuntu.tar"` | Export distro |
| `wsl --import "Ubuntu-24.04" "D:\wsl\Ubuntu" "D:\wsl\Ubuntu.tar"` | Import distro |
| `wsl --unregister "Ubuntu-24.04"` | Remove distro |

### Converting Shell Scripts from Windows

Scripts created on Windows need line-ending conversion and execution permissions:

```bash
dos2unix filename.sh
chmod +x filename.sh
```

---

<a id="usb-passthrough"></a>
## 2. USB Passthrough to WSL

Use [USBIPD-WIN](https://github.com/dorssel/usbipd-win) to attach USB devices to WSL.

### Installation

Download and install from the [USBIPD releases page](https://github.com/dorssel/usbipd-win/releases).

### Usage

```powershell
# List USB devices (run in PowerShell)
usbipd list

# Attach device to WSL
usbipd attach --wsl --busid=<bus-id>
```

**Example:**
```powershell
usbipd attach --wsl --busid=2-4
```

---

<a id="zephyr-setup"></a>
## 3. Zephyr Environment Setup

### Step 1: Install System Dependencies

```bash
sudo apt update
sudo apt upgrade
sudo apt install --no-install-recommends \
    git cmake ninja-build gperf ccache dfu-util device-tree-compiler wget \
    python3-dev python3-pip python3-setuptools python3-tk python3-wheel python3-venv \
    xz-utils file make gcc gcc-multilib g++-multilib libsdl2-dev libmagic1
```

Verify installations:
```bash
cmake --version
python3 --version
dtc --version
```

### Step 2: Create Python Virtual Environment

```bash
python3 -m venv ZPE
source ./ZPE/bin/activate
```

### Step 3: Install West

```bash
pip install west
```

### Step 4: Initialize Workspace

```bash
west init ZWS
cd ZWS
west update
```

### Step 5: Export Zephyr CMake Package

```bash
west zephyr-export
```

### Step 6: Install Python Dependencies

```bash
west packages pip --install
```

### Step 7: Install Zephyr SDK

```bash
cd ~
wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.17.4/zephyr-sdk-0.17.4_linux-x86_64.tar.xz
wget -O - https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.17.4/sha256.sum | shasum --check --ignore-missing
tar xvf zephyr-sdk-0.17.4_linux-x86_64.tar.xz
cd zephyr-sdk-0.17.4
./setup.sh
```

### Step 8: Configure udev Rules (for USB debugging)

```bash
sudo cp ~/zephyr-sdk-0.17.4/sysroots/x86_64-pokysdk-linux/usr/share/openocd/contrib/60-openocd.rules /etc/udev/rules.d
sudo udevadm control --reload
```

### Step 9: Verify Installation

```bash
west --version
```

---

<a id="shell-scripts"></a>
## 4. Shell Scripts

This folder includes shell scripts for automated setup:

| Script            | Description                            |
|-------------------|----------------------------------------|
| `install-deps.sh` | Install system dependencies            |
| `setup-venv.sh`   | Create Python virtual environment      |
| `init-west.sh`    | Initialize West workspace              |
| `install-sdk.sh`  | Install Zephyr SDK                     |
| `build-sample.sh` | Build a sample project                 |

### Usage

```bash
# Make scripts executable (if needed)
chmod +x *.sh

# Run in order
./install-deps.sh
./setup-venv.sh
./init-west.sh
./install-sdk.sh

# Build a sample
./build-sample.sh
```

> **Note:** Activate the virtual environment in each new session:
> ```bash
> source ./ZPE/bin/activate
> ```
