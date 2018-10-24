//
// Created by lilelr on 10/17/18.
//
#include <cstdio>
#include <iostream>
#include <cstring>

//#include <gmock/gmock.h>
#include <gtest/gtest.h>
//#include <stout/gtest.hpp>

#include <chinese.h>
#include <teacher.h>
#include <student.h>
#include <subject.h>
#include <compulsory_subject.h>
#include <elective_subject.h>

using std::cout;
using std::cin;
using std::endl;
using std::make_unique;
using std::unique_ptr;;

using namespace lele;


TEST(ChineseTest, ChineseClass) {
    shared_ptr<string> my_name = make_shared<string>(string("xiao_ming"));
//    string my_name("xiao_ming");
    unsigned int my_id = 1;
    int age = 24;
    Chinese xiao_ming(my_name, my_id, age);
    // 堆上分配内存
//    Chinese* xiao_p = new Chinese(my_name,my_id,age);
//    delete xiao_p;
    cout << "使用智能指针" << endl;
    unique_ptr<Chinese> xiao_unique_p = make_unique<Chinese>(Chinese(my_name, my_id, age));
    cout << *xiao_unique_p << endl;
//    EXPECT_EQ(my_name,*xiao_unique_p->get_name());
    EXPECT_EQ(*my_name, *xiao_unique_p->getMsp_name());
}

TEST(TeacherTest, TeacherClass) {
    shared_ptr<string> t_name = make_shared<string>(string("teacher_li"));
    unsigned int t_id = 2;
    int t_age = 24;
    vector<string> t_subjects;
    t_subjects.push_back("Math");
    t_subjects.push_back("Chemistry");
    Teacher teacher_li(t_name, t_id, t_age, t_subjects);
    auto t_career = make_shared<string>(string("I am a teacher\n"));

    //测试 虚函数
    teacher_li.set_career(t_career);
    EXPECT_EQ("teacher_li", *teacher_li.getMsp_name());
    EXPECT_EQ("I am a teacher\n", teacher_li.get_career());

    //测试拷贝构造
    Teacher teacher_li_copy(teacher_li);
    // 测试 赋值运算符
    Teacher teacher_li_assign = teacher_li;
    // 测试输出运算符重载
    cout << teacher_li_assign << endl;

    cout << "-------------------" << endl;

}

TEST(StudentTest, StudentClass) {

    cout << "#######################" << endl;

    vector<string> xiao_comp_subjects;
    xiao_comp_subjects.push_back("English");
    xiao_comp_subjects.push_back("Computer");
    vector<string> xiao_ele_subjects;
    xiao_ele_subjects.push_back("basketball");
    xiao_ele_subjects.push_back("swimming");
    auto xiao_ming_name = make_shared<string>(string("xiaoming"));
    Student xiao_student(xiao_ming_name, 33, 25, xiao_comp_subjects, xiao_ele_subjects);
    auto xiao_career = make_shared<string>(string("I am a student\n"));
    xiao_student.set_career(xiao_career);
    cout << xiao_student << endl;
    EXPECT_EQ("I am a student\n", xiao_student.get_career());
    cout << xiao_student.get_career() << endl;

    Student wang_student = xiao_student;
    auto wang_name = make_shared<string>(string("wangweiguo"));
    wang_student.setMsp_name(wang_name);
    EXPECT_EQ("wangweiguo", *wang_student.getMsp_name());
    cout << wang_student << endl;
    cout << "#######################" << endl;

}

TEST(CallbackTest, call_back_test) {
    shared_ptr<string> t_name = make_shared<string>(string("teacher_li"));
    unsigned int t_id = 2;
    int t_age = 24;
    vector<string> t_subjects;
    t_subjects.push_back("Math");
    t_subjects.push_back("Chemistry");
    auto teacher_li = make_shared<Teacher>(Teacher(t_name, t_id, t_age, t_subjects));

    vector<string> xiao_comp_subjects;
    xiao_comp_subjects.push_back("English");
    xiao_comp_subjects.push_back("Computer");
    vector<string> xiao_ele_subjects;
    xiao_ele_subjects.push_back("basketball");
    xiao_ele_subjects.push_back("swimming");
    auto xiao_ming_name = make_shared<string>(string("xiaoming"));
    Student xiao_student(xiao_ming_name, 33, 25, xiao_comp_subjects, xiao_ele_subjects);
    xiao_student.setMsp_head(teacher_li);

    xiao_student.print_student_and_head_relationship();
}

TEST(SubjectTest, subject_test) {
//    shared_ptr<Subject> english = make_shared<Subject>(Subject());

    shared_ptr<string> t_name = make_shared<string>(string("teacher_li"));
    unsigned int t_id = 2;
    int t_age = 24;
    vector<string> t_subjects;
    t_subjects.push_back("Math");
    t_subjects.push_back("English");
    auto teacher_li = make_shared<Teacher>(Teacher(t_name, t_id, t_age, t_subjects));
    vector<shared_ptr<Teacher>> teachers_v;
    teachers_v.push_back(teacher_li);
    shared_ptr<CompulsorySubject> english_c = make_shared<CompulsorySubject>(
            CompulsorySubject("English", 3.0, 36, "Introduction to american literature", teachers_v));
    EXPECT_EQ("English", english_c->getM_subject_name());
    EXPECT_EQ(3.0, english_c->getM_point());
    EXPECT_TRUE(english_c->getM_description().isSome());
    EXPECT_EQ("Introduction to american literature", english_c->getM_description().get());

    shared_ptr<CompulsorySubject> math_c = make_shared<CompulsorySubject>(
            CompulsorySubject("math", 4.0, 40, "高数", teachers_v));

    vector<shared_ptr<Subject>> li_subjects_v;
    li_subjects_v.push_back(english_c);
    li_subjects_v.push_back(math_c);
    Option<vector<shared_ptr<Subject>>> li_subjects_v_o = Some(li_subjects_v);
    teacher_li->setMsp_subjects(li_subjects_v_o);
    EXPECT_EQ(2, li_subjects_v_o.get().size());


}

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();

//
//    cout<<"班级测试"<<endl;
////    UniversityClass freshman_class;
////    freshman_class.m_teacher = shared_ptr<Teacher>(&teacher_li);
////    freshman_class.m_class_id = 12;
////    freshman_class.m_description = "大一新班";
////    unordered_set<unique_ptr<Student>> current_students;
////    unique_ptr<Student> wang_student_p = unique_ptr<Student>(&wang_student);
////    cout<<*wang_student_p<<endl;
//
////    current_students.insert(wang_student_p);
////    auto xiao_student_p = unique_ptr<Student>(xiao_student);
////    current_students.insert(xiao_student_p);
////    for(auto it=current_students.begin();it!=current_students.end();it++){
////        cout<<*it<<endl;
////    }
//
//    auto comp_subjects = xiao_comp_subjects;
//    auto ele_subjects = xiao_ele_subjects;
//    Student* other_student = new Student("makun",2,23,comp_subjects,ele_subjects);
//    shared_ptr<Student> other_s_student = shared_ptr<Student>(other_student);
//    cout<<*other_s_student<<endl;
//    other_s_student->set_career("I am a university student");
//    cout<<other_student->get_career()<<endl;
//    return 0;
}