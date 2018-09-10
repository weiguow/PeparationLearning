/*
 *作者:heldon
 *编写日期：18-9-9
 *功能描述：
 */

#include "Colleague.h"
#include "Mediator.h"

/*
 * 函数名：chat
 * 编写日期：18-9-9
 * 作者：heldon
 * 输入参数：string message
 * 返回值：无
 */
void WWG::chat(string message){
    mediator->chat(message,this);
}

/*
 * 函数名：send_message
 * 编写日期：18-9-9
 * 作者：heldon
 * 输入参数：string message
 * 返回值：无
 * 功能描述：输出WWG发送的消息
 */
void WWG::send_message(string message) {
    cout<<"王卫国发送消息："<<message<<endl;
}

/*
 * 函数名：chat
 * 编写日期：18-9-9
 * 作者：heldon
 * 输入参数：string message
 * 返回值：无
 */
void MK::chat(string message){
    mediator->chat(message,this);
}

/*
 * 函数名：send_messgae
 * 编写日期：18-9-9
 * 作者：heldon
 * 输入参数：string message
 * 返回值：无
 * 功能描述：输出MK发送的消息
 */
void MK::send_message(string message) {
    cout<<"马坤发送消息:"<<message<<endl;
}