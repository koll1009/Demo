#include "gtest/gtest.h"
#include <chrono>
#include <cstdint>
#include <iostream>
#include <thread>

using namespace std::chrono;

void printDuration(std::chrono::milliseconds s){
    std::cout << "milli seconds: " << s.count() << "\n";
}

TEST(StdTest, StdChronoTest) {
  auto dur = 10s; 
  std::cout << dur.count() << " seconds\n";
  printDuration(dur);

  auto start = std::chrono::steady_clock::now();
  // Simulate work by sleeping for 1 second
  std::this_thread::sleep_for(std::chrono::seconds(1));
  auto end = std::chrono::steady_clock::now();
  auto elapsed_seconds = std::chrono::duration_cast<seconds>(end - start);
  std::cout << "Elapsed time: " << elapsed_seconds.count() << " seconds\n";

  auto now = std::chrono::system_clock::now();
  std::time_t now_c = std::chrono::system_clock::to_time_t(now);
  std::cout << "Current time: " << std::ctime(&now_c) << std::endl;
}