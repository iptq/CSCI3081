/**
 * @file motion_behavior_robot.cc
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#include <stdlib.h>
#include <sys/time.h>

#include <algorithm>

#include "src/motion_behavior_robot.h"
#include "src/robot.h"
#include "src/sensor_proximity.h"

NAMESPACE_BEGIN(csci3081);

void MotionBehaviorRobot::UpdatePosition(class Robot *bot, double dt) {
    if (bot->get_frozen())
        return;

    SensorProximity *lsensor = bot->get_sensor_proximity_left(),
                    *rsensor = bot->get_sensor_proximity_right();

    // avoid other robots
    double multiplier = 0, curr_multiplier, sp, ini;
    if (lsensor->get_activated() && lsensor->get_response() == kAvoid) {
        curr_multiplier = -lsensor->get_distance();
        if (abs(curr_multiplier) > abs(multiplier))
            multiplier = curr_multiplier;
        lsensor->set_activated(false);
    }
    if (rsensor->get_activated() && rsensor->get_response() == kAvoid) {
        curr_multiplier = rsensor->get_distance();
        if (abs(curr_multiplier) > abs(multiplier))
            multiplier = curr_multiplier;
        rsensor->set_activated(false);
    }

    if (multiplier == 0) {
        // move it randomly for now
        timeval seedtime;
        gettimeofday(&seedtime, NULL);
        unsigned int seed = seedtime.tv_usec;
        bot->set_heading_angle(bot->get_heading_angle() +
                               (rand_r(&seed) % 10 - 5));

        // try to get back up to initial speed
        ini = bot->get_initial_speed();
        if ((sp = bot->get_speed()) < ini) {
            bot->set_speed(std::min(ini, sp + SLOWDOWN_CONSTANT));
        }
    } else {
        bot->set_heading_angle(bot->get_heading_angle() +
                               multiplier * PROXIMITY_CONSTANT);

        // slow down boi
        if ((sp = bot->get_speed()) > SLOWDOWN_CONSTANT) {
            bot->set_speed(sp - SLOWDOWN_CONSTANT);
        }
    }

    MotionBehavior::UpdatePosition(bot, dt);
}

NAMESPACE_END(csci3081);
