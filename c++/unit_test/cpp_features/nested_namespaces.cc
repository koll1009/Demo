#include "gtest/gtest.h"
#include <iostream>

namespace a::b::c::nested{
    int getWhatever ()
    {
        std::cout << "getWhatever which is defined in nested namespaces\n";
        return 88;
    }
}

TEST(StdTest, StdNestedNamespacesTest)
{
    ASSERT_EQ(a::b::c::nested::getWhatever(), 88);
}