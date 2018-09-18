/*机场返税。
 分别使用了仿函数和lambda两种方式来完成扣税后的产品价格计算。
 在这里我们看到，lambda数捕提了tax ratc变量，而仿函数则以tax rate初始化类。
 其他的，如在参数传递上，两者保持一致。可以看到，除去在语法层面上的不同，
 lambda和仿函数却有着相同的内涵——都可以捕捉一些变量作为初始状态，
 并接受参数进行运算。
*/
#include <iostream>
using namespace std;
class AirportPrice {
private:
    float _dutyfreerate;
public:
    AirportPrice(float rate) : _dutyfreerate(rate) {}

    float operator()(float price) {
        return price * (1 - _dutyfreerate / 100);
    }
};
int main(){
    float tax_rate = 5.5f;
    AirportPrice changi (tax_rate);  //而仿函数则以tax_rate初始化类
    auto changi2 =
    [tax_rate] (float price)->float{return price * (1 - tax_rate/100);};  //lambda数捕提了tax_ratc变量
    float purchased = changi(3699);
    float purchased2 =  changi2(2899);

    cout<<purchased<<endl;
    cout<<purchased2<<endl;
}



