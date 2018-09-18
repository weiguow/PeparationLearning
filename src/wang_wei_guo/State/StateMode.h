/*
 * 版权所有:深圳先进研究所异构智能计算体系结构与系统研究中心
 * 作者:王卫国
 * 编写日期:2018/9/6
 * 功能描述:状态类的管理以及三个状态类的声明
 */
#ifndef STATE_STATEMODE_H
#define STATE_STATEMODE_H
#include <iostream>
using namespace std;
class Context;

/*
 * 类名State*/
class State{
public:
    virtual void Handle(Context *context) = 0;
    virtual void GetState() = 0;
};

/*
 * 类名：Context状态管理类
 * 作者：王卫国
 * 编写日期：2018.9.14
 * 功能描述：对状态进行管理*/
class Context{
public:
    Context(State *state)  /*初始化状态*/
    {
        m_pState=state;
    }
    State* GetState()  /*获得当前的状态*/
    {
        return m_pState;
    }
    void SetState(State *state)  /*改变当前的状态*/
    {
        m_pState = state;
    }
    void Request()  /*执行状态类实现的方法*/
    {
        m_pState->Handle(this);
    }
    State* m_pState;
};

/*
 * 类名：具体的状态子类A
 * 作者：王卫国
 * 编写日期：2018.9.14
 * 功能描述：具体的状态子类A*/
class ConcreteStateA:public State
{
public:
    void Handle(Context *context);
    void GetState();
};

/*
 * 类名：具体的状态子类B
 * 作者：王卫国
 * 编写日期：2018.9.14
 * 功能描述：具体的状态子类B
 * */
class ConcreteStateB:public State
{
public:
    void Handle(Context *context);
    void GetState();
};

/*
 * 类名：具体的状态子类C
 * 作者：王卫国
 * 编写日期：2018.9.14
 * 功能描述：具体的状态子类C
 * */
class ConcreteStateC:public State
{
public:
    void Handle(Context *context);
    void GetState();
};


#endif //STATE_STATEMODE_H
