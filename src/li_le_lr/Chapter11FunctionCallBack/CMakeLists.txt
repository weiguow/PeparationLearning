
set(CMAKE_CXX_STANDARD 11)

set(BIND_SOURCE_FILES bind.cpp)
add_executable(lele_bind_main ${BIND_SOURCE_FILES})

set(function_call_SRC function_call.cpp)
add_executable(lele_function_call ${function_call_SRC})

set(ref_usage_SRC ref_usage.cpp)
add_executable(lele_ref_usage ${ref_usage_SRC})