//
// Created by wwg on 18-9-8.
//

#ifndef COMPOSITE_COMPOSITE_H
#define COMPOSITE_COMPOSITE_H

#include <list>
using std::list;

#include <string>
using std::string;

class Company
{
public:
    Company(char* name):mName(name){}
    virtual void attach(Company* cpn){}
    virtual void detach(Company* cpn){}
    virtual void display(string str){}

    virtual void LineOfDuty(string company){}

protected:
    char *mName;
    list<Company*> mList;
};

class ConcreteCompany:public Company{
public:
    ConcreteCompany(char* name):Company(name){}
    virtual void attach(Company* cpn);
    virtual void detach(Company* cpn);
    virtual void display(string str);
    virtual void LineOfDuty(string company);
};

class HrDepartment:public Company{
public:
    HrDepartment(char* name):Company(name){}
    virtual void display(string str);
    virtual void LineOfDuty(string company);
};

class FinanceDepartment:public Company{
public:
    FinanceDepartment(char* name):Company(name){}
    virtual void display(string str);
    virtual void LineOfDuty(string company);
};


#endif //COMPOSITE_COMPOSITE_H
