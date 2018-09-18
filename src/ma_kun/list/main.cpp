/*
 * 作者：cooooooooooooooool
 * 编写日期：18-9-13
 * 功能描述：list常用方法
 */
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    list<int> my_list;
    cout << "size = " << my_list.size() << endl;  /* 0 */

    my_list.push_back(0);
    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(3);
    my_list.push_back(4);
    cout << "size = " << my_list.size() << endl;  /* 5 */
    for(list<int>::iterator ite = my_list.begin() ; ite != my_list.end() ; ite++)
        cout << *ite << "  ";
    cout << endl;  /* 0 1 2 3 4 */

    list<int>::iterator ite = find(my_list.begin() , my_list.end() , 3);
    if(*ite != 0)
        my_list.insert(ite , 99);

    cout << "size = " << my_list.size() << endl;  /* 6 */
    cout << *ite << endl;  /* 3 */

    for(list<int>::iterator ite = my_list.begin() ; ite != my_list.end() ; ite++)
        cout << *ite << "  ";
    cout << endl;  /* 0 1 2 99 3 4 */

    ite = find(my_list.begin() , my_list.end() , 1);
    if(*ite != 0)
        cout << *(my_list.erase(ite)) << endl;  /* 2 */

    for(list<int>::iterator ite = my_list.begin() ; ite != my_list.end() ; ite++)
        cout << *ite << "  ";
    cout << endl;  /* 0 2 99 3 4 */

    int iv[5] = {5 , 6 , 7 , 8 , 9};
    list<int> my_list_1(iv , iv + 5);

    ite = find(my_list.begin() , my_list.end() , 99);
    my_list.splice(ite , my_list_1);
    for(list<int>::iterator ite = my_list.begin() ; ite != my_list.end() ; ite++)
        cout << *ite << "  ";
    cout << endl;  /* 0 2 5 6 7 8 9 99 3 4 */

    my_list.reverse();
    for(list<int>::iterator ite = my_list.begin() ; ite != my_list.end() ; ite++)
        cout << *ite << "  ";
    cout << endl;  /* 4 3 99 9 8 7 6 5 2 0 */

    my_list.sort();
    for(list<int>::iterator ite = my_list.begin() ; ite != my_list.end() ; ite++)
        cout << *ite << "  ";
    cout << endl;  /* 0 2 3 4 5 6 7 8 9 99 */
    return 0;
}