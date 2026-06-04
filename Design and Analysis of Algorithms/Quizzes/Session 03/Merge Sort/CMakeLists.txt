cmake_minimum_required(VERSION 3.15)
project(MergeSort CXX)

add_executable(MergeSort
    ex03.cpp
)

configure_file(
    ex03_inp.txt
    ex03_inp.txt
    COPYONLY
)