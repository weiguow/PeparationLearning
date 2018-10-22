
message(${CMAKE_SOURCE_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})
# 头文件搜索路径相当于 gcc -Isrc/li_le_lr/student_subjects_adminstration_old
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(Chineses_SRC chinese.h chinese.cpp)
set(Teacher_SRC teacher.h teacher.cpp)
set(Student_SRC student.h student.cpp)
#set(University_class_SRC university_class.h university_class.cpp)
set(Subject_SRC subject.h subject.cpp compulsory_subject.h compulsory_subject.cpp elective_subject.h elective_subject.cpp)
set(Ch_SRC Ch.h Ch.cpp)
#
#add_executable(lele_student_subjects_test student_subjects_test.cpp ${Chineses_SRC} ${Teacher_SRC} ${Student_SRC} ${University_class_SRC})


add_executable(lele_student_google_test student_subjects_google_test.cpp ${Chineses_SRC} ${Teacher_SRC} ${Student_SRC} ${Subject_SRC})
target_link_libraries(lele_student_google_test gmock gtest pthread)