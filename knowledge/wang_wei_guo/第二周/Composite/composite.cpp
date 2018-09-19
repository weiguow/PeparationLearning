//
// Created by wwg on 18-9-8.
//
#include "composite.h"
#include <iostream>
using namespace std;

void ConcreteCompany::attach(Company* cpn)
{
    if(nullptr != cpn)
    {
        mList.push_back(cpn);
    }
}

void ConcreteCompany::detach(Company* cpn)
{
    if(nullptr != cpn)
    {
        mList.remove(cpn);
    }
}

void ConcreteCompany::display(string str)
{
    list<Company* >::iterator beg = mList.begin();
    cout<<str<<mName<<endl;
    str = str + str;
    for ( ; beg != mList.end(); beg++)
    {
        (*beg)->display(str);
    }
}

void ConcreteCompany::LineOfDuty(string company)
{
    list<Company* >::iterator beg = mList.begin();
    string name = mName;
    for ( ; beg != mList.end(); beg++)
    {
        (*beg)->LineOfDuty(name);
    }
}

void HrDepartment::display(string str)
{
    cout<<str<<mName<<endl;
}

void HrDepartment::LineOfDuty(string company)
{
    cout<<company<<"研究生招聘培训管理！"<<endl;
}

void FinanceDepartment::display(string str)
{
    cout<<str<<mName<<endl;
}

void FinanceDepartment::LineOfDuty(string company)
{
    cout<<company<<"财务收支管理！"<<endl;
}
