#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace  std;

class test {
public:
    test(int a, int b):a_(a), b_(b){
    }
    int getA() const { return a_; }

private:
    int a_;
    int b_;

};

TEST(StdTest, SharedPtrTest)
{
    cout << "Test Begin \n";

    auto shared = std::make_shared<test>(1, 2);
    cout << "shared poiter counter: " << shared.use_count() << "\n";
    ASSERT_EQ(shared.use_count(), 1);

    auto shared_incr = shared;
    cout << "shared poiter counter: " << shared.use_count() << "\n";
    ASSERT_EQ(shared.use_count(), 2);

    auto weak_ptr = std::weak_ptr<test>(shared);
    cout << "shared poiter counter: " << shared.use_count() << "\n";
    ASSERT_EQ(shared.use_count(), 2);

    {
        auto t1 = weak_ptr.lock();
        cout << "shared poiter counter: " << shared.use_count() << "\n";
        ASSERT_EQ(shared.use_count(), 3);
    }

    ASSERT_EQ(shared.use_count(), 2);
    cout << "shared poiter counter: " << shared.use_count() << "\n";
}