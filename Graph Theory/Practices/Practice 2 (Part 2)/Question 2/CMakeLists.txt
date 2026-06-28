cmake_minimum_required(VERSION 3.15)
project(Question_2 C)

add_executable(Question_2 main.c MergeSort.h)
configure_file(input.txt input.txt COPYONLY)