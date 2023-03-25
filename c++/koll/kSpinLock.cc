#include "kSpinLock.h"

void kSpinLock::lock()
{
    while(flag_.test_and_set(std::memory_order_acquire));
}

void kSpinLock::unlock()
{
    flag_.clear(std::memory_order_release);
}