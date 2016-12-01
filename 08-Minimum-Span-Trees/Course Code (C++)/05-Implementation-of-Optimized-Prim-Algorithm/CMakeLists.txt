cmake_minimum_required(VERSION 3.5)
project(05_Implementation_of_Optimized_Prim_Algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main_performance.cpp Edge.h DenseGraph.h SparseGraph.h MinHeap.h IndexMinHeap.h LazyPrimMST.h PrimMST.h ReadGraph.h)
add_executable(05_Implementation_of_Optimized_Prim_Algorithm ${SOURCE_FILES})