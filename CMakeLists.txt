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

#some packages are provided by cmake, such as Git, located in /usr/share/cmake-3.16/Modules/
find_package(Git REQUIRED)
find_package(PkgConfig REQUIRED)

message("build jemalloc first")
execute_process(COMMAND /bin/sh ../../prebuild.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/3pp/jemalloc
    OUTPUT_FILE log.txt
)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/3pp/jemalloc/lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3pp/jemalloc/include/)

add_subdirectory(3pp)
add_subdirectory(c++)