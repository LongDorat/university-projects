param(
    [int]$Range,
    [switch]$PositiveOnly,
    [switch]$Help
)

$ErrorActionPreference = "Stop"

function Show-Usage {
    @"
Usage: Run.ps1 [options]

Options:
  -Range <r>        Set random range to 10^r (default: 6)
  -PositiveOnly     Use positive numbers only
  -Help             Show this help message
"@
}

if ($Help) {
    Show-Usage
    exit 0
}

if (-not $Range) {
    $Range = 6
}

if ($Range -lt 0) {
    Write-Error "Range must be a non-negative integer."
}

$rootDir = Split-Path -Parent $PSCommandPath
$buildDir = Join-Path $rootDir "build"

New-Item -ItemType Directory -Force -Path $buildDir | Out-Null
cmake -S $rootDir -B $buildDir | Out-Null
cmake --build $buildDir | Out-Null

$min = [int64][math]::Pow(10, $Range)
$max = 9 * $min

$numA = Get-Random -Minimum $min -Maximum ($max + 1)
$numB = Get-Random -Minimum $min -Maximum ($max + 1)

if (-not $PositiveOnly) {
    if ((Get-Random -Minimum 0 -Maximum 2) -eq 1) { $numA = -$numA }
    if ((Get-Random -Minimum 0 -Maximum 2) -eq 1) { $numB = -$numB }
}

& (Join-Path $buildDir "KarasubatBigInt") $numA $numB
