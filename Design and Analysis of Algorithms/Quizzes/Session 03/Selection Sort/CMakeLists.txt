cmake_minimum_required(VERSION 3.15)
project(BubbleSort CXX)

add_executable(BubbleSort
    ex02.cpp
)

configure_file(
    ex02_inp.txt
    ex02_inp.txt
    COPYONLY
)