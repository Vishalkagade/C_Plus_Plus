cmake_minimum_required(VERSION 3.1)
project(homework7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV 4 REQUIRED)

include_directories(include)

add_library(kmeans src/kmeans.cpp)
target_link_libraries(kmeans ${OpenCV_LIBS})

add_library(serialization src/serialize.cpp src/convert_dataset.cpp)
target_link_libraries(serialization ${OpenCV_LIBS})

add_library(bow_dictionary src/BowDictionary.cpp)
target_link_libraries(bow_dictionary ${OpenCV_LIBS} kmeans)