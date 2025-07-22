
# Add executable using source file
add_executable(task_1 main.cpp)

# Set output directory just for this target (if not using global one)
set_target_properties(task_1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

# Compiler warnings
target_compile_options(task_1 PRIVATE -Wall -Wextra -Werror)
