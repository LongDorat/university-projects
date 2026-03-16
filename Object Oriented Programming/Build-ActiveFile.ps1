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

.PARAMETER ShowDebug
    Show debug information about error detection and output parsing.

.EXAMPLE
    .\Build-ActiveFile.ps1 -ActiveFilePath "src\Main.java"
    .\Build-ActiveFile.ps1 -ActiveFilePath "src\Main.java" -InputFile "input.txt"
    .\Build-ActiveFile.ps1 -ActiveFilePath "src\Main.java" -Debug
#>

param(
    [Parameter(Mandatory = $true)]
    [ValidateScript({ Test-Path $_ -PathType Leaf })]
    [String]
    $ActiveFilePath,

    [Parameter(Mandatory = $false)]
    [String]
    $InputFile,

    [Parameter(Mandatory = $false)]
    [Switch]
    $ShowDebug
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

# Clear the bin directory before compilation
if (Test-Path $buildPath) {
    Remove-Item (Join-Path $buildPath "*") -Recurse -Force -ErrorAction SilentlyContinue
}

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
    $output = Get-Content $InputFile | & java -cp $buildPath $fullyQualifiedClassName 2>&1
} else {
    $output = & java -cp $buildPath $fullyQualifiedClassName 2>&1
}

$exitCode = $LASTEXITCODE

#endregion

#region Error Handling

$hasErrors = $false
$errorMessages = @()
$traces = @()
$normalOutput = @()

foreach ($line in $output) {
    $lineStr = $line.ToString()
    
    # Check for Java exceptions and stack traces
    if ($lineStr -match 'Exception in thread' -or 
        $lineStr -match 'Exception:' -or 
        $lineStr -match 'Error:' -or 
        $lineStr -match '^\s+at\s+\w+' -or
        $lineStr -match 'Caused by:') {
        $hasErrors = $true
        $traces += $lineStr
    } elseif ($line -is [System.Management.Automation.ErrorRecord]) {
        $hasErrors = $true
        $errorMessages += $lineStr
    } else {
        $normalOutput += $lineStr
    }
}

# Display normal output first
foreach ($line in $normalOutput) {
    Write-Host $line
}

# Debug mode: show what was captured
if ($ShowDebug) {
    Write-Host "`n[DEBUG] Output analysis:" -ForegroundColor Magenta
    Write-Host "  Normal lines: $($normalOutput.Count)" -ForegroundColor Magenta
    Write-Host "  Error traces: $($traces.Count)" -ForegroundColor Magenta
    Write-Host "  Error messages: $($errorMessages.Count)" -ForegroundColor Magenta
    if ($traces.Count -gt 0) {
        Write-Host "  First trace line: $($traces[0])" -ForegroundColor Magenta
    }
}

if ($hasErrors) {
    Write-Host ""
    Write-Section "Runtime Error Detected"
    
    # Parse and display main exception
    $mainException = $traces | Where-Object { $_ -match 'Exception in thread|Exception:|Error:' } | Select-Object -First 1
    
    if ($mainException) {
        # Extract exception type
        if ($mainException -match '(java\.[\w\.]+(?:Exception|Error))|(\w+(?:Exception|Error))') {
            $exceptionType = if ($matches[1]) { $matches[1] } else { $matches[2] }
        } else {
            $exceptionType = "RuntimeException"
        }
        
        # Extract message
        $message = "An error occurred"
        if ($mainException -match '(?:Exception|Error):\s*(.+)$') {
            $message = $matches[1].Trim()
        } elseif ($mainException -match 'Exception in thread\s+"[^"]+"\s+\S+\s*(.*)') {
            $msg = $matches[1].Trim()
            if ($msg) { $message = $msg }
        }
        
        Write-Failure "$exceptionType"
        Write-Host "  Message: " -NoNewline -ForegroundColor Gray
        Write-Host $message -ForegroundColor White
    }
    
    # Find relevant stack trace line (first non-java/jdk line from your code)
    $relevantLine = $traces | Where-Object { 
        $_ -match '\s+at\s+' -and $_ -notmatch 'java\.(base|lang|util\.Scanner)' -and $_ -match '\w+\.java'
    } | Select-Object -First 1
    
    if ($relevantLine -match 'at\s+([\w\.<>$]+)\(([\w\.]+):(\d+)\)') {
        $method = $matches[1]
        $file = $matches[2]
        $lineNum = $matches[3]
        
        Write-Host "  Location: " -NoNewline -ForegroundColor Gray
        Write-Host "$file" -NoNewline -ForegroundColor Yellow
        Write-Host " (line $lineNum)" -ForegroundColor Cyan
        Write-Host "  Method: " -NoNewline -ForegroundColor Gray
        Write-Host "$method" -ForegroundColor White
    }
    
    # Show condensed stack trace (max 5 relevant lines)
    $relevantTraces = $traces | Where-Object { 
        $_ -match '\s+at\s+' -and $_ -notmatch 'java\.(base|lang|util\.Scanner)' 
    } | Select-Object -First 5
    
    if ($relevantTraces) {
        Write-Host "`n  Stack trace:" -ForegroundColor Gray
        foreach ($trace in $relevantTraces) {
            Write-Host "    $trace" -ForegroundColor DarkYellow
        }
    }
    
    # Ask if user wants full stack trace
    if ($traces.Count -gt 5) {
        Write-Host "`nShow full stack trace? (y/N): " -NoNewline -ForegroundColor Yellow
        $showTrace = Read-Host
        
        if ($showTrace -eq "y" -or $showTrace -eq "Y") {
            Write-Host "`n--- Full Stack Trace ---" -ForegroundColor DarkGray
            $traces | ForEach-Object { Write-Host $_ -ForegroundColor DarkGray }
            Write-Host "--- End Stack Trace ---`n" -ForegroundColor DarkGray
        }
    }
}

#endregion

#region Completion

Write-Host ""
if ($exitCode -eq 0 -and -not $hasErrors) {
    Write-Success "Program completed successfully"
} elseif ($hasErrors) {
    Write-Failure "Program terminated with runtime error"
} else {
    Write-Failure "Program exited with code ${exitCode}"
}

$separator = [string][char]0x2500 * 60
Write-Host $separator -ForegroundColor Cyan
Write-Host ""

exit $exitCode

#endregion