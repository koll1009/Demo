// It is used to randomly shuffle the elements in a given range. 
// The function uses a random number generator to determine the
// new ordering of the elements.

#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>
#include <ostream>
#include <random>
#include "Common.h"

using namespace koll;

TEST(StdTest, StdShuffleTest) {
   std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Obtain a time-based seed
    std::random_device rd;
    // Use the seed to initialize a default_random_engine
    std::default_random_engine rng(rd());

    // Shuffle the elements in the vector
    std::shuffle(vec.begin(), vec.end(), rng);

    // Print the shuffled elements
    std::cout << vec << std::endl;
}