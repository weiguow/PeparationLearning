
set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED)
if(NOT Boost_FOUND)
    message("Not found Boost")
endif()




set(reload_learning_SRC reload_learning.cpp)
add_executable(lele_reload_learning_main ${reload_learning_SRC})

#target_link_libraries(reload_learning)