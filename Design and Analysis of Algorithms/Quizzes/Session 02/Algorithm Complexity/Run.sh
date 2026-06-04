#!/bin/bash

mkdir -p build
cd build
cmake ..
make

range=10000
if [ $# -ge 1 ]; then
    if [[ $1 =~ ^[0-9]+$ ]] && [ "$1" -gt 0 ]; then
        range=$1
    else
        echo "Usage: $0 [positive_integer_range]" >&2
        echo "Leave empty to use default range of 10000." >&2
        exit 1
    fi
fi

./AlgorithmComplexity $range