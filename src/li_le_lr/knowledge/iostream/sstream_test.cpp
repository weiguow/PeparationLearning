#include <iostream>
#include <cstring>
#include <strstream>
#include <sstream>
#include <fstream>

using namespace std;

void test_istrstream(){
    char *name = "www.cppblog.com/andxie99";
    int arraysize = strlen(name)+1;
    istrstream is(name,arraysize);
    char temp;
    is>>temp;
//    int n;
//    cin>>n;
    cout<<temp;
    system("pause");
}

void test_ostrstream(){
    int arraysize=1;
    char *pbuffer=new char[arraysize];
    ostrstream ostr(pbuffer,arraysize,ios::out);
    ostr<<arraysize<<ends;//使用ostrstream输出到流对象的时候,要用ends结束字符串
    cout<<pbuffer;
    delete[] pbuffer;
    system("pause");
}

void test_stringstream(){
    stringstream ostr("ccc");
    ostr.put('d');
    ostr.put('e');
    ostr<<"fg";
    string gstr = ostr.str();
    cout<<gstr<<endl;

    char a;
    ostr>>a;
    cout<<a;

    system("pause");
}

void test_state(){
    int a;
    cin>>a;
    cout<<cin.rdstate()<<endl;
    if(cin.rdstate() == ios::goodbit)
    {
        cout<<"输入数据的类型正确，无错误！"<<endl;
    }
    if(cin.rdstate() == ios_base::failbit)
    {
        cout<<"输入数据类型错误，非致命错误，可清除输入缓冲区挽回！"<<endl;
    }
    system("pause");
}

void test_read_a_file(){
    ifstream myfile("/home/lilelr/open-source/PeparationLearning/src/li_le_lr/knowledge/iostream/code.txt",ios_base::in);
    if(myfile.fail())
    {
        cout<<"文件读取失败或指定文件不存在!"<<endl;
    }
    else
    {
        char ch;
        while(myfile.get(ch))
        {
            cout<<ch;
            cout.flush();
        }
        if(myfile.eof())
        {
            cout<<"文件内容已经全部读完"<<endl;
        }
        while(myfile.get(ch))
        {
            cout<<ch;
        }
    }
    system("pause");
}
int main()
{
    test_istrstream();
//   test_stringstream();
//    test_state();
//    test_read_a_file();
}