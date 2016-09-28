cmake_minimum_required(VERSION 3.5)
project(05_Implementation_of_Bellman_Ford)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Edge.h DenseGraph.h SparseGraph.h ReadGraph.h BellmanFord.h)
add_executable(05_Implementation_of_Bellman_Ford ${SOURCE_FILES})