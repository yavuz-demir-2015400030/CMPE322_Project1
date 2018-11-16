cmake_minimum_required(VERSION 3.8)
project(CMPE322_Project1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Process.cpp Process.h CodeFile.cpp CodeFile.h EventSimulator.cpp EventSimulator.h)
add_executable(CMPE322_Project1 ${SOURCE_FILES})