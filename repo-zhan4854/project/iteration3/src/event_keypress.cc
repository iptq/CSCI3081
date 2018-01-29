/**
 * @file event_keypress.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_keypress.h"
#include "src/graphics_arena_viewer.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
EventCommand EventKeypress::keypress_to_cmd(int key) {
    switch (key) {
    case 'a':  // 'A'
    case 37:   // left
    case 263:
        return EventCommand(COM_TURN_LEFT);
        break;
    case 'd':  // 'D'
    case 39:   // right
    case 262:
        return EventCommand(COM_TURN_RIGHT);
        break;
    case 'w':  // 'W'
    case 38:   // up
    case 265:
        return EventCommand(COM_SPEED_UP);
        break;
    case 's':  // 'S'
    case 40:   // down
    case 264:
        return EventCommand(COM_SLOW_DOWN);
        break;
    default:
        // printf("Unknown keypress: %d\n", key);
        return EventCommand(COM_UNKNOWN);
        // assert(0); // don't crash the program pretty please
    } /* switch() */
} /* keypress_to_cmd() */

NAMESPACE_END(csci3081);
