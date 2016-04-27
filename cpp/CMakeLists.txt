cmake_minimum_required(VERSION 3.1)
project(cpp)

option(WARNINGS "Switch on extra warnings" ON)

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

if(WARNINGS)
    # clang++ complains about googletest's INSTANTIATE_TEST_CASE_P() use
    # of variadic macro arguments, so disable that
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-gnu-zero-variadic-macro-arguments")
endif()

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(GILDED_ROSE_SOURCE_FILES
    GildedRose.cc
    GildedRose.h
    GildedRoseUnitTests.cc
    GildedRoseTextTests.cc
    GildedRoseTests.cc
    ItemController.cpp
    ItemController.h
    Item.h)

add_executable(GildedRose ${GILDED_ROSE_SOURCE_FILES})
target_link_libraries(GildedRose ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
