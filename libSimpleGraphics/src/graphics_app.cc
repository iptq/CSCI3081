/**
 * @file graphics_app.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/simple_graphics/graphics_app.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
GraphicsApp::GraphicsApp(int width, int height, const std::string &caption)
    : nanogui::Screen(Eigen::Vector2i(width, height), caption) {
  drawAll();
  setVisible(true);
  performLayout();
  last_draw_time_ = 0.0;
}

GraphicsApp::~GraphicsApp() {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void GraphicsApp::Run() {
  glfwSetTime(0.0);
  nanogui::mainloop();
}

bool GraphicsApp::mouseButtonEvent(const Eigen::Vector2i &p, int button,
                                     bool down, int modifiers) {
  if (Screen::mouseButtonEvent(p, button, down, modifiers)) {
    return true;
  } else if (button == GLFW_MOUSE_BUTTON_LEFT) {
    if (down) {
      OnLeftMouseDown(p[0], p[1]);
    } else {
      OnLeftMouseUp(p[0], p[1]);
    }
    return true;
  } else if (button == GLFW_MOUSE_BUTTON_RIGHT) {
    if (down) {
      OnRightMouseDown(p[0], p[1]);
    } else {
      OnRightMouseUp(p[0], p[1]);
    }
    return true;
  }
  return false;
}

bool GraphicsApp::mouseMotionEvent(const Eigen::Vector2i &p,
                                   const Eigen::Vector2i &rel, int button,
                                   int modifiers) {
  if (Screen::mouseMotionEvent(p, rel, button, modifiers)) {
    return true;
  } else {
    OnMouseMove(p[0], p[1]);
    return true;
  }
}

bool GraphicsApp::keyboardEvent(int key, int scancode, int action,
                                int modifiers) {
  if (Screen::keyboardEvent(key, scancode, action, modifiers)) {
    return true;
  } else {
    if (glfwGetKeyName(key, scancode) != NULL) {
      if (action == GLFW_PRESS) {
        OnKeyDown(glfwGetKeyName(key, scancode), modifiers);
      } else {
        OnKeyUp(glfwGetKeyName(key, scancode), modifiers);
      }
      return true;
    } else {
      if (action == GLFW_PRESS) {
        OnSpecialKeyDown(key, scancode, modifiers);
      } else {
        OnSpecialKeyUp(key, scancode, modifiers);
      }
      return true;
    }
  }
}

void GraphicsApp::draw(NVGcontext *ctx) {
  double now = glfwGetTime();
  UpdateSimulation(now - last_draw_time_);
  UpdateSimulation(static_cast<unsigned int>(now - last_draw_time_));

  last_draw_time_ = now;

  /* Draw the user interface using the nanogui library, which is built upon
   * nanovg */
  Screen::draw(ctx);

  /* Draw other vector graphics using the nanovg library */
  DrawUsingNanoVG(ctx);
}

void GraphicsApp::DrawContents() {
  /* Draw the underlying window contents (e.g., your own 3D graphics) using raw
   * OpenGL */
  DrawUsingOpenGL();
}

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
void InitGraphics() { nanogui::init(); }

void ShutdownGraphics() { nanogui::shutdown(); }


NAMESPACE_END(csci3081);
