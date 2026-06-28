$scriptDir = Split-Path -Parent $PSCommandPath

$scripts = Get-ChildItem -Path $scriptDir -Filter "*.ps1" | Where-Object { $_.FullName -ne $PSCommandPath }

foreach ($script in $scripts) {
    Write-Host "Running: $($script.Name)" -ForegroundColor Green
    & $script.FullName
}