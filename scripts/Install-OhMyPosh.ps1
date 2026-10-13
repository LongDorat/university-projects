Write-Host "Installing Oh My Posh..." -ForegroundColor Blue
$localBinPath = "$HOME/.local/bin"
mkdir -p "$localBinPath"

# Add the local bin directory to $PATH for the current session
if ($env:PATH -notlike "*$localBinPath*") {
    $env:PATH = "${localBinPath}:$env:PATH"
    Write-Host "Added $localBinPath to PATH for the current session"
} else {
    Write-Host "$localBinPath is already on PATH"
}

curl -s https://ohmyposh.dev/install.sh | bash -s -- -d "$localBinPath"

Write-Host "Installing Meslo Nerd Font..." -ForegroundColor Blue
oh-my-posh font install meslo

Write-Host "Setting Amro theme in PowerShell profile..." -ForegroundColor Blue
$profilePath = "$HOME/.config/powershell/Microsoft.PowerShell_profile.ps1"

# Create profile directory/file if they don't exist
mkdir -p "$HOME/.config/powershell"
New-Item -Path $profilePath -ItemType File -Force | Out-Null

# Persist the local bin directory on PATH in the profile
$pathExport = @"
# Add local bin to PATH
`$env:PATH = "${localBinPath}:`$env:PATH"
"@
if (!(Select-String -Path $profilePath -Pattern ([regex]::Escape($localBinPath)) -Quiet)) {
    Add-Content -Path $profilePath -Value $pathExport
    Write-Host "Added $localBinPath to PATH in PowerShell profile"
} else {
    Write-Host "PATH already configured in profile"
}

# Append the Oh My Posh init to the profile if it doesn't already exist
$ohMyPoshInit = @"
# Initialize Oh My Posh with Amro theme
oh-my-posh init pwsh --config ~/.poshthemes/amro.omp.json | Invoke-Expression
"@
if (!(Select-String -Path $profilePath -Pattern "oh-my-posh init" -Quiet)) {
    Add-Content -Path $profilePath -Value $ohMyPoshInit
    Write-Host "Added Oh My Posh initialization to PowerShell profile"
} else {
    Write-Host "Oh My Posh already configured in profile"
}

Write-Host "Downloading Amro theme..." -ForegroundColor Blue
mkdir -p "$HOME/.poshthemes"
$themeUrl = "https://raw.githubusercontent.com/JanDeDobbeleer/oh-my-posh/main/themes/amro.omp.json"
Invoke-WebRequest -Uri $themeUrl -OutFile "$HOME/.poshthemes/amro.omp.json"

Write-Host "Setup complete! Please restart your terminal or run: oh-my-posh init pwsh --config ~/.poshthemes/amro.omp.json | Invoke-Expression" -ForegroundColor Blue