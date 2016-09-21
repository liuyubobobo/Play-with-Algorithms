cmake_minimum_required(VERSION 3.5)
project(06_Finding_a_Path)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DenseGraph.h SparseGraph.h ReadGraph.h Path.h)
add_executable(06_Finding_a_Path ${SOURCE_FILES})