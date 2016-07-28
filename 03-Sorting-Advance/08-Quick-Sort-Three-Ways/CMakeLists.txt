cmake_minimum_required(VERSION 3.5)
project(08_Quick_Sort_Three_Ways)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortTestHelper.h MergeSort.h InsertionSort.h QuickSort.h)
add_executable(08_Quick_Sort_Three_Ways ${SOURCE_FILES})