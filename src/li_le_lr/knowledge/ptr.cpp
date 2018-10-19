#include <climits>
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <memory>
#include <atomic>
#include <thread>
//#include <cstdatomic>
#include <unistd.h>
#include <cstdlib>
/* at_quick_exit example */
#include <stdio.h>      /* puts */
#include <stdlib.h>     /* at_quick_exit, quick_exit, EXIT_SUCCESS */
using namespace std;


int main ()
{

    char* arr2 = "abcd";
    cout<<arr2<<endl;
    cout<<*arr2<<endl;
    cout<<*(arr2+1)<<endl;
    cout<<*(arr2)<<endl;
//    *(arr2+1) = 'w';
//    cout<<*(arr2+1)<<endl;
    int x = 4;
    int* y=&x;
    cout<<&x<<endl;
    cout<<y<<endl;
    cout<<*y<<endl;

//
//    int _m = Cmf();
//
//    int _n = Cpf();
//
//
//
//    cout<<_m<<" "<<_n;
//
////    int a = 8;
////
////    Cpf(&a);
////
////    cout<<a; // a is 9
//
//
////    CExample c;
////    cout<<c.a<<endl;
////    cout<<c.b<<endl;
////    char arr[] = {'a','b','c','d','e','\0'};
////    char *arr2 = "abcde";
////    *(arr+2) = 'q';
////    cout<<arr<<endl;
//////    *(arr2+2)='w';
////    cout<<arr2<<endl;
//
//    int x =5;
////     int const * ptr = &x;
////    cout<<*ptr<<endl;
//////    *ptr = 12;
////    int y = 8;
////    ptr = &y;
////    cout<<*ptr<<endl;
////    const int * const ptr2 = &x;
////    cout<<*ptr2<<endl;
////    *ptr2 = 18;
////    cout<<*ptr2<<endl;
////    int y2 = 14;
////    ptr2 = &y2;
//

    return 0;
}
