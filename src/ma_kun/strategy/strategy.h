#ifndef _STRATEGY_H_
#define _STRATEGY_H_

/*
 * 类名：Strategy
 * 作者：cooooooooooooooool
 * 编写日期：18-9-13
 * 功能描述：抽象策略类
 */
class Strategy {
protected:
    Strategy();
public:
    ~Strategy();
    virtual void algorithm_interface() = 0;
};

/*
 * 类名：ConcreteStrategyA
 * 作者：cooooooooooooooool
 * 编写日期：18-9-13
 * 功能描述：具体策略类A
 */
class ConcreteStrategyA : public Strategy {
public:
    ConcreteStrategyA();
    ~ConcreteStrategyA();
    virtual void algorithm_interface();
};

/*
 * 类名：ConcreteStrategyB
 * 作者：cooooooooooooooool
 * 编写日期：18-9-13
 * 功能描述：具体策略类B
 */
class ConcreteStrategyB : public Strategy {
public:
    ConcreteStrategyB();
    ~ConcreteStrategyB();
    virtual void algorithm_interface();
};

/*
 * 类名：Context
 * 作者：cooooooooooooooool
 * 编写时间：18-9-13
 * 功能描述：环境类。
 * 这个类是Strategy模式的关键，
 * 也是Strategy模式和Template模式的根本区别所在。
 * Strategy通过“组合”（委托）方式实现算法（实现）的异构，
 * 而Template模式则采取的是继承的方式
 * 这两个模式的区别也是继承和组合两种实现接口重用的方式的区别
*/
class Context {
private:
    Strategy* m_strategy;
public:
    Context(Strategy*);
    ~Context();
    void do_action();
};
#endif