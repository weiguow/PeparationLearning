/*
 * 作者:heldon 764165887@qq.com
 * 编写日期：18-9-13
 * 功能描述：
 */
#include <iostream>
#include <string>
#include <list>

using namespace std;

class subject;

/*
 * 类名：Observer
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-13
 * 功能描述：抽象观察者类
 * 版本：
 */
class Observer {
protected:
    string m_name;
    subject *m_subject;
public:
    Observer(string m_name, subject *m_subject) {
        this->m_name = m_name;
        this->m_subject = m_subject;
    }
    virtual void update() = 0;
};

/*
 * 类名：StockObserver
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-13
 * 功能描述：具体观察者类,股票观察者
 * 版本：
 */
class StockObserver : public Observer{
public:
    StockObserver(string m_name, subject *subject) : Observer(m_name, subject) {}
    void update();
};

/*
 * 类名：NBAObserver
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-13
 * 功能描述：具体观察者类,NBA观察者
 * 版本：
 */
class NBAObserver : public Observer{
public:
    NBAObserver(string m_name, subject *subject) : Observer(m_name, subject) {}
    void update();
};

/*
 * 类名：subject
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-13
 * 功能描述：抽象目标类
 * 版本：
 */
class subject {
protected:
    list<Observer *> m_observers;
public:
    virtual void attach(Observer *) = 0;
    virtual void detach(Observer *) = 0;
    virtual void notify() = 0;
};

/*
 * 类名：ConcreteSubject
 * 作者：heldon 764165887@qq.com
 * 编写日期：18-9-13
 * 功能描述：具体目标类：秘书
 * 版本：
 */
class Secretary : public subject {
    /*
     * 函数名：attach
     * 作者：heldon 764165887@qq.com
     * 编写日期：18-9-13
     * 输入参数：Observer *observer
     * 返回值：无
     * 功能描述：添加一个观察者
     */
    void attach(Observer *observer){
        m_observers.push_back(observer);
    }

    /*
     * 函数名：detach
     * 作者：heldon 764165887@qq.com
     * 编写日期：18-9-13
     * 输入参数：Observer *observer
     * 返回值：无
     * 功能描述：删除一个观察者
     */
    void detach(Observer *observer){
        m_observers.remove(observer);
    }

    /*
     * 函数名：notify
     * 作者：heldon 764165887@qq.com
     * 编写日期：18-9-13
     * 输入参数：Observer *observer
     * 返回值：无
     * 功能描述：遍历观察者,每个观察者执行update()函数。
     */
    void notify(){
        list<Observer *> :: iterator it = m_observers.begin();
        while(it != m_observers.end()){
            (*it)->update();
            ++it;
        }
    }
};

void StockObserver ::update() {
    cout<<m_name<<"收到消息"<<endl;
}

void NBAObserver ::update() {
    cout<<m_name<<"收到消息"<<endl;
}

int main(){
    subject *secretary = new Secretary();
    Observer *wangweiguo = new NBAObserver("王卫国",secretary);
    Observer *makun = new NBAObserver("马坤",secretary);
    Observer *zhanghongtai = new StockObserver("张鸿泰",secretary);

    secretary->attach(wangweiguo);
    secretary->attach(makun);
    secretary->attach(zhanghongtai);

    secretary->notify();
    cout<<endl;

    secretary->detach(wangweiguo);
    secretary->notify();

    return 0;
}