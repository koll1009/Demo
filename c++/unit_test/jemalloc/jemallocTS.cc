#include <iostream>
#include "gtest/gtest.h"
#include <thread>
#include <atomic>
#include <jemalloc/jemalloc.h>

using namespace std;

#define TESTNAME CPP_ATOMIC_APIS_TEST

TEST(TESTNAME, jemalloc_test) {
    char* msg = static_cast<char*>(malloc(1024));
    snprintf(msg, 1024, " this buffer is allocated by jemalloc\n");
    std::cout << __func__ << msg;
}