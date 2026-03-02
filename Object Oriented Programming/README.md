# 🎓 Object-Oriented Programming (OOP) Projects

This repository contains practical exercises and projects for the Object-Oriented Programming course.

## 🛠️ Prerequisites

Before you begin, ensure you have the following installed:

- **☕ Java SDK**: Version 17 or higher.
- **💻 Visual Studio Code**: With the [Extension Pack for Java](https://marketplace.visualstudio.com/items?itemName=vscjava.vscode-java-pack) installed.

## 🚀 Build and Run

There are three ways to build and run the Java files in this project:

### 🔹 Method 1: VS Code Build Tasks (Recommended)
This is the easiest way to run the active file:
1. Open the `.java` file you want to run.
2. Press `Ctrl + Shift + B`.
3. Select `Java: build & run active file`.

### 🔹 Method 2: Manual CLI Commands
You can also compile and run manually using the terminal:

1. **Compile**:
   ```powershell
   javac -encoding UTF-8 -d bin src\Practical_Session_01\Ex1\App.java
   ```

2. **Run**:
   ```powershell
   java -cp bin Practical_Session_01.Ex1.App
   ```

> [!NOTE]
> Replace `src\Practical_Session_01\Ex1\App.java` with your file path and use the corresponding fully qualified class name.

### 🔹 Method 3: PowerShell Automation Script
Use the provided script to automate the process:

```powershell
.\Build-ActiveFile.ps1 -ActiveFilePath "src\Practical_Session_01\Ex1\App.java"
```

