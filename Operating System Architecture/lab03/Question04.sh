#!/bin/bash

read -p "Please input the first number: x = " x
read -p "Please input the second number: y = " y

echo "x + y = $((x + y))"
echo "x - y = $((x - y))"
echo "x * y = $((x * y))"

div=$(echo "scale=2; $x / $y" | bc)
printf "x / y = %.2f\n" "$div"

echo "x % y = $((x % y))"
echo "x^2 = $((x*x))"

factorial(){
	if [ "$1" -le 1 ]; then
		echo 1
	else
		local prev=$(factorial $(( $1 - 1 )))
		echo $(( $1 * prev ))
	fi
}
echo "x! = $(factorial $x)"

