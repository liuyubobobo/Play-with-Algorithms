cmake_minimum_required(VERSION 3.5)
project(MinimumSpanTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main_mst_performance.cpp SparseGraph.h DenseGraph.h ReadGraph.h LazyPrimMST.h Edge.h MinHeap.h PrimMST.h IndexMinHeap.h KruskalMST.h UF.h)
add_executable(MinimumSpanTree ${SOURCE_FILES})