#ifndef CPP_LIB_TEST_H
#define CPP_LIB_TEST_H
#include <string>
namespace koll {

class Test
{
public:
    Test() = default;
    ~Test() = default;
    std::string getName();
private:

};

}

#endif