// It is used to find the first position in a sorted range where
// a given value can be inserted without violating the order.
// Specifically, it returns an iterator pointing to the first element
// in the range that is greater than the given value.

#include "Common.h"
#include "gtest/gtest.h"
#include <iterator>
#include <ostream>

TEST(StdTest, StdUpperBoundTest) {
    std::vector<int> v = {1, 3, 3, 5, 7, 9};

    // Find the first position where 3 can be inserted without violating the order
    auto it = std::upper_bound(v.begin(), v.end(), 3);

    if (it != v.end()) {
        std::cout << "The upper bound for 3 is at position: " << (it - v.begin()) << std::endl;
        std::cout << "Value at the upper bound: " << *it << std::endl;
    } else {
        std::cout << "No upper bound found for 3" << std::endl;
    }
    
    ASSERT_EQ(*it, 5);
    ASSERT_EQ(3, std::distance(v.begin(), it));
}