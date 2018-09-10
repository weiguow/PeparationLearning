/*
 *作者:heldon
 *编写日期：18-9-7
 *功能描述：容器的接口
 */
#ifndef DESIGNPATTERNS_ITERATOR_AGGREGATE_H
#define DESIGNPATTERNS_ITERATOR_AGGREGATE_H

#include <vector>
#include <string>
#include <iostream>

class Iterator;
using namespace std;
typedef std::string object;

/*
 *类名：Aggregate
 *作者：heldon
 *编写日期：18-9-7
 *功能描述：容器的抽象类
 *版本：1.0
 */
class Aggregate {
public:
    virtual Iterator* create_iterator() = 0;
    virtual vector<string>* get_vector() = 0;
};

/*
 *类名：ConcreteAggregate
 *作者：heldon
 *编写日期：18-9-7
 *功能描述：容器的具体类
 *版本：1.0
 */
class ConcreteAggregate : public Aggregate{
private:
    vector<string> *items;
public:
    ConcreteAggregate();
    ~ConcreteAggregate();  /*析构函数*/

    Iterator* create_iterator();
    vector<string>* get_vector();

    int count();
    string get_elements(int index);
    void  set_elements(int index,string name);
};

#endif //DESIGNPATTERNS_ITERATOR_AGGREGATE_H
