#include <gtest/gtest.h>
#include <string.h>
#include "../src/QuackBehavior.h"

#ifndef LAB07_TEST_01

TEST(SqueakTest, volume_constructor) {
    Squeak s(1337);
    ASSERT_STREQ(s.quack().c_str(), "Quack at 1337 decibels.")
        << "FAIL: volume_constructor.";
}

#endif
