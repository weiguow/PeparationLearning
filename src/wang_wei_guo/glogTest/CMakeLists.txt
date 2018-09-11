cmake_minimum_required(VERSION 3.5)
project(glogTest)

set(CMAKE_CXX_STANDARD 11)

set(LINKER_LIBS "")

include("cmake/FindGlog.cmake")

include_directories(SYSTEM ${GLOG_INCLUDE_DIRS})

list(APPEND LINKER_LIBS ${GLOG_LIBRARIES})

add_executable(glogTest main.cpp)

target_link_libraries(glogTest ${LINKER_LIBS})



