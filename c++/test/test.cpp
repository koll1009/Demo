#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Test.h"
#include <vector>
#include "Common.h"

using namespace std;

typedef struct {
  uint64_t time;
  uint8_t cur_state;
  uint8_t next_state;
} sf_flow_states;

typedef struct {
  sf_flow_states                        states[128][8];
  uint8_t                               counts[128];
} sf_flow_metadata_t;


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
#include "gtest/gtest.h"
TEST(Test1, Negative) {
    cout << "first one \n";
}
GTEST_API_ int main(int argc,char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); 

    ifstream fs;
    fs.open("test.cpp");
    stringstream buf;
    buf << fs.rdbuf();
    std::string content = buf.str();
    cout << content.c_str() << "\n";
    koll::Test a{1,2};
    cout << "name is " << a.getName() << "\n";
    RangeBaseLoop names;
    names.push("Jerry");
    names.push("Dudu");
    names.push("Daddy");
    names.push("Mummy");
    for (auto& name : names){
        cout << "name is " << name << "\n";
    }
    int b = 10; //type is int&&, but b is a left value,
    int&& ttt = 1;
    cout << is_lvalue_reference<decltype(b)>::value <<":" << koll::showMeType(10) << "\n";
    cout << is_lvalue_reference<decltype(10)>::value <<":" << koll::showMeType(fun1()) << "\n" ;
    cout << is_rvalue_reference<decltype(ttt)>::value <<":" << koll::showMeType(ttt) << "\n";
    return 0;
}