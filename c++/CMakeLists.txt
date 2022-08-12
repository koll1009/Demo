cmake_minimum_required(VERSION 3.10)
project(myproj CXX)

include(cmake/common.cmake)
set(options arg1 arg2)
print("${options}" test)

option(RELEASE_F "release flag" OFF)
if(NOT RELEASE_F)
    message("debug version\n")
    set(CMAKE_BUILD_TYPE Debug)
endif()
add_definitions(-std=c++17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(koll)
add_subdirectory(test)
