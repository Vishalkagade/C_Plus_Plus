cmake_minimum_required(VERSION 3.1)
project(homework4)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/results/lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(ipb_algorithm INTERFACE)