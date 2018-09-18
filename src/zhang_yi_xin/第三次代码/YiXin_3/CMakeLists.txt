cmake_minimum_required(VERSION 3.6)
project(YiXin_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES TemplateMethod.cpp)
add_executable(TemplateMethod ${SOURCE_FILES})