# Zephyr-Source-Build

## Table of Contents
1. [Installation of Zephyr project and SDK for Windows Operating System](#windows-installation)
2. [WSL/Linux Setup](#wsllinux-setup)
3. [Zephyr Project Components](#project-components)

<a id="windows-installation"></a>
## 1. Installation of Zephyr project and SDK for Windows Operating System

### Prerequisite required tools for Zephyr Setup on Windows Machine :
- [Cmake](https://cmake.org/download/) 
- Python 3.11
- Download [Ninja](https://github.com/ninja-build/ninja/releases) and keep it in the Cywin bin path
- 7z Install [7Zip](https://www.7-zip.org/download.html) tool and add to Environment Path
- LinkServer (NXP flash tool) needs to be added to the Environment Path)

### Open Powershell as Administrator Run below command and powershell Script after installtion of prerequisite tools
```bash
$ Set-ExecutionPolicy -ExecutionPolicy Bypass -Scope LocalMachine
$ Set-ExecutionPolicy -ExecutionPolicy Bypass -Scope CurrentUser
$ PLATFORM_TOOLS     :   S:\platform_tools (On Environment variables add this)
$ Setup_Zephyr_Project_SDK.ps1
```

### Powershell Commands to Setup the Zephyr Environment setup and Zephyr SDK

```bash
## Python Environment Setup and Activation
$ python -m venv zephyrEnv
$ ./zephyrEnv/Script/activate
$ pip install west

## Initilize Zephyr Repository
$ west init .ZephyrWorkspace
$ cd .ZephyrWorkspace

## Before west update edit `west.yml` for neccessary repositories  
$ west update
$ west zephyr-export
$ west packages pip --install
$ cd %HOMEPATH%\.ZephyrWorkspace\zephyr

## Project creation by copy copying sample project template
$ mkdir <Project-name>
$ cd <Project-name>
$ $env:ZEPHYR_BASE="S:\Zephyr-Source-Build\.ZephyrWorkspace\zephyr"
$ Copy-Item -Recurse -Path $env:ZEPHYR_BASE\samples\philosophers\* -Destination .

## Build the project and Flash process
$ west boards  # to get list of boards
$ west build -b <your-board-name> <project-dir> -t guiconfig
$ west build -p always -b <your-board-name> <project-dir> --build-dir <build-dir>
Eg: west build -p always -b mimxrt1170_evk@A/mimxrt1176/cm7 S:/Zephyr-Source-Build/Truesample --build-dir S:/Zephyr-Source-Build/Truesample/build -- -DDTC_OVERLAY_FILE="S:/Zephyr-Source-Build/Truesample/boards/<boardname>.overlay"

## Linkserver installtion path should be added to Path Env
$ west flash --build-dir <build-dir>
$ west flash --runner jlink --build-dir ../../Truesample/build
```
- ### Downlaod Zephyr SDK directly
   [Downlaod Zephyr SDK](https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.17.0/zephyr-sdk-0.17.0_windows-x86_64.7z)
- ### Keep the extract one into s:\platforms_tools\zephyr-sdk
   $ 7z x zephyr-sdk-0.17.0_windows-x86_64.7z
- ### Run setup.cmd to register Zephyr SDK path and access from anywhere
   $ setup.cmd

<a id="wsllinux-setup"></a>
## 2. WSL-2 Installation for Linux Environment 
[WSL Installation Guide](https://learn.microsoft.com/en-us/windows/wsl/install)

```bash
$ wsl --list # To list the Distros
$ wsl --shutdown 
$ wsl --install -d Ubuntu-24.02 --location D:\WSL # Directly install on specified drive
$ wsl --setdefault "Ubuntu-24.02"
$ wsl --export "Ubuntu-24.02" "D:\wsl\Ubuntu-export.tar" # Export to differebt drive 
$ wsl --import "Ubuntu-24.02" "D:\wsl\Ubuntu" "D:\wsl\Ubuntu-export.tar" # import to drive
$ wsl --unregister "Ubuntu-24.02" # To remove the distro
```
### Shell Scripts created on windows Need convert & Premission changes
```bash
$ dos2unix filename.sh
$ chmod +x filename.sh
```
### Attaching USB to WSL Linux platform using USIPD
[USIPD Repo](https://github.com/dorssel/usbipd-win)
```bash
$ usbipd list
$ usbipd attach --wsl --busid=2-4
```
### Zephyr Enviroment and SDK setup on Linux Operating System

```bash

# 1. Installing Python Dependencies
   $ sudo apt update
   $ sudo apt upgrade
   $ sudo apt install --no-install-recommends git cmake ninja-build gperf \
      ccache dfu-util device-tree-compiler wget \
      python3-dev python3-pip python3-setuptools python3-tk python3-wheel python3-venv xz-utils file \
      make gcc gcc-multilib g++-multilib libsdl2-dev libmagic1

   $ cmake --version
   $ python3 --version
   $ dtc --version

# 2. Create Python virtual environment (ZPE)
   $ python3 -m venv ZPE
   $ source ./ZPE/bin/activate

# 3. Install west
   $ pip install west

# 4. Initialize workspace (ZWS)
   $ west init ZWS
   $ cd ZWS
   $ west update

# 5. Export Zephyr CMake package
   $ west zephyr-export

# 6. Install Python dependencies using west
   $ west packages pip --install

# 7. Install Zephyr SDK following official docs
   $ cd ~
   $ wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.17.0/zephyr-sdk-0.17.0_linux-x86_64.tar.xz
   $ wget -O - https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.17.0/sha256.sum | shasum --check --ignore-missing
   $ tar xvf zephyr-sdk-0.17.0_linux-x86_64.tar.xz
   $ cd zephyr-sdk-0.17.0
   $ ./setup.sh

   $ sudo cp ~/zephyr-sdk-0.17.0/sysroots/x86_64-pokysdk-linux/usr/share/openocd/contrib/60-openocd.rules /etc/udev/rules.d
   $ sudo udevadm control --reload

# 8. Verify installation
   $ west --version
```

<a id="project-components"></a>
## 3. Zephyr West Projects Components

| **Project Name**                           | **Description** |
|--------------------------------------------|----------------|
| `acpica`                                   | ACPI Component Architecture – Provides support for ACPI (used in x86 architectures). |
| `babblesim_base`                           | Core simulation framework for Bluetooth Low Energy (BLE) testing. |
| `babblesim_ext_2G4_channel_NtNcable`       | Simulates wired BLE RF channels for testing. |
| `babblesim_ext_2G4_channel_multiatt`       | Models multipath attenuation in BLE RF environments. |
| `babblesim_ext_2G4_device_WLAN_actmod`     | Simulates active WLAN interference for BLE testing. |
| `babblesim_ext_2G4_device_burst_interferer`| Adds burst interference in BLE radio simulations. |
| `babblesim_ext_2G4_device_playback`        | Replays recorded BLE radio signals for debugging. |
| `babblesim_ext_2G4_libPhyComv1`            | Physical communication layer library for BabbleSim. |
| `babblesim_ext_2G4_modem_BLE_simple`       | Simple BLE modem simulation in BabbleSim. |
| `babblesim_ext_2G4_modem_magic`            | Specialized BLE modem for advanced simulation. |
| `babblesim_ext_2G4_phy_v1`                 | Physical layer implementation for BLE simulation. |
| `babblesim_ext_libCryptov1`                | Cryptography library for BabbleSim. |
| `bsim`                                     | BabbleSim manifest repository, including all simulation tools. |
| `cmsis`                                    | ARM Cortex Microcontroller Software Interface Standard (CMSIS) – Low-level HAL for ARM CPUs. |
| `cmsis-dsp`                                | DSP (Digital Signal Processing) library for CMSIS. |
| `cmsis-nn`                                 | Neural Network acceleration library for CMSIS. |
| `cmsis_6`                                  | Updated CMSIS version with additional enhancements. |
| `edtt`                                     | Event-Driven Testing Tool (EDTT) for Bluetooth protocol testing. |
| `fatfs`                                    | FAT filesystem implementation for storage support. |
| `hal_adi`                                  | Hardware Abstraction Layer (HAL) for Analog Devices (ADI) MCUs. |
| `hal_altera`                               | HAL for Altera (Intel FPGA) hardware. |
| `hal_ambiq`                                | HAL for Ambiq Microcontrollers (Ultra-Low Power MCUs). |
| `hal_atmel`                                | HAL for Atmel (now Microchip) MCUs. |
| `hal_espressif`                            | HAL for ESP32 and other Espressif chips. |
| `hal_ethos_u`                              | HAL for Arm Ethos-U Neural Processing Unit (NPU). |
| `hal_gigadevice`                           | HAL for GigaDevice MCUs. |
| `hal_infineon`                             | HAL for Infineon MCUs and peripherals. |
| `hal_intel`                                | HAL for Intel hardware. |
| `hal_microchip`                            | HAL for Microchip MCUs (including SAM and AVR series). |
| `hal_nordic`                               | HAL for Nordic Semiconductor MCUs (nRF series). |
| `hal_nuvoton`                              | HAL for Nuvoton MCUs. |
| `hal_nxp`                                  | HAL for NXP MCUs (LPC, i.MX, Kinetis series). |
| `hal_openisa`                              | HAL for OpenISA (open-source CPU architectures). |
| `hal_quicklogic`                           | HAL for QuickLogic MCUs. |
| `hal_renesas`                              | HAL for Renesas MCUs. |
| `hal_rpi_pico`                             | HAL for Raspberry Pi Pico (RP2040 MCU). |
| `hal_silabs`                               | HAL for Silicon Labs MCUs. |
| `hal_st`                                   | HAL for STMicroelectronics (STM32 series). |
| `hal_stm32`                                | HAL specifically for STM32 MCUs. |
| `hal_tdk`                                  | HAL for TDK sensors and devices. |
| `hal_telink`                               | HAL for Telink Semiconductor MCUs. |
| `hal_ti`                                   | HAL for Texas Instruments (TI) MCUs. |
| `hal_wch`                                  | HAL for WCH Microcontrollers. |
| `hal_wurthelektronik`                      | HAL for Würth Elektronik products. |
| `hal_xtensa`                               | HAL for Xtensa processors (e.g., ESP32). |
| `hostap`                                   | Wi-Fi Host Access Point (HostAP) library. |
| `liblc3`                                   | LC3 (Low Complexity Communication Codec) library for Bluetooth LE Audio. |
| `libmctp`                                  | Message Control Transfer Protocol (MCTP) library. |
| `libmetal`                                 | Abstraction layer for multi-core systems. |
| `littlefs`                                 | Lightweight flash filesystem for embedded systems. |
| `loramac-node`                             | LoRaWAN networking stack. |
| `lvgl`                                     | Open-source graphics library for embedded GUIs. |
| `mbedtls`                                  | TLS/SSL cryptographic library. |
| `mcuboot`                                  | Secure bootloader for firmware updates. |
| `mipi-sys-t`                               | MIPI System Trace protocol implementation. |
| `net-tools`                                | Network utilities for testing and debugging. |
| `nrf_hw_models`                            | Hardware models for Nordic Semiconductor MCUs. |
| `nrf_wifi`                                 | Wi-Fi drivers for Nordic Semiconductor chips. |
| `open-amp`                                 | Open Asymmetric Multi-Processing (AMP) framework. |
| `openthread`                               | Open-source implementation of Thread networking protocol. |
| `percepio`                                 | Real-time tracing tools for embedded applications. |
| `picolibc`                                 | Lightweight C standard library for embedded systems. |
| `segger`                                   | Segger debugging tools and utilities. |
| `tinycrypt`                                | Minimalist cryptographic library for embedded systems. |
| `trusted-firmware-a`                       | Secure firmware for Arm Cortex-A processors. |
| `trusted-firmware-m`                       | Secure firmware for Arm Cortex-M processors. |
| `uoscore-uedhoc`                           | Lightweight cryptographic framework for constrained devices. |
| `zcbor`                                    | Library for CBOR (Concise Binary Object Representation) encoding/decoding. |