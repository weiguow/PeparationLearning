#include <iostream>

using namespace std;

int _max(int sum_1, int sum_2) {
    if (sum_1 >= sum_2) return sum_1;
    else return sum_2;
}

int main(void) {
    cout << "输入两个数字：";
    int sum_1, sum_2;
    cin >> sum_1 >> sum_2;
    cout << "最大数是：" << _max(sum_1, sum_2) << '\n';
    return 0;
}