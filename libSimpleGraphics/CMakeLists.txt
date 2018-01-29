cmake_minimum_required(VERSION 2.8.12)
project(simple_graphics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

#set(NANOGUI_BUILD_EXAMPLE OFF CACHE BOOL "Build NanoGUI example application?")
#set(NANOGUI_BUILD_SHARED OFF CACHE BOOL "Build NanoGUI as a shared library?")


add_subdirectory(ext/nanogui)
include_directories(ext/nanogui/include)
include_directories(${NANOGUI_EXTRA_INCS})
include_directories(.)
add_definitions(${NANOGUI_EXTRA_DEFS})

add_library(simple_graphics STATIC src/graphics_app.cc src/circle_viewer.cc)
target_link_libraries(simple_graphics nanogui ${NANOGUI_EXTRA_LIBS})

add_executable(TestCircles src/main-circleviewer.cc)
target_link_libraries(TestCircles simple_graphics)

add_executable(TestBlankWindow src/main-blankwindow.cc)
target_link_libraries(TestBlankWindow simple_graphics)


install(TARGETS simple_graphics
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

install(FILES include/simple_graphics/graphics_app.h
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/simple_graphics)

install(DIRECTORY ext/nanogui/include/nanogui DESTINATION ${CMAKE_INSTALL_PREFIX}/include
        FILES_MATCHING PATTERN "*.h")

install(DIRECTORY ext/nanogui/ext/eigen/Eigen DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

install(DIRECTORY ext/nanogui/ext/glfw/include/GLFW DESTINATION ${CMAKE_INSTALL_PREFIX}/include
        FILES_MATCHING PATTERN glfw3.h PATTERN glfw3native.h)

install(DIRECTORY ext/nanogui/ext/nanovg/src/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include
        FILES_MATCHING PATTERN "*.h")
