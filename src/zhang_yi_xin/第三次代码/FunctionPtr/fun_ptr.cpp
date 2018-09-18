/*
    演示了如何使用函数指针。它两次调用 estmated()函数，一次传递 betsy()函数的地址
另一次则传递pam()函数的地址。在第一种情况下, estimate()使用 betsy()计算所需的小时数;在第二种情
况下, estimate()使用pam()进行计算。这种设计有助于今后的程序开发。当 Ralph为估算时间而开发自己
的算法时，将不需要重新编写 estimate()。相反，他只需提供自己的 ralph()函数，并确保该函数的特征标
和返回类型正确即可。当然，重新编写 estimate()也并不是一件非常困难的工作，但同样的原则也适用于更
复杂的代码。另外，函数指针方式使得 Ralph能够修改 estimate()的行为，虽然他接触不到 estimate()的源代码
 */
#include <iostream>
double betsy(int);
double pam(int);
// second argument is pointer to a type double function that
// takes a type int argument
void estimate(int lines, double (*pf)(int));

int main()
{
    using namespace std;
    int code;

    cout << "How many lines of code do you need? ";
    cin >> code;
    cout << "Here's Betsy's estimate:\n";
    estimate(code, betsy);
    cout << "Here's Pam's estimate:\n";
    estimate(code, pam);
    // cin.get();
    // cin.get();
    return 0;
}

double betsy(int lns)
{
    return 0.05 * lns;
}

double pam(int lns)
{
    return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int))
{
    using namespace std;
    cout << lines << " lines will take ";
    cout << (*pf)(lines) << " hour(s)\n";
}
