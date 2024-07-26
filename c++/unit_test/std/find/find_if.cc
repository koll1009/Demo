#include "gtest/gtest.h"
#include <algorithm>
#include <array>
#include <iterator>


TEST(StdTest, StdFindIfTest) 
{
  std::array<int, 5> array = {1, 3, 3, 3, 5};
  auto ret = std::find_if(std::begin(array), std::end(array),[](int e) { return e ==3; });
  ASSERT_FALSE(ret == array.end());
  ASSERT_EQ(*ret, 3);
}