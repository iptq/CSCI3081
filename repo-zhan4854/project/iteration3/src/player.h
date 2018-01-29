/**
 * @file player.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "src/arena_mobile_entity.h"
#include "src/entity_type.h"
#include "src/event_collision.h"
#include "src/event_command.h"
#include "src/event_recharge.h"
#include "src/motion_behavior.h"
#include "src/motion_handler_player.h"
#include "src/player_battery.h"
#include "src/sensor_touch.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main user-controlled entity.
 *
 * This entity is controlled by the player through the arrow keys and has
 * internal structures to aid its movement, including:
 *
 * - RobotBattery: used to keep track of the battery level of the Player. Should
 * the player ever run out of charge, the game is lost. Charge can be
 * replenished by visiting the recharge station and exhausted by moving (or not
 * moving) or bumping into other entities.
 * - RobotMotionHandler: used for keeping track of the Player's position and
 * velocity. It receives updates from the SensorTouch to determine when to
 * change the direction.
 * - RobotMotionBehavior: used to update the position of the player every tick
 * based on its velocity.
 */
class Player : public ArenaMobileEntity {
 public:
    //! @brief Default constructor.
    explicit Player(const struct player_params *const params);

    void Reset(void);

    //! @brief Called to reset the battery to its maximum charge.
    void ResetBattery(void);

    //! @brief An update function that will be called every time the simulation
    //! steps by a frame.
    void TimestepUpdate(double dt);
    void Accept(EventRecharge *evt);
    void Accept(EventCollision *evt);

    //! @brief Handles an EventCommand input from the player.
    void EventCmd(EventCommand cmd);

    //! @brief Gets the current level of the battery.
    double get_battery_level(void) const { return battery_.get_level(); }

    //! @brief Despite its name, gets the current level of the battery as a
    //! ratio out of 1 (not out of 100).
    double get_battery_percentage(void) const {
        return battery_.get_percentage();
    }
    double get_heading_angle(void) const {
        return motion_handler_.get_heading_angle();
    }
    void set_heading_angle(double ha) { motion_handler_.set_heading_angle(ha); }
    double get_speed(void) { return motion_handler_.get_speed(); }
    void set_speed(double sp) { motion_handler_.set_speed(sp); }

    enum entity_type get_entity_type(void) const {
        return entity_type::kPlayer;
    }
    std::string get_name(void) const { return "Player"; }

 private:
    //! @brief The player's battery object.
    PlayerBattery battery_;

    //! @brief The player's motion handler.
    MotionHandlerPlayer motion_handler_;

    //! @brief The player's motion behavior (uses the default)
    MotionBehavior motion_behavior_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_PLAYER_H_
