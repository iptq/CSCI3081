/**
 * @file main-circleviewer.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/simple_graphics/circle_viewer.h"

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
int main(int argc, char **argv) {
  csci3081::InitGraphics();

  csci3081::CircleViewer *app = new csci3081::CircleViewer();
  app->Run();

  csci3081::ShutdownGraphics();

  return 0;
}
