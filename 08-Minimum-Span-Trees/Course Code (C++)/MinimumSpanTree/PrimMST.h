//
// Created by liuyubobobo on 9/13/16.
//

#ifndef MINIMUMSPANTREE_PRIMMST_H
#define MINIMUMSPANTREE_PRIMMST_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;


template<typename Graph, typename Weight>
class PrimMST{

private:
    Graph &G;
    vector<Edge<Weight>> mst;

    bool* marked;
    IndexMinHeap<Weight> ipq;
    vector<Edge<Weight>*> edgeTo;
    Weight mstWeight;


    void visit(int v){
        assert( !marked[v] );
        marked[v] = true;

        typename Graph::adjIterator adj(G,v);
        for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() ){
            int w = e->other(v);
            if( !marked[w] ){
                if( !edgeTo[w] ){
                    edgeTo[w] = e;
                    ipq.insert(w, e->wt());
                }
                else if( e->wt() < edgeTo[w]->wt() ){
                    edgeTo[w] = e;
                    ipq.change(w, e->wt());
                }
            }
        }

    }
public:
    // assume graph is connected
    PrimMST(Graph &graph):G(graph), ipq(IndexMinHeap<double>(graph.V())){

        assert( graph.E() >= 1 );

        marked = new bool[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            marked[i] = false;
            edgeTo.push_back(NULL);
        }
        mst.clear();

        visit(0);
        while( !ipq.isEmpty() ){
            int v = ipq.extractMinIndex();
            assert( edgeTo[v] );
            mst.push_back( *edgeTo[v] );
            visit( v );
        }

        mstWeight = mst[0].wt();
        for( int i = 1 ; i < mst.size() ; i ++ )
            mstWeight += mst[i].wt();
    }

    ~PrimMST(){
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    };

    Weight result(){
        return mstWeight;
    };
};

#endif //MINIMUMSPANTREE_PRIMMST_H
