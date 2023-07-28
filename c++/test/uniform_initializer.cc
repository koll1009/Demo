#include "gtest/gtest.h"
#include <iostream>
#include <string>
 
/* Advantage
 * 1. force initialization
 * 2. prevent narrowing convention
 * 3. syntax for all types
 */
#define TESTNAME UNIFORM_INITIALIZATION
using namespace std;
TEST(TESTNAME, example1) {
    bool a{true};
    char b{'b'};
    uint16_t c{}; //use default value
    int d{1};
    float f{3.14159267}; // take precision into consideration
    std::cout << a << b << c << d <<f <<" \n";
}

// pre-condition of brace-enclosed initializer list
// 1. non private data member ( aggregate initializer)
// 2. user defined constructor
class test_initializer_list
{
public:
    test_initializer_list(int age, string name)
    : age_(age)
    , name_(std::move(name))
    {}

    test_initializer_list(std::initializer_list<int> l ):v_(l){}
    std::string toString(){
        std::string str{}; 
        str.append("age:").append(to_string(age_)).append("\n");
        str.append("name:").append(name_).append("\n");
        str.append("array[]:");
        for (auto i : v_) {
            str.append(to_string(i)).append("\t");
        }
        str.append("\n");
        return str;
    }
private:
    int age_{};
    string name_{};
    std::vector<int> v_;
};

// lightweight proxy object that represents an array
// automatically constructed from a braced list of element;
TEST(TESTNAME, std_initializer_list) {
    test_initializer_list test1{36, "koll"};
    std::cout << test1.toString();
    test_initializer_list test2{1,2,3,4,5};
    std::cout << test2.toString();
    std::initializer_list<int> list {6,7,8,9,10};
    test_initializer_list test3{list};
    std::cout << test3.toString();
}