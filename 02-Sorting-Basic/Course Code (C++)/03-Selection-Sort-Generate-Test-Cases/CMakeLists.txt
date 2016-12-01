cmake_minimum_required(VERSION 3.5)
project(03_Selection_Sort_Generate_Test_Cases)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortTestHelper.h)
add_executable(03_Selection_Sort_Generate_Test_Cases ${SOURCE_FILES})