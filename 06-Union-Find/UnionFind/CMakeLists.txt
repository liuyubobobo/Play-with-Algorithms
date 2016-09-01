cmake_minimum_required(VERSION 3.5)
project(UnionFind)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp UnionFindTestHelper.h UnionFind2.h UnionFind3.h UnionFind4.h UnionFind5.h)
add_executable(UnionFind ${SOURCE_FILES})