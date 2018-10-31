#include <iostream>
#include <thread>
#include <future>
#include <string>

//从DB获取数据
std::string getDataFromDB(std::string token) {
    //获取数据
    std::string data = "Data fetched from DB by Filter :: " + token;
    return data;
}

int main() {
    //创建封装回调函数的packaged_task<>
    std::packaged_task<std::string(std::string)> task(getDataFromDB);

    //从packaged_task<>获取相关的future<>
    std::future<std::string> result = task.get_future();

    //将packaged_task传递给线程以异步运行
    std::thread th(std::move(task), "Arg");

    //join线程，阻塞直到线程完成时返回
    th.join();

    //获取packaged_task<>的结果，即getDataFromDB()的返回值
    std::string data = result.get();

    std::cout << data << std::endl;

    return 0;
}
