/*
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：虚函数实现多态
 */
#include <iostream>
#include <stdlib.h>

using namespace std;

/*
 * 类名：Father
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：定义虚函数输出"Father say hello"
 * 版本：1.0
 */
class Father {
public:
    virtual void say() {
        cout << "Father say hello" << endl;
    }
};

/*
 * 类名：Son
 * 作者：coooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：子类
 */
class Son : public Father {
public:
    void say() {
        cout << "Son say hello" << endl;
    }
};

int main() {
    Son son;
    Father *p_father = &son;  /*隐式类型转换*/
    p_father->say();
}