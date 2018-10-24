//
// Created by lilelr on 10/19/18.
//
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#ifndef PEPARATIONLEARNING_HEADER2_H
#define PEPARATIONLEARNING_HEADER2_H
namespace header2_namespace{
    namespace inside_header2{
        int inside=4;
    }
    void distinct(){
        cout<<"header2"<<endl;
    }
    int value = 8;
}

namespace header2_namespace{
    void abc(){
        cout<<"abc"<<endl;
    }
}

//    void distinct(){
//        cout<<"header2"<<endl;
//    }
//    int value = 8;






#endif //PEPARATIONLEARNING_HEADER2_H
