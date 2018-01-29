/**
 * @file entity_type.h
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#ifndef SRC_ENTITY_TYPE_H_
#define SRC_ENTITY_TYPE_H_

#include "src/common.h"

/**
 * @brief An enumeration denoting the type of an entity.
 *
 * Often, this is used to check the type of an entity rather than the more
 * convoluted and messy way of checking if the result of performing a
 * dynamic_cast on the object resulted in a non-NULL pointer.
 */
enum entity_type {
    //! @brief A robot.
    kRobot,

    //! @brief A super bot.
    kSuperBot,

    //! @brief The player.
    kPlayer,

    //! @brief The home base.
    kHomeBase,

    //! @brief The recharge station.
    kRechargeStation,

    //! @brief The wall. Not actually used yet.
    kWall,

    //! @brief An obstacle.
    kObstacle
};

#endif  // SRC_ENTITY_TYPE_H_
