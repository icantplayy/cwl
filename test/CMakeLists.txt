cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(test C)

set(CMAKE_C_STANDARD 17)

add_subdirectory(../ bin/)

include_directories(../)

add_executable(${PROJECT_NAME}
    main.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE cwl)