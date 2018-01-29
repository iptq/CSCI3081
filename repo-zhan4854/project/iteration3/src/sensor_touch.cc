/**
 * @file sensor_touch.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <limits>

#include "src/arena_entity.h"
#include "src/sensor_touch.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorTouch::SensorTouch()
    : activated_(false), point_of_contact_(0, 0), angle_of_contact_(0) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorTouch::Accept(EventCollision *evt) {
    // Determine if the sensor should be activated or inactivated.
    if (evt->get_collided()) {
        activated_ = true;
        point_of_contact_ = evt->get_point_of_contact();
        angle_of_contact_ = evt->get_angle_of_contact();
    } else {
        activated_ = false;
    }
}

void SensorTouch::Reset(void) { activated_ = false; } /* reset() */

NAMESPACE_END(csci3081);
