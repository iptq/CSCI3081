/**
 * @file sensor_entity_type.cc
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#include "src/sensor_entity_type.h"

NAMESPACE_BEGIN(csci3081);

void SensorEntityType::Accept(EventEntityType *e) {
    set_activated(e->get_activated());
    if (e->get_activated())
        set_entity_type(e->get_entity_type());
}

NAMESPACE_END(csci3081);
