cmake_minimum_required(VERSION 3.15)
project(question_2 C)

add_executable(question_2 main.c)

configure_file(
    input.txt
    input.txt
    COPYONLY
)