/*
 * 版权所有:深圳先进研究所异构智能计算体系结构与系统研究中心
 * 作者:王卫国
 * 编写日期:2018/9/14
 * 功能描述:描述主要实现的功能
 */
#include "StateMode.h"

void ConcreteStateA::Handle(Context *context)
{
    context->m_pState = new ConcreteStateB;
    cout << "当前状态是A,下一个状态是B" <<endl;
}

void ConcreteStateB::Handle(Context *context)
{
    context->m_pState = new ConcreteStateC;
    cout << "当前状态是B,下一个状态是C" <<endl;
}

void ConcreteStateC::Handle(Context *context)
{
    context->m_pState = new ConcreteStateA;
    cout << "当前状态是C,下一个状态是A" <<endl;
}

void ConcreteStateA::GetState()
{
    cout << "当前状态是A" <<endl;
}

void ConcreteStateB::GetState()
{
    cout << "当前状态是C" <<endl;
}

void ConcreteStateC::GetState()
{
    cout << "当前状态是C" <<endl;
}

