/**
 * @file mainpage.h
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */
/**
 * @mainpage CSCI3081 Project: Robot Simulator
 *
 * @section Iteration 2 Overview
 *
 * In the second iteration of this robot simulator, I introduce different game
 * mechanics for the player and robots than in iteration 1. In iteration 1, the
 * criteria for "winning" the game for the player is to successfully reach a
 * randomly wandering home base without being completely drained of battery,
 * which causes the player to "lose". Throughout the process, the player must
 * try to dodge inanimate obstacles littered throughout the arena.
 *
 * In this iteration, I introduce an enemy for the player, the robot clan, whose
 * goal is to turn all of the existing robots in the arena into SuperBots. In
 * order to do this, a complete refactor of the "Robot" class was necessary in
 * order to distinguish the Robot, which is an artificially intelligent entity
 * in the arena that is impeding the player's victory, versus the Player, which
 * was the original Robot, and is manuevered by the user through peripherals.
 *
 * The player's objective, on the other hand, is to freeze the robots by bumping
 * into them in the arena. However, if a robot has turned into a SuperBot, it is
 * too late and bumping into a SuperBot will only result in a short paralysis
 * lasting several seconds.
 *
 * The Robot has several sensors that make it aware of its surrounding
 * environment. The sensors boil down to:
 * - Distress sensor: when the bot is frozen, it notifies other bots in the
 * surrounding area so they know not to avoid it.
 * - Proximity sensor: bots can use this to detect other entities around
 * themselves.
 * - Touch sensor: bots can use this to respond to collisions that the arena
 * reports. This was the same as in the first iteration.
 * - Entity type sensor (not done): bots can use this to determine more
 * information about the robots that are within a certain range.
 *
 * The game also visually draws the proximity ranges of the Robot's sensors,
 * where the left proximity sensor is in green and the right proximity sensor is
 * in blue.
 */

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_

#endif  // SRC_MAINPAGE_H_
