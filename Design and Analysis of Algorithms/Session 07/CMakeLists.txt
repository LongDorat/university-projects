cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0135 NEW)

project(PriorityQueue CXX)

add_executable(PriorityQueue Main.cpp)

configure_file(input.txt input.txt COPYONLY)