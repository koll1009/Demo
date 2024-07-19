
#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <variant>

using namespace std;


TEST(StdTest, StdVariantTest) {
    // std::variant represents a type-safe union. 
    // An instance of std::variant at any given time either holds a value 
    // of one of its alternative types, or in the case of error - no value
    std::variant<int, float, std::string> var;
    var = "koll";
    try {
        std::cout << std::get<int>(var);
    } catch (const std::bad_variant_access& ex) {
        std::cout << "Invalid access: " << ex.what() <<"\n";
    }

    ASSERT_TRUE(std::holds_alternative<std::string>(var));

    // index or type is ok
    if (std::get_if<2>(&var)){
        std::cout << "value is string: " << std::get<2>(var) <<"\n";
        ASSERT_EQ(std::get<std::string>(var), "koll");
    }
}