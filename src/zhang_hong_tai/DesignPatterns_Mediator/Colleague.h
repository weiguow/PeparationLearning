/*
 * 作者:heldon
 * 编写日期：18-9-9
 * 功能描述：
 */
#ifndef DESIGNPATTERNS_MEDIATOR_COLLEAGUE_H
#define DESIGNPATTERNS_MEDIATOR_COLLEAGUE_H

#include <iostream>

using namespace std;

class Mediator;

/*
 * 类名：Colleague
 * 作者：heldon
 * 编写日期：18-9-9
 * 功能描述：
 * 版本：
 */
class Colleague {
public:
    Colleague(Mediator *mediator):mediator(mediator){}
protected:
    Mediator *mediator;
};

class WWG:public Colleague{
public:
    WWG(Mediator *mediator) : Colleague(mediator){}

    void chat(string message);
    void send_message(string message);
};

class MK:public Colleague{
public:
    MK(Mediator *mediator) : Colleague(mediator){}

    void chat(string message);
    void send_message(string message);
};

#endif //DESIGNPATTERNS_MEDIATOR_COLLEAGUE_H
