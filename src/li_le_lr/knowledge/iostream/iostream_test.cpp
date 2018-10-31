#include <iostream>
#include <fstream>
using namespace std;
// reference: http://www.tutorialspoint.com/cplusplus/cpp_basic_input_output.htm
int test_iostream_cout()
{
    char str[] = "Hello C++";
    std::cout << "Value of str is : " << str << std::endl;
    std::cout<<"我爱北京天安门"<<std::endl;
    return 0;
}

int test_iostream_cin()
{
    char name[50];

    std::cout << "Please enter your name: ";
    std::cin >> name;
    std::cout << "Your name is: " << name << std::endl;

    return 0;
}

int test_iostream_clog()
{
    char str[] = "Unable to read....";
    std::clog << "Error message : " << str << std::endl;

    return 0;
}

int test_iostream_cerr()
{
    char str[] = "Unable to read....";
    std::cerr << "Error message : " << str << std::endl;

    return 0;
}

// reference: https://msdn.microsoft.com/en-us/library/6xwbdak2(v=vs.80).aspx
static void TestWide()
{
    int i = 0;
    std::wcout << L"Enter a number: ";
    std::wcin >> i;
    std::wcerr << L"test for wcerr" << std::endl;
    std::wclog << L"test for wclog" << std::endl;
}

int test_iostream_w()
{
    int i = 0;
    std::cout << "Enter a number: ";
    std::cin >> i;
    std::cerr << "test for cerr" << std::endl;
    std::clog << "test for clog" << std::endl;

    TestWide();

    return 0;
}

void test_fstream(){
    fstream myfile;
    myfile.open("c:\\1.txt",ios::out|ios::app,0);
    if(!myfile)
    {
        cout<<"文件写错误,文件属性可能为只读!"<<endl;
        system("pause");
        exit(1);
    }
    myfile<<"白纸人生"<<endl<<"网址："<<"www.cppblog.com/andxie99"<<endl;
    myfile.close();

    myfile.open("c:\\1.txt",ios::in,0);
    if(!myfile)
    {
        cout<<"文件读错误,文件可能丢失!"<<endl;
        system("pause");
        exit(1);
    }
    char ch;
    while(myfile.get(ch))
    {
        cout.put(ch);
    }
    myfile.close();
}

int main(){
    test_iostream_cout();
    test_iostream_cin();
    test_iostream_clog();
    test_iostream_cerr();

}
