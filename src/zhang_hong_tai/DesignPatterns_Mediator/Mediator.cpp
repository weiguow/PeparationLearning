/*
 *作者:heldon
 *编写日期：18-9-9
 *功能描述：
 */

#include "Mediator.h"


/*
 * 函数名：chat
 * 编写日期：18-9-9
 * 作者：heldon
 * 输入参数：string message,Colleague *colleague
 * 返回值：无
 * 功能描述：显示传递消息
 */
 void ConcreteMediator::chat(string message, Colleague *colleague) {
    if(colleague == colleague1){
     colleague1->send_message(message);
    }
    else
     colleague2->send_message(message);
 }

/*
* 函数名：Colleague1
* 编写日期：18-9-9
* 作者：heldon
* 输入参数：WWG *val
* 返回值：无
* 功能描述：将WWG赋给colleague1
*/
void ConcreteMediator::Colleague1(WWG *val) {
    colleague1 = val;
}

/*
* 函数名：Colleague2
* 编写日期：18-9-9
* 作者：heldon
* 输入参数：MK *val
* 返回值：无
* 功能描述：将MK赋给colleague2
*/
void ConcreteMediator::Colleague2(MK *val) {
    colleague2 = val;
}
