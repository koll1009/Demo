#include "gtest/gtest.h"
#include <vector>
#include "Common.h"
#include <ostream>

using namespace koll;

 /* It is used to remove all instances of a certain value from a range.
  * However, it doesn't actually delete or resize the container, but rather moves all elements
  * that are not to be removed to the front of the range, and leaves the "removed" elements in a valid
  * but unspecified state. It then returns an iterator pointing to the new end of the range.
  */
TEST(StdTest, StdRemoveTest)
{
    std::vector<int> array = {1, 2, 3, 3, 4, 5};
    std::cout << array;
    int originalSize = array.size();
    auto iter = std::remove(std::begin(array), std::end(array), 3);
    std::cout << array;
    ASSERT_EQ(array.size(), originalSize);

    array.erase(iter, array.end());
    std::cout << array;
    ASSERT_GT(originalSize, array.size());
    ASSERT_EQ(originalSize, array.size() + 2);
}