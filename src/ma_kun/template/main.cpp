/*
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：自定义模板Max，返回两个数中较大的数
 */
#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline T const& Max (T const& a, T const& b) {
    return a < b ? b:a;
}
int main () {
    int int_1 = 39;
    int int_2 = 20;
    cout << "Max(int_1, int_2): " << Max(int_1, int_2) << endl;

    double double_1 = 13.5;
    double double_2 = 20.7;
    cout << "Max(double_1, double_2): " << Max(double_1, double_2) << endl;

    string string_1 = "Hello";
    string string_2 = "World";
    cout << "Max(string_1, string_2): " << Max(string_1, string_2) << endl;

    return 0;
}