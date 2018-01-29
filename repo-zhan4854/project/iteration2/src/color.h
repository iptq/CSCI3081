/**
 * @file color.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_COLOR_H_
#define SRC_COLOR_H_

#include "src/position.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief A simple representation of a position of an entity within the arena.
 */
struct Color {
 public:
    //! @brief Default constructor. Creates a Color object representing black.
    Color(void) : r(0), g(0), b(0), a(255) {}

    //! @brief Constructor. Creates a Color object using the given colors.
    Color(int in_r, int in_g, int in_b, int in_a)
        : r(in_r), g(in_g), b(in_b), a(in_a) {}

    //! @brief Red
    int r;

    //! @brief Green
    int g;

    //! @brief Blue
    int b;

    //! @brief Alpha
    int a;
};

NAMESPACE_END(csci3081);

#endif  // SRC_COLOR_H_
