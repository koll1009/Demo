#include "gtest/gtest.h"
#include <iostream>
#include <memory>
#include <ostream>
#include <vector>


/* 
 * 1. Automatic Resource Management: When a unique_ptr goes out of scope, 
 * the destructor for the unique_ptr is called, and the memory for the 
 * managed object is automatically freed.
 *
 * 2. Ownership Transfer: unique_ptr supports ownership transfer 
 * which means that you can transfer the ownership of the underlying object 
 * from one unique_ptr to another. This can be done using the move semantics
 * provided by C++11 and later.
 *
 * 3. Custom Deleters: You can specify a custom deleter with unique_ptr.
 * This is useful if you need a special function to release resources
 * other than just deleting the object.
 */
TEST(StdTest, StdUniquePtrTest) {
    auto var1 = std::make_unique<int>(2);
    ASSERT_EQ(*var1, 2);

    auto var2 = std::make_unique<std::vector<int>>();
    var2->emplace_back(1);
    var2->emplace_back(2);
    ASSERT_EQ(var2->size(), 2);

    class test{
    public:
        test(int age): age_(age) {
            std::cout << "test constructor\n";
        };
        int getAge() const {
            std::cout << "getAge() is invoked\n";
            return age_;
        }
        ~test() {
            std::cout << "test destructor\n";
        }
    private:
        int age_{0};
    };

    auto var3 = std::make_unique<test>(7);
    ASSERT_EQ(var3->getAge(), 7);

}