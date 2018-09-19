#include <iostream>
#include "composite.h"

using namespace std;

int main() {
    string str("─");

    ConcreteCommandA com1("中国科学院");
    ConcreteCommandB com2("中国科学院天津计算技术研究所");
    ConcreteCommandC com3("中国科学院北京计算所");

    cout << "一级目录" << endl;
    com1.display(str);
    cout << endl;

    cout << "添加二级目录" << endl;
    com1.attach(&com2);
    com1.attach(&com3);
    com1.display(str);
    cout << endl;

    ConcreteCommandA com11("中国科学院深圳先进研究院");
    ConcreteCommandB com22("数字所异构智能中心");
    ConcreteCommandC com33("数字所云计算中心");

    cout << "添加三级目录" << endl;
    com11.attach(&com22);
    com11.attach(&com33);
    com1.attach(&com11);
    com1.display(str);
    cout<<endl;

    cout<<"删除目录"<<endl;
    com11.detach(&com22);
    com1.display(str);
}