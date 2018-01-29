/**
 * @file actuator_commands.h
 *
 * @copyright 2017 John Harwell, All rights reserved.
 *
 */

#ifndef SRC_EVENT_COMMANDS_H_
#define SRC_EVENT_COMMANDS_H_

#include "src/common.h"
#include "src/position.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief An abstraction of the keyboard commands.
 *
 * These are the commands that are actually used and recognized by the other
 * objects in the simulation and present an abstraction for the actual key codes
 * representing the key press events. An added benefit is that multiple keys can
 * now bind to the same action (and possibly support for custom key bindings
 * read from a configuration file.)
 */
enum event_commands {
    //! @brief "Forward" button. Increases the speed of the player.
    COM_SPEED_UP,

    //! @brief "Backward" button. Decreases the speed of the player.
    COM_SLOW_DOWN,

    //! @brief Rotates the player left.
    COM_TURN_LEFT,

    //! @brief Rotates the player right.
    COM_TURN_RIGHT,

    /**
     * @brief Unknown key command.
     *
     * This is returned if a key was inputted by the user that doesn't match any
     * of the previous variants. For now, this is just ignored in
     * event_keypress.cc.
     */
    COM_UNKNOWN
};
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_COMMANDS_H_
