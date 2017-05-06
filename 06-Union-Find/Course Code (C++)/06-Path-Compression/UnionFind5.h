//
// Created by liuyubobobo on 5/5/17.
//

#ifndef INC_06_PATH_COMPRESSION_UNIONFIND5_H
#define INC_06_PATH_COMPRESSION_UNIONFIND5_H

#include <cassert>

using namespace std;

// 我们的第五版Union-Find
namespace UF5{

    class UnionFind{

    private:
        // rank[i]表示以i为根的集合所表示的树的层数
        // 在后续的代码中, 我们并不会维护rank的语意, 也就是rank的值在路径压缩的过程中, 有可能不在是树的层数值
        // 这也是我们的rank不叫height或者depth的原因, 他只是作为比较的一个标准
        // 关于这个问题，可以参考问答区：http://coding.imooc.com/learn/questiondetail/7287.html
        int* rank;
        int* parent; // parent[i]表示第i个元素所指向的父节点
        int count;   // 数据个数

    public:
        // 构造函数
        UnionFind(int count){
            parent = new int[count];
            rank = new int[count];
            this->count = count;
            for( int i = 0 ; i < count ; i ++ ){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        // 析构函数
        ~UnionFind(){
            delete[] parent;
            delete[] rank;
        }

        // 查找过程, 查找元素p所对应的集合编号
        // O(h)复杂度, h为树的高度
        int find(int p){
            assert( p >= 0 && p < count );

            // path compression 1
            while( p != parent[p] ){
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;

            // path compression 2, 递归算法
//            if( p != parent[p] )
//                parent[p] = find( parent[p] );
//            return parent[p];
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
            if( rank[pRoot] < rank[qRoot] ){
                parent[pRoot] = qRoot;
            }
            else if( rank[qRoot] < rank[pRoot]){
                parent[qRoot] = pRoot;
            }
            else{ // rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;   // 此时, 我维护rank的值
            }
        }
    };
}

#endif //INC_06_PATH_COMPRESSION_UNIONFIND5_H
