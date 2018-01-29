#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <math.h>

class Robot {
   public:
    Robot(double speed);
    void changeColors();
    bool get_pos(double t, double* x_pos, double* y_pos);
    bool get_vel(double t, double* x_vel, double* y_vel);
    bool get_color(int* r, int* g, int* b);
    double get_radius();

   private:
    double speed;
    double radius;
    int color[3];
    double circle_x(double t) { return 512 + 200.0 * cos(t); }
    double circle_y(double t) { return 350 + 200.0 * sin(t); }
};

#endif
