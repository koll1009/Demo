#include "gtest/gtest.h"
#include <algorithm>
#include <array>
#include <iterator>

//std::search is used to find the first occurrence of a subsequence in a sequence
TEST(StdTest, StdSearchTest) {
  std::vector<int> v = {1, 2, 3, 4, 1, 2, 3, 4, 5};
  std::vector<int> to_find = {2, 3};

  auto it = std::search(v.begin(), v.end(), to_find.begin(), to_find.end());

  if (it != v.end()) {
    std::cout << "First occurrence is at index " << std::distance(v.begin(), it)
              << std::endl;
  } else {
    std::cout << "Subsequence not found." << std::endl;
  }
}