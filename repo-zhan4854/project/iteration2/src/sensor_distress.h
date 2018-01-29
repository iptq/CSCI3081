/**
 * @file sensor_distress.h
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#ifndef SRC_SENSOR_DISTRESS_H_
#define SRC_SENSOR_DISTRESS_H_

#include "src/event_distress.h"
#include "src/position.h"
#include "src/sensor.h"

NAMESPACE_BEGIN(csci3081);

class SensorDistress : public Sensor {
 public:
    SensorDistress() {}

    void Reset() {}

    void Accept(EventDistress *e);
};

NAMESPACE_END(csci3081);

#endif  // SRC_SENSOR_DISTRESS_H_
