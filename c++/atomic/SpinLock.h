#ifndef  CPP_ATOMIC_SPINLOCK_H
#define  CPP_ATOMIC_SPINLOCK_H

#include <atomic>

namespace koll{
class SpinLock
{
public:
    SpinLock();
    void lock();
    void unLock();
private:
    std::atomic_flag flag_;
};
}
#endif