#include <gtest/gtest.h>
#include <string.h>
#include "../src/Duck.h"

TEST(MallardTest, default_constructor) {
    Mallard* m = new Mallard();
    ASSERT_STREQ(m->display().c_str(), "I am a Mallard.")
        << "FAIL: default_constructor";
    delete m;
}
