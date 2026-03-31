# install-sdk.ps1
# Installs Zephyr SDK via west

param(
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
Write-Host "SDK installed. If builds still detect an older SDK, clear ZEPHYR_SDK_INSTALL_DIR so Zephyr can use the registered SDK."