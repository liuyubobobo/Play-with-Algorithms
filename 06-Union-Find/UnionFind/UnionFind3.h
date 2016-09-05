//
// Created by liuyubobobo on 8/31/16.
//

#ifndef UNIONFIND_UNIONFIND3_H
#define UNIONFIND_UNIONFIND3_H

#include <cassert>

using namespace std;


// Quick Union + sz
namespace UF3{

    class UnionFind{

    private:
        int* parent;
        int* sz; // sz[i]表示以i为根的集合中元素个数
        int count;

    public:
        UnionFind(int count){
            parent = new int[count];
            sz = new int[count];
            this->count = count;
            for( int i = 0 ; i < count ; i ++ ){
                parent[i] = i;
                sz[i] = 1;
            }
        }

        ~UnionFind(){
            delete[] parent;
            delete[] sz;
        }

        int size(){
            return count;
        }

        bool isConnected( int p , int q ){
            return find(p) == find(q);
        }

        int find(int p){
            assert( p >= 0 && p < count );
            while( p != parent[p] )
                p = parent[p];
            return p;
        }

        void unionElements(int p, int q){

            int pRoot = find(p);
            int qRoot = find(q);

            if( pRoot == qRoot )
                return;

            if( sz[pRoot] < sz[qRoot] ){
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            }
            else{   // sz[pRoot] >= sz[qRoot]
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
        }
    };
}

#endif //UNIONFIND_UNIONFIND3_H
