cmake_minimum_required(VERSION 3.15)
project(ex01 CXX)

add_executable(ex01 main.cpp)

configure_file(
    input.txt
    input.txt
    COPYONLY
)