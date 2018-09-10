/*
 *作者:heldon
 *编写日期：18-9-7
 *功能描述：
 */

#include "Aggregate.h"
#include "Iterator.h"

ConcreteAggregate::ConcreteAggregate() {
    items = new std::vector<string>;
}

/*
 * 函数名：~ConcreteAggregate
 * 编写日期：18-9-8
 * 作者：heldon
 * 输入参数：无
 * 返回值：无
 * 功能描述：析构函数,当程序结束时清空调用空间
 */
ConcreteAggregate::~ConcreteAggregate() {
    delete items;
}

/*
 * 函数名：create_iterator
 * 编写日期：18-9-8
 * 作者：heldon
 * 输入参数：无
 * 返回值：指定的迭代器
 * 功能描述：创建一个正向遍历迭代器
 */
Iterator* ConcreteAggregate::create_iterator() {
    Iterator* iterator = new ConcreteIterator(this);
    return iterator;
}

/*
 * 函数名：count
 * 编写日期：18-9-8
 * 作者：heldon
 * 输入参数：无
 * 返回值：items->size()
 */
int ConcreteAggregate::count() {
    return items->size();
}

/*
 * 函数名：get_vector
 * 编写日期：18-9-8
 * 作者：heldon
 * 输入参数：无
 * 返回值：item
 */
vector<string>* ConcreteAggregate::get_vector() {
    return  items;
}

/*
 * 函数名：get_elements
 * 编写日期：18-9-8
 * 作者：heldon
 * 输入参数：int index
 * 返回值：item->at(index)
 * 功能描述：返回指定容器
 */
string ConcreteAggregate::get_elements(int index) {
    return items->at(index);
}

/*
 * 函数名：set_elements
 * 编写日期：18-9-8
 * 作者：heldon
 * 输入参数：int index,string name
 * 返回值：无
 * 功能描述：为容器输入内容(名字)
 */
void ConcreteAggregate::set_elements(int index, string name) {
    items->at(index) = name;
}