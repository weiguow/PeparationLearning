
message(${CMAKE_SOURCE_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})
# 头文件搜索路径相当于 gcc -Isrc/li_le_lr/student_subjects_adminstration
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(Chineses_SRC chinese.h chinese.cpp)
set(Teacher_SRC teacher.h teacher.cpp)
set(Ch_SRC Ch.h Ch.cpp)

add_executable(lele_student_subjects_test student_subjects_test.cpp ${Chineses_SRC} ${Teacher_SRC})
