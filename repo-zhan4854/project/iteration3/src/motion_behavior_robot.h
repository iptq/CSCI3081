/**
 * @file motion_behavior_robot.h
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#ifndef SRC_MOTION_BEHAVIOR_ROBOT_H_
#define SRC_MOTION_BEHAVIOR_ROBOT_H_

#include "src/decl.h"
#include "src/motion_behavior.h"

NAMESPACE_BEGIN(csci3081);

class MotionBehaviorRobot : public MotionBehavior {
 public:
    MotionBehaviorRobot(void) {}

    void UpdatePosition(class Robot *ent, double dt);
};

NAMESPACE_END(csci3081);

#endif  // SRC_MOTION_BEHAVIOR_ROBOT_H_
