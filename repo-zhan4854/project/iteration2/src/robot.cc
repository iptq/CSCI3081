/**
 * @file robot.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#include <stdlib.h>
#include <sys/time.h>

#include <algorithm>

#include "src/motion_behavior.h"
#include "src/robot.h"
#include "src/sensor_proximity_superbot.h"

NAMESPACE_BEGIN(csci3081);

uint Robot::next_id_ = 0;

Robot::Robot(const struct robot_params *const params)
    : ArenaMobileEntity(params->radius, params->collision_delta, params->pos,
                        Color(184, 184, 92, 255)),
      initial_params_(*params), id_(-1), entity_type_(), motion_behavior_(),
      motion_handler_(), sensor_proximity_left_(), sensor_proximity_right_(),
      sensor_distress_(), sensor_entity_type_() {
    id_ = next_id_++;
    sensor_proximity_left_ = new SensorProximity();
    sensor_proximity_right_ = new SensorProximity();

    timeval seedtime;
    gettimeofday(&seedtime, NULL);
    unsigned int seed = seedtime.tv_usec;

    double sp = rand_r(&seed) % 10 + 35;
    motion_handler_.set_initial_speed(sp);
    set_speed(sp);
    set_heading_angle(params->heading_angle);

    sensor_distress_.set_parent(this);
    sensor_entity_type_.set_parent(this);
    sensor_proximity_left_->set_parent(this);
    sensor_proximity_right_->set_parent(this);
    get_sensor_touch()->set_parent(this);
}

void Robot::Reset(void) {
    motion_handler_.Reset();
    delete sensor_proximity_left_;
    delete sensor_proximity_right_;
    sensor_proximity_left_ = new SensorProximity();
    sensor_proximity_right_ = new SensorProximity();
    sensor_distress_.Reset();
    get_sensor_touch()->Reset();
    dec_fcountdown(get_fcountdown() + 1);  // unfreeze this Mans

    entity_type_ = kRobot;
    set_color(Color(184, 184, 92, 255));
    set_pos(initial_params_.pos);

    timeval seedtime;
    gettimeofday(&seedtime, NULL);
    unsigned int seed = seedtime.tv_usec;

    double sp = rand_r(&seed) % 10 + 35;
    motion_handler_.set_initial_speed(sp);
    set_speed(sp);
    set_heading_angle(initial_params_.heading_angle);
}

void Robot::TimestepUpdate(double dt) {
    if (get_sensor_touch()->get_activated()) {
        set_heading_angle(-get_sensor_touch()->get_angle_of_contact());
        get_sensor_touch()->set_activated(false);
    }

    motion_behavior_.UpdatePosition(this, dt);
}

void Robot::Accept(__unused EventRecharge *e) {}
void Robot::Accept(__unused EventCollision *e) {}

void Robot::upgrade() {
    printf("im a big boi\n");
    set_color(Color(184, 92, 0, 255));
    set_entity_type(kSuperBot);

    // swap out sensor proximity (for ignoring player)
    // btw this is a really bad way to do it
    // had to do it this way because of constraints
    delete sensor_proximity_left_;
    delete sensor_proximity_right_;
    sensor_proximity_left_ = new SensorProximitySuperbot();
    sensor_proximity_right_ = new SensorProximitySuperbot();
}

NAMESPACE_END(csci3081);
