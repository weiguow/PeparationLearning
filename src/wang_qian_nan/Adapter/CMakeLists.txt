cmake_minimum_required(VERSION 3.12)
project(Adapter)

set(CMAKE_CXX_STANDARD 11)

add_executable(Adapter ClassAdapter.cpp ObjectAdapter.cpp Method.cpp)