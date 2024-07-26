#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>
#include <vector>


TEST(StdTest, StdVariableDefinedInIfAndSwitchTest) {
std::vector<int> vec = {1, 2, 3, 4, 5};

// Old syntax to implement find and update
auto i = std::find(vec.begin(), vec.end(), 2);
if ( i != vec.end()){
    std::cout << *i << "\n";
}
else
{

}

// Use new syntax
if(auto i = std::find(vec.begin(), vec.end(), 2); i !=vec.end()){
    *i = 3;
    std::cout << "changed from 2 to 3 \n";
}

ASSERT_EQ(std::count(vec.begin(), vec.end(), 3), 2);

// same for switch

}