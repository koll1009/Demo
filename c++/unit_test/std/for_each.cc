#include "gtest/gtest.h"
#include <iostream>

TEST(StdTest, StdForEachTest){
    std::vector<int> src = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "vector:\n";
    std::for_each(std::begin(src), std::end(src),
                [](int t) { std::cout << t << "\t"; });
    std::cout << "\n";
}