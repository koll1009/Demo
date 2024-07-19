#include "gtest/gtest.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <ostream>


TEST(StdTest, StdFindTest) 
{
  std::array<int, 5> array = {1, 3, 3, 3, 5};
  auto ret = std::find(std::begin(array), std::end(array),5);
  ASSERT_FALSE(ret == array.end());
  ASSERT_EQ(*ret, 5);
}