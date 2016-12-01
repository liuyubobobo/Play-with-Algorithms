cmake_minimum_required(VERSION 3.5)
project(08_Index_Heap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortTestHelper.h)
add_executable(08_Index_Heap ${SOURCE_FILES})