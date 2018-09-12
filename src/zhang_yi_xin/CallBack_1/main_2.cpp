/*回调中的多个参数和返回值*/
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
        j_=10;
    }
    int f(int i,int k)
    {
        std::cout<<"A::f is called ,i ="<<i<<", j = "<<j_<<", k ="<<k<<".\n";
    }
};

int main(){
    A a;
    std::function<int(int,int)> callback2 =std::bind(&A::f,&a,std::placeholders::_1,std::placeholders::_2);
    int r = callback2(2,3);
    std::cout<<"r = "<<r<< std::endl;

    return 0;
}