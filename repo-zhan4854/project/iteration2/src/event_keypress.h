/**
 * @file event_keypress.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_KEYPRESS_H_
#define SRC_EVENT_KEYPRESS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>

#include "src/event_base_class.h"
#include "src/event_command.h"
#include "src/event_commands.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief An object that represents a keypress made by the user.
 *
 * This function is an abstraction of the actual keycodes passed in by the
 * graphics viewer, so if the implementation of the graphics viewer ever
 * changes, only that implementation will be changed and the rest of the project
 * can use the abstraction normally.
 */
class EventKeypress : public EventBaseClass {
 public:
    explicit EventKeypress(int key) : key_(key) {}

    void EmitMessage(void) {
        // printf("Keypress %d command received\n", key_);
    }
    EventCommand get_keypress() { return keypress_to_cmd(key_); }

 private:
    /**
     * @brief Converts the keycode into an enumerated set of key inputs that the
     * Player will accept.
     *
     * Several values are given, using the values provided by the GLFW table as
     * well as ASCII. These values have been tested and work on Linux.
     */
    EventCommand keypress_to_cmd(int key);
    int key_;

    EventKeypress &operator=(const EventKeypress &other) = delete;
    EventKeypress(const EventKeypress &other) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_KEYPRESS_H_
