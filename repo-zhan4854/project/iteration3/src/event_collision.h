/**
 * @file event_collision.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_COLLISION_H_
#define SRC_EVENT_COLLISION_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_base_class.h"
#include <stdlib.h>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class EventCollision : public EventBaseClass {
 public:
    EventCollision()
        : collided_(false), point_of_contact_(0, 0), angle_of_contact_(0) {}
    EventCollision *opposite(void);
    void EmitMessage(void) {}

    bool get_collided() { return collided_; }
    void set_collided(bool c) { collided_ = c; }

    Position get_point_of_contact() { return point_of_contact_; }
    void set_point_of_contact(Position p) { point_of_contact_ = p; }

    double get_angle_of_contact() { return angle_of_contact_; }
    void set_angle_of_contact(double aoc) { angle_of_contact_ = aoc; }

 private:
    bool collided_;
    Position point_of_contact_;
    double angle_of_contact_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_COLLISION_H_
