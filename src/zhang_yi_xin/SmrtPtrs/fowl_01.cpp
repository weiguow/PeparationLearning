#include <iostream>
#include <string>
#include <memory>
using namespace std;
/*用shared_ptr代替auto_ptr*/
int main() {
    shared_ptr<string> films[5] =
            {
                    auto_ptr<string> (new string("Fowl Balls")),
                    auto_ptr<string> (new string("Duck Walks")),
                    auto_ptr<string> (new string("Chicken Runs")),
                    auto_ptr<string> (new string("Turkey Errors")),
                    auto_ptr<string> (new string("Goose Eggs"))
            };
    shared_ptr<string> pwin;
    pwin = films[2]; /*shared_ptr采用引用计数，pwin和films[2]都指向同一块内存,(同一个对象),引用计数器1增加到2.
                      *在程序末尾,后声明的pwin首先调用析构函数,该函数引用计数降低到1,然后shared_ptr数组的成员被释放
                      * 对films[2]调用析构函数,将引用计数降低到0,并释放以前分配的空间
                      * 即在释放空间时因为事先要判断引用计数值的大小因此不会出现多次删除一个对象的错误*/
    cout << "The nominees for best avian baseballl film are\n";
    for(int i = 0; i < 5; ++i)
        cout << *films[i] << endl;
    cout << "The winner is " << *pwin << endl;
    cin.get();

    return 0;
}

/*
 * The nominees for best avian baseballl film are
   Fowl Balls
   Duck Walks
   Chicken Runs
   Turkey Errors
   Goose Eggs
   The winner is Chicken Runs
*/
/*使用unique_ptr时编译出错，与auto_ptr一样，unique_ptr也采用所有权模型，但在使用unique_ptr时，程序不会等到运行阶段崩溃，而在编译器因下述代码行出现错误。*/