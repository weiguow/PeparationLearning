cmake_minimum_required(VERSION 3.12)
project(Buy)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Buy
        CMakeLists.txt
        Facade.h
        main.cpp
        StockA.h
        StockB.h
        StockC.h)
