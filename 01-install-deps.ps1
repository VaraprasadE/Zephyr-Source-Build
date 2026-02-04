# install-deps.ps1
# Installs required dependencies for Zephyr on Windows using winget

# Check if winget is available
if (!(Get-Command winget -ErrorAction SilentlyContinue)) {
    Write-Host "winget is not available. Please update Windows or install winget manually."
    exit 1
}

# Install dependencies
Write-Host "Installing dependencies..."
winget install Kitware.CMake Ninja-build.Ninja oss-winget.gperf Python.Python.3.12 Git.Git oss-winget.dtc wget 7zip.7zip --accept-source-agreements --accept-package-agreements

# Refresh PATH
$env:Path = [System.Environment]::GetEnvironmentVariable("Path","Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path","User")

# Verify
Write-Host "Verifying installations..."
cmake --version
python --version
dtc --version

Write-Host "Dependencies installed successfully."