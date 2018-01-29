/**
 * @file home_base.cc
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#include <stdlib.h>
#include <sys/time.h>

#include "src/home_base.h"
#include "src/motion_behavior.h"

NAMESPACE_BEGIN(csci3081);

HomeBase::HomeBase(const struct home_base_params *const params)
    : ArenaMobileEntity(params->radius, params->collision_delta, params->pos,
                        params->color),
      heading_angle_(params->heading_angle), speed_(params->speed) {
    set_pos(params->pos);
}

void HomeBase::TimestepUpdate(double dt) {
    if (get_sensor_touch()->get_activated()) {
        heading_angle_ = -get_sensor_touch()->get_angle_of_contact();
        get_sensor_touch()->set_activated(false);
    }
    timeval seedtime;
    gettimeofday(&seedtime, NULL);
    unsigned int seed = seedtime.tv_usec;
    heading_angle_ += (rand_r(&seed) % 10 - 5);

    MotionBehavior h;
    h.UpdatePosition(this, dt);
} /* TimestepUpdate() */

void HomeBase::Accept(__unused EventRecharge *evt) {}

// Pass along a collision event (from arena) to the touch sensor.
// This method provides a framework in which sensors can get different
// types of information from different sources.
void HomeBase::Accept(EventCollision *evt) { get_sensor_touch()->Accept(evt); }

void HomeBase::Reset() { set_pos(get_initial()); }

NAMESPACE_END(csci3081);
