#include <iostream>
#include "UnionFindTestHelper.h"

using namespace std;


// 对比UF1, UF2和UF3的时间性能
int main() {

    // 使用10000的数据规模
    int n = 10000;

    // 虽然isConnected只需要O(1)的时间, 但由于union操作需要O(n)的时间
    // 总体测试过程的算法复杂度是O(n^2)的
    UnionFindTestHelper::testUF1(n);

    // 对于UF2来说, 其时间性能是O(n*h)的, h为并查集表达的树的最大高度
    // 这里严格来讲, h和logn没有关系, 不过大家可以简单这么理解
    // 我们后续内容会对h进行优化, 总体而言, 这个h是远小于n的
    // 所以我们实现的UF2测试结果远远好于UF1, n越大越明显:)
    UnionFindTestHelper::testUF2(n);

    // 对于UF3来说, 其时间性能依然是O(n*h)的, h为并查集表达的树的最大高度
    // 但由于UF3能更高概率的保证树的平衡, 所以性能更优
    UnionFindTestHelper::testUF3(n);

    return 0;
}