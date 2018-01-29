/**
 * @file sensor_proximity.h
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#ifndef SRC_SENSOR_PROXIMITY_H_
#define SRC_SENSOR_PROXIMITY_H_

#include <math.h>

#include <utility>

#include "src/event_proximity.h"
#include "src/range.h"
#include "src/sensor.h"

NAMESPACE_BEGIN(csci3081);

enum ProximitySignalResponse { kTarget, kAvoid, kIgnore };

class SensorProximity : public Sensor {
 public:
    SensorProximity()
        : range_(), fov_(120), response_(), distance_(), sensed_() {}
    SensorProximity(const SensorProximity &L) = delete;
    SensorProximity &operator=(const SensorProximity &L) {
        range_ = L.range_;
        fov_ = L.fov_;
        response_ = L.response_;
        distance_ = L.distance_;
        sensed_ = L.sensed_;
        return *this;
    }

    void Reset() {}
    void Accept(EventProximity *evt);

    Range<double> get_range() { return range_; }
    void set_range(Range<double> range) { range_ = range; }
    void set_range(double from, double to) { range_ = Range<double>(from, to); }

    double get_distance() { return distance_; }
    void set_distance(double distance) { distance_ = distance; }

    double get_fov() const { return fov_; }
    void set_fov(double fov) { fov_ = fov; }

    void set_sensed(const ArenaEntity *sensed) { sensed_ = sensed; }
    const ArenaEntity *get_sensed(void) { return sensed_; }

    void set_response(enum ProximitySignalResponse response) {
        response_ = response;
    }
    enum ProximitySignalResponse get_response(void) { return response_; }

 private:
    Range<double> range_;
    double fov_;

    enum ProximitySignalResponse response_;
    double distance_;
    const ArenaEntity *sensed_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_SENSOR_PROXIMITY_H_
