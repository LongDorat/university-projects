#!/bin/bash
set -euo pipefail

mkdir -p build
cd build
cmake ..
make
clear
./Question_12