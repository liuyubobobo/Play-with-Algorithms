cmake_minimum_required(VERSION 3.5)
project(02_Selection_Sort_Using_Template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Student.h)
add_executable(02_Selection_Sort_Using_Template ${SOURCE_FILES})