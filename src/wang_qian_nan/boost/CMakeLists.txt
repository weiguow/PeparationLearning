
set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED)
if(NOT Boost_FOUND)
    message("Not found Boost")
endif()

include_directories(${Boost_INCLUDE_DIRS})
message("${Boost_INCLUDE_DIRS}")
message("${Boost_LIBRARIES}")
message("hello")

set(qiannan_lexical_cast_SRC lexical_cast.cpp std.hpp)
add_executable(qiannan_lexical_cast_main ${qiannan_lexical_cast_SRC})

target_link_libraries(qiannan_lexical_cast_main)


set(qiannan_asio_SRC  asio.cpp)
add_executable(qiannan_asio_main ${qiannan_asio_SRC})

target_link_libraries(qiannan_asio_main boost_system boost_chrono pthread)


