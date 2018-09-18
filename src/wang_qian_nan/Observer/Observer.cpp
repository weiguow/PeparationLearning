/*
 * 作者:王倩楠
 * 编写日期:2018/9/11
 * 联系方式：sherlock_vip@163.com
 * 功能描述:定义对象间的一种一对多关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新。
 *        当一个对象发生了变化，关注它的对象就会得到通知;
 */

#include <iostream>
#include <list>
using namespace std;

/*
 * 类名:Observer
 * 编写日期:18-9-11
 * 功能描述:为那些在目标发生改变时需获得通知的对象定义一个更新接口
 */

class Observer
{
public:
    virtual void Update(int) = 0;
};

/*
 * 类名:Subject
 * 编写日期:18-9-11
 * 功能描述:提供注册和删除观察者对象的接口
 */

class Subject
{
public:
    virtual void Attach(Observer *) = 0;
    virtual void Detach(Observer *) = 0;
    virtual void Notify() = 0;
};

/*
 * 类名:ConcreteObserver
 * 编写日期:18-9-11
 * 功能描述:实现Observer的更新接口以使自身状态与目标的状态保持一致
 */

class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(Subject *pSubject) : m_pSubject(pSubject){}

    void Update(int value)
    {
        cout << "ConcreteObserver get the update. New State:" << value << endl;
    }

private:
    Subject *m_pSubject;
};

/*
 * 类名:ConcreteObserver2
 * 编写日期:18-9-11
 * 功能描述:实现Observer的更新接口以使自身状态与目标的状态保持一致
 */

class ConcreteObserver2 : public Observer
{
public:
    ConcreteObserver2(Subject *pSubject) : m_pSubject(pSubject){}

    void Update(int value)
    {
        cout << "ConcreteObserver2 get the update. New State:" << value << endl;
    }

private:
    Subject *m_pSubject;
};

/*
 * 类名:ConcreteSubject
 * 编写日期:18-9-11
 * 功能描述:当它的状态发生改变时，向它的各个观察者发出通知
 */
class ConcreteSubject : public Subject
{
public:
    void Attach(Observer *pObserver);
    void Detach(Observer *pObserver);
    void Notify();

    void SetState(int state)
    {
        m_iState = state;
    }

private:
    std::list<Observer *> m_ObserverList;
    int m_iState;
};

void ConcreteSubject::Attach(Observer *pObserver)
{
    m_ObserverList.push_back(pObserver);
}

void ConcreteSubject::Detach(Observer *pObserver)
{
    m_ObserverList.remove(pObserver);
}

void ConcreteSubject::Notify()
{
    std::list<Observer *>::iterator it = m_ObserverList.begin();
    while (it != m_ObserverList.end())
    {
        (*it)->Update(m_iState);
        ++it;
    }
}


int main()
{
    // Create Subject
    ConcreteSubject *pSubject = new ConcreteSubject();

    // Create Observer
    Observer *pObserver = new ConcreteObserver(pSubject);
    Observer *pObserver2 = new ConcreteObserver2(pSubject);

    // Change the state
    pSubject->SetState(2);

    // Register the observer
    pSubject->Attach(pObserver);
    pSubject->Attach(pObserver2);

    pSubject->Notify();

    // Unregister the observer
    pSubject->Detach(pObserver);

    pSubject->SetState(3);
    pSubject->Notify();

    delete pObserver;
    delete pObserver2;
    delete pSubject;
}