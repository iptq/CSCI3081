/**
 * @file player_battery.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_PLAYER_BATTERY_H_
#define SRC_PLAYER_BATTERY_H_

#include "src/common.h"
#include "src/event_collision.h"
#include "src/position.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief The battery for the player.
 *
 * This class is responsible for managing the battery functionality of the
 * player, such as measuring the consumption of power as the player navigates
 * around the arena and collides with other objects. It's also responsible for
 * recharging the battery back to its maximum charge when the player signals
 * that it has reached a recharge station.
 */
class PlayerBattery {
 public:
    /**
     * @brief Constructor. Creates a new PlayerBattery with a specified
     * capacity.
     *
     * @param max_charge The maximum charge, or capacity of the battery.
     */
    explicit PlayerBattery(double max_charge)
        : charge_(max_charge), max_charge_(max_charge) {}

    /**
     * @brief All robots consume SOME power, even when just sitting there not
     * moving.
     */
    double kBASE_DEPLETION = 0.1;

    /**
     * @brief The amount of energy consumed by the player due to its linear
     * speed its is directly proportional to that speed, with a scaling factor.
     */
    double kLINEAR_SCALE_FACTOR = 0.5;

    /**
     * @brief The amount of energy consumed by the player due to its angular
     * speed its is directly proportional to that speed, with a scaling factor.
     */
    double kANGULAR_SCALE_FACTOR = 0.01;

    /**
     * @brief Get the current battery level.
     */
    double get_level(void) const { return charge_; }

    /**
     * @brief Get the current battery level as a ratio.
     *
     * This value is used to compute the battery indicator that appears above
     * the player in the graphics viewer.
     */
    double get_percentage(void) const { return charge_ / max_charge_; }

    /**
     * @brief Handle a recharge event by instantly restoring the player's
     * battery to its maximum value.
     */
    void EventRecharge(void) { charge_ = max_charge_; }

    /**
     * @brief Reset the player's battery to its newly constructed/undepleted
     * state.
     */
    void Reset(void) { EventRecharge(); }

    /**
     * @brief Calculate the new battery level based on the current
     * linear/angular speed.
     *
     * @param linear_vel The current linear speed, in m/s.
     * @param angular_vel The current angular speed, in rad/s.
     *
     * @return The updated battery level.
     */
    double Deplete(__unused Position old_pos, __unused Position new_pos,
                   __unused double dt);

    /**
     * @brief Handle a collision event with another player.
     *
     * The battery will discharge by a certain amount as a penalty for the
     * collision.
     */
    void Accept(EventCollision *evt);

 private:
    //! @brief The amount of charge that the battery is currently holding.
    double charge_;

    /**
     * @brief A value representing the capacity of the battery, set initially by
     * the constructor.
     */
    const double max_charge_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_PLAYER_BATTERY_H_
