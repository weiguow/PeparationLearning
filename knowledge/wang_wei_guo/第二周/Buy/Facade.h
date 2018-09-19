//
// Created by wwg on 18-9-8.
//

#ifndef BUY_FACADE_H
#define BUY_FACADE_H

#include "StockA.h"
#include "StockB.h"
#include "StockC.h"
#pragma once;

class Facade{
    StockA stockA;
    StockB stockB;
    StockC stockC;

public:
    void Buy()
    {
        stockA.Buy();
        stockB.Buy();
        stockC.Buy();
    };
    void Sell()
    {
        stockA.Sell();
        stockB.Sell();
        stockC.Sell();
    };
};
#endif //BUY_FACADE_H
