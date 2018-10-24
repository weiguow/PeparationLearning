//
// Created by lilelr on 10/22/18.
//

#ifndef PEPARATIONLEARNING_ELECTIVE_SUBJECT_H
#define PEPARATIONLEARNING_ELECTIVE_SUBJECT_H

#include <subject.h>

namespace lele {
    class ElectiveSubject : public Subject {
    public:
        ElectiveSubject(const string &m_subject_name, float m_point, short m_times, const Option<string> &m_description,
                        const vector<shared_ptr<Teacher>> &mp_teachers);
    };
}


#endif //PEPARATIONLEARNING_ELECTIVE_SUBJECT_H
