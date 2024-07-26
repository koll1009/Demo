#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include "Common.h"

using namespace koll;

//It is useful for finding whether any element from a smaller set
//(or sequence) appears in a larger sequence, and if so,
//where the first occurrence is located.
TEST(StdTest, StdFindFirstOfTest) 
{
  std::vector<int> array = {1, 3, 3, 3, 5};
  std::vector<int> array2 = {2, 3, 4, 5, 1};
  auto ret = std::find_first_of(std::begin(array2), std::end(array2), std::begin(array), std::end(array));
  std::cout << "find first of " << array2 << std::endl << "from " << array << std::endl;

  std::cout << "index of first one is: " << std::distance(array2.begin(), ret) << std::endl;
  ASSERT_FALSE(ret == array2.end());
  ASSERT_EQ(*ret, 3);
}