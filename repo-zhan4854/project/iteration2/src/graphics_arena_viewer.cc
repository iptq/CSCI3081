/**
 * @file graphics_arena_viewer.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/graphics_arena_viewer.h"

#include <nanogui/messagedialog.h>
#include <sys/time.h>

#include <iostream>
#include <string>
#include <vector>

#include "src/arena_params.h"
#include "src/common.h"
#include "src/event_keypress.h"
#include "src/game_state.h"
#include "src/home_base.h"
#include "src/obstacle.h"
#include "src/player.h"
#include "src/robot.h"
#include "src/sensor_proximity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
GraphicsArenaViewer::GraphicsArenaViewer(
    const struct arena_params *const params)
    : csci3081::GraphicsApp(params->x_dim, params->y_dim, "Robot Simulation"),
      arena_(new Arena(params)), pause_btn_(nullptr), show_dialog_(false),
      last_draw_time_(glfwGetTime()) {
    nanogui::FormHelper *gui = new nanogui::FormHelper(this);
    nanogui::ref<nanogui::Window> window =
        gui->addWindow(Eigen::Vector2i(10, 10), "Simulation Controls");
    gui->addButton("Restart",
                   std::bind(&GraphicsArenaViewer::OnRestartBtnPressed, this));
    pause_btn_ = gui->addButton(
        "Pause", std::bind(&GraphicsArenaViewer::OnPauseBtnPressed, this));

    performLayout();
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

// This is the primary driver for state change in the arena.
// It will be called at each iteration of nanogui::mainloop()
void GraphicsArenaViewer::UpdateSimulation(double dt) {
    switch (arena_->get_game_state()) {
    case GAME_WIN:
        if (!show_dialog_) {
            show_dialog_ = true;
            auto dlg = new nanogui::MessageDialog(
                this, nanogui::MessageDialog::Type::Information, "You Win!",
                "You Win!", "Restart", "", false);
            dlg->setCallback([&, this](__unused int result) {
                this->show_dialog_ = false;
                this->arena_->Reset();
            });
        }
        break;
    case GAME_LOSE:
        if (!show_dialog_) {
            show_dialog_ = true;
            auto dlg = new nanogui::MessageDialog(
                this, nanogui::MessageDialog::Type::Information, "You Lose!",
                "You Lose!", "Restart", "", false);
            dlg->setCallback([&, this](__unused int result) {
                this->show_dialog_ = false;
                this->arena_->Reset();
            });
        }
        break;
    case GAME_RUNNING:
        arena_->AdvanceTime(dt);
        break;
    case GAME_PAUSED:
    default:
        break;
    }
}

/*******************************************************************************
 * Handlers for User Keyboard and Mouse Events
 ******************************************************************************/
void GraphicsArenaViewer::OnRestartBtnPressed() { arena_->Reset(); }

void GraphicsArenaViewer::OnPauseBtnPressed() {
    // paused_ = !paused_;
    if (arena_->get_game_state() == GAME_RUNNING) {
        arena_->set_game_state(GAME_PAUSED);
        pause_btn_->setCaption("Play");
    } else {
        arena_->set_game_state(GAME_RUNNING);
        pause_btn_->setCaption("Pause");
    }
}

void GraphicsArenaViewer::OnMouseMove(__unused int x, __unused int y) {}

void GraphicsArenaViewer::OnLeftMouseDown(__unused int x, __unused int y) {}

void GraphicsArenaViewer::OnLeftMouseUp(__unused int x, __unused int y) {}

void GraphicsArenaViewer::OnRightMouseDown(__unused int x, __unused int y) {}

void GraphicsArenaViewer::OnRightMouseUp(__unused int x, __unused int y) {}

void GraphicsArenaViewer::OnKeyDown(const char *c, __unused int modifiers) {
    if (arena_->get_game_state() == GAME_RUNNING) {
        EventKeypress e(*c);
        arena_->Accept(&e);
    }
}

void GraphicsArenaViewer::OnKeyUp(__unused const char *c,
                                  __unused int modifiers) {}

void GraphicsArenaViewer::OnSpecialKeyDown(int key, __unused int scancode,
                                           __unused int modifiers) {
    if (arena_->get_game_state() == GAME_RUNNING) {
        EventKeypress e(key);
        arena_->Accept(&e);
    }
}

void GraphicsArenaViewer::OnSpecialKeyUp(__unused int key,
                                         __unused int scancode,
                                         __unused int modifiers) {}

/*******************************************************************************
 * Drawing of Entities in Arena
 ******************************************************************************/
void GraphicsArenaViewer::DrawPlayer(NVGcontext *ctx,
                                     const class Player *const player) {
    // translate and rotate all graphics calls that follow so that they are
    // centered, at the position and heading for this player
    csci3081::Color rcolor = player->get_color();
    csci3081::Position rpos = player->get_pos();
    double radius = player->get_radius();

    nvgSave(ctx);
    nvgTranslate(ctx, rpos.x, rpos.y);
    nvgRotate(ctx, player->get_heading_angle() * M_PI / 180);

    // player's circle
    nvgBeginPath(ctx);
    nvgCircle(ctx, 0.0, 0.0, radius);
    nvgFillColor(ctx,
                 nvgRGBA(static_cast<int>(rcolor.r), static_cast<int>(rcolor.g),
                         static_cast<int>(rcolor.b), 255));
    nvgFill(ctx);
    nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgStroke(ctx);

    // player id text label
    nvgSave(ctx);
    nvgRotate(ctx, M_PI / 2.0);
    NVGcolor labelColor = player->get_frozen() ? nvgRGBA(255, 16, 16, 255)
                                               : nvgRGBA(255, 255, 255, 255);
    nvgFillColor(ctx, labelColor);
    nvgText(ctx, 0.0, 10.0, player->get_name().c_str(), NULL);
    nvgRestore(ctx);
    nvgRestore(ctx);

    // draw a battery indicator
    nvgSave(ctx);
    nvgTranslate(ctx, rpos.x, rpos.y);
    nvgBeginPath(ctx);
    // black bar
    nvgRect(ctx, -radius, -radius - 5, 2 * radius, 5);
    nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgFill(ctx);
    nvgBeginPath(ctx);
    // battery bar
    // from https://stackoverflow.com/a/6394340
    auto percentage = player->get_battery_percentage();
    auto red = (percentage > 0.5 ? 1 - 2 * (percentage - 0.5) : 1.0) * 255;
    auto green = (percentage > 0.5 ? 1.0 : 2 * percentage) * 255;
    auto blue = 0.0;
    nvgRect(ctx, -radius, -radius - 5, 2.0 * radius * percentage, 5);
    nvgFillColor(ctx, nvgRGBA(red, green, blue, 255));
    nvgFill(ctx);
    nvgRestore(ctx);
}

void GraphicsArenaViewer::DrawRobot(NVGcontext *ctx,
                                    const class Robot *const robot) {
    // translate and rotate all graphics calls that follow so that they are
    // centered, at the position and heading for this player
    csci3081::Color rcolor = robot->get_color();
    csci3081::Position rpos = robot->get_pos();
    double radius = robot->get_radius();

    nvgSave(ctx);
    nvgTranslate(ctx, rpos.x, rpos.y);
    nvgRotate(ctx, robot->get_heading_angle() * M_PI / 180);

    // robot's circle
    nvgBeginPath(ctx);
    nvgCircle(ctx, 0.0, 0.0, radius);
    nvgFillColor(ctx,
                 nvgRGBA(static_cast<int>(rcolor.r), static_cast<int>(rcolor.g),
                         static_cast<int>(rcolor.b), 255));
    nvgFill(ctx);
    nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgStroke(ctx);

    // robot id text label
    nvgSave(ctx);
    nvgRotate(ctx, M_PI / 2.0);
    NVGcolor labelColor = robot->get_frozen() ? nvgRGBA(255, 16, 16, 255)
                                              : nvgRGBA(255, 255, 255, 255);
    nvgFillColor(ctx, labelColor);
    nvgText(ctx, 0.0, 10.0, robot->get_name().c_str(), NULL);
    nvgRestore(ctx);

    // proximity
    nvgSave(ctx);
    nvgBeginPath(ctx);
    nvgMoveTo(ctx, 0, 0);
    nvgFillColor(ctx, nvgRGBA(102, 204, 102, 32));
    nvgArc(ctx, 0, 0, PROXIMITY_RADIUS, 0,
           2 * M_PI - PROXIMITY_ANGLE * M_PI / 180, NVG_CCW);
    nvgFill(ctx);
    nvgClosePath(ctx);

    nvgBeginPath(ctx);
    nvgMoveTo(ctx, 0, 0);
    nvgFillColor(ctx, nvgRGBA(102, 102, 204, 32));
    nvgArc(ctx, 0, 0, PROXIMITY_RADIUS, 0, PROXIMITY_ANGLE * M_PI / 180,
           NVG_CW);
    nvgFill(ctx);
    nvgClosePath(ctx);
    nvgRestore(ctx);

    // distress beacon
    if (robot->get_frozen()) {
        double bradius = 2 * radius;
        double now = glfwGetTime();
        nvgSave(ctx);
        for (double i = (now - robot->get_time_last_frozen()); i > 0; i -= 1) {
            if (i > 3)
                continue;
            nvgBeginPath(ctx);
            nvgCircle(ctx, 0, 0, i * bradius);
            nvgStrokeColor(ctx, nvgRGBA(102, 102, 204, 192 - 64 * i));
            nvgStrokeWidth(ctx, i * 2.4);
            nvgStroke(ctx);
            nvgClosePath(ctx);
        }
        nvgRestore(ctx);
    }

    nvgRestore(ctx);
}

void GraphicsArenaViewer::DrawObstacle(NVGcontext *ctx,
                                       const Obstacle *const obstacle) {
    csci3081::Color ocolor = obstacle->get_color();
    csci3081::Position opos = obstacle->get_pos();
    double radius = obstacle->get_radius();

    nvgBeginPath(ctx);
    nvgCircle(ctx, opos.x, opos.y, radius);
    nvgFillColor(ctx,
                 nvgRGBA(static_cast<int>(ocolor.r), static_cast<int>(ocolor.g),
                         static_cast<int>(ocolor.b), 255));
    nvgFill(ctx);
    nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgStroke(ctx);

    nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgText(ctx, opos.x, opos.y, obstacle->get_name().c_str(), NULL);
}

void GraphicsArenaViewer::DrawHomeBase(NVGcontext *ctx,
                                       const HomeBase *const home) {
    csci3081::Color hcolor = home->get_color();
    csci3081::Position hpos = home->get_pos();
    double radius = home->get_radius();

    nvgBeginPath(ctx);
    nvgCircle(ctx, hpos.x, hpos.y, radius);
    nvgFillColor(ctx,
                 nvgRGBA(static_cast<int>(hcolor.r), static_cast<int>(hcolor.g),
                         static_cast<int>(hcolor.b), 255));
    nvgFill(ctx);
    nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgStroke(ctx);

    nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgText(ctx, hpos.x, hpos.y, home->get_name().c_str(), NULL);
}

// This is the primary driver for drawing all entities in the arena.
// It is called at each iteration of nanogui::mainloop()
void GraphicsArenaViewer::DrawUsingNanoVG(NVGcontext *ctx) {
    // initialize text rendering settings
    nvgFontSize(ctx, 18.0f);
    nvgFontFace(ctx, "sans-bold");
    nvgTextAlign(ctx, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

    // bg
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBA(33, 66, 99, 255));
    nvgRect(ctx, 0, 0, 1024, 768);
    nvgFill(ctx);
    nvgClosePath(ctx);

    std::vector<Obstacle *> obstacles = arena_->get_obstacles();
    for (size_t i = 0; i < obstacles.size(); i++) {
        DrawObstacle(ctx, obstacles[i]);
    } /* for(i..) */

    DrawPlayer(ctx, arena_->get_player());
    DrawHomeBase(ctx, arena_->get_home_base());

    std::vector<Robot *> robots = arena_->get_robots();
    for (size_t i = 0, l = robots.size(); i < l; ++i) {
        DrawRobot(ctx, robots[i]);
    }
}

NAMESPACE_END(csci3081);
