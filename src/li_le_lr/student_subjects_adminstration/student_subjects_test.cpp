//
// Created by lilelr on 10/17/18.
//
#include <cstdio>
#include <iostream>
#include <cstring>

#include <chinese.h>
#include <teacher.h>

using std::cout;
using std::cin;
using std::endl;

int main(){

    char my_name[]="xiao_ming";
    unsigned int my_id=1;
    int age = 24;
    Chinese xiao_ming(my_name, my_id,age);
    char* xiao_ming_name = xiao_ming.get_name();
    cout<<xiao_ming_name<<endl;

    char* new_name="xiao_ming_dong";
    xiao_ming.set_name(new_name);
    cout<<xiao_ming.get_name()<<endl;
    cout<<xiao_ming.get_id()<<endl;
    xiao_ming.set_id(667);
    cout<<xiao_ming.get_id()<<endl;
    cout<<xiao_ming<<endl;

    // 拷贝构造函数测试
    cout<<"拷贝构造函数测试"<<endl;
    Chinese xiao_ming_copy(xiao_ming);
    cout<<xiao_ming_copy<<endl;
//    Chinese xiao_ming_assign = xiao_ming_copy;
//    cout<<xiao_ming_assign<<endl;

    cout<<"-----------------"<<endl;
    char t_name[]="teacher_li";
    unsigned int t_id=2;
    int t_age = 24;
    vector<string> t_subjects;
    t_subjects.push_back("Math");
    t_subjects.push_back("Chemistry");
    Teacher teacher_li(t_name,t_id,t_age,t_subjects);
    char* t_career="I am a teacher\n";

    //测试 虚函数
    teacher_li.set_career(t_career);
    cout<<"teacher_li's career:"<<teacher_li.get_career()<<endl;

    //测试拷贝构造
    Teacher teacher_li_copy(teacher_li);
    // 测试 赋值运算符
    Teacher teacher_li_assign = teacher_li;

    cout<<"-------------------"<<endl;

    return 0;
}