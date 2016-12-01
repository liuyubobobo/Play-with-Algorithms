cmake_minimum_required(VERSION 3.5)
project(01_Weighted_Graph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Edge.h DenseGraph.h SparseGraph.h ReadGraph.h)
add_executable(01_Weighted_Graph ${SOURCE_FILES})