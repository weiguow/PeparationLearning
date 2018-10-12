#include <iostream>
#include <glog/logging.h>
int main(int argc, char **argv) {
    google::InitGoogleLogging(argv[0]);
    google::SetLogDestination(google::INFO, "/home/weiguow/project/PeparationLearning/src"
                                            "/wang_wei_guo/glogTest/log");
    LOG(INFO) << "HELLO" << "ok!";
    LOG(WARNING) << "warning test";
    return 0;
}