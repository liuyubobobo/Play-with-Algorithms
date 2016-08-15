cmake_minimum_required(VERSION 3.5)
project(05_Heapify)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Heap.h InsertionSort.h MergeSort.h QuickSort.h SortTestHelper.h)
add_executable(05_Heapify ${SOURCE_FILES})