
#include "gtest/gtest.h"


TEST(StdTest, StdDigitSeperatorTest) {
  constexpr int a = 100000;
  constexpr int b = 100'000;

  ASSERT_EQ(a, b);
}