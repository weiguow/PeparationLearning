#include <iostream>
using namespace std;

int main() {
    int j = 12;
    auto by_val_lambda = [=] { return j + 1;};
    auto by_ref_lambda = [&] { return j + 1;};
    cout << "by_val_lambda: " << by_val_lambda() << endl;   //计算的是12+1=13
    cout << "by_ref_lambda: " << by_ref_lambda() << endl;   //计算的是12+1=13


    j++;
    cout << "by_val_lambda: " << by_val_lambda() << endl;   //计算的是12+1=13
    /*在by_val_lambda中，j被视为了一个常量，一旦初始化后不会再改变（可以认为之后只是一个跟父作用域中j同名的常量）*/
    cout << "by_ref_lambda: " << by_ref_lambda() << endl;   //计算的是13+1=14
    /*在by_ref_lambda中，j仍在使用父作用域中的值。*/
}
