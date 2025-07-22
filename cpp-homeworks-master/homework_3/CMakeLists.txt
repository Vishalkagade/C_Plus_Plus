cmake_minimum_required(VERSION 3.1)
project(homework3)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/api)

add_library(html_writer src/html_writer.cpp)
add_library(image_browser src/image_browser.cpp)
target_link_libraries(image_browser html_writer)
target_include_directories(image_browser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/api)

add_executable(main src/test.cpp)
target_link_libraries(main html_writer image_browser)