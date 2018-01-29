# libSimpleGraphics

This code has been compiled and made available to you via cselabs machines at /project/f17c3081. The makefile that is included with the project already references that directory for linking. This repo is provided for you so that you can set up on your own platform. Take special note ...

1. **The project must compile on a cselabs machine when submitted for grading.**
2. **This code should not be in your repository. Clone this into a separate location and modify a local copy of the makefile to refer back to this directory on your local machine.**
3. **You do not need to clone this repository if you are working on a cselabs machine.**


## How to build and then install the libSimpleGraphics.a, headers, and all dependencies on your local machine:

To install libSimpleGraphics on your local machine, you will need cmake. Before continuing with the installation of libSimpleGraphics, please follow the instructions to install cmake specified [here.](https://cmake.org/install/)

You now need to clone the libSimpleGraphics repository onto your local machine. Run the following command whilst in your working directory.
```
git clone https://github.umn.edu/umn-csci-3081F17/libSimpleGraphics.git
cd libSimpleGraphics
```

Now that you have cloned libSimpleGraphics into your local machine, you need to update the nanogui submodule present within libSimpleGraphics.
```
git submodule update --init --recursive
```
Next, let us compile and install libSimpleGraphics on to your machine. The -DCMAKE_INSTALL_PREFIX specifies where libSimpleGraphics must be installed. Linux and Mac users are advised to run the command as it is. Windows users must specify a valid windows path where they want the installation to occur.
```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/project/f17c3081 ..
make all
make install
```

NOTE: Windows users must also modify their makefile in the src folder of the RobotSimulator application to point CS3081DIR to the location used when installing libSimpleGraphics.

This will build 1 library (libSimpleGraphics.a) and 2 programs (TestBlankWindow and TestCircles).
Only the library gets installed.
TestCircles was the precursor to the RobotViewer app used in 3081W.
Look at the RobotViewer app for a more sophisticated example that also shows how to link with a pre-installed version of libSimpleGraphics using a regular Makefile rather than building with cmake as is done for the two Test* examples here.

## Notes on reverse engineering dependencies for the graphics libraries:

Run make VERBOSE=1 to have the cmake generated Makefiles print out the actual commands they are running.  With this, you should be able to see the actual command lines used to run g++.  Then, the -L, -I, and other flags could be recreated in your own Makefile if you wish.  That is probably the easiest way to figure out how to build a project with this library without cmake.

For example, from my mac laptop, it looks like this is the example of how to compile main-robotviewer.cpp:

/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   -DGLAD_GLAPI_EXPORT -DNANOGUI_PYTHON -DNANOGUI_SHARED -DNVG_SHARED -std=c++14 -O3 -DNDEBUG -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk -I/Users/keefe/ivlab-github/sw/libSimpleGraphics/ext/nanogui/include -I/Users/keefe/ivlab-github/sw/libSimpleGraphics/ext/nanogui/ext/glfw/include -I/Users/keefe/ivlab-github/sw/libSimpleGraphics/ext/nanogui/ext/nanovg/src -I/Users/keefe/ivlab-github/sw/libSimpleGraphics/ext/nanogui/ext/eigen    -o CMakeFiles/RobotViewer.dir/main-robotviewer.cpp.o -c /Users/keefe/ivlab-github/sw/libSimpleGraphics/main-robotviewer.cpp


And, this is how to link RobotViewer:

/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++    -std=c++14 -O3 -DNDEBUG -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk -Wl,-search_paths_first -Wl,-headerpad_max_install_names  CMakeFiles/RobotViewer.dir/main-robotviewer.cpp.o  -o RobotViewer  libSimpleGraphics.dylib ext/nanogui/libnanogui.dylib -framework Cocoa -framework OpenGL -framework CoreVideo -framework IOKit -Wl,-rpath,/Users/keefe/ivlab-github/sw/libSimpleGraphics/build/ext/nanogui



The OpenGL and X-Windows libraries will be different on linux, but it looks like the key things in addition to that will be:

DEFINES:  -DGLAD_GLAPI_EXPORT -DNANOGUI_PYTHON -DNANOGUI_SHARED -DNVG_SHARED

COMPILER_FLAGS:  -std=c++14

INCLUDE_DIRS:  -Iext/nanogui/include -Iext/nanogui/ext/glfw/include -Iext/nanogui/ext/nanovg/src -Iext/nanogui/ext/eigen

LINK_LIBS:   libSimpleGraphics.so ext/nanogui/libnanogui.so -Wl,-rpath,/Users/keefe/ivlab-github/sw/libSimpleGraphics/build/ext/nanogui
