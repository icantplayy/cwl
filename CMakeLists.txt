cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(cwl C)

set(CMAKE_C_STANDARD 17)

add_compile_definitions(CWL_EXPORT)

include_directories(src)

add_library(${PROJECT_NAME} SHARED
    src/platform/x11/cwl_window_x11.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE X11)