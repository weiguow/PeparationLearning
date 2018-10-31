//系统头文件
#include <cstdio>
#include <iostream>
#include <cstring>

//项目头文件
#include "Chinese.h"
#include "Teacher.h"
#include "Student.h"

using std::cout;
using std::cin;
using std::endl;



int main ()
{
    char my_name[]="WangQianNan";
    unsigned int my_id=5;
    int age = 24;

    Chinese qian_nan(my_name,my_id,age);
    cout<<"qiannan Name:";

    // 堆上分配内存
    Chinese* xiao_p = new Chinese(my_name,my_id,age);
    delete xiao_p;

    //使用智能指针
    cout<<"使用智能指针"<<endl;
    unique_ptr<Chinese>qian_nan_p = make_unique<Chinese>(Chinese(my_name,my_id,age));

    cout<<qian_nan.get_name()<<endl;
    qian_nan.set_name(my_name);

    cout<<"qiannan ID:";
    cout<<qian_nan.get_id()<<endl;
    qian_nan.set_id(my_id);

    cout<<"qiannan age:";
    cout<<qian_nan.get_age()<<endl;
    qian_nan.set_age(age);



    //测试拷贝构造
    Chinese chinese_xiao_copy(qian_nan);
    // 测试 赋值运算符
    Chinese chinese_xiao_assign = qian_nan;

    char t_name[]="teacher_li";
    unsigned int t_id=2;
    int t_age = 24;
//
//    vector<string> t_subjects;
//    t_subjects.push_back({"Math","Chemistry"});
//    Teacher teacher_li(t_name,t_id,t_age,t_subjects);
//    char* t_career="teacher";
//    //测试 虚函数
//    teacher_li.set_career(t_career);
//
//    //测试拷贝构造
//    Teacher teacher_li_copy(teacher_li);
//    // 测试 赋值运算符
//    Teacher teacher_li_assign = teacher_li;




    return 0;
}
