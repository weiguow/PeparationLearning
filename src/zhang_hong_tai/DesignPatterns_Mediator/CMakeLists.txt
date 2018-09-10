cmake_minimum_required(VERSION 3.12)
project(DesignPatterns_Mediator)

set(CMAKE_CXX_STANDARD 11)

add_executable(DesignPatterns_Mediator main.cpp Mediator.cpp Mediator.h Colleague.cpp Colleague.h)