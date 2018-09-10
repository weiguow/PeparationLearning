cmake_minimum_required(VERSION 3.12)
project(DesignPatterns_Iterator)

set(CMAKE_CXX_STANDARD 11)

add_executable(DesignPatterns_Iterator main.cpp Iterator.h Aggregate.cpp Aggregate.h Iterator.cpp)