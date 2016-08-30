cmake_minimum_required(VERSION 3.5)
project(10_The_Disadvantages_of_Binary_Search_Tree_and_More_Trees)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp FileOps.h SequenceST.h BST.h)
add_executable(10_The_Disadvantages_of_Binary_Search_Tree_and_More_Trees ${SOURCE_FILES})