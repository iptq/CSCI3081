/**
 * @file mobile_arena_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_MOBILE_ENTITY_H_
#define SRC_ARENA_MOBILE_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>

#include "src/arena_entity.h"
#include "src/color.h"
#include "src/event_base_class.h"
#include "src/event_collision.h"
#include "src/event_recharge.h"
#include "src/sensor_touch.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A base class representing an entity that is capable of movement.
 *
 * Mobile entities roam the arena and collide with either other entities or the
 * boundaries of the arena. Special behaviors for mobile entities can be
 * observed by extending this class.
 */
class ArenaMobileEntity : public ArenaEntity {
 public:
    //! @brief Default constructor. Creates a new ArenaMobileEntity out of all
    //! the parameters given.
    ArenaMobileEntity(double radius, double collision_delta,
                      const Position &pos, const csci3081::Color &color)
        : ArenaEntity(radius, pos, color), collision_delta_(collision_delta),
          initial_(pos), sensor_touch_(), frozen_(false), time_last_frozen_(0),
          fcountdown_(0) {}

    //! @brief Always returns true, since the entity is mobile.
    bool is_mobile(void) { return true; }

    //! @brief Returns the heading angle of the current entity.
    virtual double get_heading_angle(void) const = 0;

    //! @brief Sets the heading angle of the current entity to heading_angle.
    virtual void set_heading_angle(double heading_angle) = 0;

    //! @brief Gets the speed of the current entity.
    virtual double get_speed(void) = 0;

    //! @brief Sets the speed of the current entity to sp.
    virtual void set_speed(double sp) = 0;

    //! @brief Gets the collision delta of the current entity.
    double get_collision_delta(void) const { return collision_delta_; }

    //! @brief Gets whether or not the current entity is frozen.
    bool get_frozen(void) const { return frozen_; }

    /**
     * @brief Freezes the current entity.
     *
     * @param by The amount of time before it should be released.
     *
     * Each frame from now on, call \ref dec_fcountdown in order to decrease the
     * countdown. If entities don't unfreeze themselves, don't call
     * dec_fcountdown until it needs to be unfrozen (like Robot).
     */
    void set_frozen(double by) {
        time_last_frozen_ = glfwGetTime();
        frozen_ = true;
        if (frozen_)
            fcountdown_ = by;
    }

    /**
     * @brief Get the time the entity was frozen.
     *
     * This function is used to display the ripples on the frozen robots.
     */
    double get_time_last_frozen(void) const { return time_last_frozen_; }

    //! @brief Decreases the countdown by the given amount. Unfreezes if the
    //! countdown is less than 0.
    void dec_fcountdown(double dt) {
        fcountdown_ -= dt;
        if (fcountdown_ < 0)
            frozen_ = false;
    }

    //! @brief Get the remaining countdown.
    double get_fcountdown(void) { return fcountdown_; }

    /**
     * @brief An update function that is called with every iteration of the main
     * game loop after dt time has passed.
     *
     * This function should update entity movement based on the elapsed time.
     */
    void TimestepUpdate(double dt);
    /**
     * @brief Handler function for collision events.
     *
     * This function is in charge of applying the collision information provided
     * by the collision event and updating the velocity of the player
     * accordingly.
     */
    virtual void Accept(EventCollision *evt) = 0;
    /**
     * @brief Handler function for recharge events.
     *
     * This function is in charge of notifying the player's battery that the
     * player has collided with the recharge station and that the battery should
     * return to its maximum charge.
     */
    virtual void Accept(EventRecharge *evt) = 0;
    /**
     * @brief Gets the initial position of the current entity.
     *
     * This function is useful for when this entity needs to be reset and
     * returned to its starting position.
     */
    Position get_initial() const { return initial_; }

    //! @brief Gets the current touch sensor for the entity.
    SensorTouch *get_sensor_touch(void) { return &sensor_touch_; }

 private:
    //! @brief The size of the margin around the entity used for collision
    //! calculations.
    double collision_delta_;

    //! @brief The initial position, used for restarting.
    Position initial_;

    //! @brief A touch sensor.
    SensorTouch sensor_touch_;

    //! @brief A flag indicating whether or not the entity is frozen.
    bool frozen_;

    //! @brief The timestamp at which the entity was last frozen.
    double time_last_frozen_;

    //! @brief The remaining time until the entity should be unfrozen.
    double fcountdown_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_MOBILE_ENTITY_H_
