
#include "gtest/gtest.h"
#include <ostream>
#include <vector>

using namespace std;

static int bind_expression(const char *name, int age) {
  cout << name << "\n";
  return age;
}

TEST(StdTest, StdBindTest) {
  // It allows you to create a new callable object by binding arguments
  // to a callable object's parameters. This can be useful when you want
  // to fix certain arguments of a function and leave others to be 
  // specified later
  auto func1 = std::bind(&bind_expression, "koll", placeholders::_1);
  int random = rand();
  ASSERT_EQ(func1(random), random);
}