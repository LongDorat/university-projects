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

random_digits() {
	local count="$1"
	local digits=""
	while [ "${#digits}" -lt "$count" ]; do
		local hash
		hash="$(head -c 32 /dev/urandom | sha256sum | awk '{print $1}')"
		digits+="$(printf '%s' "$hash" | tr -cd '0-9')"
	done
	printf '%s' "${digits:0:$count}"
}

random_number_in_range() {
	local range="$1"
	local length=$((range + 1))
	local first_digit
	first_digit="$((RANDOM % 9 + 1))"
	local rest
	rest="$(random_digits "$range")"
	printf '%s%s' "$first_digit" "$rest"
}

mkdir -p "$BUILD_DIR"
cmake -S "$ROOT_DIR" -B "$BUILD_DIR" >/dev/null
cmake --build "$BUILD_DIR" >/dev/null

if ! [[ "$r" =~ ^[0-9]+$ ]]; then
	echo "Error: range must be a non-negative integer." >&2
	usage >&2
	exit 1
fi

sign_a=$((RANDOM % 2))
sign_b=$((RANDOM % 2))
num_a="$(random_number_in_range "$r")"
num_b="$(random_number_in_range "$r")"

if [ "$positive_only" -eq 1 ]; then
	sign_a=0
	sign_b=0
fi

if [ "$sign_a" -eq 1 ]; then
	num_a="-$num_a"
fi
if [ "$sign_b" -eq 1 ]; then
	num_b="-$num_b"
fi

"$BUILD_DIR/KarasubatBigInt" "$num_a" "$num_b"

