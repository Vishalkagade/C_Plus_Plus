cmake_minimum_required(VERSION 3.1)
project(homework5)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV 4 REQUIRED)
include_directories(include/)

add_library(mat_serialization src/serialize.cpp)
target_link_libraries(mat_serialization ${OpenCV_LIBS})

add_library(convert_dataset src/convert_dataset.cpp)
target_link_libraries(convert_dataset ${OpenCV_LIBS} mat_serialization)

target_include_directories(convert_dataset PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)