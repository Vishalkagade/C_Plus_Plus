# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vishal/cPlusPlus/homework3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vishal/cPlusPlus/homework3/build

# Include any dependencies generated for this target.
include CMakeFiles/html_writer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/html_writer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/html_writer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/html_writer.dir/flags.make

CMakeFiles/html_writer.dir/src/html_writer.cpp.o: CMakeFiles/html_writer.dir/flags.make
CMakeFiles/html_writer.dir/src/html_writer.cpp.o: ../src/html_writer.cpp
CMakeFiles/html_writer.dir/src/html_writer.cpp.o: CMakeFiles/html_writer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vishal/cPlusPlus/homework3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/html_writer.dir/src/html_writer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/html_writer.dir/src/html_writer.cpp.o -MF CMakeFiles/html_writer.dir/src/html_writer.cpp.o.d -o CMakeFiles/html_writer.dir/src/html_writer.cpp.o -c /home/vishal/cPlusPlus/homework3/src/html_writer.cpp

CMakeFiles/html_writer.dir/src/html_writer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/html_writer.dir/src/html_writer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vishal/cPlusPlus/homework3/src/html_writer.cpp > CMakeFiles/html_writer.dir/src/html_writer.cpp.i

CMakeFiles/html_writer.dir/src/html_writer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/html_writer.dir/src/html_writer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vishal/cPlusPlus/homework3/src/html_writer.cpp -o CMakeFiles/html_writer.dir/src/html_writer.cpp.s

# Object files for target html_writer
html_writer_OBJECTS = \
"CMakeFiles/html_writer.dir/src/html_writer.cpp.o"

# External object files for target html_writer
html_writer_EXTERNAL_OBJECTS =

libhtml_writer.a: CMakeFiles/html_writer.dir/src/html_writer.cpp.o
libhtml_writer.a: CMakeFiles/html_writer.dir/build.make
libhtml_writer.a: CMakeFiles/html_writer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vishal/cPlusPlus/homework3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhtml_writer.a"
	$(CMAKE_COMMAND) -P CMakeFiles/html_writer.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/html_writer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/html_writer.dir/build: libhtml_writer.a
.PHONY : CMakeFiles/html_writer.dir/build

CMakeFiles/html_writer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/html_writer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/html_writer.dir/clean

CMakeFiles/html_writer.dir/depend:
	cd /home/vishal/cPlusPlus/homework3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vishal/cPlusPlus/homework3 /home/vishal/cPlusPlus/homework3 /home/vishal/cPlusPlus/homework3/build /home/vishal/cPlusPlus/homework3/build /home/vishal/cPlusPlus/homework3/build/CMakeFiles/html_writer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/html_writer.dir/depend

