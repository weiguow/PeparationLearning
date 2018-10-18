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
    mp_career = nullptr;
    mp_career = new char[temp_len];
    strcpy(mp_career, career);
}

string Teacher::get_career(){
    cout<<mp_career<<endl;
    string str(mp_career);
    return str;
}

Teacher::~Teacher() {
//    delete mp_career;
    cout<<"Teacher destruct"<<endl;
}
