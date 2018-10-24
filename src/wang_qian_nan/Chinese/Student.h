//
// Created by wqn on 18-10-18.


#ifndef PEPARATIONLEARNING_STUDENT_H
#define PEPARATIONLEARNING_STUDENT_H

#include <string>
#include <vector>

#include "Chinese.h"

using std::vector;
using std::string;

class Student :public Chinese{

public:
    explicit Student(char *name, unsigned int id, int age);

    explicit Student(char *name, unsigned int id, int age, vector<string> compulsory_subjects, vector<string> m_elective_subjects);
    //拷贝构造函数
    Student(const Student& s);
    //虚函数重写

private:

    vector<string> m_compulsory_subjects;
    vector<string> m_elective_subjects;

};

#endif //PEPARATIONLEARNING_STUDENT_H