cmake_minimum_required(VERSION 3.1)
project(homework_8_1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/)
add_executable(stack_limit ${CMAKE_CURRENT_SOURCE_DIR}/src/stack_limit.cpp)