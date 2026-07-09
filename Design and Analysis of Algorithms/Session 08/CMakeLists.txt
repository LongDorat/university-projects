cmake_minimum_required(VERSION 3.15)
project(Session_08 CXX)

add_executable(Session_08 Main.cpp RedBlackTree.hpp)

configure_file(input.txt input.txt COPYONLY)