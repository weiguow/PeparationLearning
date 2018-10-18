//
// Created by lilelr on 10/17/18.
//
#include <cstdio>
#include <iostream>
#include <cstring>

#include <chinese.h>
#include <teacher.h>
#include <student.h>
#include <university_class.h>

using std::cout;
using std::cin;
using std::endl;
using std::make_unique;

int main(){



    char my_name[]="xiao_ming";
    unsigned int my_id=1;
    int age = 24;
    Chinese xiao_ming(my_name, my_id,age);
    // 堆上分配内存
//    Chinese* xiao_p = new Chinese(my_name,my_id,age);
//    delete xiao_p;
    cout<<"使用智能指针"<<endl;
    unique_ptr<Chinese> xiao_unique_p = make_unique<Chinese>(Chinese(my_name,my_id,age));
    cout<<*xiao_unique_p<<endl;
    char *zhang_name = "zhanghongtai";
    shared_ptr<char*> zhanghongtai_name = make_shared<char*>(zhang_name);
    unique_ptr<Chinese> zhang_p = make_unique<Chinese>(Chinese(zhanghongtai_name,my_id,age));
    cout<<*zhanghongtai_name<<endl;
    cout<<"使用智能指针结束"<<endl;

    cout<<xiao_ming<<endl;
    shared_ptr<char*> xiao_ming_name = xiao_ming.get_name();
    cout<<*xiao_ming_name<<endl;

//
    // 拷贝构造函数测试
    cout<<"拷贝构造函数测试"<<endl;
    Chinese xiao_ming_copy(xiao_ming);
    cout<<xiao_ming_copy<<endl;
    Chinese xiao_ming_assign = xiao_ming_copy;
    cout<<xiao_ming_assign<<endl;
//
    cout<<"-----------------"<<endl;
    char t_name[]="teacher_li";
    unsigned int t_id=2;
    int t_age = 24;
    vector<string> t_subjects;
    t_subjects.push_back("Math");
    t_subjects.push_back("Chemistry");
//    Teacher teacher_li(t_name,t_id,t_age,t_subjects);
    shared_ptr<Teacher> teacher_li = make_shared<Teacher>(Teacher(t_name,t_id,t_age,t_subjects));
    char* t_career="I am a teacher\n";
//
    //多态测试， 用智能指针 测试虚函数
    cout<<"测试 虚函数和多态"<<endl;
    teacher_li->set_career(t_career);
//    Chinese* duo_t = &teacher_li;
//    duo_t->set_career("I am a duo_t");

    shared_ptr<Chinese> duo_t = teacher_li;
    duo_t->set_career("I am a duo_t");
//    cout<<duo_t->ge
    cout<<"teacher_li's career:"<<teacher_li->get_career()<<endl;
//
//    //测试拷贝构造
//    Teacher teacher_li_copy(teacher_li);
//    // 测试 赋值运算符
//    Teacher teacher_li_assign = teacher_li;
//    // 测试输出运算符重载
//    cout<<teacher_li_assign<<endl;
//
//    cout<<"-------------------"<<endl;
//
//
//    cout<<"#######################"<<endl;
//
//    vector<string> xiao_comp_subjects;
//    xiao_comp_subjects.push_back("English");
//    xiao_comp_subjects.push_back("Computer");
//    vector<string> xiao_ele_subjects;
//    xiao_ele_subjects.push_back("basketball");
//    xiao_ele_subjects.push_back("swimming");
//    Student xiao_student(xiao_ming.get_name(),xiao_ming.get_id(),xiao_ming.getM_age(),xiao_comp_subjects,xiao_ele_subjects);
//    char* xiao_career = "I am a student";
//    xiao_student.set_career(xiao_career);
//    cout<<xiao_student<<endl;
//    cout<<xiao_student.get_career()<<endl;
//
//    Student wang_student = xiao_student;
//    char* wang_name = "wangweiguo";
//    wang_student.set_name(wang_name);
//    cout<<wang_student<<endl;
//    cout<<"#######################"<<endl;
//
//
//    cout<<"班级测试"<<endl;
//    UniversityClass freshman_class;
//    freshman_class.m_teacher = shared_ptr<Teacher>(&teacher_li);
//    freshman_class.m_class_id = 12;
//    freshman_class.m_description = "大一新班";
//    unordered_set<unique_ptr<Student>> current_students;
//    unique_ptr<Student> wang_student_p = unique_ptr<Student>(&wang_student);
//    cout<<*wang_student_p<<endl;

//    current_students.insert(wang_student_p);
//    auto xiao_student_p = unique_ptr<Student>(xiao_student);
//    current_students.insert(xiao_student_p);
//    for(auto it=current_students.begin();it!=current_students.end();it++){
//        cout<<*it<<endl;
//    }

//    auto comp_subjects = xiao_comp_subjects;
//    auto ele_subjects = xiao_ele_subjects;
//    Student* other_student = new Student("makun",2,23,comp_subjects,ele_subjects);
//    shared_ptr<Student> other_s_student = shared_ptr<Student>(other_student);
//    cout<<*other_s_student<<endl;
//    other_s_student->set_career("I am a university student");
//    cout<<other_student->get_career()<<endl;
//
//    delete xiao_p;
//    delete duo_t;
    return 0;
}