cmake_minimum_required(VERSION 3.15)
project(BubbleSort CXX)

add_executable(BubbleSort
    ex01_1.cpp
)

configure_file(
    ex01_1_inp.txt
    ex01_1_inp.txt
    COPYONLY
)