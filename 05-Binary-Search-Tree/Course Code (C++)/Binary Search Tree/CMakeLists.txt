cmake_minimum_required(VERSION 3.5)
project(Binary_Search_Tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main_bst_remove.cpp BST.h SequenceST.h FileOps.h)
add_executable(Binary_Search_Tree ${SOURCE_FILES})