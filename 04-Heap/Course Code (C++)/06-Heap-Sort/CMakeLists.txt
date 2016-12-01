cmake_minimum_required(VERSION 3.5)
project(06_Heap_Sort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortTestHelper.h Heap.h MergeSort.h QuickSort.h InsertionSort.h HeapSort.h)
add_executable(06_Heap_Sort ${SOURCE_FILES})