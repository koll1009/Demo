#include <iostream>
#include "gtest/gtest.h"
#include <thread>
#include <atomic>
using namespace std;

#define TESTNAME CPP_ATOMIC_APIS_TEST

TEST(TESTNAME, atomic_fetch_add_test) {
  int times = 1000000;
  int threads = 10;
  std::atomic_int stats = 0;

  auto stats_increment = [&stats](int n) {
    for (int i = 0; i < n; i++) {
        stats++;
    }
  };

  std::thread t[threads];
  for (int i = 0; i < threads; i++) {
    t[i] = std::thread(stats_increment, times);
  }

  for (int i = 0; i < threads; i++) {
    t[i].join();
  }
  std::cout << "sum: " << stats << "\n";
  ASSERT_EQ(stats, threads * times);
}