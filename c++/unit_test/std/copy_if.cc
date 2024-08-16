#include "gtest/gtest.h"
#include "Common.h"

using namespace koll;;

TEST(StdTest, StdCopyIfTest){
    std::vector<int> src = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> dest;

    // Resize the destination vector to accommodate the copied elements
    dest.resize(src.size());

    // Copy only even numbers from src to dest
    auto it = std::copy_if(src.begin(), src.end(), dest.begin(), [](int v){ return v % 2 == 0; });

    // Resize the destination vector to the actual number of copied elements
    dest.resize(std::distance(dest.begin(), it));

    // Print the src vector
    std::cout << "Original numbers: ";
    std::cout << src;
    std::cout << std::endl;

    // Print the destination vector
    std::cout << "Copied even numbers: ";
    std::cout << dest;
    std::cout << std::endl;
}