//
// Created by liuyubobobo on 9/2/16.
//

#ifndef INC_04_OPTIMIZE_BY_SIZE_UNIONFIND3_H
#define INC_04_OPTIMIZE_BY_SIZE_UNIONFIND3_H

#include <cassert>

using namespace std;

// 我们的第三版Union-Find
namespace UF3{

    class UnionFind{

    private:
        int* parent; // parent[i]表示第i个元素所指向的父节点
        int* sz;     // sz[i]表示以i为根的集合中元素个数
        int count;   // 数据个数

    public:
        // 构造函数
        UnionFind(int count){
            parent = new int[count];
            sz = new int[count];
            this->count = count;
            for( int i = 0 ; i < count ; i ++ ){
                parent[i] = i;
                sz[i] = 1;
            }
        }

        // 析构函数
        ~UnionFind(){
            delete[] parent;
            delete[] sz;
        }

        // 查找过程, 查找元素p所对应的集合编号
        // O(h)复杂度, h为树的高度
        int find(int p){
            assert( p >= 0 && p < count );
            // 不断去查询自己的父亲节点, 直到到达根节点
            // 根节点的特点: parent[p] == p
            while( p != parent[p] )
                p = parent[p];
            return p;
        }

        // 查看元素p和元素q是否所属一个集合
        // O(h)复杂度, h为树的高度
        bool isConnected( int p , int q ){
            return find(p) == find(q);
        }

        // 合并元素p和元素q所属的集合
        // O(h)复杂度, h为树的高度
        void unionElements(int p, int q){

            int pRoot = find(p);
            int qRoot = find(q);

            if( pRoot == qRoot )
                return;

            // 根据两个元素所在树的元素个数不同判断合并方向
            // 将元素个数少的集合合并到元素个数多的集合上
            if( sz[pRoot] < sz[qRoot] ){
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            }
            else{
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
        }
    };
}

#endif //INC_04_OPTIMIZE_BY_SIZE_UNIONFIND3_H
