//
// Created by lilelr on 10/17/18.
//

#ifndef PEPARATIONLEARNING_CHINESE_H
#define PEPARATIONLEARNING_CHINESE_H

#include <iostream>

using std::ostream;
using std::cout;
using std::cin;
using std::endl;

class Chinese {

public:
    Chinese() = delete;

    explicit Chinese(char *name, unsigned int id, int age);

    // 拷贝构造函数
    Chinese(const Chinese &c);

    // 赋值运算符
    Chinese &operator=(const Chinese &c);

    // 移动构造函数
    Chinese(Chinese &&c)noexcept;

    char *get_name();

    void set_name(const char *name);

    unsigned int get_id();

    void set_id(unsigned int id);

    int getM_age() const;

    void setM_age(int m_age);

    // 虚函数
    virtual void set_career(const char *career);

    // 输出运算重载
    friend ostream &operator<<(ostream &output, const Chinese &c) {
        cout << " Chinese  operator<< begins" << endl;

        output << c.m_id << endl;
        output << c.mp_name << endl;
        output << c.m_age << endl;
        cout << " Chinese  operator<< ends" << endl;

        return output;
    }

    int getM_er() const;

    void setM_er(int m_er);

    // 虚析构函数
    virtual ~Chinese();

protected:
    char *mp_career;
    char *mp_name;
    unsigned int m_id;

private:
    int m_age;
    int m_er;
};

#endif //PEPARATIONLEARNING_CHINESE_H
