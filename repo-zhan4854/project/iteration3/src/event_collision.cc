/**
 * @file event_collision.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_collision.h"
#include "src/arena_mobile_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

EventCollision *EventCollision::opposite(void) {
    EventCollision *result = new EventCollision();
    result->set_collided(get_collided());
    result->set_point_of_contact(get_point_of_contact());
    result->set_angle_of_contact(POSITIVE(get_angle_of_contact() + 180));
    return result;
}

NAMESPACE_END(csci3081);
