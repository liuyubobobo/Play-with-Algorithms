cmake_minimum_required(VERSION 3.5)
project(05_Optimize_by_Rank)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp UnionFind1.h UnionFind2.h UnionFind3.h UnionFindTestHelper.h)
add_executable(05_Optimize_by_Rank ${SOURCE_FILES})