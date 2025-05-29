# Get the current script directory
$currentDirectory = $PWD
$parentDirectory = Split-Path -Parent $currentDirectory

# Define the virtual drive letter
$virtualDrive = "S:"

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
