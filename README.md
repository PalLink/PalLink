# PalLink

<!-- Build & CI -->
![Linux Build](https://img.shields.io/github/actions/workflow/status/PalLink/PalLink/cmake-linux-debian.yml?label=Linux&style=flat-square)
![Windows Build](https://img.shields.io/github/actions/workflow/status/PalLink/PalLink/cmake-windows.yml?label=Windows&style=flat-square)

<!-- Version & Release -->
![Latest Tag](https://img.shields.io/github/v/tag/PalLink/PalLink?style=flat-square)
![Downloads](https://img.shields.io/github/downloads/PalLink/PalLink/latest/total?style=flat-square)

<!-- Social -->
![GitHub Stars](https://img.shields.io/github/stars/PalLink/PalLink?style=social)


## ⚙️ Setting up PalLink

- [Windows](./.github/Windows.md)
- [Linux](./.github/Linux.md)

## 🧠 Design decisions

### 📦 Dependency Versioning
> We intentionally include version numbers in dependency folder names (e.g., `spdlog-1.15.3`) to ensure CMake will break if a version is changed without updating cmake. This forces conscious updates and avoids accidental API mismatches.

## 📝 License
This project is licensed under the terms of the MIT license. See [LICENSE](./LICENSE) for details.