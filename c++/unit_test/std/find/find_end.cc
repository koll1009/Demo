#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include "Common.h"

using namespace koll;

TEST(StdTest, StdFindEndTest) 
{

  //It searches for the last occurrence of a smaller sequence 
  //(subrange) within a larger sequence and returns an iterator
  //to the beginning of this occurrence
  std::vector<int> array = {1, 2, 3, 4, 5};
  std::vector<int> array2 = {2, 3, 4};
  auto ret = std::find_end(std::begin(array), std::end(array), std::begin(array2), std::end(array2));
  std::cout << "find end of " << array2 << std::endl << "from " << array << std::endl;

  std::cout << "the ret is: " << *ret << std::endl;
  ASSERT_FALSE(ret == array.end());
  ASSERT_EQ(ret, array.begin()+1);
}