cmake_minimum_required(VERSION 3.12)
project(Test)

set(CMAKE_CXX_STANDARD 11)


add_subdirectory(./googletest)



include_directories(./googletest/include)


link_directories(./googletest)

add_executable(Test main.cpp)
set(LIBRARIES
        test
        pthread)

#[[set(SOURCE_FILES main.cpp)]]



target_link_libraries(Test ${LIBRARIES})