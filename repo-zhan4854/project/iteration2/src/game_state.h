/**
 * @file game_state.h
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#ifndef SRC_GAME_STATE_H_
#define SRC_GAME_STATE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/position.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Enumeration Definitions
 ******************************************************************************/
/**
* @brief An enumeration of possible states that the simulation could be in.
*
* The arena keeps track of the current simulation state to inform the
* GraphicsArenaViewer about what it should be doing with the simulation.
*/
enum game_state {
    /**
     * The arena is in this state while the simulation is running, at which time
     * the GraphicsArenaViewer should be accepting keystrokes from the user and
     * running the main game loop, and updating all entities in the simulation.
     */
    GAME_RUNNING,
    /**
     * The arena is in this state when the user presses the 'PAUSE' button. The
     * GraphicsArenaViewer should use this state to determine the label of the
     * 'PAUSE/PLAY' button and should control the playback of the simulation
     * appropriately.
     *
     * The reason I chose to use this over the original paused variable is
     * because using an enumeration of game states more accurately represents
     * the simulation than having separate flags for whether the game is paused,
     * or whether the game is won/lost.
     */
    GAME_PAUSED,
    /**
     * The arena is in this state when the player collides with the home base,
     * winning the game. In terms of playback, this state is functionally very
     * similar to the pause state in that no entities should be moving and the
     * arena should not be accepting keystrokes from the user. Rather, the GUI
     * displays a dialog indicating that the user has completed the goal and
     * waits for the user to restart the simulation.
     */
    GAME_WIN,
    /**
     * Identically similar to the 'win' state except the dialog shows a dialog
     * indicating that hte user has lost the game.
     */
    GAME_LOSE
};

NAMESPACE_END(csci3081);

#endif  // SRC_GAME_STATE_H_
