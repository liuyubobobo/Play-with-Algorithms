cmake_minimum_required(VERSION 3.5)
project(Optional_01_Bubble_Sort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortTestHelper.h SelectionSort.h InsertionSort.h)
add_executable(Optional_01_Bubble_Sort ${SOURCE_FILES})