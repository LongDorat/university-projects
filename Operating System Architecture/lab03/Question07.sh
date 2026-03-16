#!/bin/bash

read -p "Please enter number a = " a
read -p "Please enter number b = " b

if [ "$a" -eq 0 ]; then
	echo "The equation has no result!"
	exit 0
else
	result=$( echo "-$b/$a" | bc -l)
	printf "x = %.2f\n" "$result"
fi
