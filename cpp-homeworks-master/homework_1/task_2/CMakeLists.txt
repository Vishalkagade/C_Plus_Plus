cmake_minimum_required(VERSION 3.1)
project(learning_build)
set(CMAKE_CXX_STANDARD 17)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/install)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)

include_directories(include/)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/results/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/results/bin)

add_library(ipb_arithmetic src/sum.cpp src/subtract.cpp)
add_executable(test_ipb_arithmetic src/main.cpp)

target_link_libraries(test_ipb_arithmetic ipb_arithmetic)

install(TARGETS ipb_arithmetic test_ipb_arithmetic)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)