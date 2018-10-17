//
// Created by lilelr on 10/17/18.
//
// 系统库头文件
#include <cstdio>
#include <iostream>
#include <cstring>

// 项目头文件
#include <chinese.h>

using std::cout;
using std::cin;
using std::endl;

Chinese::Chinese(char *name, unsigned int id, int age) : m_id(id), m_age(age) {
    cout << "construct Chinese" << endl;
    int temp_len = strlen(name);
    mp_career = nullptr;
    mp_name = new char[temp_len];
    strcpy(mp_name, name);

}

Chinese::Chinese(const Chinese &c) {

    m_age = c.m_age;
    m_id = c.m_id;


//    if (mp_name){
//        delete mp_name; // 释放已占有的内存
//    }


    if (c.mp_name == nullptr) {
        mp_name = nullptr;
    } else {
        int temp_len = strlen(c.mp_name);
        mp_name = new char[temp_len]; // 重新分配内存
        strcpy(mp_name, c.mp_name);
    }

//    if(mp_career){
//        cout<<mp_career<<endl;
//        delete mp_career;// 释放已占有的内存
//    }
    if(c.mp_career== nullptr){
        mp_career= nullptr;
    }else{
        int temp_len = strlen(c.mp_career);
        mp_career = new char[temp_len]; // 重新分配内存
        memset(mp_career,0,temp_len);
        strcpy(mp_career,c.mp_career);
    }

    cout << "Chinese copy construct" << endl;

}

// 赋值运算符
Chinese& Chinese::operator=(const Chinese &c) {
    m_age = c.getM_age();
    m_id = c.m_id;

    if (c.mp_name == nullptr) {
        mp_name = nullptr;
    } else {
        int temp_len = strlen(c.mp_name);
        mp_name = new char[temp_len];
        strcpy(mp_name, c.mp_name);
    }


    if (c.mp_career == nullptr) {
        mp_career = nullptr;
    } else {
        int temp_len = strlen(c.mp_career);
        mp_career = new char[temp_len];
        strcpy(mp_career, c.mp_career);
    }

    cout << "Chinese assign " << endl;
    return *this;
}

//     // 移动构造函数
Chinese::Chinese(Chinese &&c)noexcept:m_age(c.m_age),m_id(c.m_id),mp_name(c.mp_name),mp_career(c.mp_career) {
    c.mp_name = nullptr;    // 挪为己用后，把c的指针指向空
    c.mp_career = nullptr;

}

char *Chinese::get_name() {
    return mp_name;
}

void Chinese::set_name(const char *name) {
    int temp_len = strlen(name);
    if (strlen(mp_name) > 0) {
        delete mp_name; // 先释放内存
    }
    mp_name = new char[temp_len];
    strcpy(mp_name, name);
}


unsigned int Chinese::get_id() {
    return m_id;
}

void Chinese::set_id(unsigned int id) {
    m_id = id;
}

int Chinese::getM_age() const {
    return m_age;
}

void Chinese::setM_age(int m_age) {
    Chinese::m_age = m_age;
}

// 虚函数默认实现
void Chinese::set_career(const char *career) {
    mp_career = nullptr;
}

// 析构函数，记得释放内存
Chinese::~Chinese() {
    cout << "destruct Chinese" << endl;
    delete mp_name;
    delete mp_career;
}

