/**
 * @file circle_viewer.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef INCLUDE_CIRCLE_VIEWER_H_
#define INCLUDE_CIRCLE_VIEWER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/simple_graphics/graphics_app.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/**
 *  @brief An application that opens up a window that includes a few buttons for
 *  controlling the simulation and can be used to draw circles and other
 *  computer graphics.
 *
 *  After constructing a new \ref CircleViewer, call \ref Run() to start and run
 *  the application.  \ref Run() will not return until the application window is
 *  closed.  Make sure that you call \ref cs3081::InitGraphics() before creating the
 *  \ref RobotViewer app.  Example:
 *
 *  ```
 *  int main(int argc, char **argv) {
 *      cs3081::InitGraphics();
 *      cs3081::CircleViewer *app = new cs3081::CircleViewer();
 *      app->Run();
 *      cs3081::ShutdownGraphics();
 *      return 0;
 *  }
 *  ```
 *
 *  While the window is open \ref UpdateSimulation() will be called
 *  repeatedly, once per frame.  Fill this in to update your simulation
 *  or perform any other processing that should happen over time as the
 *  simulation progresses.
 *
 *  Fill in the On*() methods as desired to respond to user input events.
 *
 *  Fill in the Draw*() methods to draw graphics to the screen using
 *  either the nanovg library or raw OpenGL.
 */
class CircleViewer : public GraphicsApp {
 public:
  CircleViewer();
  ~CircleViewer();

  void UpdateSimulation(double dt);

  void OnRestartBtnPressed();

  void OnPauseBtnPressed();

  void OnMouseMove(int x, int y);

  void OnLeftMouseDown(int x, int y);

  void OnLeftMouseUp(int x, int y);

  void OnRightMouseDown(int x, int y);

  void OnRightMouseUp(int x, int y);

  void OnKeyDown(const char *c, int modifiers);

  void OnKeyUp(const char *c, int modifiers);

  void OnSpecialKeyDown(int key, int scancode, int modifiers);

  void OnSpecialKeyUp(int key, int scancode, int modifiers);

  void DrawUsingNanoVG(NVGcontext *ctx);

  void DrawUsingOpenGL();

 private:
  double sim_time_;
  bool paused_;
  nanogui::Button *pause_btn_;
};

NAMESPACE_END(csci3081);

#endif /* INCLUDE_CIRCLE_VIEWER_H_ */
