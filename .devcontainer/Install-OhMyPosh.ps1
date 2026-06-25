Write-Host "Install Oh My Posh"
mkdir -p "$HOME/.local/bin"
curl -s https://ohmyposh.dev/install.sh | bash -s -- -d "$HOME/.local/bin"

Write-Host "Install Meslo Nerd Font"
oh-my-posh font install meslo

Write-Host "Set Amro theme in PowerShell profile"
$profilePath = "$HOME/.config/powershell/Microsoft.PowerShell_profile.ps1"
$ohMyPoshInit = @"
# Initialize Oh My Posh with Amro theme
oh-my-posh init pwsh --config ~/.poshthemes/amro.omp.json | Invoke-Expression
"@

# Create profile directory if it doesn't exist
mkdir -p "$HOME/.config/powershell"
New-Item -Path "$HOME/.config/powershell/" -Name "Microsoft.PowerShell_profile.ps1" -ItemType File

# Append to profile if the line doesn't already exist
if (!(Select-String -Path $profilePath -Pattern "oh-my-posh init" -Quiet)) {
    Add-Content -Path $profilePath -Value $ohMyPoshInit
    Write-Host "Added Oh My Posh initialization to PowerShell profile"
} else {
    Write-Host "Oh My Posh already configured in profile"
}

Write-Host "Download Amro theme"
mkdir -p "$HOME/.poshthemes"
$themeUrl = "https://raw.githubusercontent.com/JanDeDobbeleer/oh-my-posh/main/themes/amro.omp.json"
Invoke-WebRequest -Uri $themeUrl -OutFile "$HOME/.poshthemes/amro.omp.json"

Write-Host "Setup complete! Please restart your terminal or run: oh-my-posh init pwsh --config ~/.poshthemes/amro.omp.json | Invoke-Expression"