/*
 * 版权所有:深圳先进研究所异构智能计算体系结构与系统研究中心
 * 作者:王卫国
 * 编写日期:2018/9/16
 * 功能描述:组合模式和命令模式实现
 */

#include "composite.h"
#include <iostream>

using namespace std;

/*
 * 函数名:attch
 * 功能描述:将树结构的下一层依附在上一层
 * 调用函数清单:str
 * 输入参数说明:
 * 返回值说明:
 * 其他说明:
 */
void ConcreteCommandA::attach(Command *cpn) {
    if (nullptr != cpn) {  /*如果指针不为空，将节点放到后面*/
        mList.push_back(cpn);
    }
}

/*
 * 函数名:detach
 * 功能描述:将树结构的下一层删除
 * 调用函数清单:
 * 输入参数说明:
 * 返回值说明:
 * 其他说明:
 */
void ConcreteCommandA::detach(Command *cpn) {
    if (nullptr != cpn) {      /*如果指针不为空，移走该节点*/
        mList.remove(cpn);
    }
}

/*
 * 函数名:display
 * 功能描述:将树结构的下一层依附在上一层
 * 调用函数清单:
 * 输入参数说明:str
 * 返回值说明:
 * 其他说明:
 */
void ConcreteCommandA::display(string str) {
    list<Command *>::iterator beg = mList.begin();  /*顺序遍历*/
    cout << str << mName << endl;
    str = str + str;
    for (; beg != mList.end(); beg++) {
        (*beg)->display(str);
    }
}

void ConcreteCommandB::display(string str) {
    cout << str << mName << endl;
}

void ConcreteCommandB::attach(Command *cpn) {
    if (nullptr != cpn) {  /*如果指针不为空，将节点放到后面*/
        mList.push_back(cpn);
    }
}

void ConcreteCommandC::display(string str) {
    cout << str << mName << endl;
}

void ConcreteCommandC::detach(Command *cpn) {
    if (nullptr != cpn) {      /*如果指针不为空，移走该节点*/
        mList.remove(cpn);
    }
}







