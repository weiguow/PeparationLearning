//
// Created by wqn on 18-10-22.
//

#ifndef PEPARATIONLEARNING_TEACHER_H
#define PEPARATIONLEARNING_TEACHER_H

#include <vector>
#include <string>

#include "Chinese.h"

using std::string;
using std::vector;

class Teacher:public Chinese{
    
public:
    Teacher()= delete;
    explicit Teacher(char *name, unsigned int id, int age, vector<string>subjects);
    
    //拷贝构造函数
    Teacher(const Teacher& t);

    // 虚析构函数
    virtual ~Teacher();

private:
    vector<string> m_subjects;
    
};

#endif //PEPARATIONLEARNING_TEACHER_H
