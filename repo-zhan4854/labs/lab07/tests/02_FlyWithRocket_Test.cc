#include <gtest/gtest.h>
#include <string.h>
#include "../src/FlyBehavior.h"

TEST(FlyBehaviorTest, empty_constructor) {
    FlyWithRocket f;
    ASSERT_STREQ(f.fly().c_str(), "Fly with wings at speed of 20 mph.")
        << "FAIL: empty_constructor.";
}
