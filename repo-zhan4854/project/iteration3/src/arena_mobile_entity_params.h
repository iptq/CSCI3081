/**
 * @file arena_mobile_entity_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_MOBILE_ENTITY_PARAMS_H_
#define SRC_ARENA_MOBILE_ENTITY_PARAMS_H_

#include "src/arena_entity_params.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief A structure containing the parameters used for initializing a mobile
 * entity.
 */
struct arena_mobile_entity_params : public arena_entity_params {
    //! @brief Default constructor.
    arena_mobile_entity_params(void)
        : arena_entity_params(), collision_delta() {}

    //! @brief The amount of space between two objects for them to be considered
    //! colliding.
    double collision_delta;
};

NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_MOBILE_ENTITY_PARAMS_H_
