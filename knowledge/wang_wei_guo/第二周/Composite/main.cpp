#include <iostream>
#include "composite.h"
using namespace std;

int main()
{
    //
    ConcreteCompany com1("中国科学院");
    FinanceDepartment com2("中国科学院天津计算技术研究所");
    HrDepartment com3("中国科学院北京计算所");

    com1.attach(&com2);
    com1.attach(&com3);

    ConcreteCompany com11("中国科学院深圳先进院");
    FinanceDepartment com22("数字所异构智能能中心");
    HrDepartment com33("数字所云计算中心");

    com11.attach(&com22);
    com11.attach(&com33);

    com1.attach(&com11);

    string str("─");
    com1.display(str);

    cout<<endl;

    com1.LineOfDuty(str);
}