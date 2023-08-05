#include <iostream>
#include "gtest/gtest.h"
using namespace std;

#define TESTNAME CPP_DELEGATING_CONSTRUCTOR_TEST


// Initializer of delegating constructor must appear alone
class test
{
public:
    test():test(0){

    }
    explicit test (int a): test(a,0){

    }
    test(int a, int b)
    : a_(a)
    , b_(b)
    {

    }
    int getA() const {return a_;}
    int getB() const {return b_;}
private:
    int a_;
    int b_;
};

TEST(TESTNAME, delegating_constructor_test)
{
    test a1;
    EXPECT_EQ(a1.getA(), 0);
    EXPECT_EQ(a1.getB(), 0);

    test a2(1);
    EXPECT_EQ(a2.getA(), 1);
    EXPECT_EQ(a2.getB(), 0);

    test a3(1, 2);
    EXPECT_EQ(a3.getA(), 1);
    EXPECT_EQ(a3.getB(), 2);
}