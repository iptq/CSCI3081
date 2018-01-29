/**
 * @file motion_handler_player.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_MOTION_HANDLER_PLAYER_H_
#define SRC_MOTION_HANDLER_PLAYER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_mobile_entity.h"
#include "src/event_collision.h"
#include "src/event_commands.h"
#include "src/motion_handler_base_class.h"
#include "src/player_params.h"
#include "src/sensor_touch.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief The handler for the robot's actuators, which in this case are the two
 * wheel actuators. Its main job is to translate the directional commands from
 * the user into the appropriate differential drive wheel speeds.
 *
 * - RobotMotionHandler manages the modification to the velocity based on
 * user input and collisions.
 * - RobotMotionBehavior translates velocity and position to a new position.
 * Both of these are straightforward, but the framework allows for more
 * sophisticated models of motion in which each wheel has distinct speed.
 *
 * For this iteration, both wheels are always going at maximum speed, and
 * cannot be controlled independently.
 */
class MotionHandlerPlayer : public MotionHandlerBaseClass {
 public:
    //! @brief Constructor. Creates an empty MotionHandlerPlayer class.
    MotionHandlerPlayer() {}

    /**
     * @brief Command from user keypress via the viewer.
     *
     * @param cmd The command as an enum.
     */
    void AcceptCommand(enum event_commands cmd);

    /**
     * @brief Handler for a collision event.
     *
     * @param ec The collision event that was received from the arena.
     */
    void Accept(EventCollision *ec);

    /**
    * @brief Change the speed and direction according to the sensor readings.
    *
    * @param st touch sensor that can be activated and contains
    * point-of-contact.
    */
    void UpdateVelocity(SensorTouch *st);
};

NAMESPACE_END(csci3081);

#endif  // SRC_MOTION_HANDLER_PLAYER_H_
