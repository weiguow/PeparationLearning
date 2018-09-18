/*
 * 作者：cooooooooooooooool
 * 编写日期：18-9-13
 * 功能描述：queue用法
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
     * 创建：默认创建：queue<int> q1;
     * 拷贝创建：queue<int> q2(ano);
     */
    queue<int> my_queue;
    queue<int> my_queue_1(my_queue);

    /*
     * 插入：void push()
     */
    for(int i = 0; i < 10; i++)
        my_queue.push(i);

    /*
     * 访问但不删除队首元素：DT front();
     */
    cout << my_queue.front() << endl;  /* 0 */

    /*
     * 删除但不访问队首元素：void pop();
     */
    my_queue.pop();
    cout << my_queue.front() << endl;  /* 1 */

    /*
     * 判断是否为空：bool empty();
     */
    cout << my_queue.empty() << " " << my_queue_1.empty() << endl;  /* 0 1 */

    /*
     * 队列中元素的个数：int size()
     */
    cout << my_queue.size() << endl;  /* 9 */
    return 0;
}