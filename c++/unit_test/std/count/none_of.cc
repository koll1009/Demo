//Returns true if no element satisfies a condition

#include "gtest/gtest.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

TEST(StdTest, StdNoneOfTest) 
{
  std::array<int, 5> array = {1, 3, 3, 3, 5};
  ASSERT_EQ(std::none_of(std::begin(array), std::end(array), [](int e){ return e <= 0; }), true);
}