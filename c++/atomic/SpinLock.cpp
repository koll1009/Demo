#include "SpinLock.h"

namespace koll {

SpinLock::SpinLock()
: flag_(ATOMIC_FLAG_INIT)
{

}

void SpinLock::lock()
{
    while(flag_.test_and_set());
}

void SpinLock::unLock()
{
    flag_.clear();
}

}