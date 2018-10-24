//
// Created by wqn on 18-10-22.
//
#include <cstring>
#include <iostream>

#include "Teacher.h"

using std::cout;
using std::endl;


Teacher::Teacher(char *name, unsigned int id, int age, vector<string> subjects):Chinese(name,id,age),m_subjects(subjects){
    cout<<"Teacher construct"<<endl;
}

//拷贝构造函数
Teacher::Teacher(const Teacher &t) :Chinese(t){
    cout<<"Teacher copy construct"<<endl;

    m_subjects =t.m_subjects;
}