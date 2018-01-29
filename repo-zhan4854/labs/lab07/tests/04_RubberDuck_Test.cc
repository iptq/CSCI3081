#include <gtest/gtest.h>
#include <string.h>
#include "../src/Duck.h"

TEST(RubberDuck, default_constructor) {
    RubberDuck d;
    ASSERT_STREQ(d.display().c_str(), "I am a Rubber Duck.")
        << "FAIL: default_constructor";
}
