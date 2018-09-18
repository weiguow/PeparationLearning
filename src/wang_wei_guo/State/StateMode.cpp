/*
 * ��Ȩ����:�����Ƚ��о����칹���ܼ�����ϵ�ṹ��ϵͳ�о�����
 * ����:������
 * ��д����:2018/9/14
 * ��������:������Ҫʵ�ֵĹ���
 */
#include "StateMode.h"

void ConcreteStateA::Handle(Context *context)
{
    context->m_pState = new ConcreteStateB;
    cout << "��ǰ״̬��A,��һ��״̬��B" <<endl;
}

void ConcreteStateB::Handle(Context *context)
{
    context->m_pState = new ConcreteStateC;
    cout << "��ǰ״̬��B,��һ��״̬��C" <<endl;
}

void ConcreteStateC::Handle(Context *context)
{
    context->m_pState = new ConcreteStateA;
    cout << "��ǰ״̬��C,��һ��״̬��A" <<endl;
}

void ConcreteStateA::GetState()
{
    cout << "��ǰ״̬��A" <<endl;
}

void ConcreteStateB::GetState()
{
    cout << "��ǰ״̬��C" <<endl;
}

void ConcreteStateC::GetState()
{
    cout << "��ǰ״̬��C" <<endl;
}

