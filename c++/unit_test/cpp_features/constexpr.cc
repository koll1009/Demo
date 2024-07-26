#include "gtest/gtest.h"

/* In C++, the constexpr specifier declares that it is possible 
 * to evaluate the value of a function or variable at compile time. 
 * This can be useful for performance optimization, as it allows 
 * computations to be done during compilation rather than at runtime.
 */

/* Restrictions:
 * constexpr functions are subject to certain restrictions.
 * They can only contain a limited subset of C++ constructs:
 *
 * No mutable state: constexpr functions cannot modify any state
 * or have any side effects.
 * 
 * Limited types of loops and conditional statements:
 * Loops and conditional statements are allowed as long as
 * they can be evaluated at compile time.
 * 
 * Restrictions on the types of expressions and functions
 * they can call: A constexpr function can only call other
 * constexpr functions, and can only operate on literal types
 * or other constexpr objects. 
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