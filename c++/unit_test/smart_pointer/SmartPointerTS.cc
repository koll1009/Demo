#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace  std;

class test {
public:
    test(int a, int b):a_(a), b_(b){}

private:
    int a_;
    int b_;

};

TEST(StdTest, SmartPointerTest)
{
    cout << "Test Begin \n";
    auto shared = std::make_shared<test>(1, 2);
    cout << "shared poiter counter: " << shared.use_count() << "\n";
    auto shared_incr = shared;
    cout << "shared poiter counter: " << shared.use_count() << "\n";
    auto weak_ptr = std::weak_ptr<test>(shared);
    cout << "shared poiter counter: " << shared.use_count() << "\n";
    {
        auto t1 = weak_ptr.lock();
        cout << "shared poiter counter: " << shared.use_count() << "\n";
    }
    cout << "shared poiter counter: " << shared.use_count() << "\n"; 
}