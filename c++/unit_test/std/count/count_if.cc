#include "gtest/gtest.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <ostream>


TEST(StdTest, StdCountIfTest) 
{
  std::array<int, 5> array = {1, 3, 3, 3, 5};
  ASSERT_EQ(std::count_if(std::begin(array), std::end(array), [](int val){return val > 3;}), 1);
}