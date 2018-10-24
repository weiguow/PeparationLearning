/*
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：代理模式
 */
#include <iostream>

using namespace std;

/*
 * 类名：subject
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：Subject类、抽象角色
 */
class subject {
public:
    virtual void function() {
        cout << "subject" << endl;
    }
};

/*
 * 类名：RealSubject
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：RealSubject类、真实角色
 */
class RealSubject : public subject {
public:
    virtual void function() {
        cout << "Hello World!" << endl;
    }
};

/*
 * 类名：Proxy
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：Proxy类、代理角色
 */
class Proxy : public subject {
    RealSubject m_real;
public:
    virtual void function() {
        cout << "I am Proxy ,RealSubject let me tell you something :" << endl;
        m_real.function();
    }
};

int main() {
    Proxy proxy;
    proxy.function();
    return 0;
}
