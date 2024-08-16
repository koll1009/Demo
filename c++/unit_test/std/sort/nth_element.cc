//std::nth_element partially sorts the elements in a range 
//such that the element at the n-th position is the same
//as if the entire range was sorted. Additionally, all elements
//before this n-th element are less than or equal to the n-th element,
//and all elements after it are greater than or equal to the n-th element.

#include "gtest/gtest.h"
#include <numeric>
#include "Common.h"

using namespace koll;

TEST(StdTest, StdNthElementTest){
    std::vector<int> vec = {10, 5, 8, 3, 9, 4, 1, 7, 2, 6};
    size_t n = 4;
    std::cout << "Original numbers: ";
    std::cout << vec;
    std::cout << std::endl;

    std::nth_element(vec.begin(), vec.begin() + n, vec.end());

    std::cout << "The " << n + 1 << "th smallest element is " << vec[n] << std::endl;

    std::cout << "after nth element sort numbers: ";
    std::cout << vec;
    std::cout << std::endl;
}