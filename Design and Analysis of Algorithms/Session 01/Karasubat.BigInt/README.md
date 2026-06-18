# Karasubat

## Setup

1. Need at least one C/C++ compiler (e.g., g++, clang++).
2. Make sure [CMake](https://cmake.org/download/) is installed and available in PATH.
3. Use the provided scripts to build and run the program automatically.

## Bash (Linux/macOS)

```bash
./Run.sh
./Run.sh --range 4
./Run.sh --positive-only
./Run.sh -r 3 -p
```

## PowerShell

```powershell
./Run.ps1
./Run.ps1 -Range 4
./Run.ps1 -PositiveOnly
./Run.ps1 -Range 3 -PositiveOnly
```

> [!NOTE]
> The random range is determine by [10^r, 9*10^r], where r is the value of the `Range` parameter. By default, r is 6, which means the random numbers will be between 1000000 and 9999999.

## Troubleshooting

- The .sh script may or may not saved with CRLF endings, make sure to use LF endings if you encounter issues running the script on Linux/macOS. You can convert the line endings using tools like `dos2unix` or by configuring your text editor to use LF line endings for this file.
- The .ps1 script may require PowerShell to be configured to allow script execution. You can run `Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser` to allow locally created scripts to run.