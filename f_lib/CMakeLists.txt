cmake_minimum_required(VERSION 3.22)
project(f_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS PN)

add_library(tools tools.cpp)
add_executable(main main.cpp)
target_link_libraries(main tools)

