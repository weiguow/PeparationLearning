/*回调基本函数,在C++11中使用std::function定义回调函数和参数类型,使用std::bind绑定回调函数*/
#include <iostream>
#include <functional>
using namespace std;

void f(int i){
    std::cout<<"f is called,i="<<i<<".\n";
}

int main() {
    /*std::bind将可调用函数与实参进行绑定,绑定后复制给定义的回调函数*/
    std::function<void(int)> callback = std::bind(f,std::placeholders::_1);
    /*定义带参数的回调需使用std::placeholders做占位符,可以根据参数多少任意增加*/
    callback(1);
    return 0;
}