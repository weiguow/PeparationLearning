//
// Created by lilelr on 10/17/18.
//

#ifndef PEPARATIONLEARNING_STUDENT_H
#define PEPARATIONLEARNING_STUDENT_H

#include <vector>
#include <string>

#include <chinese.h>

using std::string;
using std::vector;

class Student :public Chinese{

public:
    explicit Student(char* name, unsigned int id, int age);

    explicit Student(char* name, unsigned int id, int age, vector<string> compulsory_subjects, vector<string> elective_subjects);

    Student(const Student& s);

    string get_career();
    // 虚函数重写
    void set_career(const char *career) override;

    virtual ~Student();
protected:

private:
    vector<string> m_compulsory_subjects;
    vector<string> m_elective_subjects;

};


#endif //PEPARATIONLEARNING_STUDENT_H
