//
// Created by liuyubobobo on 8/31/16.
//

#ifndef UNIONFIND_UNIONFIND4_H
#define UNIONFIND_UNIONFIND4_H

#include <cassert>

using namespace std;


// Quick Union + rank
namespace UF4{

    class UnionFind{

    private:
        int* parent;
        int* rank; // rank[i]表示以i为根的集合所表示的树的层数
        int count;

    public:
        UnionFind(int count){
            parent = new int[count];
            rank = new int[count];
            this->count = count;
            for( int i = 0 ; i < count ; i ++ ){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind(){
            delete[] parent;
            delete[] rank;
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

            if( rank[pRoot] < rank[qRoot] )
                parent[pRoot] = qRoot;
            else if( rank[qRoot] < rank[pRoot])
                parent[qRoot] = pRoot;
            else{ // rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] ++;
            }
        }
    };
}

#endif //UNIONFIND_UNIONFIND4_H
