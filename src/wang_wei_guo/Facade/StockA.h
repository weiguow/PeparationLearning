/*
 * 版权所有：深圳先进研究所异构智能计算体系结构与系统研究中心
 * 作者：王卫国
 * 编写日期：2018/9/8
 * 功能描述：实现股票A的买入卖出
 */

#ifndef BUY_STOCKA_H
#define BUY_STOCKA_H

#include <iostream>

using namespace std;
#pragma once;

/*
 * 类名：Facade
 * 作者：王卫国
 * 编写日期：2018/9/8
 * 功能描述：子系统StockA的声明
 * 版本：1.0
 */

class StockA {
public:
    void Buy() {
        cout << "股票A买入" << endl;
    }

    void Sell() {
        cout << "股票A卖出" << endl;
    }
};

#endif //BUY_STOCKA_H
