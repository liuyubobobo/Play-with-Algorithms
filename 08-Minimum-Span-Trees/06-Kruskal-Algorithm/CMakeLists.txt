cmake_minimum_required(VERSION 3.5)
project(06_Kruskal_Algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main_performance.cpp Edge.h DenseGraph.h SparseGraph.h MinHeap.h ReadGraph.h LazyPrimMST.h IndexMinHeap.h PrimMST.h UF.h KruskalMST.h)
add_executable(06_Kruskal_Algorithm ${SOURCE_FILES})