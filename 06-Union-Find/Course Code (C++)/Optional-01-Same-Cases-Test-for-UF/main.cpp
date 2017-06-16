#include <iostream>
#include <vector>
#include "UnionFindTestHelper.h"

using namespace std;

// 对比UF1, UF2, UF3, UF4, UF5和UF6的时间性能
// 在这里, 我们对于不同的UnionFind的实现, 使用相同的测试用例, 让测试结果更加准确
int main() {

    // 使用5,000,000的数据规模
    int n = 5000000;

    srand( time(NULL) );

    // 生成unionElements的测试用例
    vector<pair<int,int>> unionTest;
    for(int i = 0 ; i < n ; i ++){
        int a = rand()%n;
        int b = rand()%n;
        unionTest.push_back(make_pair(a,b));
    }

    // 生成isConnected的测试用例
    vector<pair<int,int>> connectTest;
    for(int i = 0 ; i < n ; i ++){
        int a = rand()%n;
        int b = rand()%n;
        connectTest.push_back(make_pair(a,b));
    }

    // 测试我们的UF1 ~ UF6

    // 100万数据对于UF1和UF2来说太慢了, 不再测试
//    UF1::UnionFind uf1 = UF1::UnionFind(n);
//    UnionFindTestHelper::testUF("UF1", uf1, unionTest, connectTest);
//
//    UF2::UnionFind uf2 = UF2::UnionFind(n);
//    UnionFindTestHelper::testUF("UF2", uf2, unionTest, connectTest);

    UF3::UnionFind uf3 = UF3::UnionFind(n);
    UnionFindTestHelper::testUF("UF3", uf3, unionTest, connectTest);

    UF4::UnionFind uf4 = UF4::UnionFind(n);
    UnionFindTestHelper::testUF("UF4", uf4, unionTest, connectTest);

    UF5::UnionFind uf5 = UF5::UnionFind(n);
    UnionFindTestHelper::testUF("UF5", uf5, unionTest, connectTest);

    UF6::UnionFind uf6 = UF6::UnionFind(n);
    UnionFindTestHelper::testUF("UF6", uf6, unionTest, connectTest);

    return 0;
}