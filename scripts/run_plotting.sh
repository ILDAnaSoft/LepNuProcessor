#!/bin/bash
# Code directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}"  )" && pwd  )"
PLOTTER_DIR=${DIR}/../plotting/shell_scripts

echo ""
echo "Staring complete plotting"
echo ""

cd ${PLOTTER_DIR}
./initialize.sh

echo ""
