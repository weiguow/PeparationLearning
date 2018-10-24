//
// Created by lilelr on 10/17/18.
//
// 系统库头文件
#include <cstdio>
#include <cstring>

// 项目头文件
#include <chinese.h>


Chinese::Chinese(shared_ptr<char*> name, unsigned int id, int age) : m_id(id), m_age(age) {
    cout << "construct Chinese with shared_ptr" << endl;
    msp_career = nullptr;
    msp_name = name; // 共享指针+1
}

Chinese::Chinese(char* name, unsigned int id, int age) : m_id(id), m_age(age) {
    cout << "construct Chinese with shared_ptr" << endl;
    int temp_len = strlen(name);
    msp_career = nullptr;
    msp_name = make_shared<char*>(new char[temp_len]);
    strcpy(*msp_name, name);

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

// 赋值运算符
Chinese& Chinese::operator=(const Chinese &c) {
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

    cout << "Chinese assign " << endl;
    return *this;
}

//     // 移动构造函数

//Chinese::Chinese(Chinese &&c) {
//
//}
//Chinese::Chinese(Chinese &&c)noexcept:m_age(c.m_age),m_id(c.m_id),msp_name(c.msp_name),msp_career(c.msp_career) {
//    c.msp_name = nullptr;    // 挪为己用后，把c的指针指向空
//    c.msp_career = nullptr;
//
//}

shared_ptr<char*> Chinese::get_name() {
    return msp_name;
}

void Chinese::set_name(shared_ptr<char*> name) {
//    int temp_len = strlen(name);
//    if (strlen(msp_name) > 0) {
//        delete msp_name; // 先释放内存
//    }
//    msp_name = new char[temp_len];
//    strcpy(msp_name, name);
    msp_name = name;
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
//    msp_career = nullptr;
}

// 析构函数，记得释放内存
Chinese::~Chinese() {
    cout << "destruct Chinese" << endl;
//    delete msp_name;
//    delete msp_career;
}

int Chinese::getM_er() const {
    return m_er;
}

void Chinese::setM_er(int m_er) {
    Chinese::m_er = m_er;
}

