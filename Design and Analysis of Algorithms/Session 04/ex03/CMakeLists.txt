cmake_minimum_required(VERSION 3.15)
project(ex03 CXX)

add_executable(ex03 main.cpp)
configure_file(
    input.txt
    input.txt
    COPYONLY
)