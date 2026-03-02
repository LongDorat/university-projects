param(
    [Parameter(Mandatory = $true)]
    [String]
    $ActiveFilePath,

    [String]
    $InputFile
)

if (-not $ActiveFilePath){
    Write-Error "No source file found"
    exit 1;
}

$root = ${PSScriptRoot}
$buildPath = Join-Path $root "bin"
$srcPath = Join-Path $root "src"

New-Item -ItemType Directory -Force -Path $buildPath | Out-Null

$pkgMatch = Select-String -Path $ActiveFilePath -Pattern '^\s*package\s+([A-Za-z_]\w*(\.[A-Za-z_]\w*)*)\s*;' | Select-Object -First 1

$pkg = if ($pkgMatch) { $pkgMatch.Matches[0].Groups[1].Value } else {""}

$cls  = [IO.Path]::GetFileNameWithoutExtension($ActiveFilePath)
$fqcn = if ($pkg) { "$pkg.$cls" } else { $cls }

Clear-Host

Write-Host "Compiling: $ActiveFilePath"
& javac -encoding UTF-8 -d $buildPath -sourcepath $srcPath -cp $buildPath $ActiveFilePath
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "Running: $fqcn"

if (-not $InputFile) {
    Write-Host "No input file provided, do you want to run without input? (Y/n)"
    $response = Read-Host
    if ($response -ne "Y" -and $response -ne "y" -and $response -ne "") {
        Write-Host "Which input file do you want to use? (leave blank to run without input)"
        $InputFile = Read-Host
        if (-not $InputFile -or -not (Test-Path $InputFile)) {
            Write-Host "File path is blank or invalid. Running without input."
        } else {
            Write-Host "Using input file: $InputFile"
        }
    }
} elseif (-not (Test-Path $InputFile)) {
    Write-Warning "Input file '$InputFile' not found, running without input"
}

if (Test-Path $InputFile) {
    Get-Content $InputFile | & java -cp $buildPath $fqcn
} else {
    & java -cp $buildPath $fqcn
}

exit $LASTEXITCODE