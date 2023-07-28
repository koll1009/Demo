cmake_minimum_required(VERSION 3.13)
project(demo CXX)

include(c++/cmake/common.cmake)

set(BUILD_GMOCK OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_definitions(-std=c++17)

option(RELEASE_FLAG "release version" OFF)
if(NOT RELEASE_FLAG)
    message("debug version\n")
    set(CMAKE_BUILD_TYPE Debug)
else()
    message("release version\n")
    set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(3pp/gtest)
add_subdirectory(c++)