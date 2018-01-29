/**
 * @file position.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_POSITION_H_
#define SRC_POSITION_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>

#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A simple representation of a position of an entity within the arena.
 */
struct Position {
    Position(void) : x(0), y(0) {}
    Position(double in_x, double in_y) : x(in_x), y(in_y) {}

    double x, y;

    double to(Position *other) {
        return sqrt(pow(x - other->x, 2) + pow(y - other->y, 2));
    }
    double to(Position other) { return to(&other); }
};

inline bool operator==(const Position &left, const Position &right) {
    return left.x == right.x && left.y == right.y;
}

inline bool operator!=(const Position &left, const Position &right) {
    return !(left == right);
}

NAMESPACE_END(csci3081);

#endif  // SRC_POSITION_H_
