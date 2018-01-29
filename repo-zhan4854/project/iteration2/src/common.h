/**
 * @file common.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_COMMON_H_
#define SRC_COMMON_H_

/*
 * TL's note: why is NAMESPACE_BEGIN/END necessary/a good idea??????
 */

//! @brief Begin namespace
#define NAMESPACE_BEGIN(name) namespace name {

//! @brief End namespace
#define NAMESPACE_END(name) }

//! @brief The maximum number of robots possible.
#define MAX_ROBOTS 8

//! @brief The maximum number of obstacles possible.
#define MAX_OBSTACLES 8

//! @brief The radius of the proximity sensor.
#define PROXIMITY_RADIUS 60

//! @brief The angle of the proximity sensor.
#define PROXIMITY_ANGLE 120

//! @brief How much to turn by depending on distance.
#define PROXIMITY_CONSTANT 0.35

//! @brief How much to slow down by when something is in proximity.
#define SLOWDOWN_CONSTANT 5

//! @brief The range for distress and entity type sensors.
#define SENSING_RANGE 75

//! @brief Makes sure the angle is between 0 and 360 degrees.
#define POSITIVE(angle)                                                        \
    ((angle < 0) ? (360 + angle) : ((angle > 360) ? fmod(angle, 360) : angle))

/**
 * @brief This should be placed in front of any variable defined but not used to
 * satisfy the compiler - otherwise a warning is given.
 */
#define __unused __attribute__((unused))

#endif  // SRC_COMMON_H_
