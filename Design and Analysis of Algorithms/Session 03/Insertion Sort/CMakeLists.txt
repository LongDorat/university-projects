cmake_minimum_required(VERSION 3.15)
project(InsertionSort CXX)

add_executable(InsertionSort
    ex01_3.cpp
)

configure_file(
    ex01_3_inp.txt
    ex01_3_inp.txt
    COPYONLY
)