//
// Created by liuyubobobo on 9/2/16.
//

#ifndef INC_05_OPTIMIZE_BY_RANK_UNIONFIND3_H
#define INC_05_OPTIMIZE_BY_RANK_UNIONFIND3_H

#include <cassert>

using namespace std;


namespace UF3{

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

        int find(int p){
            assert( p >= 0 && p < count );
            while( p != parent[p] )
                p = parent[p];
            return p;
        }

        bool isConnected( int p , int q ){
            return find(p) == find(q);
        }

        void unionElements(int p, int q){

            int pRoot = find(p);
            int qRoot = find(q);

            if( pRoot == qRoot )
                return;

            if( rank[pRoot] < rank[qRoot] ){
                parent[pRoot] = qRoot;
            }
            else if( rank[qRoot] < rank[pRoot]){
                parent[qRoot] = pRoot;
            }
            else{ // rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;
            }
        }
    };
}

#endif //INC_05_OPTIMIZE_BY_RANK_UNIONFIND3_H
