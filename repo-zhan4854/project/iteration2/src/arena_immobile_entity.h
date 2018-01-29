/**
 * @file arena_immobile_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_IMMOBILE_ENTITY_H_
#define SRC_ARENA_IMMOBILE_ENTITY_H_

#include "src/arena_entity.h"
#include "src/color.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief An entity that does not move.
 *
 * Immobile entities act as obstacles to mobile entities and still interact with
 * them as physical bodies through collision.
 */
class ArenaImmobileEntity : public ArenaEntity {
 public:
    //! @brief Default constructor.
    ArenaImmobileEntity(double radius, const Position &pos,
                        const csci3081::Color &color)
        : ArenaEntity(radius, pos, color) {}

    //! @brief Always returns false, since ArenaImmobileEntity should not be
    //! mobile.
    bool is_mobile(void) { return false; }
};

NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_IMMOBILE_ENTITY_H_
