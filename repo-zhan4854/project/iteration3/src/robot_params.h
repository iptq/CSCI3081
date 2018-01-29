/**
 * @file robot_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_PARAMS_H_
#define SRC_ROBOT_PARAMS_H_

#include "src/arena_mobile_entity_params.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief A set of parameters used to initialize a Robot.
 *
 * None of the variables have actually been initialized, they should be
 * initialized in main.cc.
 */
struct robot_params : public arena_mobile_entity_params {
    //! @brief Constructor for the robot parameter set.
    robot_params(void) : arena_mobile_entity_params(), heading_angle() {}

    //! @brief The initial starting angle for the robot.
    double heading_angle;
};

NAMESPACE_END(csci3081);

#endif  // SRC_ROBOT_PARAMS_H_
