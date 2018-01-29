#include <iostream>

#include "robot.h"
#include "tests.h"

void robot_unittest() {
    Robot robot;
    ExpectEqual("Default r", robot.get_radius(), 5);
    ExpectEqual("Default x", robot.get_position().x, 0);
    ExpectEqual("Default y", robot.get_position().y, 0);

    Robot *robot1 = new Robot(1, 0, 0), *robot2 = new Robot(1, 2, 0);
    ExpectEqual("Should not collide.", robot1->CheckOverlap(*robot2), false);
    delete robot1;
    delete robot2;

    robot1 = new Robot(2, 0, 0), robot2 = new Robot(2, 1, 0);
    ExpectEqual("Should collide.", robot1->CheckOverlap(*robot2), true);
}
