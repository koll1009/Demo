#include "gtest/gtest.h"
#include "kSpinLock.h"

kSpinLock lock;
TEST(StdTest, lock_guard)
{
    std::cout << "lock_guard" <<"\n";
    std::lock_guard<kSpinLock> guard(lock);
}