// Other than upper_bound function, lower_bound returns an iterator
// pointing to the first element in the range that is not less than
// (i.e., greater than or equal to) the given value.

#include "Common.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <iterator>
#include <ostream>

TEST(StdTest, StdLowerBoundTest) {
    std::vector<int> v = {1, 3, 3, 5, 7, 9};

    // Find the first position where 3 can be inserted without violating the order
    auto it = std::lower_bound(v.begin(), v.end(), 3);

    if (it != v.end()) {
        std::cout << "The lower bound for 3 is at position: " << (it - v.begin()) << std::endl;
        std::cout << "Value at the lower bound: " << *it << std::endl;
    } else {
        std::cout << "No upper bound found for 3" << std::endl;
    }
    
    ASSERT_EQ(*it, 3);
    ASSERT_EQ(1, std::distance(v.begin(), it));
}