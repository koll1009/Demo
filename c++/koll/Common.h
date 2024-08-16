#ifndef CPP_kOLL_COMMON_H
#define CPP_kOLL_COMMON_H
#include <algorithm>
#include <iterator>
#include <string>
#include <typeinfo>
#include <ostream>
#include <vector>

using namespace std;

namespace koll {

template<typename  T>
ostream& operator<< (ostream& os, std::vector<T>& vec){
  std::for_each(std::begin(vec), std::end(vec),
                [&os](T &t) { os << t << "\t"; });
  os << "\n";
  return os;
}
    
template<typename T>
std::string showMeType(T&& t)
{
    std::string type{};
    type.append(typeid(t).name());
    type.append(std::is_rvalue_reference<decltype(t)>::value ? "&&":"");
    type.append(std::is_lvalue_reference<decltype(t)>::value ? "&":"");
    return type;
}

}
#endif