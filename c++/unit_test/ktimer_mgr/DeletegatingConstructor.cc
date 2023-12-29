#include "kTimer.h"
#include "kTimerManager.h"
#include <bits/types/struct_timeval.h>
#include <condition_variable>
#include <cstdint>
#include <iostream>
#include "gtest/gtest.h"
#include <sys/select.h>

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

TEST(TESTNAME, delegating_constructor_test_timer)
{
    uint32_t now = 0;
    kTimerManager mgr(now);
    kTimer* t = new kTimer(322222222); 
    mgr.addTimer(t);
    mgr.addTimer(new kTimer(1111));
    mgr.addTimer(new kTimer(1));
    mgr.addTimer(new kTimer(22));
    mgr.addTimer(new kTimer(133));
    mgr.addTimer(new kTimer(500));
    mgr.addTimer(new kTimer(255));
    mgr.addTimer(new kTimer(65535));
    mgr.addTimer(new kTimer(111500));
    mgr.addTimer(new kTimer(65536));
    mgr.process(10);
}