cmake_minimum_required(VERSION 3.5)
project(05_Quick_Sort_Another_Partition)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp QuickSort.h SortTestHelper.h)
add_executable(05_Quick_Sort_Another_Partition ${SOURCE_FILES})