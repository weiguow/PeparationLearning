


add_subdirectory(./googletest)



include_directories(./googletest/include)


link_directories(./googletest)

add_executable(Test main.cpp)
set(LIBRARIES
        test
        pthread)

#[[set(SOURCE_FILES main.cpp)]]



target_link_libraries(Test ${LIBRARIES})