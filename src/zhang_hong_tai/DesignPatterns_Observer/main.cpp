/*
 * 作者：张鸿泰 764165887@qq.com
 * 编写日期：18-9-13
 * 功能描述：主函数
 */
#include <iostream>
#include <list>

using namespace std;

/*
 * 类名：Observer
 * 作者：张鸿泰 764165887@qq.com
 * 编写日期：18-9-13
 * 功能描述：观察者类的接口
 */
class Observer{
public:
    virtual void update(int) = 0;
};

/*
 * 类名：subject
 * 作者：张鸿泰 764165887@qq.com
 * 编写日期：18-9-13
 * 功能描述：目标类的接口
 */
class subject {
public:
    virtual void attach(Observer *) = 0;
    virtual void detach(Observer *) = 0;
    virtual void notify() = 0;
};

class ConcreteObserver1 : public Observer{
public:
    ConcreteObserver1(subject *subject) : m_subject(subject) {}
    void update(int value){
        cout<<"ConcreteObserver1 get the update, the new update is :"<<value<<endl;
    }
private:
    subject *m_subject;
};

class ConcreteObserver2 : public Observer{
public:
    ConcreteObserver2(subject *subject) : m_subject(subject) {}
    void update(int value){
        cout<<"ConcreteObserver2 get the update, the new update is :"<<value<<endl;
    }
private:
    subject *m_subject;
};

class ConcreteSubject : public subject {
public:
    void attach(Observer *observer);
    void detach(Observer *observer);
    void notify();

    void set_state(int state){
        m_state = state;
    };
private:
    list<Observer *> m_observer_list;
    int m_state;
};

void ConcreteSubject :: attach(Observer *observer) {
    m_observer_list.push_back(observer);
}

void ConcreteSubject :: detach(Observer *observer) {
    m_observer_list.remove(observer);
}

void ConcreteSubject :: notify() {
    list<Observer *>::iterator it = m_observer_list.begin();
    while (it != m_observer_list.end()){
        (*it)->update(m_state);
        ++it;
    }
}

int main() {
    ConcreteSubject *subject = new ConcreteSubject();

    ConcreteObserver1 *observer1 = new ConcreteObserver1(subject);
    ConcreteObserver2 *observer2 = new ConcreteObserver2(subject);

    subject->set_state(2);
    subject->attach(observer1);
    subject->attach(observer2);
    subject->notify();

    subject->detach(observer1);
    subject->set_state(3);
    subject->notify();

    delete subject;
    delete observer1;
    delete observer2;
    return 0;
}