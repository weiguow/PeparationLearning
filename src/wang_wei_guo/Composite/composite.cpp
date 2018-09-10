/*
 * 版权所有:深圳先进研究所异构智能计算体系结构与系统研究中心
 * 作者:王卫国
 * 编写日期:2018/9/9
 * 功能描述:组合模式实现
 */

#include "composite.h"
#include <iostream>

using namespace std;

/*
 * 函数名:attch
 * 功能描述:将树结构的下一层依附在上一层
 * 调用函数清单:
 * 输入参数说明:int num,int x
 * 返回值说明: int sum
 * 其他说明:
 */

void ConcreteCompany::attach(Company *cpn) {
    if (nullptr != cpn) {  /*如果指针不为空，将节点放到后面*/
        mList.push_back(cpn);
    }
}

void ConcreteCompany::detach(Company *cpn) {
    if (nullptr != cpn) {      /*如果指针不为空，移走该节点*/
        mList.remove(cpn);
    }
}

void ConcreteCompany::display(string str) {
    list<Company *>::iterator beg = mList.begin();  /*顺序遍历*/
    cout << str << mName << endl;
    str = str + str;
    for (; beg != mList.end(); beg++) {
        (*beg)->display(str);
    }
}

void HrDepartment::display(string str) {
    cout << str << mName << endl;
}

void FinanceDepartment::display(string str) {
    cout << str << mName << endl;
}

void ConcreteCompany::LineOfDuty(string company) {
    list<Company *>::iterator beg = mList.begin();
    string name = mName;
    for (; beg != mList.end(); beg++) {
        (*beg)->LineOfDuty(name);
    }
}

void HrDepartment::LineOfDuty(string company) {
    cout << company << "研究生招聘培训管理！" << endl;
}

void FinanceDepartment::LineOfDuty(string company) {
    cout << company << "财务收支管理！" << endl;
}
