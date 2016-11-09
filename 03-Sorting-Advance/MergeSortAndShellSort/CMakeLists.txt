cmake_minimum_required(VERSION 3.5)
project(MergeSortAndShellSort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp InsertionSort.h MergeSort.h ShellSort.h SortTestHelper.h)
add_executable(MergeSortAndShellSort ${SOURCE_FILES})