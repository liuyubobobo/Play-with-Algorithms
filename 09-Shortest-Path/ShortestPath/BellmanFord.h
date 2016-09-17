//
// Created by liuyubobobo on 9/16/16.
//

#ifndef SHORTESTPATH_BELLMANFORD_H
#define SHORTESTPATH_BELLMANFORD_H

#include <stack>
#include <vector>
#include "Edge.h"

using namespace std;


template <typename Graph, typename Weight>
class BellmanFord{

private:
    Graph &G;
    int s;
    Weight* distTo;
    Edge** edgeTo;

    bool hasNegativeCycle;

    bool detectNegativeCycle(){

        for( int i = 0 ; i < G.V() ; i ++ ){
            typename Graph::adjIterator adj;
            for( Edge* e = adj.begin() ; !adj.end() ; e = adj.next() )
                if( edgeTo[e->v()] && edgeTo[e->w()] && distTo[e->v()] + e->wt() < distTo[e->w()] )
                    return true;
        }

        return false;
    }

public:
    BellmanFord(Graph &graph, int s):G(graph){

        this->s = s;
        distTo = new Weight[graph.V()];
        edgeTo = new Edge<Weight>*[graph.V()];
        for( int i = 0 ; i < graph.V() ; i ++ )
            edgeTo[i] = NULL;

        edgeTo[s] = new Edge<Weight>(s,s,Weight());
        distTo[s] = Weight();

        for( int pass = 1 ; pass < graph.V() ; pass ++ )
            for( int i = 0 ; i < graph.V() ; i ++ ){
                typename Graph::adjIterator adj;
                for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() )
                    if( edgeTo[e->v()] && edgeTo[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()] ){
                        distTo[e->w()] = distTo[e->v()] + e->wt();
                        edgeTo[e->w()] = e;
                    }
            }

        hasNegativeCycle = detectNegativeCycle();

    }

    ~BellmanFord(){

        delete distTo;
        delete edgeTo[s];
        delete edgeTo;
    }

    Weight shortestPathTo( int w ){
        return distTo[w];
    }

    bool hasPathTo( int w ){
        return edgeTo[w] != NULL;
    }

    void shortedtPath( int w, vector<Edge<Weight>> &vec ){

        stack<Edge<Weight>*> s;
        Edge *e = edgeTo[w];
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
#endif //SHORTESTPATH_BELLMANFORD_H
