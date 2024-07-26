// It is used to find the first pair of consecutive elements
// in a range that satisfy a specific condition. By default,
// the condition is that the elements are equal, but a custom
// binary predicate can be specified to find consecutive elements that meet a
// particular criterion

#include "gtest/gtest.h"
#include <algorithm>
#include <array>
#include <iterator>

TEST(StdTest, StdAdjacentFindTest) {
  std::vector<int> v = {1, 2, 3, 4, 4, 5, 6};

  auto it = std::adjacent_find(v.begin(), v.end());

  if (it != v.end()) {
    std::cout << "First pair of consecutive equal elements: " << *it
              << std::endl;
  } else {
    std::cout << "No consecutive equal elements found." << std::endl;
  }
}
