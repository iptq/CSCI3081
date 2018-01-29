/**
 * @file circle_viewer.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/simple_graphics/circle_viewer.h"
#include <iostream>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
CircleViewer::CircleViewer() : GraphicsApp(1024, 768, "Circle Simulation") {
  nanogui::FormHelper *gui = new nanogui::FormHelper(this);
  nanogui::ref<nanogui::Window> window =
      gui->addWindow(Eigen::Vector2i(10, 10), "Simulation Controls");
  pause_btn_ = gui->addButton("Pause",
                             std::bind(&CircleViewer::OnPauseBtnPressed, this));
  gui->addButton("Restart",
                 std::bind(&CircleViewer::OnRestartBtnPressed, this));

  performLayout();

  sim_time_ = 0.0;
  paused_ = false;
}

CircleViewer::~CircleViewer() {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void CircleViewer::UpdateSimulation(double dt) {
  if (!paused_) {
    sim_time_ += dt;
    std::cout << "Update Simulation " << sim_time_ << std::endl;
  }
}

void CircleViewer::OnRestartBtnPressed() { sim_time_ = 0.0; }

void CircleViewer::OnPauseBtnPressed() {
  paused_ = !paused_;
  if (paused_) {
    pause_btn_->setCaption("Play");
  } else {
    pause_btn_->setCaption("Pause");
  }
}

void CircleViewer::OnMouseMove(int x, int y) {
  std::cout << "Mouse moved to (" << x << ", " << y << ")" << std::endl;
}

void CircleViewer::OnLeftMouseDown(int x, int y) {
  std::cout << "Left mouse button DOWN (" << x << ", " << y << ")" << std::endl;
}

void CircleViewer::OnLeftMouseUp(int x, int y) {
  std::cout << "Left mouse button UP (" << x << ", " << y << ")" << std::endl;
}

void CircleViewer::OnRightMouseDown(int x, int y) {
  std::cout << "Right mouse button DOWN (" << x << ", " << y << ")"
            << std::endl;
}

void CircleViewer::OnRightMouseUp(int x, int y) {
  std::cout << "Right mouse button UP (" << x << ", " << y << ")" << std::endl;
}

void CircleViewer::OnKeyDown(const char *c, int modifiers) {
  std::cout << "Key DOWN (" << c << ") modifiers=" << modifiers << std::endl;
}

void CircleViewer::OnKeyUp(const char *c, int modifiers) {
  std::cout << "Key UP (" << c << ") modifiers=" << modifiers << std::endl;
}

void CircleViewer::OnSpecialKeyDown(int key, int scancode, int modifiers) {
  std::cout << "Special Key DOWN key=" << key << " scancode=" << scancode
            << " modifiers=" << modifiers << std::endl;
}

void CircleViewer::OnSpecialKeyUp(int key, int scancode, int modifiers) {
  std::cout << "Special Key UP key=" << key << " scancode=" << scancode
            << " modifiers=" << modifiers << std::endl;
}

void CircleViewer::DrawUsingNanoVG(NVGcontext *ctx) {
  // example of drawing some circles

  nvgBeginPath(ctx);
  nvgCircle(ctx, 512 + 50.0 * cos(sim_time_), 350 + 200.0 * sin(sim_time_), 50);
  nvgFillColor(ctx, nvgRGBA(100, 100, 255, 200));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  nvgBeginPath(ctx);
  nvgCircle(ctx, 512 + 200.0 * cos(sim_time_), 350 + 50.0 * sin(sim_time_), 50);
  nvgFillColor(ctx, nvgRGBA(255, 100, 100, 200));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);
}

void CircleViewer::DrawUsingOpenGL() {}

NAMESPACE_END(csci3081);
