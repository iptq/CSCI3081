/**
 * @file event_proximity.h
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#ifndef SRC_EVENT_PROXIMITY_H_
#define SRC_EVENT_PROXIMITY_H_

#include "src/arena_mobile_entity.h"
#include "src/common.h"
#include "src/event_base_class.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief An event triggered when a robot detects something in its proximity.
 */
class EventProximity : public EventBaseClass {
 public:
    //! @brief Default constructor.
    EventProximity() : activated_(false), distance_(), sensed_() {}

    //! @brief Copy constructor.
    EventProximity(const EventProximity &L) = delete;

    //! @brief Assignment operator.
    EventProximity &operator=(const EventProximity &L) {
        activated_ = L.activated_;
        distance_ = L.distance_;
        sensed_ = L.sensed_;
        return *this;
    }

    void EmitMessage(void) {}

    //! @brief Set the activation status of this event.
    void set_activated(bool activated) { activated_ = activated; }

    //! @brief Gets the activation status of this event.
    bool get_activated(void) { return activated_; }

    //! @brief Sets the distance related to the entity detected.
    void set_distance(double distance) { distance_ = distance; }

    //! @brief Gets the distance to the entity detected.
    double get_distance(void) { return distance_; }

    //! @brief Sets the entity that was detected.
    void set_sensed(const ArenaEntity *sensed) { sensed_ = sensed; }

    //! @brief Gets the entity that was detected.
    const ArenaEntity *get_sensed(void) { return sensed_; }

 private:
    //! @brief Whether this event is activated.
    bool activated_;

    //! @brief The distance to the entity detected.
    double distance_;

    //! @brief A reference to the entity detected.
    const ArenaEntity *sensed_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_PROXIMITY_H_
