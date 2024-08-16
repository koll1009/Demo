#include "gtest/gtest.h"
#include <functional>
#include <numeric>

TEST(StdTest, StdAccumulateTest)
{
    //It is used to perform a cumulative operation on a range of elements,
    //typically summing them up, but it can also be used with other binary
    //operations.
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Using std::accumulate to sum the values
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum: " << sum << std::endl; // Output: Sum: 15 
    ASSERT_EQ(sum, 15);
    
    // Using std::accumulate to sum the values
    int init = 10;
    int sum2 = std::accumulate(numbers.begin(), numbers.end(), init);
    ASSERT_EQ(sum2, sum + init);

    // Using std::accumulate with a custom binary operation 
    // std::multiplies
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());
    std::cout << "multiplies: " << product << std::endl; // Output: Product: 120
    ASSERT_EQ(product, 120);

    // std::plus
    // sum = 15
    int plus = std::accumulate(numbers.begin(), numbers.end(), 0, std::plus<int>());
    std::cout << "plus: " << plus << std::endl;
    ASSERT_EQ(plus, 15);

    // std::minus
    // sum = 15
    int minus = std::accumulate(numbers.begin(), numbers.end(), 0, std::minus<int>());
    std::cout << "minus: " << minus << std::endl;
    ASSERT_EQ(minus, -15);

    int divide = std::accumulate(numbers.begin(), numbers.end(), 120, std::divides<int>());
    std::cout << "divide: " << divide << std::endl;
    ASSERT_EQ(divide, 1);
}