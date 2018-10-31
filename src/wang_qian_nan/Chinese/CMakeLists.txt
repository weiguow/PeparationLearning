
cmake_minimum_required(VERSION 3.7)

project(Chinese)

set(CMAKE_CXX_STANDARD 14)


set(qiannan_chinese_main_SRC Chinese.cpp Chinese.h main.cpp)
add_executable(qiannan_chinese_main ${qiannan_chinese_main_SRC})

set(qiannan_student_main_SRC Student.cpp Student.h)
add_executable(qiannan_student_main ${qiannan_student_main_SRC})

set(qiannan_teacher_main_SRC Teacher.cpp Teacher.h)
add_executable(qiannan_teacher_main ${qiannan_teacher_main_SRC})