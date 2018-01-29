/**
 * @file robot_arena.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_H_
#define SRC_ARENA_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <iostream>
#include <vector>

#include "src/event_collision.h"
#include "src/event_keypress.h"
#include "src/event_proximity.h"
#include "src/game_state.h"
#include "src/home_base.h"
#include "src/player.h"
#include "src/recharge_station.h"
#include "src/robot.h"
#include "src/sensor.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
struct arena_params;

/**
 * @brief The main class for the simulation of a 2D world with many robots
 * running
 * around.
 *
 * RobotViewer or Tests call \ref set_time and \ref advance_time to control the
 * simulation and use the get*() functions to read out the current state of the
 * simulation (i.e., the current positions and orientations of robots and
 * obstacles).
 *
 *  For now, RobotArena is hard coded to run a simulation of two robots running
 *  around in a circle.  You can see their sensors, but they don't yet respond
 *  to each other or to obstacles.
 */
class Arena {
 public:
    //! @brief Constructor. Builds a new Arena from the given parameters.
    explicit Arena(const struct arena_params *const params);

    //! @brief Deconstructor.
    ~Arena(void);

    /**
     * @brief Advance the simulation by the specified amount of time.
     *
     * @param[in] dt The # of steps to increment by.
     */
    void AdvanceTime(double dt);

    /**
    * @brief Handle the key press passed along by the viewer.
    *
    * @param[in] an event holding the key press.
    *
    */
    void Accept(EventKeypress *evt);

    //! @brief Reset all in the arena
    void Reset(void);

    /**
     * @brief Get a list of all obstacles (i.e. non-mobile entities in the
     * arena).
     */
    std::vector<class Obstacle *> get_obstacles(void);

    /**
     * @brief Get a list of all of the robots (specifically) in the arena.
     */
    std::vector<class Robot *> get_robots(void);

    /**
     * @brief Get a list of sensors that have been registered into the arena.
     */
    std::vector<class Sensor *> get_sensors(void);

    /**
     * @brief Adds a Sensor to the Arena's internal list of registered sensors.
     *
     * The Arena keeps track of a list of sensors in case there's something it
     * needs to broadcast to a mass of Sensors, such as a EventDistress. Having
     * each entity register their sensors makes this process a lot easier.
     */
    void RegisterSensor(Sensor *h);

    /**
     * @brief Undoes the registration of the entity's sensor.
     */
    void UnregisterSensor(Sensor *h);

    /**
     * @brief Get the list of all mobile entities in the arena.
     */
    std::vector<class ArenaMobileEntity *> get_mobile_entities(void) {
        return mobile_entities_;
    }

    //! @brief Gets the current running state.
    enum game_state get_game_state() { return game_state_; }

    //! @brief Sets the current running state.
    void set_game_state(enum game_state state) { game_state_ = state; }

    //! @brief Get a reference to the player object.
    Player *get_player(void) const { return player_; }

    //! @brief Get a reference to the home base object.
    HomeBase *get_home_base(void) const { return home_base_; }

    //! @brief Get a reference to the recharge station object.
    RechargeStation *get_recharge_station(void) const {
        return recharge_station_;
    }

 private:
    /**
     * @brief Determine if two entities have collided in the arena. Collision is
     * defined as the difference between the extents of the two entities being
     * less
     * than a run-time parameter.
     *
     * @param ent1 Entity #1.
     * @param ent2 Entity #2.
     * @param pointer to a collision event
     *
     * Collision Event is populated appropriately.
     */
    void CheckForEntityCollision(const ArenaEntity *const ent1,
                                 const ArenaEntity *const ent2,
                                 EventCollision *const event,
                                 double collision_delta);

    /**
     * @brief Determine if a particular entity is gone out of the boundaries of
     * the simulation.
     *
     * @param ent The entity to check.
     * @param pointer to a collision event.
     *
     * Collision event is populated appropriately.
     */
    void CheckForEntityOutOfBounds(const class ArenaMobileEntity *const ent,
                                   EventCollision *ec);

    /**
     * @brief Check if a robot is close enough to another entity to trigger a
     * EventProximity.
     *
     * If the entity is close enough to be detected, populate EventProximity
     * with the relevant values. Otherwise, EventProximity will be inactive.
     */
    void CheckProximity(const Robot *ent1, const SensorProximity *sensor,
                        const ArenaEntity *ent2, EventProximity *ep);

    /**
     * @brief Update all entities.
     */
    void UpdateEntitiesTimestep(double dt);

    enum game_state game_state_;

    //! @brief top of the graphics window
    double x_min_;

    //! @brief left of the graphics window
    double y_min_;

    //! @brief right (x dimension) of the graphics window
    double x_max_;

    //! @brief bottom (y dimension) of the graphics window
    double y_max_;

    //! @brief The player.
    Player *player_;

    //! @brief The single recharge station in the game.
    RechargeStation *recharge_station_;

    //! @brief The single home base in the game.
    HomeBase *home_base_;

    //! @brief A list of all entities, including mobile entities.
    std::vector<class ArenaEntity *> entities_;

    //! @brief A list of mobile entities. This may overlap with entities.
    std::vector<class ArenaMobileEntity *> mobile_entities_;

    //! @brief A list of registered sensors.
    std::vector<class Sensor *> sensors_;

    //! @brief Assignment operator. Satisfies compilers warning that the
    //! assignment operator should not exist.
    Arena &operator=(const Arena &other) = delete;

    //! @brief Copy constructor. Satisfies compilers warning that the copy
    //! constructor should not exist.
    Arena(const Arena &other) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_H_
