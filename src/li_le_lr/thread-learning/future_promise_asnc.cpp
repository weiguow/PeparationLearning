//
// Created by lilelr on 10/28/18.
//

#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using std::cout;
using std::cin;
using std::endl;
using std::thread;
using std::promise;
using std::future;
using std::string;
using namespace std::chrono;

string fetch_data_from_db(string recv_data){
    std::this_thread::sleep_for(seconds(5));

    return "DB_"+recv_data;
}

string fetch_data_from_file(string recv_data){
    std::this_thread::sleep_for(seconds(5));
    return "File_"+recv_data;
}

void initiazer(promise<int>* prom_obj){
    cout<<"Inside thread "<<endl;
    prom_obj->set_value(34);
}

struct  DataFetcher{
    string operator()(string recv_data){
        std::this_thread::sleep_for(seconds(5));
        return "File_"+recv_data;
    }
};


std::future<std::string> resultFromDB = std::async([](std::string recvdData) {

    std::this_thread::sleep_for(seconds(5));
    //处理创建数据库连接、获取数据等事情
    return "DB_" + recvdData;

}, "Data");

int main(){
//    promise<int> promise_obj;
//    future<int> future_obj = promise_obj.get_future();
//    thread th(initiazer, &promise_obj);
//    cout<<future_obj.get()<<endl;
//    th.join();
    system_clock::time_point start = system_clock::now();

//    std::string db_data = fetch_data_from_db("Data");
    future<string>  result_from_db = std::async(std::launch::async,fetch_data_from_db,"Data");


//    std::string file_data = fetch_data_from_file("Data");
    future<string> result_from_file = std::async(DataFetcher(),"Data");
    std::string file_data = result_from_file.get();
    string db_data = result_from_db.get();

    auto end = system_clock::now();
    auto diff = duration_cast<std::chrono::seconds> (end-start).count();
    cout<<"Total time taken ="<<diff<<"seconds"<<endl;

    string data = db_data + ":: "+file_data;
    cout<<"Data = "<< data<<endl;

    return 0;
}