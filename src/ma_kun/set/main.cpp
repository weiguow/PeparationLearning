/*
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：展示set存储结构
 */
#include<iostream>
#include<set>

using namespace std;

int main() {
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(2);
    s.insert(4);
    s.insert(3);

    cout << "set 的 size 值为 ：" << s.size() << endl;
    cout << "set 的 maxsize的值为 ：" << s.max_size() << endl;
    cout << "set 中的第一个元素是 ：" << *s.begin() << endl;
    cout << "set 中的最后一个元素是:" << *s.end() << endl;

    /*中序遍历 升序遍历*/
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (set<int>::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    s.clear();
    if (s.empty()) {
        cout << "set 为空 ！！！" << endl;
    }
    cout << "set 的 size 值为 ：" << s.size() << endl;
    cout << "set 的 maxsize的值为 ：" << s.max_size() << endl;

    return 0;
}