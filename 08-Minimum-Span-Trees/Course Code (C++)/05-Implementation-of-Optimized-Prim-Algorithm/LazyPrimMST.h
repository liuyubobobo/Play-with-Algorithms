//
// Created by liuyubobobo on 9/26/16.
//

#ifndef INC_05_IMPLEMENTATION_OF_OPTIMIZED_PRIM_ALGORITHM_LAZYPRIMMST_H
#define INC_05_IMPLEMENTATION_OF_OPTIMIZED_PRIM_ALGORITHM_LAZYPRIMMST_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "MinHeap.h"

using namespace std;


template<typename Graph, typename Weight>
class LazyPrimMST{

private:
    Graph &G;
    vector<Edge<Weight>> mst;

    bool* marked;
    MinHeap<Edge<Weight>> pq;
    Weight mstWeight;


    void visit(int v){
        assert( !marked[v] );
        marked[v] = true;

        typename Graph::adjIterator adj(G,v);
        for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() )
            if( !marked[e->other(v)] )
                pq.insert(*e);

    }
public:
    // 保证图是连通无向有权图
    LazyPrimMST(Graph &graph):G(graph), pq(MinHeap<Edge<Weight>>(graph.E())){

        marked = new bool[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ )
            marked[i] = false;
        mst.clear();

        visit(0);
        while( !pq.isEmpty() ){
            Edge<Weight> e = pq.extractMin();
            if( marked[e.v()] && marked[e.w()] )
                continue;

            mst.push_back(e);
            if( !marked[e.v()] )
                visit(e.v());
            if( !marked[e.w()] )
                visit(e.w());
        }

        mstWeight = mst[0].wt();
        for( int i = 1 ; i < mst.size() ; i ++ )
            mstWeight += mst[i].wt();
    }

    ~LazyPrimMST(){
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    };

    Weight result(){
        return mstWeight;
    };
};

#endif //INC_05_IMPLEMENTATION_OF_OPTIMIZED_PRIM_ALGORITHM_LAZYPRIMMST_H
