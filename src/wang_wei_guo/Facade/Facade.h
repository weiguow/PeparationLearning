/*
 * 版权所有：深圳先进研究所异构智能计算体系结构与系统研究中心
 * 作者：王卫国
 * 编写日期：2018/9/8
 * 功能描述：外观模式的头文件，调用StockA.h,StockB.h,StockC.h,
 * 对外只给出Sell()和Buy()函数
 */

#ifndef BUY_FACADE_H
#define BUY_FACADE_H

#include "StockA.h"
#include "StockB.h"
#include "StockC.h"

#pragma once;

/*
 * 类名：Facade
 * 作者：王卫国
 * 编写日期：2018/9/8
 * 功能描述：外观类的声明
 * 版本：1.0
 */

class Facade {
    StockA stockA;
    StockB stockB;
    StockC stockC;

public:
    void Buy() {
        stockA.Buy();
        stockB.Buy();
        stockC.Buy();
    };

    void Sell() {
        stockA.Sell();
        stockB.Sell();
        stockC.Sell();
    };
};

#endif //BUY_FACADE_H
