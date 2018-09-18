#include <iostream>
using namespace std;

extern int z ;
extern float c;

void calc(int& , int, float &, float);

void TestCalc()   //用户试图用自己写的函数Testcal进行测试。这里使用lambda函数直接访问了Testcal中的局部的变量来完成这个工作。
{
    int x, y = 3;
    float a, b = 4.0;
    int success = 0;

    auto validate = [&]()->bool
    {
        if ((x == y + z) && (a == b + c))
            return 1;
        else
            return 0;
    };

    calc(x, y, a, b);
    success += validate();

    y = 1024;
    b = 100.0;
    calc(x, y, a, b);
    success += validate();
}
