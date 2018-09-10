/*
 * 版权所有：深圳先进研究所异构智能计算体系结构与系统研究中心
 * 作者：王卫国
 * 编写日期：2018/9/8
 * 功能描述：外观模式的实现
 */

#include "Facade.h"

/*
 * 函数名称：main
 * 编写日期：2018/9/8
 * 功能描述：通过使用外观模式，让客户端实现股票买入卖出
 * 调用函数清单：Buy()买入股票 Sell()卖出股票
 * 输入参数说明：无
 * 返回值说明：0
 * 其他说明：无
 */

int main() {
    Facade *facade = new Facade;
    facade->Buy();
    facade->Sell();
    getchar();
    return 0;
}