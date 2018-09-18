/*
 * 版权所有:深圳先进研究所异构智能计算体系结构与系统研究中心
 * 作者:王卫国
 * 编写日期:2018/9/14
 * 功能描述:使用状态类
 */
#include <iostream>
#include "StateMode.h"
using namespace std;

int main() {
    Context* context = new Context(new ConcreteStateA);  /*初始化A状态*/
    context->Request();
    context->Request();
    context->Request();
    getchar();
    return 0;
}