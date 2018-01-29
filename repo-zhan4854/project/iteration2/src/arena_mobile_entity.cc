/**
 * @file arena_mobile_entity.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#include "src/arena_mobile_entity.h"
#include "src/motion_behavior.h"

NAMESPACE_BEGIN(csci3081);

void ArenaMobileEntity::TimestepUpdate(double dt) {
    MotionBehavior h;
    h.UpdatePosition(this, dt);
} /* TimestepUpdate() */

NAMESPACE_END(csci3081);
