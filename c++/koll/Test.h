#ifndef CPP_LIB_TEST_H
#define CPP_LIB_TEST_H
#include <string>
namespace koll {

class Test
{
public:
    Test() = delete;
    Test(int a, int b)
    : a_(a)
    , b_(b){
        
    }
    ~Test() = default;
    std::string getName();
private:
    int a_;
    int b_;

};

}

#endif