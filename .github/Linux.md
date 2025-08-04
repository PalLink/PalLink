# ⚙️ Setting up PalLink (Linux)

## 🔧 Requirements

- `g++` (GCC 13+)
- `cmake` (v3.16 or newer)
- `make` or `ninja`
- `git`

Install on Ubuntu / WSL:

```bash
sudo apt update
sudo apt install -y build-essential cmake git
```

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

Navigate to the project root:
```bash
cd PalLink
```

## [Optional] 📦 Install CLI Commands

This step adds the pallink command globally to your user shell.
```bash
./scripts/install_linux_commands.sh
source ~/.bashrc  # or restart your terminal
```
✅ After this, you can use from anywhere:
```bash
pallink build             # Generates the project (CMake)
pallink compile debug     # Builds with debug info
pallink compile release   # Builds optimized with debug symbols
pallink clean             # Removes build/ and bin/
```

## 🛠️ Generating PalLink (Without CLI)

If you don't want to install the `pallink` command, you can run the scripts manually:
```bash
scripts/build_project.sh
```

## 🧱 Building PalLink

You can either use 
```bash
pallink compile <debug|release>
```

Or manually:
- Build in Debug mode:
  ```bash
  scripts/compile_project_debug.sh
  ```
  📁 Output: `/PalLink/bin/Debug/PalLink.so`

- Build in Release mode:
  ```bash
  scripts/compile_project_release.bat
  ```   
  📁 Output: `/PalLink/bin/RelWithDebInfo/PalLink.so`
   
### ▶️ Running PalLink
1. Copy `PalLink.so` from the build output:
  ```bash
  cp bin/RelWithDebInfo/PalLink.so <YourServerPath>/Pal/Binaries/Linux/
  ```
2. Run the server:
  ```bash
  LD_PRELOAD=./PalLink.so ./PalServer-Linux-Shipping
  ```

⚠️ **Do not run `PalServer.sh` — it loads PalLink.so into the wrong executable!** ⚠️
