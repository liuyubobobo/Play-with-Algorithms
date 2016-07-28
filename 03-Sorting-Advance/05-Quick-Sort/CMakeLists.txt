cmake_minimum_required(VERSION 3.5)
project(05_Quick_Sort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortTestHelper.h MergeSort.h InsertionSort.h)
add_executable(05_Quick_Sort ${SOURCE_FILES})