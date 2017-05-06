//
// Created by liuyubobobo on 5/5/17.
//

#ifndef INC_06_PATH_COMPRESSION_UNIONFINDTESTHELPER_H
#define INC_06_PATH_COMPRESSION_UNIONFINDTESTHELPER_H

#include <iostream>
#include <ctime>
#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"
#include "UnionFind5.h"

using namespace std;

// 测试并查集的辅助函数
namespace UnionFindTestHelper{

    // 测试第一版本的并查集, 测试元素个数为n
    void testUF1( int n ){

        srand( time(NULL) );
        UF1::UnionFind uf = UF1::UnionFind(n);

        time_t startTime = clock();

        // 进行n次操作, 每次随机选择两个元素进行合并操作
        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        // 再进行n次操作, 每次随机选择两个元素, 查询他们是否同属一个集合
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();

        // 打印输出对这2n个操作的耗时
        cout<<"UF1, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }

    // 测试第二版本的并查集, 测试元素个数为n, 测试逻辑和之前是完全一样的
    // 思考一下: 这样的冗余代码如何消除?
    // 由于这个课程不是设计模式课程, 在这里就不过多引入相关的问题讲解了。留作给大家的思考题:)
    void testUF2( int n ){

        srand( time(NULL) );
        UF2::UnionFind uf = UF2::UnionFind(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();

        cout<<"UF2, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }

    // 测试第三版本的并查集, 测试元素个数为n
    void testUF3( int n ){

        srand( time(NULL) );
        UF3::UnionFind uf = UF3::UnionFind(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();

        cout<<"UF3, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }

    // 测试第四版本的并查集, 测试元素个数为n
    void testUF4( int n ){

        srand( time(NULL) );
        UF4::UnionFind uf = UF4::UnionFind(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();

        cout<<"UF4, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }

    // 测试第五版本的并查集, 测试元素个数为n
    void testUF5( int n ){

        srand( time(NULL) );
        UF5::UnionFind uf = UF5::UnionFind(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();

        cout<<"UF5, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }
}

#endif //INC_06_PATH_COMPRESSION_UNIONFINDTESTHELPER_H
