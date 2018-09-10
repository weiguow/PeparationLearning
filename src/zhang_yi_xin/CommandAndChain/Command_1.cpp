#include <iostream>
#include <vector>
using namespace std;


/*
 * 类名:RoastCook
 * 编写日期:18-9-9
 * 功能描述:菜单类  Receiver 菜单类
 */
class RoastCook
{
public:
    void make_mutton(){
        cout << "烤羊肉" << endl;
    }
    void make_chicken_wing(){
        cout << "烤鸡翅膀" << endl;
    }
};

/*
 * 类名:Command
 * 编写日期:18-9-9
 * 功能描述:充当抽象命令角色
 */
class Command
{
protected:
    RoastCook* receiver;
public:
    Command(RoastCook* temp){
        receiver = temp;
    }
    virtual void execute_cmd() = 0;
};

/*
 * 类名:MakeMuttonCmd
 * 编写日期:18-9-9
 * 功能描述:烤羊肉命令
 */
class MakeMuttonCmd : public Command
{
public:
    MakeMuttonCmd(RoastCook* temp) : Command(temp) {}
    virtual void execute_cmd(){
        receiver->make_mutton();
    }
};

/*
 * 类名:MakeChickenWingCmd
 * 编写日期:18-9-9
 * 功能描述:烤鸡翅膀命令
 */
class MakeChickenWingCmd : public Command
{
public:
    MakeChickenWingCmd(RoastCook* temp) : Command(temp) {}
    virtual void execute_cmd(){
        receiver->make_chicken_wing();
    }
};

/*
 * 类名:MenuItem
 * 编写日期:18-9-9
 * 功能描述:服务员类.调用者角色,要求一个对象命令执行一个请求.
 */
class Waiter
{
public:
    void set_cmd(Command* temp);
    void notify();   /*通知执行*/
protected:
    vector<Command *> m_commandList;
};

void Waiter::set_cmd(Command* temp)
{
    m_commandList.push_back(temp);
    cout << "增加订单" << endl;
}

void Waiter::notify()
{
    vector<Command *>::iterator it;
    for (it=m_commandList.begin(); it!=m_commandList.end(); ++it)
    {
        (*it)->execute_cmd();
    }
}

int main()
{
    /*店里添加烤肉师傅、菜单、服务员等顾客*/
    RoastCook* cook = new RoastCook();
    Command* cmd_1 = new MakeMuttonCmd(cook);
    Command* cmd_2 = new MakeChickenWingCmd(cook);
    Waiter* waiter = new Waiter();

    waiter->set_cmd(cmd_1); /* 点菜*/
    waiter->set_cmd(cmd_2);

    waiter->notify(); /*服务员通知*/
    return 0;
}