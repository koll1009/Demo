#ifndef CPP_LIB_KTIMER_H
#define CPP_LIB_KTIMER_H

#include <algorithm>
#include <cstdint>
#include <iostream>
class kTimer {
public:
    kTimer(uint32_t expire) : expire_(expire){

    }
    uint32_t getExpire(){ return expire_; }
    virtual void timeout()
    {
        std::cout << __func__ << ":" << expire_ << "\n";
    }
private:
    uint32_t expire_;
};

#endif