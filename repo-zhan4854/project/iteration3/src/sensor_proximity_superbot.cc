/**
 * @file sensor_proximity_superbot.cc
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#include "src/sensor_proximity_superbot.h"
#include <stdio.h>

NAMESPACE_BEGIN(csci3081);

void SensorProximitySuperbot::Accept(EventProximity *evt) {
    set_activated(evt->get_activated());
    if (evt->get_activated()) {
        set_distance(evt->get_distance());
        set_sensed(evt->get_sensed());

        // determine if we should target or avoid this
        ProximitySignalResponse r;
        const ArenaEntity *ent = evt->get_sensed();
        const ArenaMobileEntity *entr =
            dynamic_cast<const ArenaMobileEntity *>(ent);
        switch (ent->get_entity_type()) {
        case kRobot:
            r = (entr->get_frozen()) ? kTarget : kAvoid;
            break;
        case kPlayer:
        case kHomeBase:
            r = kIgnore;
        case kRechargeStation:
        case kSuperBot:
        case kObstacle:
        case kWall:
            r = kAvoid;
            break;
        default:
            r = kIgnore;
            break;
        }
        set_response(r);
    }
}

NAMESPACE_END(csci3081);
