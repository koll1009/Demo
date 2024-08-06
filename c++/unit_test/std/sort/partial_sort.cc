//It is used to partially sort a range of elements such that
//the first N elements are sorted, while the remaining elements
//are left in an unspecified order.
//It is particularly useful when you need only a subset of sorted elements,
//which can be more efficient than fully sorting the entire range.

// Other than upper_bound function, lower_bound returns an iterator
// pointing to the first element in the range that is not less than
// (i.e., greater than or equal to) the given value.

#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include "Common.h"

using namespace koll;

TEST(StdTest, StdPartialSortTest) {
    std::vector<int> v = {9, 3, 1, 4, 6, 2, 8, 5, 7};

    std::cout << "Originl vector: ";
    std::cout << v;
    std::cout << std::endl;

    // Partially sort the first 5 elements
    std::partial_sort(v.begin(), v.begin() + 5, v.end());

    // Print the entire vector to show the unsorted remainder
    std::cout << "Vector after partial sort: ";
    std::cout << v;
    std::cout << std::endl;
}