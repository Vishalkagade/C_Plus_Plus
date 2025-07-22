cmake_minimum_required(VERSION 3.1)
project(homework9)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(OpenCV 4 REQUIRED)
include_directories(include ${OPENCV_INCLUDE_DIRS})


add_library(kmeans src/kmeans.cpp)
target_link_libraries(kmeans ${OpenCV_LIBS})

add_library(bow_dictionary src/BowDictionary.cpp)
target_link_libraries(bow_dictionary ${OpenCV_LIBS} kmeans)

add_library(histogram src/histograms.cpp)
target_link_libraries(histogram ${OpenCV_LIBS} bow_dictionary)


# enable_testing()
# add_subdirectory(tests/)