//
// Created by liuyubobobo on 8/31/16.
//

#ifndef UNIONFIND_UNIONFIND_H
#define UNIONFIND_UNIONFIND_H

#include <cassert>

using namespace std;


// Quick Find
namespace UF1{

    class UnionFind{

    private:
        int* id;
        int count;

    public:
        UnionFind(int count){
            id = new int[count];
            this->count = count;
            for( int i = 0 ; i < count ; i ++ )
                id[i] = i;
        }

        ~UnionFind(){
            delete[] id;
        }

        int size(){
            return count;
        }

        bool isConnected( int p , int q ){
            return id[p] == id[q];
        }

        int find(int p){
            assert( p >= 0 && p < count);
            return id[p];
        }

        void unionElements(int p, int q){

            int pID = find(p);
            int qID = find(q);

            if( pID == qID )
                return;

            for( int i = 0 ; i < count ; i ++ )
                if( id[i] == pID )
                    id[i] = qID;
        }
    };
}
#endif //UNIONFIND_UNIONFIND_H
