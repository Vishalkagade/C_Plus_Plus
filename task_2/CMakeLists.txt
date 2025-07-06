cmake_minimum_required(VERSION 3.10)
project(ipb_arithmetic)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 1) Tell CMake where to look for headers:
#    This makes `#include <ipb_arithmetic/add.hpp>` work.
include_directories("${PROJECT_SOURCE_DIR}/include")

# 2) Build the library target:
add_library(ipb_arithmetic
    src/sum.cpp
    src/subtract.cpp
)

# 3) Specify that users of the library need the include/ directory:
target_include_directories(ipb_arithmetic
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)

# 4) Build your example executable:
add_executable(example_app
    src/main.cpp
)
# Link it against your library:
target_link_libraries(example_app ipb_arithmetic
)

# 5) Standard install rules:
include(GNUInstallDirs)

# install(TARGETS ipb_arithmetic example_app
#     EXPORT ipb_arithmeticTargets
#     ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}   # .a files
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}   # .so/.dylib
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}   # executables
# )

# # 6) Install headers so that users can #include <ipb_arithmetic/...>
# install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/ipb_arithmetic"
#     DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
# )

