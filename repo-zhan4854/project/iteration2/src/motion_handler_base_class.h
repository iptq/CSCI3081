/**
 * @file motion_handler_base_class.h
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#ifndef SRC_MOTION_HANDLER_BASE_CLASS_H_
#define SRC_MOTION_HANDLER_BASE_CLASS_H_

#include <stdio.h>

#include "src/common.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief The base class for a Motion Handler.
 */
class MotionHandlerBaseClass {
 public:
    //! @brief Default constructor.
    MotionHandlerBaseClass()
        : heading_angle_(0), speed_(0), max_speed_(500), angle_delta_(5),
          initial_speed_() {}

    /**
     * @brief Reset the actuators to their newly constructed/un-commanded state.
     */
    void Reset(void) {
        heading_angle_ = -143;
        speed_ = initial_speed_;
    }

    //! @brief Gets the current speed of the robot.
    double get_speed() { return speed_; }

    //! @brief Sets the current speed of the robot.
    void set_speed(double sp) { speed_ = sp; }

    //! @brief Gets the current heading angle of the robot.
    double get_heading_angle() const { return heading_angle_; }
    /**
     * @brief Sets the current heading angle of the robot.
     *
     * This angle is measured in degrees. Should the angle provided ever fall
     * out of the range of 0 to 360 degrees, this function will correct the
     * value before setting it. This way, the robot's angles will be a finite
     * field rather than increasing infinitely.
     */
    void set_heading_angle(double ha) {
        while (ha > 360)
            ha -= 360;
        while (ha < 0)
            ha += 360;
        heading_angle_ = ha;
    }

    //! @brief Gets the maximum possible speed of the robot.
    double get_max_speed() { return max_speed_; }

    //! @brief Sets the maximum possible speed of the robot.
    void set_max_speed(double ms) { max_speed_ = ms; }

    //! @brief Gets the angle that the robot turns by.
    double get_angle_delta() const { return angle_delta_; }

    //! @brief Sets the angle that the robot turns by.
    void set_angle_delta(double ad) { angle_delta_ = ad; }

    //! @brief Gets the initial speed, useful for resetting.
    double get_initial_speed() { return initial_speed_; }

    //! @brief Sets the initial speed of the robot.
    void set_initial_speed(double speed) {
        speed_ = speed;
        initial_speed_ = speed;
    }

 private:
    //! @brief The current heading angle, used for calculations.
    double heading_angle_;

    //! @brief The current speed.
    double speed_;

    //! @brief The maximum speed of the motion handler.
    double max_speed_;

    //! @brief The angle in degrees to change by.
    double angle_delta_;

    //! @brief The initial speed, eventually will be replaced by params.
    double initial_speed_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_MOTION_HANDLER_BASE_CLASS_H_
