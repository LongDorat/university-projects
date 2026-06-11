cmake_minimum_required(VERSION 3.15)
project(ex02 CXX)

add_executable(ex02 main.cpp)

configure_file(
    input.txt
    input.txt
    COPYONLY
)