//std::stable_sort, on the other hand, preserves the relative order of equivalent elements.
//This means that if two items are considered equal by the sorting criteria, their order
//relative to each other will remain unchanged after sorting

#include "gtest/gtest.h"

struct Employee {
    int id;
    std::string name;
};

static bool compareById(const Employee& a, const Employee& b) {
    return a.id < b.id;
}

TEST(StdTest, StdStableSortTest) {
    std::vector<Employee> employees = {
        {2, "Alice"},
        {1, "Bob"},
        {3, "Charlie"},
        {1, "David"}
    };

    // Sorting by id while preserving the relative order of employees with the same id
    std::stable_sort(employees.begin(), employees.end(), compareById);

    for (const auto& e : employees) {
        std::cout << e.id << " " << e.name << std::endl;
    }
}