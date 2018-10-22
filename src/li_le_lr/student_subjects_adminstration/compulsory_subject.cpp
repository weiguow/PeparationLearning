//
// Created by lilelr on 10/22/18.
//

#include <compulsory_subject.h>

lele::CompulsorySubject::CompulsorySubject(const string &m_subject_name, float m_point, short m_times,
                                           const Option<string> &m_description,
                                           const vector<shared_ptr<lele::Teacher>> &mp_teachers) : Subject(
        m_subject_name, m_point, m_times, m_description, mp_teachers) {}
