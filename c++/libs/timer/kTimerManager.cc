#include "kTimerManager.h"
#include "kTimer.h"
#include <cstdint>
#include <iostream>
#include <list>
#include <memory>
#include <queue>

void kTimerManager::addTimer(kTimer *timer) {
  timer->setExpire(timer->getTimeout() + ticks_);
  reInsert(timer);
}

void kTimerManager::reInsert(kTimer *timer)
{
    uint32_t duration = timer->getExpire() - ticks_;
    int index = 0;
    if (duration <= 0xff) {
        index = 0;
    } else if (duration <= 0xffff) {
        index = 1;
    } else if (duration <= 0xffffff) {
        index = 2;
    } else {
        index = 3;
    }

    timers_[index][(timer->getExpire() >> (8 * index)) & (ARRAYSIZE - 1)]
        .push_back(timer);
}

void kTimerManager::process(int processes) {
  int p = 0;
  while (true) {
    ticks_++;
    int index = 0;
    while (index < ARRAYS && cascade(index))
      index++;

    auto &list = timers_[0][ticks_ & (ARRAYSIZE - 1)];
    if (!list.empty()) {
      std::cout << __func__ << "ticks_:" << ticks_ << "\n";
    }

    while (!list.empty()) {
      auto t = list.begin();
      (*t)->timeout();
      list.pop_front();
      if (++p == processes)
        return;
    }
  }
}

bool kTimerManager::cascade(int index) {
  if (!((ticks_ >> (index * ARRAYBITS)) & (ARRAYSIZE - 1))) {
    auto &list = timers_[index + 1]
                        [(ticks_ >> (index + 1) * ARRAYBITS) & (ARRAYSIZE - 1)];
    for (auto timer : list) {
      reInsert(timer);
    }
    list.clear();
    return true;
  } else {
    return false;
  }
}