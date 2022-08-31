#include <iostream>
#include "gtest/gtest.h"
using namespace std;

/* [] captures no variables (cannot be omitted).

[x, &y] captures x by value and y by reference.

[=, &x] captures all variables from the enclosing scope by value except x, which is captured by reference.

[&, x,y] captures all variables by reference except x and y, which are captured by value.

[this] captures the this pointer, granting the body access to all members of the surrounding object. */
TEST(StdTest, LambdaTest)
{
    cout << "Test Begin \n";
    int a = 1;
    int b = 2;
    auto func1 = [a](int arg1) {return a + arg1;};
    cout << "func1(2): " << func1(2) << " a:" << a << "\n";

    auto func2 = [&a](int arg1) { return a += arg1; };
    cout << "func2(2): " << func2(2) << " a:" << a << "\n";

    auto func3 = [](int arg1) {
        return arg1;
    };

    auto func4 = [=](int arg1) {
        return a + b + arg1;
    };
    cout << "func4(2): " << func4(2) << " a:" << a  << " b:" << b << "\n";
    auto func5 =[&](int arg1) {
        return a += (b += arg1);
    };
    cout << "func5(2): " << func5(2) << " a:" << a  << " b:" << b << "\n";
}