cmake_minimum_required(VERSION 3.5)
project(Chapter_09_Completed_Code)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main_bellmanford.cpp Edge.h DenseGraph.h SparseGraph.h ReadGraph.h IndexMinHeap.h Dijkstra.h BellmanFord.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(Chapter_09_Completed_Code ${SOURCE_FILES})