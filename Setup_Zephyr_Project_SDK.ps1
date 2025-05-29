# Get the current script directory
$currentDirectory = $PWD
$parentDirectory = Split-Path -Parent $currentDirectory

# Define the virtual drive letter
$virtualDrive = "S:"

# Zephyr base location
$zephyrBaseLocation = "$virtualDrive\Zephyr-Source-Build\ZWS\zephyr"
$westFile = "$currentDirectory\west.yml"

# Use subst to create the virtual drive
if (Test-Path -Path $virtualDrive) {
    Write-Host "The virtual drive $virtualDrive already exists."
} else {
    subst $virtualDrive $parentDirectory
}

# Confirm the virtual drive has been created
if (Test-Path -Path $virtualDrive) {
    Write-Host "The virtual drive $virtualDrive has been successfully created and points to $parentDirectory."
} else {
    Write-Host "Failed to create the virtual drive $virtualDrive."
    exit
}

# Define platform tools directory
$platformTools = "$virtualDrive\platform_tools"

# Ensure PLATFORM_TOOLS directory exists
if (-not (Test-Path -Path $platformTools)) {
    New-Item -ItemType Directory -Path $platformTools -Force
    Write-Host "Folder created at: $platformTools"
} else {
    Write-Host "Folder already exists at: $platformTools"
}

# Create and activate Python virtual environment
$venvPath = "$currentDirectory\ZPE"
if (-not (Test-Path -Path $venvPath)) {
    Write-Host "Creating Python virtual environment at $venvPath..."
    python -m venv $venvPath
} else {
    Write-Host "Python virtual environment already exists at $venvPath."
}

# Activate the virtual environment
Write-Host "Activating Python virtual environment..."
. "$venvPath\Scripts\Activate.ps1"

# Install west using pip
Write-Host "Installing west using pip..."
pip install west

# Initialize West (Zephyr's repository management tool)
if (-not (Test-Path -Path "$currentDirectory\ZWS\.west")) {
    Write-Host "Initializing West..."
    west init ZWS
    # Ensure the destination folder exists
    if (!(Test-Path $zephyrBaseLocation)) {
        Write-Host "Zephyr Workspace base folder does not exist!"
    }

    # Copy and replace the file
    Copy-Item -Path $westFile -Destination $zephyrBaseLocation -Force
    Write-Host "File copied successfully and replaced if it already existed."
} else {
    Write-Host "West is already initialized."
}

# Update the required repositories
Write-Host "Updating Zephyr dependencies..."
Set-Location "$currentDirectory\ZWS"

west update

Write-Host $env:ZEPHYR_BASE
Write-Host "Selected repositories have been updated successfully!"

# Export Zephyr environment variables
Write-Host "Exporting Zephyr environment variables..."
west zephyr-export

# Install Zephyr Python dependencies
Write-Host "Installing Zephyr Python dependencies..."
west packages pip --install

# Define Zephyr SDK installation path (under platform_tools)
Set-Location "$currentDirectory\ZWS\zephyr"
$zephyrSdkPath = "$platformTools\zephyr-sdk-0.17.0"

# Download the Zephyr SDK bundle
Write-Host "Downloading Zephyr SDK bundle..."
$sdkUrl = "https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.17.0/zephyr-sdk-0.17.0_windows-x86_64.7z"
$sdkArchive = "$platformTools\zephyr-sdk-0.17.0_windows-x86_64.7z"
if (-not (Test-Path -Path $sdkArchive)) {
    try {
        Invoke-WebRequest -Uri $sdkUrl -OutFile $sdkArchive
    } catch {
        Write-Host "An error occurred while downloading the Zephyr SDK."
        exit 1
    }
} else {
    Write-Host "Zephyr SDK bundle already exists."
}

# Ensure Zephyr SDK directory exists
if (-not (Test-Path -Path $zephyrSdkPath)) {
    Write-Host "Extracting Zephyr SDK bundle..."
    7z x $sdkArchive -o"$platformTools"
    # Run the Zephyr SDK setup script
    Write-Host "Running Zephyr SDK setup script..."
    Set-Location "$zephyrSdkPath"
    .\setup.cmd
} else {
    Write-Host "Zephyr SDK is already installed."
}

Write-Host "Zephyr repository setup completed successfully!"
Set-Location "$zephyrBaseLocation"
