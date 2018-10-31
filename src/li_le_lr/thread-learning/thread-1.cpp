//#include <iostream>
//#include <thread>
//
//void thread_function() {
//    for (int i = 0; i < 100; i++)
//        std::cout << "thread function excuting" << std::endl;
//}
//
//int main() {
//    std::thread threadObj(thread_function);
//    for (int i = 0; i < 100; i++)
//        std::cout << "Display from MainThread" << std::endl;
//    threadObj.join();
//    std::cout << "Exit of Main function" << std::endl;
//    return 0;
//}


#include <iostream>
#include <thread>

void thread_function() {
    std::cout << "inside thread :: ID = " << std::this_thread::get_id() << std::endl;
}

int main() {
    std::thread threadObj1(thread_function);
    std::thread threadObj2(thread_function);

    if (threadObj1.get_id() != threadObj2.get_id()) {
        std::cout << "Both Threads have different IDs" << std::endl;
    }
    std::cout << "From Main Thread :: ID of Thread 1 = " << threadObj1.get_id() << std::endl;
    std::cout << "From Main Thread :: ID of Thread 2 = " << threadObj2.get_id() << std::endl;

    threadObj1.join();
    threadObj2.join();

    return 0;
}

