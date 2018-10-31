
message(${CMAKE_SOURCE_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})
# 头文件搜索路径相当于 gcc -Isrc/li_le_lr/student_subjects_adminstration_old
include_directories(${CMAKE_SOURCE_DIR})


#include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(Chineses_SRC chinese.h chinese.cpp)
set(Teacher_SRC teacher.h teacher.cpp)
set(Student_SRC student.h student.cpp)
#set(University_class_SRC university_class.h university_class.cpp)
set(Subject_SRC subject.h subject.cpp compulsory_subject.h compulsory_subject.cpp elective_subject.h elective_subject.cpp)
set(Ch_SRC Ch.h Ch.cpp)

#add_executable(lele_student_subjects_test student_subjects_test.cpp ${Chineses_SRC} ${Teacher_SRC} ${Student_SRC} ${University_class_SRC})


add_executable(lele_student_google_test student_subjects_google_test.cpp ${Chineses_SRC} ${Teacher_SRC} ${Student_SRC} ${Subject_SRC})
target_link_libraries(lele_student_google_test gmock gtest pthread)


include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

add_subdirectory(proto)


#message(${PROJECT_BINARY_DIR})
# Define third-party include directories. Tells compiler toolchain where to get
# headers for our third party libs (e.g., -I/path/to/glog on Linux).
###############################################################################
set(LELE_INCLUDE_DIRS
        ${LELE_INCLUDE_DIRS}
        ${MESOS_PUBLIC_INCLUDE_DIR}
        # Contains (e.g.) compiled *.pb.h files.
        ${PROJECT_BINARY_DIR}/proto/
        ${PROJECT_BINARY_DIR}/my_hello/proto/
        )
message("71")
message(${PROCESS_3RDPARTY_INCLUDE_DIRS})
set(LELE_3RDPARTY_INCLUDE_DIRS
        ${LELE_3RDPARTY_INCLUDE_DIRS}
        ${PROCESS_INCLUDE_DIRS}
        ${PROCESS_3RDPARTY_INCLUDE_DIRS}
        ${LEVELDB_INCLUDE_DIR}
        )

# Define third-party lib install directories. Used to tell the compiler
# toolchain where to find our third party libs (e.g., -L/path/to/glog on
# Linux).
########################################################################
set(LELE_LIB_DIRS
        ${PROCESS_LIB_DIRS}
        )

# Define third-party libs. Used to generate flags that the linker uses to
# include our third-party libs (e.g., -lglog on Linux).
#########################################################################
# 3rdparty/libprocess/cmake/ProcessConfigure.cmake 139 ${Process_libs}
# 49 ${PROCESS_TARGET}
set(LELE_LIBS
        ${PROCESS_LIBS}
        ${PROCESS_TARGET}
        )

# INCLUDE DIRECTIVES FOR LELE EXECUTABLE (generates, e.g., -I/path/to/thing
# on Linux).
############################################################################
include_directories(SYSTEM ${LELE_3RDPARTY_INCLUDE_DIRS})
include_directories(${LELE_INCLUDE_DIRS})

# LINKING LIBRARIES BY DIRECTORY (might generate, e.g., -L/path/to/thing on
# Linux).
###########################################################################
link_directories(${LELE_LIB_DIRS})

add_subdirectory(teacher_student_actor)