#include "Common.h"
#include "gtest/gtest.h"
#include <ostream>
#include <vector>

using namespace koll;

class element {
public:
 explicit element(int value) : value_(value) {}
 friend ostream &operator<<(ostream &os, const element &obj) {
    os << obj.value_;
    return os;
  }

  bool operator<(const element &other) { return this->value_ < other.value_; }

  bool operator>(const element &other) const { return this->value_ > other.value_; }

  bool operator==(const element &other) { return this->value_ == other.value_; }

  bool operator>=(const element &other) { return this->value_ >= other.value_; }

  bool operator<=(const element &other) { return this->value_ <= other.value_; }

private:
  int value_;
};

TEST(StdTest, StdSortTest) {
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

  std::sort(vec.begin(), vec.end(),
            [](const element &l, const element &r) { return l > r; });
  cout << vec;
}