# init-west.ps1
# Initializes West workspace and installs Zephyr

param(
    [string]$WorkspaceName = "ZWS"
)

# Assume venv is activated
Write-Host "Installing West..."
pip install west

# Install additional required packages
Write-Host "Installing additional Python dependencies..."
pip install jsonschema

$workspacePath = Join-Path $PWD $WorkspaceName

if (!(Test-Path $workspacePath)) {
    Write-Host "Initializing West workspace..."
    west init $WorkspaceName
} else {
    Write-Host "West workspace already exists."
}

Set-Location $workspacePath

Write-Host "Updating repositories..."
west update

Write-Host "Exporting Zephyr CMake package..."
west zephyr-export

Write-Host "Installing Python dependencies..."
$packages = west packages pip
python -m pip install @($packages -split ' ')

Write-Host "West setup complete."