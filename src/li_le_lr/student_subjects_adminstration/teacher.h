//
// Created by lilelr on 10/17/18.
//

#ifndef PEPARATIONLEARNING_TEACHER_H
#define PEPARATIONLEARNING_TEACHER_H

#include <chinese.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Teacher :public Chinese{

public:
    Teacher() = delete;
    explicit Teacher(char* name, unsigned int id, int age, vector<string> subjects);

    // 拷贝构造函数
    Teacher(const Teacher& t);
    // 移动构造函数
    Teacher(Teacher&& t);
    // 虚函数重写
    void set_career(const char *career) override;
    string get_career();
    // 虚析构函数
    virtual ~Teacher();

private:
    vector<string> m_subjects;
};


#endif //PEPARATIONLEARNING_TEACHER_H
