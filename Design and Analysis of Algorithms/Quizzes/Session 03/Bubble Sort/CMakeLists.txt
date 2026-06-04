cmake_minimum_required(VERSION 3.15)
project(BubbleSort CXX)

add_executable(BubbleSort
    ex01.cpp
)

configure_file(
    ex01_inp.txt
    ex01_inp.txt
    COPYONLY
)