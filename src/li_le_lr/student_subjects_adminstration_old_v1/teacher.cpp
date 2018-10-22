//
// Created by lilelr on 10/17/18.
//
#include <cstring>

#include <teacher.h>


Teacher::Teacher(char *name, unsigned int id, int age, vector<string> subjects):Chinese(name,id,age),m_subjects(subjects){
    cout<<"Teacher construct"<<endl;
}

// 拷贝构造函数，初始化列表里面调用父类的构造函数
Teacher::Teacher(const Teacher &t):Chinese(t) {
   cout<<"Teacher copy construct"<<endl;

    m_subjects = t.m_subjects;
}

// 移动构造函数，初始化列表里面调用父类的移动构造函数
Teacher::Teacher(Teacher&& t):Chinese(t),m_subjects(t.m_subjects){
}

void Teacher::set_career(const char *career) {
//    Chinese::set_career(career);
    int temp_len = strlen(career);
    msp_career = nullptr;
    msp_career = make_shared<char*>(new char[temp_len]);
    strcpy(*msp_career, career);
}

string Teacher::get_career(){
    cout<<*msp_career<<endl;
    string str(*msp_career);
    return str;
}

Teacher::~Teacher() {
//    delete msp_career;
    cout<<"Teacher destruct"<<endl;
}
