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
include CMakeFiles/TestBlankWindow.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestBlankWindow.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestBlankWindow.dir/flags.make

CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o: CMakeFiles/TestBlankWindow.dir/flags.make
CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o: ../src/main-blankwindow.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/School/CSCI3081/libSimpleGraphics/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o -c /home/michael/Documents/School/CSCI3081/libSimpleGraphics/src/main-blankwindow.cc

CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michael/Documents/School/CSCI3081/libSimpleGraphics/src/main-blankwindow.cc > CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.i

CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michael/Documents/School/CSCI3081/libSimpleGraphics/src/main-blankwindow.cc -o CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.s

CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o.requires:

.PHONY : CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o.requires

CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o.provides: CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o.requires
	$(MAKE) -f CMakeFiles/TestBlankWindow.dir/build.make CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o.provides.build
.PHONY : CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o.provides

CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o.provides.build: CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o


# Object files for target TestBlankWindow
TestBlankWindow_OBJECTS = \
"CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o"

# External object files for target TestBlankWindow
TestBlankWindow_EXTERNAL_OBJECTS =

TestBlankWindow: CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o
TestBlankWindow: CMakeFiles/TestBlankWindow.dir/build.make
TestBlankWindow: libsimple_graphics.a
TestBlankWindow: ext/nanogui/libnanogui.so
TestBlankWindow: CMakeFiles/TestBlankWindow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michael/Documents/School/CSCI3081/libSimpleGraphics/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestBlankWindow"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestBlankWindow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestBlankWindow.dir/build: TestBlankWindow

.PHONY : CMakeFiles/TestBlankWindow.dir/build

CMakeFiles/TestBlankWindow.dir/requires: CMakeFiles/TestBlankWindow.dir/src/main-blankwindow.cc.o.requires

.PHONY : CMakeFiles/TestBlankWindow.dir/requires

CMakeFiles/TestBlankWindow.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestBlankWindow.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestBlankWindow.dir/clean

CMakeFiles/TestBlankWindow.dir/depend:
	cd /home/michael/Documents/School/CSCI3081/libSimpleGraphics/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michael/Documents/School/CSCI3081/libSimpleGraphics /home/michael/Documents/School/CSCI3081/libSimpleGraphics /home/michael/Documents/School/CSCI3081/libSimpleGraphics/build /home/michael/Documents/School/CSCI3081/libSimpleGraphics/build /home/michael/Documents/School/CSCI3081/libSimpleGraphics/build/CMakeFiles/TestBlankWindow.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestBlankWindow.dir/depend

