#!/bin/bash
set -e

INSTALL_PATH="$HOME/.local/bin"
mkdir -p "$INSTALL_PATH"

TARGET="$INSTALL_PATH/pallink"

cat > "$TARGET" <<'EOF'
#!/bin/bash

set -e
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && cd ~/PalLink/PalLink/scripts && pwd)"

case "$1" in
  compile)
    case "$2" in
      debug)
        "$SCRIPT_DIR/compile_project_debug.sh"
        ;;
      release)
        "$SCRIPT_DIR/compile_project_release.sh"
        ;;
      *)
        echo "Usage: pallink compile [debug|release]"
        exit 1
        ;;
    esac
    ;;
  build)
    "$SCRIPT_DIR/build_project.sh"
    ;;
  clean)
    rm -rf ~/PalLink/PalLink/build ~/PalLink/PalLink/bin
    echo "Cleaned build and bin directories."
    ;;
  *)
    echo "Usage: pallink [compile|build|clean] ..."
    exit 1
    ;;
esac
EOF

chmod +x "$TARGET"

# Add to PATH if missing
if ! grep -q "$INSTALL_PATH" "$HOME/.bashrc"; then
  echo "export PATH=\"\$HOME/.local/bin:\$PATH\"" >> "$HOME/.bashrc"
  echo "Added $INSTALL_PATH to PATH in .bashrc"
fi

echo "✅ Command 'pallink' installed at $TARGET"
echo "👉 Run 'source ~/.bashrc' or restart your terminal to use it"
