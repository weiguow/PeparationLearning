// Created by wqn on 18-10-17.
//
//系统头文件
#include <stdio.h>
#include <iostream>
#include <cstring>

//项目头文件
#include "Chinese.h"

using std::cout;
using std::cin;
using std::endl;

Chinese::Chinese(char *name, unsigned int id, int age):m_id(id),m_age(age)
{
    cout << "construct Chinese with shared_ptr" << endl;
    int temp_len = strlen(name);
    mp_career = nullptr;
    mp_name = new char[temp_len];
    strcpy(mp_name,name);

}

Chinese::Chinese(shared_ptr<char*> name, unsigned int id, int age) : m_id(id), m_age(age) {
    cout << "construct Chinese with shared_ptr" << endl;
    msp_career = nullptr;
    msp_name = name; // 共享指针+1
}

Chinese::Chinese(const Chinese &c) {

    m_age = c.m_age;
    m_id = c.m_id;

//    if (msp_name){
//        delete msp_name; // 释放已占有的内存
//    }
    msp_name.reset(); // 释放msp——name 所指向的对象，引用计数减1
    if (c.msp_name == nullptr) {
        msp_name = nullptr;
    } else {
        int temp_len = strlen(*c.msp_name);
        msp_name = make_shared<char*>(new char[temp_len]); // 重新分配内存
        strcpy(*msp_name, *c.msp_name);
    }

//    if(msp_career){
//        cout<<msp_career<<endl;
//        delete msp_career;// 释放已占有的内存
//    }
    msp_career.reset();
    if(c.msp_career== nullptr){
        msp_career= nullptr;
    }else{
        int temp_len = strlen(*c.msp_career);
        msp_career = make_shared<char*>(new char[temp_len]); // 重新分配内存
        memset(msp_career.get(),0,temp_len);
        strcpy(*msp_career,*c.msp_career);
    }

    cout << "Chinese copy construct" << endl;

}

//// 虚函数默认实现
//void Chinese::set_caree(const char *career) {
////    msp_career = nullptr;
//}

// 析构函数，记得释放内存
Chinese::~Chinese() {
    cout << "destruct Chinese" << endl;
//    delete msp_name;
//    delete msp_career;
}





//get_name

char* Chinese::get_name() {

    return this->mp_name;

}

//set_name

void Chinese::set_name(const char *name) {

    mp_name = new char[strlen(name)+1];
    strcpy(mp_name,name);

}


//get_id

unsigned int Chinese::get_id() {

    return m_id;
}



void Chinese::set_id(unsigned int id) {

    this->m_id = id;
}


//get_age

int Chinese::get_age() {

    return m_age;

}

//set_age

void Chinese::set_age(int age) {
    this->m_age = age;

}
