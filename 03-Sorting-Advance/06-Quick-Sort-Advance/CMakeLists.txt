cmake_minimum_required(VERSION 3.5)
project(06_Quick_Sort_Advance)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortTestHelper.h MergeSort.h InsertionSort.h)
add_executable(06_Quick_Sort_Advance ${SOURCE_FILES})