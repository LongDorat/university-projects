#!/bin/bash

read -p "What is your favorite operating system?: " os
os=$(echo "$os" | xargs | tr '[:upper:]' '[:lower:]')

case $os in
	linux)
		echo "Great choice!"
		;;
	windows)
		echo "You are a chill person, no?"
		;;
	macos)
		echo "You rich!"
		;;
	*)
		echo "Is ${os} an operating system?"
		;;
esac
