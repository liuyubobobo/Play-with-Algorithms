cmake_minimum_required(VERSION 3.5)
project(ShortestPath)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main_bell.cpp Edge.h DenseGraph.h SparseGraph.h ReadGraph.h IndexMinHeap.h Dijkstra.h BellmanFord.h)
add_executable(ShortestPath ${SOURCE_FILES})