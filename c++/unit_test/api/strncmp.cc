#include <cstring>
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

#define COMBINE(a, b, c) a## _b##c

TEST(StdTest, apiStrCmpTest)
{
    const char c1[] = "test1";
    const char *c2 = "tes";

    int COMBINE(a, b, c) = 1;
    EXPECT_TRUE(strncmp(c1, c2, strlen(c1)));
}