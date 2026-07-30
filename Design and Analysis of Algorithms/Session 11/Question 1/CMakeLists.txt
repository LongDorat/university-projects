cmake_minimum_required(VERSION 3.15)
project(Question_01 CXX)

cmake_minimum_required(VERSION 3.15)
project(Question_01 CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

add_executable(Question_01 Main.cpp)
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/input.txt"
    "${CMAKE_BINARY_DIR}/bin/input.txt"
    COPYONLY
)