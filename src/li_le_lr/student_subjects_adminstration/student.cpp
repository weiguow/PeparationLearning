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
    mp_career = nullptr;
    mp_career = new char[temp_len];
    strcpy(mp_career, career);
}

string Student::get_career() {
    string str(mp_career);
    return str;
}
