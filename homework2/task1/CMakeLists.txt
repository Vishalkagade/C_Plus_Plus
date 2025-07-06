cmake_minimum_required(VERSION 3.22)
project(guassing_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Clang tools
include(/home/vishal/cPlusPlus/homework2/cmake/ClangFormat.cmake)

# Tell CMake to process the src folder
add_subdirectory(src)

# Optional: Set global output directory for all executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
