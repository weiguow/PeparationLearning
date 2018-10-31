cmake_minimum_required(VERSION 3.5)
project(CommandAndChain)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(ResponsibilityOfChain ${SOURCE_FILES})

set(SOURCE_FILES_1 Command.cpp)
add_executable(Command ${SOURCE_FILES_1})

set(SOURCE_FILES_2 Command_1.cpp Command_1.cpp)
add_executable(Command_1 ${SOURCE_FILES_2})