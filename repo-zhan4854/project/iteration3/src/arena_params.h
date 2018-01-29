/**
 * @file arena_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 */

#ifndef SRC_ARENA_PARAMS_H_
#define SRC_ARENA_PARAMS_H_

#include "src/arena_entity_params.h"
#include "src/home_base_params.h"
#include "src/player_params.h"
#include "src/robot_params.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief The parameters used to construct the arena.
 */
struct arena_params {
    arena_params(void)
        : player(), recharge_station(), home_base(), obstacles(), n_obstacles(),
          robots(), n_robots(), x_min(0), y_min(0), x_dim(), y_dim() {}
    //! @brief The parameters for the player.
    struct player_params player;

    //! @brief The parameters for the recharge station.
    struct arena_entity_params recharge_station;

    //! @brief The parameters for the home base.
    struct home_base_params home_base;

    /**
     * @brief A list of parameters for each of the obstacles.
     *
     * This may be larger than the actual number of obstacles in the arena, so
     * the actual number of obstacles in the arena is represented by the
     * n_obstacles field.
     */
    struct arena_entity_params obstacles[MAX_OBSTACLES];

    //! @brief The number of obstacles in the arena.
    size_t n_obstacles;

    //! @brief The list of robots to create.
    struct robot_params robots[MAX_ROBOTS];

    //! @brief The number of robots in the aforementioned robots array.
    size_t n_robots;

    //! @brief The leftmost boundary of the arena.
    uint x_min;

    //! @brief The uppermost boundary of the arena.
    uint y_min;

    //! @brief The rightmost boundary of the arena.
    uint x_dim;

    //! @brief The lowermost boundary of the arena.
    uint y_dim;
};

NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_PARAMS_H_
