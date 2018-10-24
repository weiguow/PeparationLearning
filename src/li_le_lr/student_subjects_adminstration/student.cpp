//
// Created by lilelr on 10/17/18.
//
#include <cstring>

#include <student.h>

namespace lele {
    Student::Student(shared_ptr<string> name, unsigned int id, int age) : Chinese(name, id, age) {

    }

    Student::Student(shared_ptr<string> name, unsigned int id, int age, vector<string> compulsory_subjects,
                     vector<string> elective_subjects) : Chinese(name, id, age),
                                                         m_compulsory_subjects(compulsory_subjects),
                                                         m_elective_subjects(elective_subjects) {

    }

    Student::Student(const Student &s) : Chinese(s) {
        m_compulsory_subjects = s.m_compulsory_subjects;
        m_elective_subjects = s.m_elective_subjects;
    }

    Student::~Student() {
        m_compulsory_subjects.clear();
        m_elective_subjects.clear();
    }

    void Student::set_career(shared_ptr<string> career) {
        msp_career = career;
    }

    string Student::get_career() {
        return *msp_career;
    }

    const shared_ptr<Teacher> &Student::getMsp_head() const {
        return msp_head;
    }

    void Student::setMsp_head(const shared_ptr<Teacher> &msp_head) {
        Student::msp_head = msp_head;
    }
}