cmake_minimum_required(VERSION 3.5)
project(03_Quick_Union)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp UnionFind2.h UnionFind1.h UnionFindTestHelper.h)
add_executable(03_Quick_Union ${SOURCE_FILES})