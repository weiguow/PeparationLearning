//
// Created by wqn on 18-10-17.
//
#include <iostream>
#include <cstring>
#include <memory>
#include <vector>
#include <functional>
//#include <string>

using namespace std;
using namespace std::placeholders;

//class Complex {
//private:
//    double real, imag;
//public:
//    Complex();
//    Complex(double r, double i);
//    Complex(double a);
//
//};
//
//Complex::Complex(double r, double i) {
//    real = r;
//    imag = i;
//
//}
//
//Complex::Complex(double a){
//    real = a;
//
//}
//
//class Base
// {
// public:
//    Base(int b) : m_b(b)
//    {
//    }
//private:
//    int m_b;
// };
//
//
//
//
//class String
//{
//public:
//    //String();
//    String(const char *str =NULL);
//    String( const String &other);
//    ~String(void);
//
//private:
//    char *m_data;
//};
//
//String::~String()
//{
//    cout<<m_data<<endl;
//    delete m_data;
//    cout<<"xigou" <<endl;
//}
//
////String::String():m_data(NULL) {
////    cout<<"empty construct" <<endl;
////
////}
//
//
//String::String(const char *str)
//{
//    if (str==NULL)
//    {
//        m_data = new char[1];
//        *m_data ='\0';
//    }
//    else
//    {
//        int length = strlen(str);
//        m_data = new char[length+1];
//        strcpy(m_data,str);
//
//    }
//    cout<<"构造" <<endl;
//}
//
//String::String( const String &other)
//{
//     int length = strlen(other.m_data);
//     m_data = new char[length+1];
//     strcpy(m_data, other.m_data);
//    cout<<"copy构造" <<endl;
//
// }
//
//
//int main ()
//
//{
//    String a;
//   char* b = "127";
//   String str_b(b);
//
//   //String str_c(str_b);
//
//}

//class Complex{
//private:
//    double real, imag;
//public:
//    Complex(double r);
//    Complex(double r, double i);
//    Complex(Complex cl, Complex c2);
//    ~Complex();
//
////    double get_name();
////    void set_name(int  name);
//};
//
////double  Complex::get_name() {
////    return this->imag;
////}
////
////void Complex::set_name(int name) {
////
////    this->imag=name;
////    cout<<imag;
//
//Complex::Complex(double r)  //构造函数 1
//{
//    real = r;
//    imag = 0;
//}
//Complex :: Complex(double r, double i)  //构造数 2
//{
//    real = r;
//    imag = i;
//}
//Complex :: Complex(Complex cl, Complex c2)  //构造函数 3
//{
//
//    real = cl.real + c2.real;
//    imag = cl.imag + c2.imag;
//}
//Complex::~Complex() {
//
//}
//
//
//
//class Point {
//    int x ,y;
//public:
//    Point(int a, int b);
//    void MovePoint( int a, int b);
//    void print();
//
//};
//
//Point::Point(int a, int b) {
//    x=a;
//    y=b;
//}
//
//void Point::MovePoint(int a, int b) {
//    cout<< sizeof(this)<<endl;
//
//    x+=a;
//    y+=b;
//
//}
//void Point::print() {
//    cout<<"x="<<x<<" y="<<y<<endl;
//}

//int main(){
//    Complex test(7,8);
//    test.get_name();
//    test.set_name(8);
    // Complex cl(3), c2(1,2), c3(cl,c2), c4 = 7;
//    Point point1(3,5);
//    point1.MovePoint(2,2);
//    point1.print();

   // int a = 8;
   //const int *p =7;
    //int *const p =&a;
    //a = 0;
    //*p = 9;


//}

//class Person
//{
//public:
//    //Person(){cout<<"111"<<endl;}
////    Person(const Person& p)
////    {
////        cout << "Copy Constructor" << endl;
////    }
//
//    Person& operator=(const Person& p)
//    {
//        cout << "Assign" << endl;
//        return *this;
//    }
//
//private:
//    int age;
//    string name;
//};
//
//void f(Person p)
//{
//    return;
//}
//
//Person f1()
//{
//    Person a;
//    return a;
//}
//
//int main()
//{
//    Person p;
//    Person p1 = p;    // 1
//    Person p2;
//    p2 = p;           // 2
//    f(p2);            // 3
//    f1();           // 4
//
//    //Person p3 = f1(); // 5
//
//    //getchar();
//    return 0;
//}



//class Base1 {
//public:
//
//    Base1(){
//        cout << "调用了Base的默认构造函数" << endl;
//    }
//
//    Base1(int b ,int d)  {
//        cout << "调用了带两个参数的Base的构造函数" << endl;
//    }
//
//    Base1(int b)  {
//        cout << "调用了带一个参数的Base的构造函数" << endl;
//    }
//
//    ~Base1() {
//        cout << "调用了Base的析构函数" << endl;
//    }
//};
//
//class Derived1 :public Base1{
//public:
//
//    Derived1()  {
//        cout << "调用了Derived1的默认构造函数" << endl;
//    }
//
//
//    Derived1(int b, int d)  {
//        cout << "调用了带两个参数的Derived1构造函数" << endl;
//    };
//
//    ~Derived1() {
//        cout << "调用了Derived1的析构函数" << endl;
//
//    }
//};
//
//    int main()
//
//{
//
//    Base1 b1;
//    Base1 b2(10);
//    Base1 b3(10,20);
//
//
//    cout<<"==========="<<endl;
//
//    Derived1 d1;
//
//    Derived1 d2(1,2);
//
//
//    cout<<"================="<<endl;
//
//    return 0;
//}

//class Test1
//
//{
//public:
//    Test1() // 无参构造函数
//    {
//        cout << "Construct Test1" << endl ;
//    }
//
//    Test1 (const Test1& t1) // 拷贝构造函数  (Test1为返回类型)
//    {
//        cout << "Copy constructor for Test1" << endl ;
//        this->a = t1.a ;
//    }
//
//    Test1& operator = (const Test1& t1) // 赋值运算符
//    {
//        cout << "assignment for Test1" << endl ;
//        this->a = t1.a ;
//        return *this;
//    }
//
//    int a ;
//};
//
//class Test2
//{
//public:
//    Test1 test1 ;
//    Test2(Test1 &t1):test1(t1)
//    {
//        test1 = t1 ;
//    }
//};





// int main()
// {
//     int x =5;
//     int *ptr = &x;
//     cout<< ptr<<endl;
//     cout<< &ptr<<endl;
//
//     int &y =x;
//     cout <<y<<endl;
//
//     int *ptr2 =NULL;
//     cout<< ptr2<<endl;
//
// }
//
// int *function (int a)
// {
//     int temp=5;
//     return &temp;
// }




//深拷贝和浅拷贝
//class String
//{
//public:
//    String(const char *pStr ="")
//    {
//        if(NULL == pStr)
//        {
//            pstr = new char[1];
//            *pstr = '\0';
//        }
//        else
//        {
//            pstr = new char[strlen(pStr)+1];//加1,某位是'\0'
//            strcpy(pstr,pStr);//用拷贝字符串的函数
//        }
//    }
//
//    String(const String &s)
//            :pstr(new char[strlen(s.pstr)+1])    //浅拷贝的问题，指向同一块空间，可能造成释放的错误 ，这是浅拷贝的缺点
//    {
//        strcpy(pstr,s.pstr);
//    }
//
//    String& operator=(const String&s)
//    {
//        if(this != &s)
//        {
//            delete[] pstr;  //将原来所指向的空间释放
//            pstr = s.pstr;  //让pstr重新指向s的pstr所指向的空间（也会导致错误）
//        }
//        cout<<"1";
//        return *this;
//    }
//
//    ~String()
//    {
//        if(NULL != pstr)
//        {
//            delete[] pstr;//释放指针所指向的内容
//            pstr = NULL;//将指针置为空
//        }
//    }
//    friend ostream &operator<<(ostream & _cout,const String &s)
//    {
//        _cout<<s.pstr;
//        return _cout;
//    }
//private:
//    char *pstr;
//};
//
//
//int main()
//{
//    String s1("sss");
//   String s2(s1);
//    String s3(NULL);
//
//    s3 = s1;
//    //s3 = s2;
//    cout<<s1<<endl;
////    cout<<s2<<endl;
//    cout<<s3<<endl;
//    return 0;
//}


//智能指针
//int main() {
//    shared_ptr<double> pd;
//    double *p_reg = new double;
//   // pd =p_reg;  //not allow
//    pd = shared_ptr<double>(p_reg);
//}


//class Test
//{
//public:
//    Test();
//    int a;
//    int b;
////    Test(int a=0,int b=0)
////    {
////        Test::a=a;
////        Test::b=b;
////    }
////    int a;
////    int b;
//};
//Test::Test() {}
//int main()
//
//{
//    Test t;
//
//}


//mutable 关键字

  //c++ primer 练习

//class Screen{
//public:
//    typedef string::size_type pos;
//    Screen() = default;
//    Screen(pos ht,pos wd, char c):height(ht), width(wd), contents(ht *wd, c){}
//char get() const {
//        return contents[cursor]; //隐式内联
//
//    }
//    inline char get(pos ht, pos wd)const;
//
//    Screen &move (pos r, pos c);
//    Screen &set(char);
//    Screen &set(pos, pos, char);
//
//    Screen &display(ostream &os){
//        do_display(os);
//        return *this;
//    }
//     const Screen &display(ostream &os) const {
//         do_display(os);
//         return *this;
//    }
//    void some_member() const ;
//
//
//    vector<Screen> screens{Screen(24,80,' ')};
//
//private:
//    pos cursor =0;
//    pos height =0, width =0;
//    string contents;
//
//    mutable  size_t access_ctr;
//
//    //显示Screen的内容
//    void do_display(ostream &os)const {
//        os<<contents;
//    }
//};
//
//class Window_mgr{
//public:
//    using ScreenIndex = vector<Screen>::size_type ;
//    void clear(ScreenIndex);
//
//private:
//    vector<Screen> screens{Screen(24, 80, ' ')};
//};
//
//inline Screen& Screen::set(char c) {
//    contents[cursor] = c;
//    return *this;
//
//}
//
//inline Screen& Screen::set(Screen::pos r, Screen::pos col, char ch) {
//    contents[r*width +col] = ch;
//    return *this;
//
//}
//
//void Screen::some_member() const {
//    ++access_ctr;
//}


//回调函数
//就是使用者自己定义一个函数，使用者自己实现这个函数的程序内容，然后把这个函数作为参数传入别人（或系统）的函数中，由别人（或系统）的函数在运行时来调用的函数
//定义回调函数
//void PrintfText()
//{
//    printf("Hello World!\n");
//}
//
////定义实现回调函数的"调用函数"
//void CallPrintfText(void (*callfuct)())
//{
//    callfuct();
//}
//
////在main函数中实现函数回调
//int main(int argc,char* argv[])
//{
//    CallPrintfText(PrintfText);
//    return 0;
//}


//定义带参回调函数
//将一个函数指针A作为参数传入另外一个函数B，然后在函数B中调用函数A

//void PrintfText(char* s)
//{
//    printf(s);
//}
//
////定义实现带参回调函数的"调用函数"
//void CallPrintfText(void (*callback)(char*),char* s)
//{
//    callback(s);
//}
//
////在main函数中实现带参的函数回调
//int main()
//{
//    CallPrintfText(PrintfText,"Hello World!\n");
//    return 0;
//}



//void printWelcome(int len)
//{
//    printf("welcome -- %d\n", len);
//}
//
//void printGoodbye(int len)
//{
//    printf("byebye-- %d\n", len);
//}
//
//void callback(int times, void (* print)(int))
//{
//    int i;
//    for (i = 0; i < times; ++i)
//    {
//        print(i);
//    }
//    printf("\n welcome or byebye !\n");
//}

//int main(void)
//{
//    callback(10, printWelcome);
//    callback(10, printGoodbye);
//}





//typedef std::function<void(int,int)> Fun;
//
//class B{
//public:
//    void call(int a,Fun f)  //f是fun的形参
//    {
//        f(a,2);
//    }
//};
//
//class Test{
//public:
//    void callback(int a,int b)
//    {
//        cout<<a<<"+"<<b<<"="<<a+b<<endl;
//    }
//
//    void bind()
//    {
//        Fun fun=std::bind(&Test::callback,this,_1,_2);
//        B b;
//        b.call(1,fun);   //fun是Fun类型,相当于一个函数指针
//    }
//
//};
//int main()
//{
//    Test test;
//    test.bind();
//    return 0;
//}


typedef std::function<void ()> fp;

void g_fun()
{
    cout<<"g_fun()"<<endl;
}
class A
{
public:
    static void A_fun_static()
    {
        cout<<"A_fun_static()"<<endl;
    }
    void A_fun()
    {
        cout<<"A_fun()"<<endl;
    }
    void A_fun_int(int i)
    {
        cout<<"A_fun_int() "<<i<<endl;
    }

    //非静态类成员，因为含有this指针，所以需要使用bind
    void init()
    {
        fp fp1=std::bind(&A::A_fun,this);
        fp1();
    }

    void init2()
    {
        typedef std::function<void (int)> fpi;
        //对于参数要使用占位符 std::placeholders::_1
        fpi f=std::bind(&A::A_fun_int,this,_1);
        f(5);
    }
};


int main()
{
    //绑定到全局函数
    fp f2=fp(&g_fun);
    f2();

    //绑定到类静态成员函数
    fp f1=fp(&A::A_fun_static);
    f1();

    A().init();
    A().init2();
    return 0;
}
