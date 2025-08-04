# PalLink

![GitHub Last Commit](https://img.shields.io/github/last-commit/PalLink/PalLink?style=flat-square)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/PalLink/PalLink?style=flat-square)
![GitHub Tag](https://img.shields.io/github/v/tag/PalLink/PalLink?style=flat-square)
![GitHub Stars](https://img.shields.io/github/stars/PalLink/PalLink?style=social)
![GitHub Downloads (all assets, latest release)](https://img.shields.io/github/downloads/PalLink/PalLink/latest/total?style=flat-square)

## ⚙️ Setting up PalLink

- [Windows](./.github/Windows.md)
- [Linux](./.github/Linux.md)

## 🧠 Design decisions

### 📦 Dependency Versioning
> We intentionally include version numbers in dependency folder names (e.g., `spdlog-1.15.3`) to ensure CMake will break if a version is changed without updating cmake. This forces conscious updates and avoids accidental API mismatches.

## 📝 License
This project is licensed under the terms of the MIT license. See [LICENSE](./LICENSE) for details.