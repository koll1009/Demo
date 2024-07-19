#include "gtest/gtest.h"

/* In C++, the constexpr specifier declares that it is possible 
 * to evaluate the value of a function or variable at compile time. 
 * This can be useful for performance optimization, as it allows 
 * computations to be done during compilation rather than at runtime.
 */

static constexpr int factorial(int n) 
{
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

TEST(StdTest, StdConstexprTest) {
  constexpr int val = factorial(5); // Computed at compile time
  static_assert(val == 120, "calculation error");
  ASSERT_EQ(val, 120);
}