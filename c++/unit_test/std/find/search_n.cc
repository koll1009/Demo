#include "gtest/gtest.h"
#include <algorithm>
#include <array>
#include <iterator>

//std::search is used to find the first occurrence of a subsequence in a sequence
TEST(StdTest, StdSearchNTest) {
    std::vector<int> v = {1, 2, 2, 2, 3, 4, 4, 4, 4};

    // Search for three consecutive 2s
    int value = 2;
    int count = 3;

    auto result = std::search_n(v.begin(), v.end(), count, value);

    if (result != v.end()) {
        std::cout << "Found " << count << " consecutive " << value << "s starting at position "
                  << std::distance(v.begin(), result) << std::endl;
    } else {
        std::cout << "No sequence of " << count << " consecutive " << value << "s found." << std::endl;
    }
}