cmake_minimum_required(VERSION 3.5)
project(01_2_Selection_Sort_Using_template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortHelper.h SortHelper.cpp )
add_executable(01_2_Selection_Sort_Using_template ${SOURCE_FILES} SortHelper.h SortHelper.cpp )