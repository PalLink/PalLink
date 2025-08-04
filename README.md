# PalLink

![GitHub Last Commit](https://img.shields.io/github/last-commit/PalLink/PalLink?style=flat-square)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/PalLink/PalLink?style=flat-square)
![GitHub Tag](https://img.shields.io/github/v/tag/PalLink/PalLink?style=flat-square)
![GitHub Stars](https://img.shields.io/github/stars/PalLink/PalLink?style=social)
![GitHub Downloads (all assets, latest release)](https://img.shields.io/github/downloads/PalLink/PalLink/latest/total?style=flat-square)
<br>
## ✅ Supported Platforms

![Windows](https://img.shields.io/badge/-Windows-blue?style=flat-square)
![Linux](https://img.shields.io/badge/-Linux-red?style=flat-square)

## ⚙️ Setting up PalLink

### 🔧 Requirements
- Code Editor such as **Visual Studio** or **VSCode**: [download](https://visualstudio.microsoft.com/free-developer-offers/)
- ⚠️ **Visual Studio 2022** with:
  - **MSVC v143 toolset**
  - **C++23**
  - **Windows 11 SDK**
- [CMake 3.29+](https://cmake.org/download/)
- [git](https://git-scm.com/)

### 📥 Downloading PalLink
1. Open your terminal and clone this repository:
   - via HTTPS:
     ```bash
     git clone https://github.com/PalLink/PalLink.git
     ```
   - via SSH:
     ```bash
     git clone git@github.com:PalLink/PalLink.git
     ```

### 🛠️ Generating PalLink project
From the root project directory:
- Generate the project:
   ```bash
   scripts/build_project.bat
   ```
- Open project:
   ```bash
   scripts/open_project.bat
   ```

### 🧱 Building PalLink
From the root project directory:
- Generate and build in **Debug mode**:
  ```bash
  scripts/compile_project_debug.bat
  ```
  📁 Output: `/PalLink/bin/Debug/` will contain **PalLink.dll** and all wrapper DLLs.<br><br>


- Generate and build in **Release mode**:
  ```bash
  scripts/compile_project_release.bat
  ```   
  📁 Output: `/PalLink/bin/RelWithDebInfo/` will contain **PalLink.dll** and all wrapper DLLs.
   
### ▶️ Running PalLink
- Copy the following DLLs into your server folder:
  ```
  /PalLink/bin/Release/PalLink.dll
  /PalLink/bin/Release/d3d9.dll
  ```

- Place them in:
  ```
  <YourServerPath>/Pal/Binaries/Win64/
  ```
- Then run `PalServer.exe`.


## 🧠 Design decisions

### 📦 Dependency Versioning
> We intentionally include version numbers in dependency folder names (e.g., `spdlog-1.15.3`) to ensure CMake will break if a version is changed without updating cmake. This forces conscious updates and avoids accidental API mismatches.

## 📝 License
This project is licensed under the terms of the MIT license. See [LICENSE](./LICENSE) for details.