cmake_minimum_required(VERSION 3.5)
project(06_Quick_Sort_Deal_With_Nearly_Ordered_Array)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortTestHelper.h MergeSort.h InsertionSort.h)
add_executable(06_Quick_Sort_Deal_With_Nearly_Ordered_Array ${SOURCE_FILES})