//
// Created by lilelr on 10/17/18.
//
// 系统库头文件
#include <cstdio>
#include <cstring>

// 项目头文件
#include <chinese.h>

Chinese::Chinese(shared_ptr<string> name, unsigned int id,int age):m_id(id),m_age(age) {
    cout<<"construct Chinese:Chinese"<<endl;
    msp_name = name;
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
       msp_name = make_shared<string>(string(*c.msp_name));
    }

//    if(msp_career){
//        cout<<msp_career<<endl;
//        delete msp_career;// 释放已占有的内存
//    }
    msp_career.reset();
    if(c.msp_career== nullptr){
        msp_career= nullptr;
    }else{
        msp_career = make_shared<string>(string(*c.msp_career));
//        int temp_len = strlen(*c.msp_career);
//        msp_career = make_shared<char*>(new char[temp_len]); // 重新分配内存
//        memset(msp_career.get(),0,temp_len);
//        strcpy(*msp_career,*c.msp_career);
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
        msp_name = make_shared<string>(string(*c.msp_name));
    }

//    if(msp_career){
//        cout<<msp_career<<endl;
//        delete msp_career;// 释放已占有的内存
//    }
    msp_career.reset();
    if(c.msp_career== nullptr){
        msp_career= nullptr;
    }else{
        msp_career = make_shared<string>(string(*c.msp_career));
//        int temp_len = strlen(*c.msp_career);
//        msp_career = make_shared<char*>(new char[temp_len]); // 重新分配内存
//        memset(msp_career.get(),0,temp_len);
//        strcpy(*msp_career,*c.msp_career);
    }
    cout << "Chinese assign " << endl;
    return *this;
}

//     // 移动构造函数


Chinese::Chinese(Chinese &&c)noexcept:m_age(c.m_age),m_id(c.m_id),msp_name(c.msp_name),msp_career(c.msp_career) {
    c.msp_name = nullptr;    // 挪为己用后，把c的指针指向空
    c.msp_career = nullptr;

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
void Chinese::set_career(shared_ptr<string> career) {
//    msp_career = nullptr;
}

// 析构函数，记得释放内存
Chinese::~Chinese() {
    cout << "destruct Chinese" << endl;
//    delete msp_name;
//    delete msp_career;
}

const shared_ptr<string> &Chinese::getMsp_name() const {
    return msp_name;
}

void Chinese::setMsp_name(const shared_ptr<string> &msp_name) {
    Chinese::msp_name = msp_name;
}


