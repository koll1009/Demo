#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include "gtest/gtest.h"
#include <ostream>
#include <pstl/glue_algorithm_defs.h>
#include <type_traits>
#include <utility>
#include <vector>
using namespace  std;

template<typename  T>
ostream& operator<< (ostream& os, std::vector<T>& vec){
    for(auto& iter : vec){
        os << iter << "\t";
    }
    os << "\n";
    return os;
}

 /* It is used to remove all instances of a certain value from a range.
  * However, it doesn't actually delete or resize the container, but rather moves all elements
  * that are not to be removed to the front of the range, and leaves the "removed" elements in a valid
  * but unspecified state. It then returns an iterator pointing to the new end of the range.
  */
TEST(StdTest, StdRemoveTest)
{
    std::vector<int> array = {1, 2, 3, 3, 4, 5};
    cout << array;
    int originalSize = array.size();
    auto iter = std::remove(array.begin(), array.end(), 3);
    cout << array;
    ASSERT_EQ(array.size(), originalSize);

    array.erase(iter, array.end());
    cout << array;
    ASSERT_GT(originalSize, array.size());
    ASSERT_EQ(originalSize, array.size() + 2);std::vector<int>::iterator a;
}
class element {
public:
    element(int value):value_(value){

    }
    friend ostream& operator<<(ostream&os, const element& obj){
        os << obj.value_;
        return os;
    }

    bool operator<(const element& other){
        return this->value_ < other.value_;
    }

    bool operator>(const element& other){
        return this->value_ > other.value_;
    }

    bool operator==(const element& other){
        return this->value_ == other.value_;
    }

    bool operator>=(const element& other){
        return this->value_ >= other.value_;
    }

    bool operator<=(const element& other){
        return this->value_ <= other.value_;
    }        
    int getValue() {return value_;}
private:
    int value_;
};




TEST(StdTest, StdSortTest)
{
    vector<element> vec;
    vec.emplace_back(3);
    vec.emplace_back(1);
    vec.emplace_back(2);
    vec.emplace_back(5);
    vec.emplace_back(4);
    vec.emplace_back(2);

    cout << vec;
    std::sort(vec.begin(), vec.end());
    cout << vec;

    std::sort(vec.begin(), vec.end(), [](element &l, element &r) {
      return l > r;
    });
    cout << vec;
}

TEST(StdTest, StdCountTest)
{
/*     std::vector<int> array = {1, 2, 3, 3, 4, 5};
    int originalSize = array.size();
    auto iter = std::remove(array.begin(), array.end(), 3);
    ASSERT_EQ(array.size(), originalSize);
    ASSERT_EQ(iter, 3);

    array.erase(iter, array.end());
    ASSERT_GT(originalSize, array.size());
    ASSERT_EQ(originalSize, array.size() + 2);std::vector<int>::iterator a; */
}

TEST(StdTest, StdCountIfTest)
{
/*     std::vector<int> array = {1, 2, 3, 3, 4, 5};
    int originalSize = array.size();
    auto iter = std::remove(array.begin(), array.end(), 3);
    ASSERT_EQ(array.size(), originalSize);
    ASSERT_EQ(iter, 3);

    array.erase(iter, array.end());
    ASSERT_GT(originalSize, array.size());
    ASSERT_EQ(originalSize, array.size() + 2);std::vector<int>::iterator a; */
}

static int bind_expression(const char* name, int age)
{
    cout << name << "\n";
    return age;
}

TEST(StdTest, StdFunctionTest)
{
    enum class FunctionType {
        STATIC_FUNCTION,
        LAMBDA_FUNCTION,
        STD_BIND_EXP,
        CLASS_FUNCTOR,
        MEMBER_FUNCTION
    };
    
    class TestFunction {
    public:
        FunctionType operator()(){
            return FunctionType::CLASS_FUNCTOR;
        }

        static FunctionType staticFunc(){
            return FunctionType::STATIC_FUNCTION;
        }

        FunctionType memFunc(){
            return FunctionType::MEMBER_FUNCTION;
        }
    };

    TestFunction ctx;
    std::function<FunctionType(void)> func;

    //Free fucntions or static member function
    func = &TestFunction::staticFunc;
    ASSERT_EQ(func(), FunctionType::STATIC_FUNCTION);

    //functor
    func = ctx;
    ASSERT_EQ(func(), FunctionType::CLASS_FUNCTOR);

    //member function
    func = std::bind(&TestFunction::memFunc, &ctx);
    ASSERT_EQ(func(), FunctionType::MEMBER_FUNCTION);

    //lambda
    func = []()->FunctionType {
        return FunctionType::LAMBDA_FUNCTION;
    };
    ASSERT_EQ(func(), FunctionType::LAMBDA_FUNCTION);

    //bind
    auto func1 = std::bind(&bind_expression, "koll", placeholders::_1);
    int random = rand();
    ASSERT_EQ(func1(random), random);


/*     std::vector<int> array = {1, 2, 3, 3, 4, 5};
    int originalSize = array.size();
    auto iter = std::remove(array.begin(), array.end(), 3);
    ASSERT_EQ(array.size(), originalSize);
    ASSERT_EQ(iter, 3);

    array.erase(iter, array.end());
    ASSERT_GT(originalSize, array.size());
    ASSERT_EQ(originalSize, array.size() + 2);std::vector<int>::iterator a; */
}

TEST(StdTest, StdBindTest)
{
/*     std::vector<int> array = {1, 2, 3, 3, 4, 5};
    int originalSize = array.size();
    auto iter = std::remove(array.begin(), array.end(), 3);
    ASSERT_EQ(array.size(), originalSize);
    ASSERT_EQ(iter, 3);

    array.erase(iter, array.end());
    ASSERT_GT(originalSize, array.size());
    ASSERT_EQ(originalSize, array.size() + 2);std::vector<int>::iterator a; */
}

