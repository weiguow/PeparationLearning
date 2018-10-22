//
// Created by lilelr on 10/22/18.
//

#ifndef PEPARATIONLEARNING_SUBJECT_H
#define PEPARATIONLEARNING_SUBJECT_H

#include <vector>
#include <string>
#include <memory>

#include <stout/option.hpp>

#include <teacher.h>


using std::string;
using std::vector;
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;

namespace lele {
    class Teacher; // 前向声明
    class Subject {

    private:
        string m_subject_name; // 课程名
        float m_point; //  学分
        short m_times; //  学时

        Option<string> m_description; // 课程描述

//        bool m_complusory; // 是否必修

        // 老师集合
        vector<shared_ptr<Teacher>> mp_teachers;

    protected:
        Subject(const string &m_subject_name, float m_point, short m_times, const Option<string> &m_description,
                const vector<shared_ptr<Teacher>> &mp_teachers);

    public:
        Subject() = delete;


        const string &getM_subject_name() const;

        float getM_point() const;

        short getM_times() const;

        const Option<string> &getM_description() const;

        const vector<shared_ptr<Teacher>> &getMp_teachers() const;

        void setM_point(float m_point);

        void setM_times(short m_times);

        void setM_description(const Option<string> &m_description);


        void setMp_teachers(const vector<shared_ptr<Teacher>> &mp_teachers);

        virtual ~Subject();

    };
}


#endif //PEPARATIONLEARNING_SUBJECT_H
