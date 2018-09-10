/*
 *作者:heldon
 *编写日期：18-9-7
 *功能描述：迭代器的接口
 */

#ifndef DESIGNPATTERNS_ITERATOR_ITERATOR_H
#define DESIGNPATTERNS_ITERATOR_ITERATOR_H

#include <vector>
#include <iostream>
#include "Aggregate.h"  /*容器的接口*/

using namespace std;

/*
 * 类名：Iterartor
 * 作者：heldon
 * 编写日期：18-9-7
 * 功能描述：迭代器的抽象类
 */
class Iterator{
public:
    virtual string first() = 0;
    virtual string next() = 0;
    virtual string current_item() = 0;
    virtual bool is_done() = 0;
};

/*
 * 类名：ConcreteIterartor
 * 作者：heldon
 * 编写日期：18-9-7
 * 功能描述：具体迭代器的类,继承迭代器的抽象类
 */
class ConcreteIterator : public Iterator{
private:
    ConcreteAggregate* aggregate;
    int current;
public:
    ConcreteIterator(Aggregate* aggregate);
    string first();
    string next();
    string current_item();
    bool is_done();
};

#endif //DESIGNPATTERNS_ITERATOR_ITERATOR_H
