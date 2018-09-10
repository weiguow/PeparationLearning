/*
 *作者:heldon
 *编写日期：18-9-7
 *功能描述：主函数
 */
#include <iostream>
#include "Aggregate.h"
#include "Iterator.h"

using namespace std;

int main() {
    /*容器.指代公交车*/
    ConcreteAggregate* bus = new ConcreteAggregate();

    /* 为容器添加内容;
     * push_back表示在vector后面继续添加
     */
    bus->get_vector()->push_back("王卫国");
    bus->get_vector()->push_back("马  坤");
    bus->get_vector()->push_back("张艺馨");
    bus->get_vector()->push_back("王倩楠");
    bus->get_vector()->push_back("张鸿泰");

    /*
     * 新创建一个迭代器
     */
    Iterator* iterator = bus->create_iterator();
    cout<<"正向遍历的迭代器："<<endl;
    cout<<"***************"<<endl;

    while(!iterator->is_done()){
        cout<<iterator->current_item()<<"  请买票！"<<endl;
        iterator->next();
    }

    delete bus,iterator;

}