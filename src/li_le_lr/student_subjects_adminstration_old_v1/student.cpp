//
// Created by lilelr on 10/17/18.
//
#include <cstring>

#include <student.h>

Student::Student(char *name, unsigned int id, int age):Chinese(name,id,age) {

}

Student::Student(char* name, unsigned int id, int age, vector<string> compulsory_subjects, vector<string> elective_subjects):Chinese(name,id,age),m_compulsory_subjects(compulsory_subjects),m_elective_subjects(elective_subjects) {

}

Student::Student(const Student &s):Chinese(s) {
    m_compulsory_subjects = s.m_compulsory_subjects;
    m_elective_subjects = s.m_elective_subjects;
}

Student::~Student() {
    m_compulsory_subjects.clear();
    m_elective_subjects.clear();
}

void Student::set_career(const char *career) {
    int temp_len = strlen(career);
    msp_career = nullptr;
    msp_career = make_shared<char*>(new char[temp_len]);
    strcpy(*msp_career, career);
}

string Student::get_career() {
    string str(*msp_career);
    return str;
}
