cmake_minimum_required(VERSION 3.5)
project(02_Graph_Representation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DenseGraph.h SparseGraph.h)
add_executable(02_Graph_Representation ${SOURCE_FILES})