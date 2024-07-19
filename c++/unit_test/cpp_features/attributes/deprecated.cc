#include "gtest/gtest.h"

[[deprecated("expired, please don't use this function")]]
static int test() { return 1; }

TEST(StdTest, StdDeprecatedTest) {
   //#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
   ASSERT_EQ(test(), 1);
}