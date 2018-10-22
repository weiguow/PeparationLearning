//
// Created by lilelr on 10/19/18.
//
#include <iostream>
#include <header1.h>
#include <header2.h>
using std::cout;
using std::cin;
using std::endl;
using header1_namespace::value;
using header2_namespace::inside_header2::inside;

//using namespace header1_namespace;
//using namespace header2_namespace;

int main(){
    std::cout<<value<<std::endl;
//    distinct();
    header1_namespace::distinct();
    header2_namespace::distinct();
    header2_namespace::abc();
    cout<<inside<<endl;
    return 0;
}