/*
 * 作者:张艺馨
 * 编写日期:2018/9/9
 * 功能描述:开发一个公告板系统.系统提供主菜单,主菜单中含一些菜单项(MenuItem),可以通过Menu类的addMenuItem()方法增加菜单项
 *         菜单项的主要方法是click(),每一个菜单项包含一个抽象命令类,具体命令类包括OpenCommand,CreateCommand,EditCommand.
 *         命令类具有一个execute()方法,用于调用公告板系统界面类(BoardScreen)的open(),create(),edit()方法.
 *         用该模式使得MenuItem类和BoardScreen类耦合度降低
 */
#include <iostream>
#include <vector>
using namespace std;

/*
 * 类名:Command
 * 编写日期:18-9-9
 * 功能描述:充当抽象命令角色
 */
class Command
{
public:
    virtual void execute() = 0;
};

/*
 * 类名:MenuItem
 * 编写日期:18-9-9
 * 功能描述:菜单项类.调用者角色,要求一个对象命令执行一个请求.
 */
class MenuItem
{
private:
    string name;
    Command command;
public:
    MenuItem(string name){
        this->name=name;
    }

public:
    string get_name(){
        return this->name;
    }
    void set_name(string name){
        this->name=name;
    }
    Command get_command(){
        return this->command;
    }
    void setCommand(Command command){
        this->command=command;
    }
    void click(){
        command.execute();
    }
};

/*
 * 类名:Menu
 * 编写日期:18-9-9
 * 功能描述:菜单类
 */
class Menu
{
public:
    vector<MenuItem *>item_list;
    void addMenuItem(MenuItem *item){
        item_list.push_back(item);
    }
};

/*
 * 类名:OpenCommand
 * 编写日期:18-9-9
 * 功能描述:打开命令:具体命令
 */
class OpenCommand : public Command
{
private:
    BoardScreen *screen;
public:
    OpenCommand(BoardScreen *screen){
        this->screen=screen;
    }
    void execute(){
        screen->open();
    }
};

/*
 * 类名:CreateCommand
 * 编写日期:18-9-9
 * 功能描述:具体命令
 */
class CreateCommand : public Command
{
private:
    BoardScreen *screen;
public:
    CreateCommand(BoardScreen *screen){
        this->screen=screen;
    }
    void execute(){
        screen->create();
    }
};

/*
 * 类名:CreateCommand
 * 编写日期:18-9-9
 * 功能描述:具体命令
 */
class EditCommand : public Command
{
private:
    BoardScreen *screen;
public:
    EditCommand(BoardScreen *screen){
        this->screen=screen;
    }
    void execute(){
        screen->edit();
    }
};

/*
 * 类名:CreateCommand
 * 编写日期:18-9-9
 * 功能描述:具体命令
 */
class BoardScreen{
private:
    Menu *menu;
    MenuItem *open_item,*create_item,*edit_item;
public:
    BoardScreen(){
        menu = new Menu();
        open_item=new MenuItem("打开");
        create_item=new MenuItem("新建");
        edit_item=new MenuItem("编辑");
        menu->addMenuItem(open_item);
        menu->addMenuItem(create_item);
        menu->addMenuItem(edit_item);
    }
    void display(){
        cout<<"主菜单选项"<<endl;
    }
public:
    void open(){
        cout<<"显示打开窗口"<<endl;
    }
    void create(){
        cout<<"显示新建窗口"<<endl;
    }
    void edit(){
        cout<<"显示编辑窗口"<<endl;
    }
    Menu getMenu(){
        return *menu;
    }
};

int main(){
    BoardScreen *screen = new BoardScreen(); /*接收者*/
    Menu menu =screen->getMenu();
    Command *open_command,*create_command,*edit_command;
    open_command = new OpenCommand(screen);
    create_command = new CreateCommand(screen);
    edit_command = new EditCommand(screen);

    MenuItem *open_item,*create_item,*edit_item;
    open_item = (MenuItem)menu.item_list.get(0); /*返回元素在此列表的指定位置*/
    create_item = (MenuItem)menu.item_list.get(1);
    edit_item = (MenuItem)menu.item_list.get(2);

    open_item->setCommand(*open_command);
    create_item->setCommand(*create_command);
    edit_item->setCommand(*edit_command);

    screen->display();
    open_item->click();
    create_item->click();
    edit_item->click();
}