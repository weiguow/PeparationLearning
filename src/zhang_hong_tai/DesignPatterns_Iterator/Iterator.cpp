/*
 *作者:heldon
 *编写日期：18-9-7
 *功能描述：编写具体迭代器的方法
 */

#include "Iterator.h"

ConcreteIterator::ConcreteIterator(Aggregate *aggregate) {
    this->aggregate = (ConcreteAggregate*)aggregate;
    current = 0;
}

/*
 * 函数名：first
 * 作者：heldon
 * 编写日期：18-9-7
 * 输入参数：无
 * 返回值：返回容器中第一个元素
 */
string ConcreteIterator::first() {
    return aggregate->get_vector()->at(0);
}

/*
 * 函数名：first
 * 作者：heldon
 * 编写日期：18-9-7
 * 输入参数：无
 * 返回值：返回下一个元素
 */
string ConcreteIterator::next() {
    current++;
    if(current < aggregate->get_vector()->size()) {
        return aggregate->get_vector()->at(current);
    }
}

/*
 * 函数名：isdone
 * 作者：heldon
 * 编写日期：18-9-8
 * 输入参数：无
 * 返回值：若当前元素是容器中最后一个元素则返回ture,否则返回false
 */
bool ConcreteIterator::is_done() {
    if(current >= aggregate->get_vector()->size()){
        return true;
    }
    else
        return false;
}

/*
 * 函数名：current_item
 * 作者：heldon
 * 编写日期：18-9-7
 * 输入参数：无
 * 返回值：返回容器中当前元素
 */
string ConcreteIterator::current_item() {
    return aggregate->get_vector()->at(current);
}






















