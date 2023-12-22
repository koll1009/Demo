#ifndef CPP_LIB_KTIMERMANAGER_H
#define CPP_LIB_KTIMERMANAGER_H

#include <array>
#include <list>
#include <memory>
static const int ARRAYBITS = 8;
static const int ARRAYS = 4;
static const int ARRAYSIZE = 1 << ARRAYBITS;

class kTimer;

using TimerList = std::list<kTimer*>;
class kTimerManager {
public:
    kTimerManager(uint32_t ticks)
    : ticks_(ticks){

    }

    ~kTimerManager() = default;
    void insert(kTimer* timer);
    void process(int processes);
protected:
private:
    bool cascade(int index);
    uint32_t ticks_;
    std::array<TimerList, ARRAYSIZE> timers_[ARRAYS];
};
#endif