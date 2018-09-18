/*通过带状态的仿函数，可以设定两种不同的税率计算*/
#include <iostream>
using namespace std;
class Tax {
private:
    float rate;  //仿函数可以拥有初始状态，一般通过class定义私有成员
    int base;
public:
    Tax(float r, int b):rate(r), base(b){}
    float operator()(float money){return (money - base) * rate;}
};

int main() {
    Tax high(0.40, 30000); //并在声明对象的时候对其进行初始化,私有成员的状态就成了仿函数的初始状态
    Tax middle(0.25, 20000);
    cout << "tax over 3w: " << high(37500) << endl;   
    cout << "tax over 2w: " << middle(27500) << endl;
    return 0;
}

//声明一个仿函数对象可以拥有多个不同初始状态的实例，因此可以借由仿函数产生多个功能类似却不同的仿函数实例