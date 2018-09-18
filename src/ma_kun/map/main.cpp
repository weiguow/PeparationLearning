/*
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：向map中插入数据及删除
 */
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<int, string> student;
    map<int, string>::iterator iter;
    /*向map中插入数据*/
    student.insert(pair<int, string>(101, "Mike"));
    student.insert(pair<int, string>(101, "MIKE"));  /*重复插入*/
    student.insert(map<int, string>::value_type(102, "Sam"));
    student.insert(map<int, string>::value_type(102, "SAM"));  /*重复插入*/
    student[103] = "Jake";
    student[103] = "JAKE";  /*重复插入*/

    /*为了测试删除，先插入两个数据,看插入结果主要看上面的插入方式*/
    student[104] = "Bob";
    student[105] = "Ben";

    cout << "完成插入后map中的数据：" << endl;
    for (iter = student.begin(); iter != student.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }

    /*从map中删除数据*/
    iter = student.begin();
    student.erase(iter);
    cout << "利用迭代器删除map中第一个元素：" << endl;
    for (iter = student.begin(); iter != student.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    student.erase(102);
    cout << "利用键值删除map中的第一个元素：" << endl;
    for (iter = student.begin(); iter != student.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    student.erase(student.begin(), student.end());
    cout << "利用范围迭代器删除map中的所有数据:" << endl;
    for (iter = student.begin(); iter != student.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}