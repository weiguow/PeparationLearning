//
// Created by lilelr on 10/22/18.
//

#include <subject.h>

namespace lele {

    Subject::Subject(const string &m_subject_name, float m_point, short m_times, const Option<string> &m_description,
                     const vector<shared_ptr<Teacher>> &mp_teachers) : m_subject_name(m_subject_name), m_point(m_point),
                                                                       m_times(m_times), m_description(m_description),
                                                                       mp_teachers(mp_teachers) {}

    Subject::~Subject() {

    }

    const string &Subject::getM_subject_name() const {
        return m_subject_name;
    }

    float Subject::getM_point() const {
        return m_point;
    }

    short Subject::getM_times() const {
        return m_times;
    }

    const Option<string> &Subject::getM_description() const {
        return m_description;
    }


    const vector<shared_ptr<Teacher>> &Subject::getMp_teachers() const {
        return mp_teachers;
    }

    void Subject::setM_point(float m_point) {
        Subject::m_point = m_point;
    }

    void Subject::setM_times(short m_times) {
        Subject::m_times = m_times;
    }

    void Subject::setM_description(const Option<string> &m_description) {
        Subject::m_description = m_description;
    }


    void Subject::setMp_teachers(const vector<shared_ptr<Teacher>> &mp_teachers) {
        Subject::mp_teachers = mp_teachers;
    }


}