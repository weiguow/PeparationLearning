/*
 * 作者：cooooooooooooooool
 * 编写时间：18-9-13
 * 功能描述： Context 指向 Strategy (由指针实现)；
 * Context 通过 Strategy 接口，调用一系列算法；
 * ConcreteStrategy 实现了一系列具体的算法
 */
#include "strategy.h"

int main() {
    /*
     * Strategy模式和Template模式实际是实现一个抽象接口的两种方式：继承和组合之间的区别。
     * 要实现一个抽象接口，继承是一种方式：我们将抽象接口声明在基类中，将具体的实现放在具体子类中。
     * 组合（委托）是另外一种方式：我们将接口的实现放在被组合对象中，将抽象接口放在组合类中。
     * 这两种方式各有优缺点
     */
    /*策略A与B可替换*/
    Strategy* m_str = new ConcreteStrategyA();
    Context* m_con = new Context(m_str);
    m_con->do_action();

    m_str = new ConcreteStrategyB();
    m_con = new Context(m_str);
    m_con->do_action();

    return 0;
}