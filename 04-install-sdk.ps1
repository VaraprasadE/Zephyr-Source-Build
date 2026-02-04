# install-sdk.ps1
# Installs Zephyr SDK

param(
    [string]$SdkVersion = "0.17.4",
    [string]$WorkspaceName = "ZWS"
)

# Assume in repo root, cd to workspace zephyr
$zephyrPath = Join-Path $PWD "$WorkspaceName\zephyr"
if (!(Test-Path $zephyrPath)) {
    Write-Host "Error: Zephyr directory $zephyrPath does not exist. Run from repo root after initializing workspace."
    exit 1
}
Set-Location $zephyrPath

Write-Host "Installing Zephyr SDK..."
west sdk install

# If manual install needed, uncomment below
# $sdkUrl = "https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v$SdkVersion/zephyr-sdk-${SdkVersion}_windows-x86_64.7z"
# $sdkPath = "$env:USERPROFILE\.local\zephyr-sdk\$SdkVersion"
# if (!(Test-Path $sdkPath)) {
#     Write-Host "Downloading SDK..."
#     Invoke-WebRequest -Uri $sdkUrl -OutFile "zephyr-sdk.7z"
#     7z x zephyr-sdk.7z -o"$env:USERPROFILE\.local\zephyr-sdk"
#     Set-Location "$env:USERPROFILE\.local\zephyr-sdk\$SdkVersion"
#     .\setup.cmd
# }

Write-Host "SDK installed."