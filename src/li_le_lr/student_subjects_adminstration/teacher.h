//
// Created by lilelr on 10/17/18.
//

#ifndef PEPARATIONLEARNING_TEACHER_H
#define PEPARATIONLEARNING_TEACHER_H

#include <vector>
#include <string>

#include <stout/option.hpp>

#include <chinese.h>
#include <subject.h>

using std::string;
using std::vector;
using std::function;
using namespace std::placeholders;

namespace lele {
    class Subject;
//函数对象容器定义
    typedef function<void(string &, string &)> Fun;

class Teacher : public Chinese{

public:
    Teacher() = delete;

    explicit Teacher(shared_ptr<string> name, unsigned int id, int age, vector<string> subjects);

    // 拷贝构造函数
    Teacher(const Teacher& t);

    // 移动构造函数
    Teacher(Teacher&& t);

    // 虚函数重写
    void set_career(const shared_ptr<string> career) override;

    // 与student 之间的回调函数
    void call(string &a, Fun f) {
        f(*this->getMsp_name(), a);
    }

    const Option<vector<shared_ptr<Subject>>> &getMsp_subjects() const;

    void setMsp_subjects(const Option<vector<shared_ptr<Subject>>> &msp_subjects);

    string get_career();

    // 虚析构函数
    virtual ~Teacher();

private:
    vector<string> m_subjects;
    Option<vector<shared_ptr<Subject>>> msp_subjects;
};


}

#endif //PEPARATIONLEARNING_TEACHER_H
