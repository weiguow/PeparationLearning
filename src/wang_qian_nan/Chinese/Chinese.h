//
// Created by wqn on 18-10-17.
//

#ifndef PEPARATIONLEARNING_CHINESE_H
#define PEPARATIONLEARNING_CHINESE_H

#include <iostream>
#include <memory>

using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
using std::make_shared;
using std::make_unique;


class Chinese
{
public:

    //构造函数
    Chinese() = delete;

    explicit Chinese(shared_ptr<char*> name, unsigned int id, int age);
    explicit Chinese(char*name,unsigned int id,int age);

    // 拷贝构造函数
    Chinese(const Chinese &c);

    // 赋值运算符
    Chinese &operator=(const Chinese &c);

    //成员函数
    char *get_name();

    void set_name(const char* name);

    unsigned int get_id();

    void set_id(unsigned int id);

    int get_age();

    void set_age(int age);


    //virtual void set_caree(const char* career);

    //输出运算符重载
    friend ostream &operator<<(ostream &output, const Chinese &c) {
        cout << " Chinese  operator<< begins" << endl;

        output << c.m_id << endl;
        output << c.mp_name << endl;
        output << c.m_age << endl;
        cout << " Chinese  operator<< ends" << endl;

        return output;
    }

   //析构函数
   ~Chinese();

protected:
    char *mp_career;
    char *mp_name;

    shared_ptr<char*> msp_career;
    shared_ptr<char*> msp_name;
    unsigned int m_id;

private:
    int m_age;
};


#endif //PEPARATIONLEARNING_CHINESE_H
