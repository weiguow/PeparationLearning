#include <vector>
#include <algorithm>
using namespace std;

extern vector<int> nums;

void OneCond(int val){
    // 传统的for循环
    for (auto i = nums.begin(); i != nums.end(); i++)
        if (*i == val) break;

    // 内置的functor(template) equal_to, 通过bind2nd使其成为单参数调用的functor
    find_if(nums.begin(), nums.end(), bind2nd(equal_to<int>(), val));
    //bind2nd定义了一个功能是比较i==val的仿函数，并通过一定方式（bind2nd)使其函数调用接口只需要一个参数即可

    // 使用lambda函数，其意义简洁明了，使用者使用的时候，也不需要有太多的背景知识。
    find_if(nums.begin(), nums.end(), [=](int i) {
        return i == val;
    });
}

