#include <iostream>
#include <string>
#include <memory>
using namespace std;

/*对象的创建和销毁*/
class Report
{
private:
    string str;
public:
    Report(const string s):str(s){    /*对一个string类型变量的常引用,常引用参数就是在函数内不能修改传入的变量的值*/
        cout<<"Object created! \n";
    }
    ~Report(){
        cout<<"Object deleted! \n";   /*当一个类的对象离开作用域时，析构函数将被调用(系统自动调用)。析构函数的名字和类名一样，不过要在前面加上 ~ .
                                       *对一个类来说，只能允许一个析构函数，析构函数不能有参数，并且也没有返回值。
                                       * 析构函数的作用是完成一个清理工作，如释放从堆中分配的内存。*/
    }
    void comment() const{
        cout<<str<<"\n";
    }

};
int main() {  /*每个智能指针都放在一个代码块中,这样离开代码快时,指针将过期*/
    {
        auto_ptr<Report> ps (new Report("using auto_ptr"));
        ps->comment();               /*use -> to invoke a member function*/
    }
    {
        shared_ptr<Report> ps (new Report("using shared_ptr"));
        ps->comment();               /*use -> to invoke a member function*/
    }
    {
        unique_ptr<Report> ps (new Report("using unique_ptr"));
        ps->comment();               /*use -> to invoke a member function*/
    }

    return 0;
}

/*
 * 程序输出:
 * Object created!
 * using auto_ptr!
 * Object deleted!
 * Object created!
 * using shared_ptr
 * Object deleted!
 * Object created!
 * using unique_ptr
 * Object deleted!
 */