cmake_minimum_required(VERSION 3.15)
project(TowerOfHanoi CXX)

add_executable(TowerOfHanoi
    ex02.cpp
)

configure_file(
    ex02_inp.txt
    ex02_inp.txt
    COPYONLY
)