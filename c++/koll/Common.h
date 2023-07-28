#ifndef CPP_kOLL_COMMON_H
#define CPP_kOLL_COMMON_H
#include <string>
#include <typeinfo>
namespace koll {
    
template<typename T>
std::string showMeType(T&& t)
{
    std::string type{};
    type.append(typeid(t).name());
    type.append(std::is_rvalue_reference<decltype(t)>::value ? "&&":"");
    type.append(std::is_lvalue_reference<decltype(t)>::value ? "&":"");
    return type;
}
template<typename T>
void double_(T&& t) 
{ 
    t <<= 1; 
}

}
#endif