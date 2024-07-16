
#include "gtest/gtest.h"
#include <ostream>
#include <vector>

using namespace std;

static int bind_expression(const char *name, int age) {
  cout << name << "\n";
  return age;
}

TEST(StdTest, StdFunctionTest) {
  enum class FunctionType {
    STATIC_FUNCTION,
    LAMBDA_FUNCTION,
    STD_BIND_EXP,
    CLASS_FUNCTOR,
    MEMBER_FUNCTION
  };

  class TestFunction {
  public:
    FunctionType operator()() { return FunctionType::CLASS_FUNCTOR; }

    static FunctionType staticFunc() { return FunctionType::STATIC_FUNCTION; }

    FunctionType memFunc() { return FunctionType::MEMBER_FUNCTION; }
  };

  TestFunction ctx;
  std::function<FunctionType(void)> func;

  // Free fucntions or static member function
  func = &TestFunction::staticFunc;
  ASSERT_EQ(func(), FunctionType::STATIC_FUNCTION);

  // functor
  // In C++, a functor (also known as a function object) is an object that can be called
  // as if it were a function. This is achieved by providing an overloaded operator() 
  // in the object's class
  func = ctx;
  ASSERT_EQ(func(), FunctionType::CLASS_FUNCTOR);

  // member function
  func = std::bind(&TestFunction::memFunc, &ctx);
  ASSERT_EQ(func(), FunctionType::MEMBER_FUNCTION);

  // lambda
  func = []() -> FunctionType { return FunctionType::LAMBDA_FUNCTION; };
  ASSERT_EQ(func(), FunctionType::LAMBDA_FUNCTION);

  // bind
  auto func1 = std::bind(&bind_expression, "koll", placeholders::_1);
  int random = rand();
  ASSERT_EQ(func1(random), random);
}