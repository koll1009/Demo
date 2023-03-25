#ifndef CPP_KOLL_KSPINLOCK_H
#define CPP_KOLL_KSPINLOCK_H

#include <atomic>

class kSpinLock {
public:
  kSpinLock() = default;
  ~kSpinLock() = default;
  void lock();
  void unlock();

protected:
private:
  std::atomic_flag flag_{ATOMIC_FLAG_INIT};
};
#endif