#!/bin/bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
BUILD_DIR="$ROOT_DIR/build"

usage() {
	cat <<'EOF'
Usage: Run.sh [options]

Options:
  -r, --range <r>   Set random range to 10^r (default: 6)
	-p, --positive-only  Use positive numbers only
  -h, --help        Show this help message
EOF
}

r=6
positive_only=0
while [ "$#" -gt 0 ]; do
	case "$1" in
		-r|--range)
			if [ "$#" -lt 2 ]; then
				echo "Error: --range requires a value." >&2
				usage >&2
				exit 1
			fi
			r="$2"
			shift 2
			;;
		-p|--positive-only)
			positive_only=1
			shift
			;;
		-h|--help)
			usage
			exit 0
			;;
		--)
			shift
			break
			;;
		-*)
			echo "Error: Unknown option: $1" >&2
			usage >&2
			exit 1
			;;
		*)
			echo "Error: Unexpected argument: $1" >&2
			usage >&2
			exit 1
			;;
	esac
done

mkdir -p "$BUILD_DIR"
cmake -S "$ROOT_DIR" -B "$BUILD_DIR" >/dev/null
cmake --build "$BUILD_DIR" >/dev/null

if ! [[ "$r" =~ ^[0-9]+$ ]]; then
	echo "Error: range must be a non-negative integer." >&2
	usage >&2
	exit 1
fi

min=$((10 ** r))
max=$((9 * min))
range_size=$((max - min + 1))

sign_a=$((RANDOM % 2))
sign_b=$((RANDOM % 2))
num_a=$((RANDOM % range_size + min))
num_b=$((RANDOM % range_size + min))

if [ "$positive_only" -eq 1 ]; then
	sign_a=0
	sign_b=0
fi

if [ "$sign_a" -eq 1 ]; then
	num_a=$((-num_a))
fi
if [ "$sign_b" -eq 1 ]; then
	num_b=$((-num_b))
fi

"$BUILD_DIR/KarasubatBigInt" "$num_a" "$num_b"

