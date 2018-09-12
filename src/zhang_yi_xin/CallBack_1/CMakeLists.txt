cmake_minimum_required(VERSION 3.6)
project(CallBack_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(CallBack_1 ${SOURCE_FILES})

set(SOURCE_FILES_1 main_1.cpp)
add_executable(CallBack_2 ${SOURCE_FILES_1})

set(SOURCE_FILES_2 main_2.cpp)
add_executable(CallBack_3 ${SOURCE_FILES_2})