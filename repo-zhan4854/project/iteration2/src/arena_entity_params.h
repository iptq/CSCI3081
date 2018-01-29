/**
 * @file arena_entity_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_ENTITY_PARAMS_H_
#define SRC_ARENA_ENTITY_PARAMS_H_

#include <nanogui/nanogui.h>

#include "src/color.h"
#include "src/position.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief A structure containing the parameters used for initializing a generic
 * arena entity.
 */
struct arena_entity_params {
    //! @brief Constructor. Creates an empty ArenaEntity parameter set.
    arena_entity_params(void) : radius(), pos(), color() {}

    //! @brief The radius of the arena entity.
    double radius;

    //! @brief The position of the arena entity.
    Position pos;

    //! @brief The color of the arena entity.
    Color color;
};

NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_ENTITY_PARAMS_H_
