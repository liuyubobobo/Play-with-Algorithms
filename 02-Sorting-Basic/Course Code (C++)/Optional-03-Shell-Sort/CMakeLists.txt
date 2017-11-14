cmake_minimum_required(VERSION 3.5)
project(Optional_02_Shell_Sort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortTestHelper.h SelectionSort.h InsertionSort.h BubbleSort.h)
add_executable(Optional_02_Shell_Sort ${SOURCE_FILES})