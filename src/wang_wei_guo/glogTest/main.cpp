#include <iostream>
#include <glog/logging.h>
int main(int argc, char **argv) {
    google::InitGoogleLogging(argv[0]);
    google::SetLogDestination(google::INFO, "./Log");
    LOG(INFO) << "HELLO" << "ok!";
    LOG(WARNING) << "warning test";
    return 0;
}