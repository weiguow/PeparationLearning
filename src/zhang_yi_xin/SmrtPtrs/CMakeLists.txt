cmake_minimum_required(VERSION 3.6)
project(SmrtPtrs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(SmrtPtrs ${SOURCE_FILES})


set(SOURCE_FILES_1 fowl.cpp)
add_executable(fowl ${SOURCE_FILES_1})

set(SOURCE_FILES_2 fowl_01.cpp)
add_executable(fowl01 ${SOURCE_FILES_2})