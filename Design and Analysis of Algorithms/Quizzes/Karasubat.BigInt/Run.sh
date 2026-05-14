#!/bin/bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
BUILD_DIR="$ROOT_DIR/build"

mkdir -p "$BUILD_DIR"
cmake -S "$ROOT_DIR" -B "$BUILD_DIR" >/dev/null
cmake --build "$BUILD_DIR" >/dev/null

sign_a=$((RANDOM % 2))
sign_b=$((RANDOM % 2))
num_a=$((RANDOM % 1000000))
num_b=$((RANDOM % 1000000))

if [ "$sign_a" -eq 1 ]; then
	num_a=$((-num_a))
fi
if [ "$sign_b" -eq 1 ]; then
	num_b=$((-num_b))
fi

"$BUILD_DIR/KarasubatBigInt" "$num_a" "$num_b"

