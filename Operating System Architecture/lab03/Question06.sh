#!/bin/bash

for (( i=0; i<=10; i++ )); do
	line=$( printf '%*s' "$i" | tr ' ' '*' )
	echo "$line"
done

for (( i=0; i<5; i++)) do
	for (( j=1; j<=5; j++)) do
		printf "%d\t" "$j"
	done
	echo ""
done
