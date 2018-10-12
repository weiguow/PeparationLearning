
set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED)
if(NOT Boost_FOUND)
    message("Not found Boost")
endif()

include_directories(${Boost_INCLUDE_DIRS})
message("${Boost_INCLUDE_DIRS}")
message("${Boost_LIBRARIES}")


set(lele_asio_main_SRC asio.cpp)
add_executable(lele_asio_main ${lele_asio_main_SRC})

target_link_libraries(lele_asio_main boost_system boost_chrono pthread)


set(lele_client1_main_SRC client1.cpp)
add_executable(lele_client1_main ${lele_client1_main_SRC})

target_link_libraries(lele_client1_main boost_chrono boost_system pthread)

set(lele_server1_main_SRC server1.cpp)
add_executable(lele_server1_main ${lele_server1_main_SRC})

target_link_libraries(lele_server1_main boost_chrono boost_system pthread)