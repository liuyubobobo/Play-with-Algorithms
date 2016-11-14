cmake_minimum_required(VERSION 3.5)
project(MergeSortImplementationComparison2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MergeSort.h SortTestHelper.h InsertionSort.h)
add_executable(MergeSortImplementationComparison2 ${SOURCE_FILES})