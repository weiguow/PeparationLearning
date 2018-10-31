add_executable(lele-thread-1 thread-1.cpp)
target_link_libraries(lele-thread-1 pthread)

add_executable(lele-future_promise_begin future_promise_begin.cpp)
target_link_libraries(lele-future_promise_begin pthread)

add_executable(lele-future_promise_async future_promise_asnc.cpp)
target_link_libraries(lele-future_promise_async pthread)

add_executable(lele-packaged_task packaged_task.cpp)
target_link_libraries(lele-packaged_task pthread)

add_executable(lele-condition_value condition_value.cpp)
target_link_libraries(lele-condition_value pthread)
#
#
#add_executable(lele-thread-join thread_join.cpp)
#target_link_libraries(lele-thread-join pthread)