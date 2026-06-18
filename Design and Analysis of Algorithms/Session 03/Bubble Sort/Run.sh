#!/bin/bash
set -euo pipefail

if [[ "${1:-}" == "--fresh" ]]; then
  cmake --fresh -S . -B build
else
  cmake -S . -B build
fi

cmake --build build
clear
./build/BubbleSort