#Requires -Version 7.0

<#
.SYNOPSIS
    Build and run a Java file with optional input file support.

.DESCRIPTION
    Compiles and executes a Java source file with proper package resolution.
    Supports piping input from a text file for automated testing.

.PARAMETER ActiveFilePath
    The absolute path to the Java source file to compile and run.

.PARAMETER InputFile
    Optional path to a text file containing input data to pipe to the program.

.EXAMPLE
    .\Build-ActiveFile.ps1 -ActiveFilePath "src\Main.java"
    .\Build-ActiveFile.ps1 -ActiveFilePath "src\Main.java" -InputFile "input.txt"
#>

param(
    [Parameter(Mandatory = $true)]
    [ValidateScript({ Test-Path $_ -PathType Leaf })]
    [String]
    $ActiveFilePath,

    [Parameter(Mandatory = $false)]
    [String]
    $InputFile
)

#region Helper Functions

function Write-Section {
    param([string]$Title)
    $separator = [string][char]0x2500 * 60
    Write-Host "`n$separator" -ForegroundColor Cyan
    Write-Host "  $Title" -ForegroundColor Cyan
    Write-Host "$separator" -ForegroundColor Cyan
}

function Write-Success {
    param([string]$Message)
    Write-Host "[✓] $Message" -ForegroundColor Green
}

function Write-Info {
    param([string]$Message)
    Write-Host "[i] $Message" -ForegroundColor Blue
}

function Write-Failure {
    param([string]$Message)
    Write-Host "[✗] $Message" -ForegroundColor Red
}

#endregion

#region Initialization

Clear-Host

# Validate source file
if (-not $ActiveFilePath) {
    Write-Failure "No source file provided"
    exit 1
}

# Setup paths
$root = $PSScriptRoot
$buildPath = Join-Path $root "bin"
$srcPath = Join-Path $root "src"
$fileName = [IO.Path]::GetFileName($ActiveFilePath)

# Create build directory
New-Item -ItemType Directory -Force -Path $buildPath | Out-Null

#endregion

#region Package Resolution

Write-Section "Resolving Package and Class"

# Extract package name from source file
$pkgMatch = Select-String -Path $ActiveFilePath -Pattern '^\s*package\s+([A-Za-z_]\w*(\.[A-Za-z_]\w*)*)\s*;' | 
            Select-Object -First 1

$packageName = if ($pkgMatch) { 
    $pkgMatch.Matches[0].Groups[1].Value 
} else { 
    "" 
}

$className = [IO.Path]::GetFileNameWithoutExtension($ActiveFilePath)
$fullyQualifiedClassName = if ($packageName) { 
    "$packageName.$className" 
} else { 
    $className 
}

if ($packageName) {
    Write-Info "Package: $packageName"
}
Write-Info "Class: $className"
Write-Info "FQCN: $fullyQualifiedClassName"

#endregion

#region Compilation

Write-Section "Compiling Source File"
Write-Host "Source: " -NoNewline -ForegroundColor Gray
Write-Host $fileName -ForegroundColor White

& javac -encoding UTF-8 -d $buildPath -sourcepath $srcPath -cp $buildPath $ActiveFilePath

if ($LASTEXITCODE -ne 0) {
    Write-Failure "Compilation failed with exit code $LASTEXITCODE"
    exit $LASTEXITCODE
}

Write-Success "Compilation successful"

#endregion

#region Input File Handling

$useInputFile = $false

if ($InputFile) {
    # Input file was provided as parameter
    if (Test-Path $InputFile) {
        $useInputFile = $true
        Write-Info "Using input file: $InputFile"
    } else {
        Write-Warning "Input file '$InputFile' not found"
        Write-Host "Continue without input? (Y/n): " -NoNewline -ForegroundColor Yellow
        $response = Read-Host
        if ($response -eq "n" -or $response -eq "N") {
            Write-Failure "Execution cancelled"
            exit 0
        }
    }
} else {
    # No input file provided - ask user
    Write-Host "`nRun with input file? (y/N): " -NoNewline -ForegroundColor Yellow
    $response = Read-Host
    
    if ($response -eq "y" -or $response -eq "Y") {
        Write-Host "Enter input file path: " -NoNewline -ForegroundColor Yellow
        $InputFile = Read-Host
        
        if ($InputFile -and (Test-Path $InputFile)) {
            $useInputFile = $true
            Write-Success "Input file loaded: $InputFile"
        } else {
            Write-Warning "Invalid path. Running without input"
        }
    }
}

#endregion

#region Execution

Write-Section "Running Program"
Write-Host ""

Set-Location $root

if ($useInputFile) {
    Get-Content $InputFile | & java -cp $buildPath $fullyQualifiedClassName
} else {
    & java -cp $buildPath $fullyQualifiedClassName
}

$exitCode = $LASTEXITCODE

#endregion

#region Completion

Write-Host ""
if ($exitCode -eq 0) {
    Write-Success "Program completed successfully"
} else {
    Write-Failure "Program exited with code ${exitCode}"
}

$separator = [string][char]0x2500 * 60
Write-Host $separator -ForegroundColor Cyan
Write-Host ""

exit $exitCode

#endregion