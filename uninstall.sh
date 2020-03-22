#!/usr/bin/env bash
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# Exit if error occurs
set -e

command -v stow >/dev/null 2>&1 || { echo >&2 "stow not found. Aborting."; exit 1; }

if [ $# -ne 1 ]
  then
    echo "Example:"
    echo "./install.sh /path/to/qmk_directory"
    exit -1
fi

if [[ ! -d $1 ]]; then
    echo "Argument is not a directory"
    exit -1
fi

TARGET_DIR=$1
echo "Unstowing $SCRIPT_DIR/qmk_firmware from $TARGET_DIR"
stow -D -d $SCRIPT_DIR qmk_firmware -t $TARGET_DIR
