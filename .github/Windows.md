# ⚙️ Setting up PalLink (Windows)

## 🔧 Requirements

- Code Editor such as **Visual Studio** or **VSCode**: [Download here](https://visualstudio.microsoft.com/free-developer-offers/)
- ⚠️ **Visual Studio 2022** with:
  - **MSVC v143 toolset**
  - **C++23**
  - **Windows 11 SDK**
- [CMake 3.16+](https://cmake.org/download/)
- [git](https://git-scm.com/)

## 📥 Downloading PalLink

Clone this repository:
- via HTTPS:
  ```bash
  git clone https://github.com/PalLink/PalLink.git
  ```
- via SSH:
  ```bash
  git clone git@github.com:PalLink/PalLink.git
  ```

## 🛠️ Generating PalLink project
From the root of the repository, run:
- To generate the project:
   ```bash
   scripts/build_project.bat
   ```
- To open the project in Visual Studio:
   ```bash
   scripts/open_project.bat
   ```

## 🧱 Building PalLink

**If the solution is open, you can use your IDE to build!**

From the root directory, you can build using the provided scripts:
- Build in Debug mode:
  ```bash
  scripts/compile_project_debug.bat
  ```
  📁 Output: `/PalLink/bin/Debug/` will contain **PalLink.dll** and all wrapper DLLs.

- Build in Release mode (with debug symbols):
  ```bash
  scripts/compile_project_release.bat
  ```   
  📁 Output: `/PalLink/bin/RelWithDebInfo/` will contain **PalLink.dll** and all wrapper DLLs.
   
### ▶️ Running PalLink
- Copy the following files into your server directory:
  ```
  /PalLink/bin/RelWithDebInfo/PalLink.dll
  /PalLink/bin/RelWithDebInfo/wrapper/d3d9.dll
  ```

- Place them into:
  ```
  <YourServerPath>/Pal/Binaries/Win64/
  ```

- Run your server with:
  ```bash
  PalServer-Win64-Shipping-Cmd.exe
  ```
  ✅ PalLink will automatically hook into the process via the d3d9.dll proxy.