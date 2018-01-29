#include "../src/position.h"
#include <gtest/gtest.h>

TEST(PositionTest, Constructor) {
    struct csci3081::Position p1 = {1.0, 2.0}, p2;

    ASSERT_EQ(p1.x, 1.0);
    ASSERT_EQ(p1.y, 2.0);

    ASSERT_EQ(p2.x, 0.0);
    ASSERT_EQ(p2.y, 0.0);
}

TEST(PositionTest, EqualOverloader) {
    struct csci3081::Position p1 = {5.0, 6.0}, p2 = {5.0, 6.0}, p3;

    ASSERT_EQ(p1, p2);
    ASSERT_NE(p2, p3);
    ASSERT_NE(p1, p3);
}