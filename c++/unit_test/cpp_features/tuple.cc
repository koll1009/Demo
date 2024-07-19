#include "gtest/gtest.h"
#include <string>
#include <tuple>

TEST(StdTest, StdTupleTest)
{
    auto tuple = std::make_tuple("koll", 36, true);
    ASSERT_EQ(std::get<0>(tuple), "koll");
    ASSERT_EQ(std::get<1>(tuple), 36);
    ASSERT_TRUE(std::get<2>(tuple));

    //structured bindings, introduced in C++17. 
    //This feature allows you to unpack tuple-like objects into 
    //individual variables easily.
    auto& [name, age, male] = tuple;
    ASSERT_EQ(name, "koll");
    ASSERT_EQ(age, 36);
    ASSERT_TRUE(male);

    age = 37;
    ASSERT_EQ(std::get<1>(tuple), 37);
}