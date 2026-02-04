# build-sample.ps1
# Builds a Zephyr sample, optionally out-of-tree

param(
    [string]$Board = "native_sim",
    [string]$Sample = "zephyr/samples/basic/blinky",
    [string]$OutOfTreePath = "D:\GIT\Zephyr-Source-Build\blinky",
    [string]$WorkspaceName = "ZWS"
)

# Assume in zephyr dir, cd to workspace root
$workspaceRoot = Split-Path -Parent $PWD
Set-Location $workspaceRoot

# Now in workspace root
if ($OutOfTreePath) {
    if (!(Test-Path $Sample)) {
        Write-Host "Error: Sample path $Sample does not exist."
        exit 1
    }
    Write-Host "Copying sample $Sample to $OutOfTreePath..."
    if (!(Test-Path $OutOfTreePath)) {
        New-Item -ItemType Directory -Path $OutOfTreePath -Force
    }
    Write-Host "Source: $Sample"
    Write-Host "Destination: $OutOfTreePath"
    Copy-Item -Recurse -Path "$Sample\*" -Destination $OutOfTreePath -Force
    Write-Host "Copy complete."
    Get-ChildItem $OutOfTreePath
    if (!(Test-Path "$OutOfTreePath\CMakeLists.txt")) {
        Write-Host "Error: CMakeLists.txt not found in $OutOfTreePath after copy."
        exit 1
    }
    $buildPath = $OutOfTreePath
} else {
    if (!(Test-Path $Sample)) {
        Write-Host "Error: Sample path $Sample does not exist."
        exit 1
    }
    $buildPath = $Sample
}

Write-Host "Building sample at $buildPath for board $Board..."
Set-Location $buildPath
$env:ZEPHYR_BASE = "$workspaceRoot\zephyr"
west build -p always -b $Board .

if ($LASTEXITCODE -eq 0) {
    Write-Host "Build complete."
} else {
    Write-Host "Build failed."
    exit 1
}