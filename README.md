# PalLink

![GitHub Last Commit](https://img.shields.io/github/last-commit/PalLink/PalLink?style=flat-square)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/PalLink/PalLink?style=flat-square)
![GitHub Tag](https://img.shields.io/github/v/tag/PalLink/PalLink?style=flat-square)
![GitHub Stars](https://img.shields.io/github/stars/PalLink/PalLink?style=social?style=flat-square)
![GitHub Downloads (all assets, latest release)](https://img.shields.io/github/downloads/PalLink/PalLink/latest/total?style=flat-square)
<br>
Platforms:<br>
![Platform](https://img.shields.io/badge/-Windows-blue?style=flat-square)

## Setting up PalLink

### Requirements
- Code Editor such as **Visual Studi** or **VSCode**: [download](https://visualstudio.microsoft.com/free-developer-offers/)
- [CMake 3.9+](https://cmake.org/download/)
- C++23 compatible v143 MSVC Platform Toolset
- Windows 11 SDK
- [git](https://git-scm.com/)

### Downloading PalLink
1. Open your ternimal and clone this repository:
   - via HTTPS:
     ```bash
     git clone https://github.com/PalLink/PalLink.git
     ```
   - via SSH:
     ```bash
     git clone git@github.com:PalLink/PalLink.git
     ```

### Generating PalLink project
1. Navigate to the project directory and open the terminal.
2. To generate the project, run:
   ```bash
   scripts/build_project.bat
   ```
3. To open the project, run:
   ```bash
   scripts/open_project.bat
   ```

### Compiling PalLink
1. Navigate to the project directory and open the terminal.
2. To build the project, run:
   - In Debug mode:
     ```bash
     scripts/compile_project_debug.bat
     ```
   - In Release mode:
     ```bash
     scripts/compile_project_release.bat
     ```
   A new directory should appear: `/PalLink/bin/`. Those contains the PalLink.dll as well as the dll wrapper.
   

### Running PalLink
1. Copy `d3d9.dll` and `PalLink.dll` into your Palserver's `.../Pal/Binaries/Win64/` directory.
2. Run your PalServer.exe
3. Done.