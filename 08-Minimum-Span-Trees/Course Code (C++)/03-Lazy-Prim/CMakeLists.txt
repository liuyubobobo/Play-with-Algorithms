cmake_minimum_required(VERSION 3.5)
project(03_Lazy_Prim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Edge.h DenseGraph.h SparseGraph.h ReadGraph.h MinHeap.h LazyPrimMST.h)
add_executable(03_Lazy_Prim ${SOURCE_FILES})