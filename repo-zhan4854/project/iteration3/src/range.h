/**
 * @file range.h
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#ifndef SRC_RANGE_H_
#define SRC_RANGE_H_

#include "src/common.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief A class representing a visual range for an entity.
 *
 * The range is literally an angle and provides a useful functionality adapted
 * from proximity.py used to check whether two ranges of proximity sensors
 * overlapped each other or not. This is used by the Arena to check whether to
 * activate a SensorProximity or not.
 *
 * In this project the only class going into T should be double float, but in
 * reality this should be generic over numeric types. (TODO: something about
 * fmod vs. mod)
 *
 * All angles used in this class are in degrees.
 */
template <class T> class Range {
 public:
    //! @brief Default constructor. This should rarely be used.
    Range() : from_(0), to_(0) {}

    /**
     * @brief Constructor. Creates a range from a pair of values.
     *
     * @param from The starting angle.
     * @param to The ending angle.
     */
    Range(T from, T to) : from_(from), to_(to) {}

    /**
     * @brief A utility method used to check whether two proximity ranges
     * overlap.
     *
     * @param other The "other" range that the method is comparing "this" to
     *
     * The two ranges used for comparison are "this" and "other". Therefore, an
     * example of a comparison that could be used is:
     *
     * ```
     * // assume ranges A and B
     * if (A.in(B)) {
     *     ...
     * }
     * ```
     */
    bool in(const Range other) {
        // haHAA ported straight from example code

        double r10 = from_, r11 = to_;
        double r20 = other.from_, r21 = other.to_;

        double dist;
        if (r10 > r11) {
            dist = 360.0 - r10;
            r10 = fmod(r10 + dist, 360);
            r11 = r11 + dist;
            r20 = fmod(r20 + dist, 360);
            r21 = fmod(r21 + dist, 360);
        }
        if (r20 > r21) {
            dist = 360 - r20;
            r10 = fmod(r10 + dist, 360);
            r11 = r11 + dist;
            r20 = fmod(r20 + dist, 360);
            r21 = fmod(r21 + dist, 360);
        }

        if (r20 < r10 && r21 > r11)
            return true;
        if (r20 >= r10 && r20 <= r11)
            return true;
        if (r21 >= r10 && r21 <= r11)
            return true;
        return false;
    }

 private:
    //! @brief The starting angle of the range, in degrees.
    T from_;

    //! @brief The ending angle of the range, in degrees.
    T to_;
};

NAMESPACE_END(3081);

#endif  // SRC_RANGE_H_
