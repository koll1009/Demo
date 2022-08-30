#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Test.h"
#include <vector>
#include "Common.h"

using namespace std;
// pre-condition of brace-enclosed initializer list
// 1. non private data member ( aggregate initializer)
// 2. user defined constructor
// 3. std::
class test_initializer_list
{
public:
    test_initializer_list(int age, string name)
    : age_(age)
    , name_(std::move(name))
    , a_(1)
    {}

    test_initializer_list(std::initializer_list<int> l ):v_(l){}
    void print(){std::cout << "age:" << age_ << " name:" << name_ << "\n"; }
private:
    int age_;
    string name_;
    int a_;
    std::vector<int> v_;
};

class RangeBaseLoop
{
    using NameArray = std::vector<string>;
public:
    NameArray::iterator begin() { return names_.begin(); }
    NameArray::iterator end() { return names_.end(); }
    void push(string name) {
        names_.push_back(std::move(name));
    }
private:
    NameArray names_;
};

koll::Test fun1()
{
    return koll::Test(1,2);
}
int main(int argc,char* argv[])
{
    ifstream fs;
    fs.open("test.cpp");
    stringstream buf;
    buf << fs.rdbuf();
    std::string content = buf.str();
    cout << content.c_str() << "\n";
    koll::Test a{1,2};
    cout << "name is " << a.getName() << "\n";
    test_initializer_list obj{1, "koll"};
    test_initializer_list obj2{1,2,3};
    obj.print();
    RangeBaseLoop names;
    names.push("Jerry");
    names.push("Dudu");
    names.push("Daddy");
    names.push("Mummy");
    for (auto& name : names){
        cout << "name is " << name << "\n";
    }
    int b = 10; //type is int&&, but b is a left value,
    cout << is_lvalue_reference<decltype(b)>::value <<":" << koll::showMeType(b) << "\n";
    cout << is_lvalue_reference<decltype(10)>::value <<":" << koll::showMeType(fun1()) << "\n" ;
    return 0;

    
}