#!/bin/bash

read -p "Please provide the number: " num

num=${num#-}
totalDigits=${#num}

echo "Total digits inside $num is $totalDigits"
