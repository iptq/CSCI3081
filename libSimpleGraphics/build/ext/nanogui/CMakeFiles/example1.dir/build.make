# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/michael/Documents/School/CSCI3081/libSimpleGraphics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michael/Documents/School/CSCI3081/libSimpleGraphics/build

# Include any dependencies generated for this target.
include ext/nanogui/CMakeFiles/example1.dir/depend.make

# Include the progress variables for this target.
include ext/nanogui/CMakeFiles/example1.dir/progress.make

# Include the compile flags for this target's objects.
include ext/nanogui/CMakeFiles/example1.dir/flags.make

ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.o: ext/nanogui/CMakeFiles/example1.dir/flags.make
ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.o: ../ext/nanogui/src/example1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/School/CSCI3081/libSimpleGraphics/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.o"
	cd /home/michael/Documents/School/CSCI3081/libSimpleGraphics/build/ext/nanogui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example1.dir/src/example1.cpp.o -c /home/michael/Documents/School/CSCI3081/libSimpleGraphics/ext/nanogui/src/example1.cpp

ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example1.dir/src/example1.cpp.i"
	cd /home/michael/Documents/School/CSCI3081/libSimpleGraphics/build/ext/nanogui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michael/Documents/School/CSCI3081/libSimpleGraphics/ext/nanogui/src/example1.cpp > CMakeFiles/example1.dir/src/example1.cpp.i

ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example1.dir/src/example1.cpp.s"
	cd /home/michael/Documents/School/CSCI3081/libSimpleGraphics/build/ext/nanogui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michael/Documents/School/CSCI3081/libSimpleGraphics/ext/nanogui/src/example1.cpp -o CMakeFiles/example1.dir/src/example1.cpp.s

ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.o.requires:

.PHONY : ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.o.requires

ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.o.provides: ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.o.requires
	$(MAKE) -f ext/nanogui/CMakeFiles/example1.dir/build.make ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.o.provides.build
.PHONY : ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.o.provides

ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.o.provides.build: ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.o


# Object files for target example1
example1_OBJECTS = \
"CMakeFiles/example1.dir/src/example1.cpp.o"

# External object files for target example1
example1_EXTERNAL_OBJECTS =

ext/nanogui/example1: ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.o
ext/nanogui/example1: ext/nanogui/CMakeFiles/example1.dir/build.make
ext/nanogui/example1: ext/nanogui/libnanogui.so
ext/nanogui/example1: ext/nanogui/CMakeFiles/example1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michael/Documents/School/CSCI3081/libSimpleGraphics/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example1"
	cd /home/michael/Documents/School/CSCI3081/libSimpleGraphics/build/ext/nanogui && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ext/nanogui/CMakeFiles/example1.dir/build: ext/nanogui/example1

.PHONY : ext/nanogui/CMakeFiles/example1.dir/build

ext/nanogui/CMakeFiles/example1.dir/requires: ext/nanogui/CMakeFiles/example1.dir/src/example1.cpp.o.requires

.PHONY : ext/nanogui/CMakeFiles/example1.dir/requires

ext/nanogui/CMakeFiles/example1.dir/clean:
	cd /home/michael/Documents/School/CSCI3081/libSimpleGraphics/build/ext/nanogui && $(CMAKE_COMMAND) -P CMakeFiles/example1.dir/cmake_clean.cmake
.PHONY : ext/nanogui/CMakeFiles/example1.dir/clean

ext/nanogui/CMakeFiles/example1.dir/depend:
	cd /home/michael/Documents/School/CSCI3081/libSimpleGraphics/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michael/Documents/School/CSCI3081/libSimpleGraphics /home/michael/Documents/School/CSCI3081/libSimpleGraphics/ext/nanogui /home/michael/Documents/School/CSCI3081/libSimpleGraphics/build /home/michael/Documents/School/CSCI3081/libSimpleGraphics/build/ext/nanogui /home/michael/Documents/School/CSCI3081/libSimpleGraphics/build/ext/nanogui/CMakeFiles/example1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ext/nanogui/CMakeFiles/example1.dir/depend
