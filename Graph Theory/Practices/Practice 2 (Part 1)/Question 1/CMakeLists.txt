cmake_minimum_version(VERSION 3.15)

project(Question_1 C)

add_executable(Question_1 main.c)

configure_file(
    input.txt
    input.txt
    COPYONLY
)