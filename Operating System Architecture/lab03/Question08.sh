#!/bin/bash

read -p "Please provide the number: " num

table() {
    local n=$1
    local idx=$2

    for (( i=idx; i < idx + 10; i++ )); do
        echo "$n * $i = $(( n * i ))"
    done    
}

index=1
while true; do
    table "$num" "$index"
    
    read -p "Type '1' to see more, anything else to quit: " choice

    if [[ "$choice" == "1" ]]; then
        index=$(( index + 10 ))
    else
        break
    fi
done
