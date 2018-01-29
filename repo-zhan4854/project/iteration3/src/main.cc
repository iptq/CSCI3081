/**
 * @file main.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#include "src/arena_params.h"
#include "src/color.h"
#include "src/graphics_arena_viewer.h"

/**
 * @brief Main entry point to the program.
 *
 * This function creates all of the hardcoded parameter sets and initializing
 * the GraphicsArenaViewer class using those sets. Command-line parameters are
 * not used.
 */
int main(int, char **) {
    // Essential call to initiate the graphics window
    csci3081::InitGraphics();

    // Initialize default start values for various arena entities
    csci3081::player_params pparams;

    pparams.battery_max_charge = 100.0;
    pparams.angle_delta = 5;
    pparams.collision_delta = 1;
    pparams.radius = 20.0;
    pparams.pos = csci3081::Position(924, 668);
    pparams.color = csci3081::Color(0, 0, 255, 255); /* blue */

    csci3081::arena_params aparams;

    aparams.player = pparams;

    aparams.recharge_station.radius = 20.0;
    aparams.recharge_station.pos = {600, 150};
    aparams.recharge_station.color =
        csci3081::Color(0, 255, 128, 255); /* green */

    aparams.home_base.radius = 20.0;
    aparams.home_base.collision_delta = 1;
    aparams.home_base.pos = {300, 300};
    aparams.home_base.heading_angle = 90;
    aparams.home_base.speed = 40;                              // 20;
    aparams.home_base.color = csci3081::Color(255, 0, 0, 255); /* red */

    aparams.obstacles[0].radius = 30.0;
    aparams.obstacles[0].pos = {150, 150};
    aparams.obstacles[0].color =
        csci3081::Color(255, 255, 255, 255); /* white */

    aparams.obstacles[1].radius = 30.0;
    aparams.obstacles[1].pos = {300, 150};
    aparams.obstacles[1].color =
        csci3081::Color(255, 255, 255, 255); /* white */

    aparams.obstacles[2].radius = 30.0;
    aparams.obstacles[2].pos = {450, 150};
    aparams.obstacles[2].color =
        csci3081::Color(255, 255, 255, 255); /* white */

    aparams.obstacles[3].radius = 30.0;
    aparams.obstacles[3].pos = {150, 300};
    aparams.obstacles[3].color =
        csci3081::Color(255, 255, 255, 255); /* white */

    aparams.obstacles[4].radius = 30.0;
    aparams.obstacles[4].pos = {450, 300};
    aparams.obstacles[4].color =
        csci3081::Color(255, 255, 255, 255); /* white */

    aparams.n_obstacles = 5;

    aparams.robots[0].radius = 20.0;
    aparams.robots[0].pos = {300, 450};
    aparams.robots[0].heading_angle = 0;

    aparams.robots[1].radius = 20.0;
    aparams.robots[1].pos = {300, 600};
    aparams.robots[1].heading_angle = 315;

    aparams.robots[2].radius = 20.0;
    aparams.robots[2].pos = {450, 600};
    aparams.robots[2].heading_angle = 270;

    aparams.robots[3].radius = 20.0;
    aparams.robots[3].pos = {600, 600};
    aparams.robots[3].heading_angle = 225;

    aparams.robots[4].radius = 20.0;
    aparams.robots[4].pos = {600, 450};
    aparams.robots[4].heading_angle = 180;

    aparams.n_robots = 5;
    aparams.x_dim = 1024;
    aparams.y_dim = 768;

    // Start up the graphics (which creates the arena).
    // Run will enter the nanogui::mainloop()
    csci3081::GraphicsArenaViewer *app =
        new csci3081::GraphicsArenaViewer(&aparams);
    app->Run();
    csci3081::ShutdownGraphics();
    return 0;
}
