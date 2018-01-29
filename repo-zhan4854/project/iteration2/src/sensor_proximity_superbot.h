/**
 * @file sensor_proximity_superbot.h
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#ifndef SRC_SENSOR_PROXIMITY_SUPERBOT_H_
#define SRC_SENSOR_PROXIMITY_SUPERBOT_H_

#include "src/sensor_proximity.h"

NAMESPACE_BEGIN(csci3081);

class SensorProximitySuperbot : public SensorProximity {
 public:
    void Accept(EventProximity *e);
};

NAMESPACE_END(csci3081);

#endif  // SRC_SENSOR_PROXIMITY_SUPERBOT_H_
