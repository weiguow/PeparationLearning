#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;
vector<int> largeNums;

const int ubound = 10;

inline void LargeNumsFunc(int i){
    if (i > ubound)
        largeNums.push_back(i);
}
/*分别用了3种方式来遍一个vector nums,找出其中大于ubound的值 并将其写入另外一个vector largeNums中*/
void Above() {
    // 传统的for循环
    for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
        if (*itr >= ubound)
            largeNums.push_back(*itr);
    }

    // 使用函数指针
    for_each(nums.begin(), nums.end(), LargeNumsFunc);

    // 使用lambda函数和算法for_each
    for_each(nums.begin(), nums.end(), [=](int i){
        if (i > ubound)
            largeNums.push_back(i);
    });
}


/*
 * 使用for each算法相较于手写的循环在效率、正确性、可维护性上都具有一定优
势。最典型的，程序员不用关心iterator,或者说循环的细节，只需要设定边界，作用于每个
元素的操作，就可以在近似"一条语句"内完成循环，正如函数指针版本和lambda版本完
成的那样。
*/

