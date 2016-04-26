cmake_minimum_required(VERSION 2.8.4)
project(cpp)

# CMake FindThreads is broken until 3.1
#find_package(Threads REQUIRED)
set(CMAKE_THREAD_LIBS_INIT pthread)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(GILDED_ROSE_SOURCE_FILES
    GildedRose.cc
    GildedRose.h
    GildedRoseUnitTests.cc
    GildedRoseTextTests.cc
    GildedRoseTests.cc ItemController.cpp ItemController.h)

add_executable(GildedRose ${GILDED_ROSE_SOURCE_FILES})
target_link_libraries(GildedRose ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
