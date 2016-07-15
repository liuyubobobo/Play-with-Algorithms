cmake_minimum_required(VERSION 3.5)
project(03_Selection_Sort_Using_Helper_Functions)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortTestHelper.h)
add_executable(03_Selection_Sort_Using_Helper_Functions ${SOURCE_FILES})