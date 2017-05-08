cmake_minimum_required(VERSION 3.5)
project(07_BFS_and_Shortest_Path)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DenseGraph.h SparseGraph.h ReadGraph.h Path.h ShortestPath.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(07_BFS_and_Shortest_Path ${SOURCE_FILES})