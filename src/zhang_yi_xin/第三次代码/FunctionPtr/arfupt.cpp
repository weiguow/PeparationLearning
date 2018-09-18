#include <iostream>
using namespace std;
// various notations, same signatures
// 三个函数的原型，它们的特征标和返回类型相同
const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);

int main()
{
    double av[3] = {1112.3, 1542.6, 2227.9};
    // pointer to a function
    //声明指针p1，指向函数f1
    const double *(*p1)(const double *, int) = f1;
    auto p2 = f2;  // C++0x automatic type deduction    声明指针p2，指向函数f2
    // pre-C++0x can use the following code instead
    // const double *(*p2)(const double *, int) = f2;
    cout << "Using pointers to functions:\n";
    cout << " Address  Value\n";
    cout <<  (*p1)(av,3) << ": " << *(*p1)(av,3) << endl; //(*pl)(av,3)和p2(av,3)都调用指向的函，返回值的类型为 const double *(即 double值的地址)
    cout << p2(av,3) << ": " << *p2(av,3) << endl; //为查看存储在这些地址处的实际值 *(*p1)(av,3)和 *p2(av,3)
    cout << "-----------------------" << endl;
    // pa an array of pointers
    // auto doesn't work with list initialization
    const double *(*pa[3])(const double *, int) = {f1,f2,f3};  //pa是一个包含三个元素的数组 声明：*pa[3]表明pa是一个包含三个指针的数组
    // but it does work for initializing to a single value
    // pb a pointer to first element of pa
    auto pb = pa;
    // pre-C++0x can use the following code instead
    // const double *(**pb)(const double *, int) = pa;
    cout << "\nUsing an array of pointers to functions:\n";   //函数指针数组
    cout << " Address  Value\n";
    for (int i = 0; i < 3; i++)
        cout << pa[i](av,3) << ": " << *pa[i](av,3) << endl;
    cout << "-----------------------" << endl;
    cout << "\nUsing a pointer to a pointer to a function:\n";
    cout << " Address  Value\n";
    for (int i = 0; i < 3; i++)
        cout << pb[i](av,3) << ": " << *pb[i](av,3) << endl;
    cout << "-----------------------" << endl;

    // what about a pointer to an array of function pointers
    cout << "\nUsing pointers to an array of pointers:\n";
    cout << " Address  Value\n";
    // easy way to declare pc
    auto pc = &pa;  //创建指向整个数组的指针
    // pre-C++0x can use the following code instead
    // const double *(*(*pc)[3])(const double *, int) = &pa;
    cout << (*pc)[0](av,3) << ": " << *(*pc)[0](av,3) << endl;
    cout << "-----------------------" << endl;

    // hard way to declare pd
    const double *(*(*pd)[3])(const double *, int) = &pa;
    // store return value in pdb
    const double * pdb = (*pd)[1](av,3);
    cout << pdb << ": " << *pdb << endl;

    cout << "-----------------------" << endl;
    // alternative notation
    cout << (*(*pd)[2])(av,3) << ": " << *(*(*pd)[2])(av,3) << endl;   //*(*(*pd[i])(av,3)是指向的double值。使用(*(*pd)[i])(av,3)来调用函数
    // cin.get();
    return 0;
}

// some rather dull functions

const double * f1(const double * ar, int n)
{
    return ar;
}
const double * f2(const double ar[], int n)
{
    return ar+1;
}
const double * f3(const double ar[], int n)
{
    return ar+2;
}


