//
// Created by lilelr on 10/17/18.
//

#ifndef PEPARATIONLEARNING_STUDENT_H
#define PEPARATIONLEARNING_STUDENT_H

#include <vector>
#include <string>

#include <chinese.h>
#include <teacher.h>

using std::string;
using std::vector;
using std::function;
using namespace std::placeholders;

namespace lele {
//函数对象容器定义
    typedef function<void(string &, string &)> Fun;

    class Student : public Chinese{

    public:
        explicit Student(shared_ptr<string> name, unsigned int id, int age);

        explicit Student(shared_ptr<string> name, unsigned int id, int age, vector<string> compulsory_subjects, vector<string> elective_subjects);

        Student(const Student& s);

        const shared_ptr<Teacher> &getMsp_head() const;

        void setMsp_head(const shared_ptr<Teacher> &msp_head);

        string get_career();

        // 虚函数重写
        void set_career(const shared_ptr<string> career) override;

        // 回调函数
        void print_callback(string &t, string &s) {
            cout << s << " is a student of teacher " << t << endl;
        }

        void print_student_and_head_relationship() {
            Fun fun = std::bind(&Student::print_callback, this, _1, _2);
            msp_head->call(*this->getMsp_name(), fun);
        }

        virtual ~Student();
protected:

    private:
        shared_ptr<Teacher> msp_head;
        vector<string> m_compulsory_subjects;
        vector<string> m_elective_subjects;

    };
}


#endif //PEPARATIONLEARNING_STUDENT_H
