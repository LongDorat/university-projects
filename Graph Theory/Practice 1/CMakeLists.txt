cmake_minimum_required(VERSION 3.15)
project(Practice_1 C)

function(add_subdirectory_executable TARGET_NAME)
    add_executable(${TARGET_NAME} ${ARGN})
    set_target_properties(${TARGET_NAME} PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${TARGET_NAME}"
    )
endfunction()

function(add_subdirectory_files TARGET_NAME)
    foreach(FILE ${ARGN})
        configure_file(
            "${CMAKE_CURRENT_SOURCE_DIR}/${FILE}" 
            "${CMAKE_BINARY_DIR}/bin/${TARGET_NAME}/${FILE}" 
            COPYONLY
        )
    endforeach()
endfunction()

add_subdirectory("Question 1")
add_subdirectory("Question 2-3")
add_subdirectory("Question 4-7")
add_subdirectory("Question 12")