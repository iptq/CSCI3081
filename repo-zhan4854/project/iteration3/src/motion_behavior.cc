/**
 * @file motion_behavior.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>

#include "src/arena_mobile_entity.h"
#include "src/motion_behavior.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void MotionBehavior::UpdatePosition(ArenaMobileEntity *const ent, double dt) {
    if (ent->get_frozen())
        return;

    // Save position for debugging purposes
    Position new_pos = ent->get_pos();
    // Position old_pos = ent->pos();

    // Movement is always along the heading_angle (i.e. the hypotenuse)
    new_pos.x +=
        cos(ent->get_heading_angle() * M_PI / 180.0) * ent->get_speed() * dt;
    new_pos.y +=
        sin(ent->get_heading_angle() * M_PI / 180.0) * ent->get_speed() * dt;
    ent->set_pos(new_pos);
} /* update_position() */

NAMESPACE_END(csci3081);
