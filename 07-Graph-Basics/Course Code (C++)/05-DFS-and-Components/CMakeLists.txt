cmake_minimum_required(VERSION 3.5)
project(05_DFS_and_Components)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Components.h DenseGraph.h SparseGraph.h ReadGraph.h)
add_executable(05_DFS_and_Components ${SOURCE_FILES})