#include <iostream>
#include "gtest/gtest.h"
#include <thread>

#define TESTNAME GCC_SYNC_APIS_TEST
using namespace std;

TEST(TESTNAME, sync_add_and_fetch_test) {
  int stats = 0;

  auto stats_increment = [&stats](int n) {
    for (int i = 0; i < n; i++) {
      __sync_add_and_fetch(&stats, 1);
    }
  };

  std::thread t[10];
  for (int i = 0; i < 10; i++) {
    t[i] = std::thread(stats_increment, 1000000);
  }

  for (int i = 0; i < 10; i++) {
    t[i].join();
  }
  cout << "sum: " << stats << "\n";
  ASSERT_EQ(stats, 10 * 1000000);
}

TEST(TESTNAME, sync_fetch_and_add_test) {
  int stats = 0;
  int ret = 0;
  auto stats_increment = [&stats](int n) {
    for (int i = 0; i < n; i++) {
      __sync_fetch_and_add(&stats, 1);
    }
  };

  std::thread t[10];
  for (int i = 0; i < 10; i++) {
    t[i] = std::thread(stats_increment, 1000000);
  }

  for (int i = 0; i < 10; i++) {  
    t[i].join();
  }

  ret = __sync_fetch_and_add(&stats, 1);
  cout << "stats: " << stats << ", ret: "<< ret <<"\n";
  ASSERT_EQ(ret, 10 * 1000000);
  ASSERT_EQ(stats, 10 * 1000000 + 1);
}

TEST(TESTNAME, sync_lock_test_and_set_test) {
  int is_locked = 0;
  int stats = 0;
  auto lock = [&is_locked](){
    return !__sync_lock_test_and_set(&is_locked, 1); //
  };

  auto unlock = [&is_locked] (){
    __sync_lock_release(&is_locked);
  };

  auto stats_increment = [&](int n) {
    for (int i = 0; i < n; i++) {
      while (!lock());

      stats++;
      unlock();
    }
  };

  std::thread t[10];
  for (int i = 0; i < 10; i++) {
    t[i] = std::thread(stats_increment, 10000);
  }

  for (int i = 0; i < 10; i++) {  
    t[i].join();
  }

  cout << "stats: " << stats << "\n";
  ASSERT_EQ(stats, 10 * 10000);
}
