//
// Created by liuyubobobo on 9/15/16.
//

#ifndef SHORTESTPATH_DIJKSTRA_H
#define SHORTESTPATH_DIJKSTRA_H

#include <iostream>
#include <vector>
#include <stack>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;


template<typename Graph, typename Weight>
class Dijkstra{

private:
    Graph &G;
    int s;
    Weight *distTo;
    Edge<Weight> **edgeTo;

public:
    Dijkstra(Graph &graph, int s):G(graph){

        this->s = s;
        distTo = new Weight[G.V()];
        edgeTo = new Edge*[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ )
            edgeTo[i] = NULL;

        IndexMinHeap<Weight> ipq(G.V());

        // start dijkstra
        edgeTo[s] = new Edge<Weight>(s,s,Weight());
        distTo[s] = Weight();
        ipq.insert(s, distTo[s] );

        while( !ipq.isEmpty() ){
            int v = ipq.extractMinIndex();

            typename Graph::adjIterator adj(G, v);
            for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() ){
                int w = e->other(v);
                if( edgeTo[w] == NULL || distTo[v] + e->wt() < distTo[w] ){
                    distTo[w] = distTo[v] + e->wt();
                    edgeTo[w] = e;
                    if( ipq.contain(w) )
                        ipq.change(w, distTo[w] );
                    else
                        ipq.insert(w, distTo[w] );
                }
            }
        }
    }

    ~Dijkstra(){
        delete[] distTo;
        delete edgeTo[s];
        delete[] edgeTo;
    }

    Weight shortestPathTo( int w ){
        return distTo[w];
    }

    bool hasPathTo( int w ){
        return edgeTo[w] != NULL;
    }

    void shortedtPath( int w, vector<Edge<Weight>> &vec ){

        stack<Edge<Weight>*> s;
        Edge<Weight> *e = edgeTo[w];
        while( e ){
            s.push(e);
            e = edgeTo[e->v()];
        }

        while( !s.empty() ){
            e = s.top();
            vec.push_back( *e );
            s.pop();
        }
    }
};

#endif //SHORTESTPATH_DIJKSTRA_H
