cmake_minimum_required(VERSION 3.1)
project(homework6)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include/ io_tools/)

add_library(io_tools io_tools/io_tools.cpp)
add_library(image src/Image.cpp)
target_link_libraries(image io_tools)
target_include_directories(image PUBLIC include/)
