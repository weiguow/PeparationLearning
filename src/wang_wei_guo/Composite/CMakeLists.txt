cmake_minimum_required(VERSION 3.12)
project(Composite)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Composite
        CMakeLists.txt
        composite.cpp
        composite.h
        main.cpp)
