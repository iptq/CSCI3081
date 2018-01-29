/**
 * @file sensor_entity_type.h
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#ifndef SRC_SENSOR_ENTITY_TYPE_H_
#define SRC_SENSOR_ENTITY_TYPE_H_

#include "src/entity_type.h"
#include "src/event_entity_type.h"
#include "src/sensor.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief A sensor for nearby entities, but only their types.
 *
 * TODO
 */
class SensorEntityType : public csci3081::Sensor {
 public:
    //! @brief Constructor. Creates an empty SensorEntityType object.
    SensorEntityType() : entity_type_() {}

    //! @brief Resets the SensorEntityType to its original state.
    void Reset() { set_activated(false); }

    /**
     * @brief Handler for detecting nearby entities.
     */
    void Accept(EventEntityType *e);

    /**
     * @brief Gets the entity type.
     *
     * @return An entity_type enum representing the entity type detected.
     *
     * Do not use this method if the sensor is not activated. Although
     * initially empty, this value is not reset unless the sensor is activated.
     */
    enum entity_type get_entity_type() { return entity_type_; }

    /**
     * @brief Sets the entity type.
     *
     * @param entity_type The type of entity that was detected.
     *
     * This method should only be used by Arena.
     */
    void set_entity_type(enum entity_type entity_type) {
        entity_type_ = entity_type;
    }

 private:
    enum entity_type entity_type_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_SENSOR_ENTITY_TYPE_H_
