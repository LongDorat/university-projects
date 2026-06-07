cmake_minimum_required(VERSION 3.15)
project(TowerOfHanoi CXX)

add_library(TowerOfHanoiLib STATIC
    TowerOfHanoi.hpp
    TowerOfHanoi.cpp
)

add_executable(TowerOfHanoi
    ex02.cpp
)
target_link_libraries(TowerOfHanoi PRIVATE TowerOfHanoiLib)

configure_file(
    ex02_inp.txt
    ex02_inp.txt
    COPYONLY
)