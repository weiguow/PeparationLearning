/*
 * 版权所有:深圳先进研究所异构智能计算体系结构与系统研究中心
 * 作者:王卫国
 * 编写日期:2018/9/10
 * 功能描述:gTest的使用
 */

#include <iostream>
#include "./googletest/include/gtest/gtest.h"

using namespace std;

int add(int a, int b) {
    return a + b;
}

TEST(Test1, TestError) {
    EXPECT_EQ(4, add(2, 3));
}

TEST(Test2, TestTrue) {
    EXPECT_EQ(4, add(2, 2));
}


GTEST_API_ int main(int argc, char **argv) {
    cout << "hello,world!" << endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
