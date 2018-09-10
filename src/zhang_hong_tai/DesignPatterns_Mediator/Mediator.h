/*
 * 作者:heldon
 * 编写日期：18-9-9
 * 功能描述：
 */
#ifndef DESIGNPATTERNS_MEDIATOR_MEDIATOR_H
#define DESIGNPATTERNS_MEDIATOR_MEDIATOR_H

#include <string>
#include "Colleague.h"

using namespace std;

class Colleague;

/*
 * 类名：Mediator
 * 作者：heldon
 * 编写日期：18-9-9
 * 功能描述：中介者的抽象类
 * 版本：1.0
 */
class Mediator {
public:
    virtual void chat(string message,Colleague *colleague) = 0;
};

/*
 * 类名：ConcreteMediator
 * 作者：heldon
 * 编写日期：18-9-9
 * 功能描述：中介者的具体类
 */
class ConcreteMediator:public Mediator{
public:
    void chat(string message,Colleague *colleague);
    void Colleague1(WWG *val);
    void Colleague2(MK *val);

private:
    WWG *colleague1;
    MK *colleague2;
};
#endif //DESIGNPATTERNS_MEDIATOR_MEDIATOR_H
