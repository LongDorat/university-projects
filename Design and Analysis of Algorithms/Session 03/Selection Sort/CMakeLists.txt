cmake_minimum_required(VERSION 3.15)
project(SelectionSort CXX)

add_executable(SelectionSort
    ex01_2.cpp
)

configure_file(
    ex01_2_inp.txt
    ex01_2_inp.txt
    COPYONLY
)