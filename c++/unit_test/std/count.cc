#include "gtest/gtest.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <ostream>

TEST(StdTest, StdCountTest) 
{
  std::array<int, 5> array = {1, 3, 3, 3, 5};
  ASSERT_EQ(std::count(std::begin(array), std::end(array), 1), 1);
  ASSERT_EQ(std::count(std::begin(array), std::end(array), 3), 3);
  ASSERT_EQ(std::count(std::begin(array), std::end(array), 5), 1);
  ASSERT_EQ(std::count(std::begin(array), std::end(array), 2), 0);
}