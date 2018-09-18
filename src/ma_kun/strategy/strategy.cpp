/*
 * 作者：cooooooooooooooool
 * 编写日期：18-9-13
 * 功能描述：具体策略类A、B实现具体的算法
 */
#include <iostream>
#include "strategy.h"

using namespace std;

Strategy::Strategy() {}

Strategy::~Strategy() {}

ConcreteStrategyA::ConcreteStrategyA() {}

ConcreteStrategyA::~ConcreteStrategyA() {}

void ConcreteStrategyA::algorithm_interface() {
    cout << "ConcreteStrategyA::algorithm_interface" << endl;
}

ConcreteStrategyB::ConcreteStrategyB() {}

ConcreteStrategyB::~ConcreteStrategyB() {}

void ConcreteStrategyB::algorithm_interface() {
    cout << "ConcreteStrategyB::algorithm_interface" << endl;
}

Context::Context(Strategy* strategy) {
    this->m_strategy = strategy;
}

Context::~Context() {
    delete this->m_strategy;
}

void Context::do_action() {
    this->m_strategy->algorithm_interface();
}