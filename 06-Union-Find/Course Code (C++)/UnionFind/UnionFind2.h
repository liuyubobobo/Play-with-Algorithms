//
// Created by liuyubobobo on 8/31/16.
//

#ifndef UNIONFIND_UNIONFIND2_H
#define UNIONFIND_UNIONFIND2_H

#include <cassert>

using namespace std;


// Quick Union
namespace UF2{

    class UnionFind{

    private:
        int* parent;
        int count;

    public:
        UnionFind(int count){
            parent = new int[count];
            this->count = count;
            for( int i = 0 ; i < count ; i ++ )
                parent[i] = i;
        }

        ~UnionFind(){
            delete[] parent;
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

            parent[pRoot] = qRoot;
        }
    };
}

#endif //UNIONFIND_UNIONFIND2_H
