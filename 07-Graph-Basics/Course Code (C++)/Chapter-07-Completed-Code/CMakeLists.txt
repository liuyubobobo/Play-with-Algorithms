cmake_minimum_required(VERSION 3.5)
project(Graph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main_path.cpp DenseGraph.h SparseGraph.h Component.h Path.h ShortestPath.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(Graph ${SOURCE_FILES})