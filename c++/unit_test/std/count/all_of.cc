//std::all_of is a function template in the C++ Standard Library
//that checks if a predicate is true for all elements in a given range.

#include "gtest/gtest.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

TEST(StdTest, StdAllOfTest) 
{
  std::array<int, 5> array = {1, 3, 3, 3, 5};
  ASSERT_EQ(std::all_of(std::begin(array), std::end(array), [](int e){ return e == 3;}), false);
}