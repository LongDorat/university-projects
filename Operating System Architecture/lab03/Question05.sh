#!/bin/bash

read -p "Please enter a directory: " directory

mkdir -p $directory 2>/dev/null

if [ -d "$directory" ]; then
	echo "The $directory is created sucessfully"
else
	echo "Cannot create $directory"
fi
