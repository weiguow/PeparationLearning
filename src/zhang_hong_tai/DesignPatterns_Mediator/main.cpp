/*
 * 作者：heldon
 * 编写日期：18-9-9
 * 功能描述：主函数
 */

 #include <iostream>
 #include <string>
 #include "Mediator.h"
 #include "Colleague.h"

int main() {
     auto concreteMediator= new ConcreteMediator();
     WWG* wwg = new WWG(concreteMediator);
     MK* mk = new MK(concreteMediator);

     concreteMediator->Colleague1(wwg);
     concreteMediator->Colleague2(mk);

     wwg->chat("晚上来我宿舍");
     mk->chat("你想干嘛？？");

     return 0;

}