cmake_minimum_required(VERSION 3.5)
project(Graph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main_path.cpp DenseGraph.h SparseGraph.h RandomGraph.h Component.h Path.h ShortestPath.h)
add_executable(Graph ${SOURCE_FILES})