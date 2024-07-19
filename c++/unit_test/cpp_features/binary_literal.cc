#include "gtest/gtest.h"


TEST(StdTest, StdBinaryLiteralTest) {
  constexpr int a = 0b11000011;
  constexpr int b = 0b1100'0011;
  constexpr int c = 0xc3;

  ASSERT_EQ(a, c);
  ASSERT_EQ(b, c);
}