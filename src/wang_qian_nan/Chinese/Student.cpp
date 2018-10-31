//
// Created by wqn on 18-10-18.
//
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>


#include "Student.h"

 Student::Student(char *name, unsigned int id, int age) {

}

 Student::Student(char *name, unsigned int id, int age, vector<string> compulsory_subjects, vector<string> elective_subjects):Chinese(name,id,age),m_compulsory_subjects(compulsory_subjects),m_elective_subjects(elective_subjects) {

}

 Student::Student(const Student &s):Chinese(s){
    this->m_elective_subjects =s.m_elective_subjects;
    this->m_compulsory_subjects =s.m_compulsory_subjects;

}
