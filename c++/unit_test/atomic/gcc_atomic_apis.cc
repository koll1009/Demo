#include <iostream>
#include "gtest/gtest.h"
#include <thread>
using namespace std;

#define TESTNAME GCC_ATOMIC_APIS_TEST

//These functions are intended to replace the legacy ‘__sync’ builtins. 
//The main difference is that the memory order that is requested is a parameter 
//to the functions. New code should always use the ‘__atomic’ builtins 
//rather than the ‘__sync’ builtins

TEST(TESTNAME, atomic_fetch_add_test) {
  int stats = 0;

  auto stats_increment = [&stats](int n) {
    for (int i = 0; i < n; i++) {
      __atomic_fetch_add(&stats, 1, __ATOMIC_RELAXED); //
    }
  };

  std::thread t[10];
  for (int i = 0; i < 10; i++) {
    t[i] = std::thread(stats_increment, 1000000);
  }

  for (int i = 0; i < 10; i++) {
    t[i].join();
  }
  std::cout << "sum: " << stats << "\n";
  ASSERT_EQ(stats, 10 * 1000000);
}

TEST(TESTNAME, atomic_load_and_store_test) {
  int stats = 0;

  auto store = [&stats](int n) {
    for (int i = 1; i <= n; i++) {
      __atomic_store_n(&stats, i, __ATOMIC_RELAXED);//Don't care about memory reordering
    }
  };

  auto load = [&stats](int n) {
    int ret[n];
    for (int i = 0; i < n; i++) {
      ret[i] =  __atomic_load_n(&stats, __ATOMIC_RELAXED);
    }
    for (int i = 0; i < n; i++) {
          std::cout << ret[i];
    }
    std::cout << "\n";
  };

  std::thread stores[2], loads[2];
  for (int i = 0; i < 1; i++) {
    stores[i] = std::thread(store, 10);
    loads[i] = std::thread(load, 10);
  }

  for (int i = 0; i < 1; i++) {
    stores[i].join();
    loads[i].join();
  }
}

/* TEST(TESTNAME, atomic_fetch_add_memory_order_test) {
  uint stats = 0;
  int stop = false;

  auto store1 = [&]() {
    while (!stop) {
      __atomic_store_n(&stats, 0, __ATOMIC_RELAXED);//always write 0
    }
  };

  auto store2 = [&]() {
    while (!stop) {
      __atomic_store_n(&stats, 0XFFFFFFFF, __ATOMIC_RELAXED);//always write 0
    }
  };


  auto load = [&]() {
    while(true) {
      uint ret = __atomic_load_n(&stats, __ATOMIC_RELAXED);
      std::cout << ret << "\n";
      if (ret!=0 && ret!= 0xFFFFFFFF){
        stop = true;
        std::cout << "reorder happens\n";
        break;
      }
    }
  };
  
  std::thread t1{store1};
  std::thread t2(store2);
  std::thread t3{load};
  t1.join();
  t2.join();
  t3.join();

} */