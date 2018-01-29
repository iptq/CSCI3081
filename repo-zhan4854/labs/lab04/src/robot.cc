#include "robot.h"
#include <stdlib.h>

Robot::Robot(double speed) {
    this->changeColors();

    this->speed = speed;
    this->radius = 50;
}

void Robot::changeColors() {
    this->color[0] = rand() % 255;
    this->color[1] = rand() % 255;
    this->color[2] = rand() % 255;
}

bool Robot::get_pos(double _t, double* x_pos, double* y_pos) {
    double t = _t * this->speed;
    *x_pos = this->circle_x(t);
    *y_pos = this->circle_y(t);

    return true;
}

bool Robot::get_vel(double _t, double* x_vel, double* y_vel) {
    double delta = 0.1;
    double t = _t * this->speed;
    double xnow, ynow, xprev, yprev;

    xnow = this->circle_x(t);
    ynow = this->circle_y(t);
    xprev = this->circle_x(t - delta);
    yprev = this->circle_y(t - delta);

    *x_vel = xnow - xprev;
    *y_vel = ynow - yprev;
    return true;
}

bool Robot::get_color(int* r, int* g, int* b) {
    *r = this->color[0];
    *g = this->color[1];
    *b = this->color[2];
    return true;
}

double Robot::get_radius() { return this->radius; }
