#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>

//In C++, the constexpr specifier declares that it is possible
//to evaluate the value of a function or variable at compile time

//Compile-time Condition: The condition inside if constexpr must be
//a constant expression, meaning it must be evaluatable at compile time.

//Discarding branches: The non-chosen branch of an if constexpr 
//is discarded before the program is compiled into machine code,
//which can help in avoiding compilation errors in code that
//is not applicable for certain template instantiations.

template<typename T>
auto printValue(const T& value) {
    if constexpr (std::is_integral<T>::value) {
        std::cout << "Integral: " << value << std::endl;
    } else if constexpr (std::is_floating_point<T>::value) {
        std::cout << "Floating point: " << value << std::endl;
    } else {
        std::cout << "Other type" << std::endl;
    }
}

TEST(StdTest, StdIfConstexprTest) {
    printValue(10);    // Integral
    printValue(3.14);  // Floating point
    printValue("Hello, World!");  // Other type
}