# Zephyr-Source-Build

A streamlined setup for building Zephyr RTOS projects on Windows and Linux.

## Table of Contents

1. [Windows Setup](#windows-setup)
2. [Linux/WSL Setup](#linux-setup)
3. [Building and Flashing](#building-and-flashing)
4. [Zephyr West Project Components](#project-components)

---

<a id="windows-setup"></a>
## 1. Windows Setup

This repo provides PowerShell scripts to set up Zephyr on Windows. Run scripts in order as Administrator.

### Prerequisites

- Windows 10 or later
- Internet connection

### Step-by-Step Setup

| Step | Script                  | Description                                                                 |
|------|-------------------------|-----------------------------------------------------------------------------|
| 1    | `.\01-install-deps.ps1` | Installs required tools using winget: CMake, Ninja, Gperf, Python 3.12, Git, DTC |
| 2    | `.\02-setup-venv.ps1`   | Creates and activates a Python virtual environment (`ZPE`)                  |
| 3    | `.\03-init-west.ps1`    | Installs West, initializes workspace (`ZWS`), updates repos, exports CMake package |
| 4    | `.\04-install-sdk.ps1`  | Installs and registers the compatible Zephyr SDK via `west sdk install`     |
| 5    | `.\05-build-sample.ps1` | (Optional) Builds a sample project                                          |

### Quick Start

```powershell
# Run all setup scripts in order
.\01-install-deps.ps1
.\02-setup-venv.ps1
.\03-init-west.ps1
.\04-install-sdk.ps1

# Build a sample
cd ZWS
.\..\05-build-sample.ps1 -Sample zephyr/samples/basic/blinky
```

### Notes

- **Activate venv in each new session:** `.\ZPE\Scripts\Activate.ps1`
- **SDK installs:** Use `.\04-install-sdk.ps1`, which runs `west sdk install` from `ZWS\zephyr`

### VSCode and MCUExpresso Integration

For development in VSCode with MCUExpresso IDE:

- Use the same ZWS workspace and import the projects into MCUExpresso.
- Leave `ZEPHYR_SDK_INSTALL_DIR` unset unless you intentionally need to override Zephyr's SDK auto-detection.

### Custom Application Notes

The repository also contains custom Zephyr applications under `APPS/`.

| Application | Description |
|-------------|-------------|
| `APPS/uart_stream_processor` | UART receive and multi-threaded stream-processing application plan with ISR, circular buffering, semaphore signaling, static memory pool usage, and staged task-based processing. |

See `APPS/uart_stream_processor/README.rst` for the current architecture plan and implementation intent.

---

<a id="linux-setup"></a>
## 2. Linux/WSL Setup

For Linux and WSL setup instructions, see **[Linux-README.md](Linux-README.md)**.

The repo includes:

| File               | Description                          |
|--------------------|--------------------------------------|
| `README.md`        | Full Linux/WSL setup guide           |
| `install-deps.sh`  | Install system dependencies          |
| `setup-venv.sh`    | Create Python virtual environment    |
| `init-west.sh`     | Initialize West workspace            |
| `install-sdk.sh`   | Install Zephyr SDK                   |
| `build-sample.sh`  | Build a sample project               |

---

<a id="building-and-flashing"></a>
## 3. Building and Flashing

### List Supported Boards

```bash
west boards
```

### Build Commands

```bash
# Basic build
west build -b <board-name> <project-dir>

# Build with GUI config
west build -b <board-name> <project-dir> -t guiconfig

# Clean build with custom build directory
west build -p always -b <board-name> <project-dir> --build-dir <build-dir>

# Build with device tree overlay
west build -p always -b mimxrt1170_evk@A/mimxrt1176/cm7 ./MyProject \
    --build-dir ./MyProject/build \
    -- -DDTC_OVERLAY_FILE="./MyProject/boards/mimxrt1170_evk.overlay"
```

### Simulation

```bash
# QEMU simulation (Windows compatible)
west build -b qemu_x86 zephyr/samples/basic/blinky

# Native simulation (Linux/WSL preferred)
west build -b native_sim zephyr/samples/basic/blinky
```

### Flash Commands

```bash
# Default flash
west flash --build-dir <build-dir>

# Flash with J-Link
west flash --runner jlink --build-dir <build-dir>
```

> **Note:** Add LinkServer installation path to your `PATH` environment variable.

---

<a id="project-components"></a>
## 4. Zephyr West Project Components

### Simulation & Testing

| Project                                     | Description                                                |
|---------------------------------------------|------------------------------------------------------------|
| `babblesim_base`                            | Core simulation framework for Bluetooth Low Energy testing |
| `babblesim_ext_2G4_channel_NtNcable`        | Simulates wired BLE RF channels for testing                |
| `babblesim_ext_2G4_channel_multiatt`        | Models multipath attenuation in BLE RF environments        |
| `babblesim_ext_2G4_device_WLAN_actmod`      | Simulates active WLAN interference for BLE testing         |
| `babblesim_ext_2G4_device_burst_interferer` | Adds burst interference in BLE radio simulations           |
| `babblesim_ext_2G4_device_playback`         | Replays recorded BLE radio signals for debugging           |
| `babblesim_ext_2G4_libPhyComv1`             | Physical communication layer library for BabbleSim         |
| `babblesim_ext_2G4_modem_BLE_simple`        | Simple BLE modem simulation in BabbleSim                   |
| `babblesim_ext_2G4_modem_magic`             | Specialized BLE modem for advanced simulation              |
| `babblesim_ext_2G4_phy_v1`                  | Physical layer implementation for BLE simulation           |
| `babblesim_ext_libCryptov1`                 | Cryptography library for BabbleSim                         |
| `bsim`                                      | BabbleSim manifest repository with all simulation tools    |
| `edtt`                                      | Event-Driven Testing Tool for Bluetooth protocol testing   |
| `nrf_hw_models`                             | Hardware models for Nordic Semiconductor MCUs              |

### ARM CMSIS Libraries

| Project     | Description                                                              |
|-------------|--------------------------------------------------------------------------|
| `cmsis`     | ARM Cortex Microcontroller Software Interface Standard – Low-level HAL   |
| `cmsis-dsp` | DSP (Digital Signal Processing) library for CMSIS                        |
| `cmsis-nn`  | Neural Network acceleration library for CMSIS                            |
| `cmsis_6`   | Updated CMSIS version with additional enhancements                       |

### Hardware Abstraction Layers (HAL)

| Project             | Description                                          |
|---------------------|------------------------------------------------------|
| `hal_adi`           | HAL for Analog Devices (ADI) MCUs                    |
| `hal_altera`        | HAL for Altera (Intel FPGA) hardware                 |
| `hal_ambiq`         | HAL for Ambiq Microcontrollers (Ultra-Low Power)     |
| `hal_atmel`         | HAL for Atmel (now Microchip) MCUs                   |
| `hal_espressif`     | HAL for ESP32 and other Espressif chips              |
| `hal_ethos_u`       | HAL for Arm Ethos-U Neural Processing Unit (NPU)     |
| `hal_gigadevice`    | HAL for GigaDevice MCUs                              |
| `hal_infineon`      | HAL for Infineon MCUs and peripherals                |
| `hal_intel`         | HAL for Intel hardware                               |
| `hal_microchip`     | HAL for Microchip MCUs (SAM and AVR series)          |
| `hal_nordic`        | HAL for Nordic Semiconductor MCUs (nRF series)       |
| `hal_nuvoton`       | HAL for Nuvoton MCUs                                 |
| `hal_nxp`           | HAL for NXP MCUs (LPC, i.MX, Kinetis series)         |
| `hal_openisa`       | HAL for OpenISA (open-source CPU architectures)      |
| `hal_quicklogic`    | HAL for QuickLogic MCUs                              |
| `hal_renesas`       | HAL for Renesas MCUs                                 |
| `hal_rpi_pico`      | HAL for Raspberry Pi Pico (RP2040 MCU)               |
| `hal_silabs`        | HAL for Silicon Labs MCUs                            |
| `hal_st`            | HAL for STMicroelectronics (STM32 series)            |
| `hal_stm32`         | HAL specifically for STM32 MCUs                      |
| `hal_tdk`           | HAL for TDK sensors and devices                      |
| `hal_telink`        | HAL for Telink Semiconductor MCUs                    |
| `hal_ti`            | HAL for Texas Instruments (TI) MCUs                  |
| `hal_wch`           | HAL for WCH Microcontrollers                         |
| `hal_wurthelektronik` | HAL for Würth Elektronik products                  |
| `hal_xtensa`        | HAL for Xtensa processors (e.g., ESP32)              |

### Filesystems

| Project     | Description                                        |
|-------------|----------------------------------------------------|
| `fatfs`     | FAT filesystem implementation for storage support  |
| `littlefs`  | Lightweight flash filesystem for embedded systems  |

### Networking & Connectivity

| Project        | Description                                              |
|----------------|----------------------------------------------------------|
| `hostap`       | Wi-Fi Host Access Point (HostAP) library                 |
| `loramac-node` | LoRaWAN networking stack                                 |
| `nrf_wifi`     | Wi-Fi drivers for Nordic Semiconductor chips             |
| `openthread`   | Open-source implementation of Thread networking protocol |
| `net-tools`    | Network utilities for testing and debugging              |
| `libmctp`      | Message Control Transfer Protocol (MCTP) library         |

### Security & Cryptography

| Project              | Description                                              |
|----------------------|----------------------------------------------------------|
| `mbedtls`            | TLS/SSL cryptographic library                            |
| `tinycrypt`          | Minimalist cryptographic library for embedded systems    |
| `mcuboot`            | Secure bootloader for firmware updates                   |
| `trusted-firmware-a` | Secure firmware for Arm Cortex-A processors              |
| `trusted-firmware-m` | Secure firmware for Arm Cortex-M processors              |
| `uoscore-uedhoc`     | Lightweight cryptographic framework for constrained devices |

### Audio & Codecs

| Project  | Description                                                   |
|----------|---------------------------------------------------------------|
| `liblc3` | LC3 (Low Complexity Communication Codec) for Bluetooth LE Audio |

### Graphics & UI

| Project | Description                                   |
|---------|-----------------------------------------------|
| `lvgl`  | Open-source graphics library for embedded GUIs |

### Multi-Core & System

| Project    | Description                                                       |
|------------|-------------------------------------------------------------------|
| `libmetal` | Abstraction layer for multi-core systems                          |
| `open-amp` | Open Asymmetric Multi-Processing (AMP) framework                  |
| `acpica`   | ACPI Component Architecture – Support for ACPI (x86 architectures) |

### Debugging & Tracing

| Project      | Description                                    |
|--------------|------------------------------------------------|
| `mipi-sys-t` | MIPI System Trace protocol implementation      |
| `percepio`   | Real-time tracing tools for embedded applications |
| `segger`     | Segger debugging tools and utilities           |

### Libraries

| Project   | Description                                                       |
|-----------|-------------------------------------------------------------------|
| `picolibc` | Lightweight C standard library for embedded systems              |
| `zcbor`   | Library for CBOR (Concise Binary Object Representation) encoding |
