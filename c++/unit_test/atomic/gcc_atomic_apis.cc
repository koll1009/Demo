#include <iostream>
#include "gtest/gtest.h"
#include <thread>
using namespace std;

#define TESTNAME GCC_ATOMIC_APIS_TEST

//These functions are intended to replace the legacy ‘__sync’ builtins. 
//The main difference is that the memory order that is requested is a parameter 
//to the functions. New code should always use the ‘__atomic’ builtins 
//rather than the ‘__sync’ builtins

/* memory_order_relaxed：
    there are no synchronization or ordering constraints imposed on other reads or writes,
    only this operation's atomicity is guaranteed (see Relaxed ordering below).

  memory_order_consume
    A load operation with this memory order performs a consume operation
    on the affected memory location: no reads or writes in the current thread 
    dependent on the value currently loaded can be reordered before this load.
    Writes to data - dependent variables in other threads that release the same atomic
    variable are visible in the current thread.On most platforms, this affects compiler
    optimizations only

  memory_order_acquire
    A load operation with this memory order performs the acquire operation on the affected memory location:
    no reads or writes in the current thread can be reordered before this load .
    All writes in other threads that release the same atomic variable are visible in the current thread
            
  memory_order_release A store operation with
    this memory order performs the release operation : no reads or writes in the current thread can be reordered after
    this store.All writes in the current thread are visible in other threads that acquire the same atomic
    variable and writes that carry a dependency into the atomic variable become visible in other threads that consume the same
    atomic
                    
  memory_order_acq_rel
    A read - modify - write operation with this memory order is both an acquire
    operation and a release operation.No memory reads or writes in the current thread can be reordered before the load,
    nor after the store All writes in other threads that release the same atomic variable are visible before the modification and the
    modification is visible in other threads that acquire the same atomic variable
    
  memory_order_seq_cst
    A load operation with this memory order performs an acquire operation, a store performs a release operation,
    and read - modify - write performs both an acquire operation and a release operation,
    plus a single total order exists in which all threads observe all
    modifications in the same order */

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