# setup-venv.ps1
# Sets up Python virtual environment for Zephyr

param(
    [string]$VenvName = "ZPE"
)

$venvPath = Join-Path $PWD $VenvName

if (!(Test-Path $venvPath)) {
    Write-Host "Creating virtual environment at $venvPath..."
    python -m venv $venvPath
} else {
    Write-Host "Virtual environment already exists at $venvPath."
}

Write-Host "Activating virtual environment..."
& "$venvPath\Scripts\Activate.ps1"

Write-Host "Virtual environment activated. Run 'deactivate' to exit."