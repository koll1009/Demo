//If the type is a reference type, it is replaced by the type it refers to.
//If the type is an array of T, it is replaced by a pointer to T.
//If the type is a function type, it is replaced by a pointer to the function.
//Any top-level const, volatile, or const volatile qualifiers are removed

#include "gtest/gtest.h"

template <typename T>
void printDecayedType() {
    using DecayedType = typename std::decay<T>::type;
    std::cout << typeid(DecayedType).name() << std::endl;
}

TEST(StdTest, StdDecayTest)
{
    printDecayedType<int>();         // prints "int"
    printDecayedType<int&>();        // prints "int"
    printDecayedType<const int>();   // prints "int"
    printDecayedType<int[]>();       // prints "int*"
    printDecayedType<void()>();      // prints "void (*)()"
}