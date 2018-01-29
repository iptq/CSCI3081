/**
 * @file main-blankwindow.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * The GraphicsApp base class can also run as its own app, but it just displays
 * a blank screen
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/simple_graphics/graphics_app.h"

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
int main(int argc, char **argv) {
  csci3081::InitGraphics();

  csci3081::GraphicsApp *app =
      new csci3081::GraphicsApp(1024, 768, "3081 Graphics App");
  app->Run();

  csci3081::ShutdownGraphics();

  return 0;
}
