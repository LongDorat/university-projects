param(
    [Parameter(Mandatory = $true)]
    [String]
    $ActiveFilePath
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

Write-Host "Compiling: $ActiveFilePath"
& javac -encoding UTF-8 -d $buildPath -sourcepath $srcPath -cp $buildPath $ActiveFilePath
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "Running: $fqcn"
& java -cp $buildPath $fqcn
exit $LASTEXITCODE