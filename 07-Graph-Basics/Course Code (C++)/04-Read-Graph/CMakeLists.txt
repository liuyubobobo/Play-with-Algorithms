cmake_minimum_required(VERSION 3.5)
project(04_Read_Graph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DenseGraph.h SparseGraph.h ReadGraph.h)
add_executable(04_Read_Graph ${SOURCE_FILES})