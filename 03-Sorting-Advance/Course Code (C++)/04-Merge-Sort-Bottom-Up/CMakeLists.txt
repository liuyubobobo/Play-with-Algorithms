cmake_minimum_required(VERSION 3.5)
project(04_Merge_Sort_Bottom_Up)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortTestHelper.h InsertionSort.h MergeSort.h)
add_executable(04_Merge_Sort_Bottom_Up ${SOURCE_FILES})