/**
 * @file sensor.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_H_
#define SRC_SENSOR_H_

#include "src/common.h"
#include "src/decl.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief Base class for sensors. Should be inherited by classes like
 * SensorTouch.
 *
 * Each sensor has one property by default: activation. When it's activated,
 * that means it has received an event from the arena, and ArenaMobileEntities
 * should check their sensors every TimestepUpdate and act appropriately.
 */
class Sensor {
 public:
    //! @brief Constructor. Creates a deactivated sensor.
    Sensor() : activated_(false), parent_() {}

    //! @brief Copy constructor.
    Sensor(const Sensor &L) = delete;

    //! @brief Assignment operator.
    Sensor &operator=(const Sensor &L) {
        activated_ = L.activated_;
        parent_ = L.parent_;
        return *this;
    }

    //! @brief Default destructor.
    virtual ~Sensor() = default;

    /**
     * @brief Getter method for sensor status.
     *
     * @return `true` if sensor is activated. `false` if sensor is deactivated.
     */
    bool get_activated() const { return activated_; }

    /**
     * @brief Setter method for sensor status.
     *
     * @param value The new sensor activation status.
     */
    void set_activated(bool value) { activated_ = value; }

    void set_parent(ArenaMobileEntity *parent) { parent_ = parent; }
    ArenaMobileEntity *get_parent(void) { return parent_; }

    //! @brief Reset the sensor to its newly constructed state.
    virtual void Reset() = 0;

 private:
    //! @brief Whether or not the sensor should be activated.
    bool activated_;

    //! @brief The arena entity that owns this sensor.
    ArenaMobileEntity *parent_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_SENSOR_H_
