//Returns true if any element satisfies a condition

#include "gtest/gtest.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

TEST(StdTest, StdAnyOfTest) 
{
  std::array<int, 5> array = {1, 3, 3, 3, 5};
  ASSERT_EQ(std::any_of(std::begin(array), std::end(array), [](int e){ return e == 1;}), true);
}