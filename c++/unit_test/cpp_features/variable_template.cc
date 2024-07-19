#include "gtest/gtest.h"

template<typename T> 
T var1 = T(1.1);

template<>
char var1<char> = 'A'; //specilization

TEST(StdTest, StdVariableTemplateTest) {
    ASSERT_EQ(var1<int>, 1);
    // It's hard to rep
    ASSERT_EQ(var1<double>, 1.1);
    ASSERT_EQ(var1<char>, 'A');
}