cmake_minimum_required(VERSION 3.5)
project(04_Binary_Search_Tree_Search)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SequenceST.h FileOps.h)
add_executable(04_Binary_Search_Tree_Search ${SOURCE_FILES})