/*
 * 版权所有：深圳先进研究所异构智能计算体系结构与系统研究中心
 * 作者：王卫国
 * 编写日期：2018/9/8
 * 功能描述：实现股票B的买入卖出
 */

#ifndef BUY_STOCKB_H
#define BUY_STOCKB_H

#include <iostream>

using namespace std;
#pragma once;

/*
 * 类名：Facade
 * 作者：王卫国
 * 编写日期：2018/9/8
 * 功能描述：子系统StockB的声明
 * 版本：1.0
 */

class StockB {
public:
    void Buy() {
        cout << "股票B买入" << endl;
    }

    void Sell() {
        cout << "股票B卖出" << endl;
    }
};

#endif //BUY_STOCKB_H
