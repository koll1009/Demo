#ifndef CPP_LIB_KTIMER_H
#define CPP_LIB_KTIMER_H

#include <algorithm>
#include <cstdint>
#include <iostream>
class kTimer {
public:
    kTimer(uint32_t timeout)
    : kTimer(timeout, true)
    {

    }

    kTimer(uint32_t timeout, bool isRepeat)
    : timeout_(timeout)
    , isRepeat_(isRepeat)
    {

    }

    uint32_t getExpire(){ return expire_; }
    void setExpire(uint32_t expire) {
        expire_ = expire;
    }
    virtual void timeout()
    {
        std::cout << __func__ << ":" << expire_ << "\n";
    }
    uint32_t getTimeout() {return timeout_;}
    uint32_t getIsRepeat() { return isRepeat_; }
private:
    uint32_t expire_;
    uint32_t timeout_;
    bool     isRepeat_;
};

#endif 