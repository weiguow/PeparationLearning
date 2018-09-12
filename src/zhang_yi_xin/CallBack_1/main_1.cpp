/*回调对象中的函数*/
#include <iostream>
#include <functional>
using namespace std;

class A
{
private:
    int j_;
public:
    A()
    {
        j_=1;
    }
    void f(int i)
    {
        std::cout<<"A::f is called ,i ="<<i<<", j = "<<j_<<".\n";
    }
};

int main(){
    A a;
    std::function<void(int)> callback1 =std::bind(&A::f,&a,std::placeholders::_1);
    callback1(2);
}