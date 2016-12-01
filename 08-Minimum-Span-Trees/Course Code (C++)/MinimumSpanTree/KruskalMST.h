//
// Created by liuyubobobo on 9/14/16.
//

#ifndef MINIMUMSPANTREE_KRUSKALMST_H
#define MINIMUMSPANTREE_KRUSKALMST_H

#include <iostream>
#include <vector>
#include "MinHeap.h"
#include "UF.h"
#include "Edge.h"

using namespace std;


template <typename Graph, typename Weight>
class KruskalMST{

private:
    vector<Edge<Weight>> mst;
    Weight mstWeight;

public:
    KruskalMST(Graph &graph){

        MinHeap<Edge<Weight>> pq( graph.E() );
        for( int i = 0 ; i < graph.V() ; i ++ ){
            typename Graph::adjIterator adj(graph,i);
            for( Edge<Weight> *e = adj.begin() ; !adj.end() ; e = adj.next() )
                if( e->v() < e->w() )
                    pq.insert(*e);
        }

        UnionFind uf = UnionFind(graph.V());
        while( !pq.isEmpty() && mst.size() < graph.V() - 1 ){

            Edge<Weight> e = pq.extractMin();
            if( uf.isConnected( e.v() , e.w() ) )
                continue;

            mst.push_back( e );
            uf.unionElements( e.v() , e.w() );
        }

        mstWeight = mst[0].wt();
        for( int i = 1 ; i < mst.size() ; i ++ )
            mstWeight += mst[i].wt();
    }

    ~KruskalMST(){

    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    };

    Weight result(){
        return mstWeight;
    };
};

#endif //MINIMUMSPANTREE_KRUSKALMST_H
