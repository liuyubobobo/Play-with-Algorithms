//
// Created by liuyubobobo on 9/28/16.
//

#ifndef INC_03_IMPLEMENTATION_OF_DIJKSTRA_DIJKSTRA_H
#define INC_03_IMPLEMENTATION_OF_DIJKSTRA_DIJKSTRA_H

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
    bool *marked;
    vector<Edge<Weight>*> from;

public:
    Dijkstra(Graph &graph, int s):G(graph){

        this->s = s;
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            distTo[i] = Weight();
            marked[i] = false;
            from.push_back(NULL);
        }

        IndexMinHeap<Weight> ipq(G.V());

        // start dijkstra
        distTo[s] = Weight();
        ipq.insert(s, distTo[s] );
        marked[s] = true;
        while( !ipq.isEmpty() ){
            int v = ipq.extractMinIndex();

            // distTo[v]就是s到v的最短距离
            marked[v] = true;
            //cout<<v<<endl;
            typename Graph::adjIterator adj(G, v);
            for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() ){
                int w = e->other(v);
                if( !marked[w] ){
                    if( from[w] == NULL || distTo[v] + e->wt() < distTo[w] ){
                        distTo[w] = distTo[v] + e->wt();
                        from[w] = e;
                        if( ipq.contain(w) )
                            ipq.change(w, distTo[w] );
                        else
                            ipq.insert(w, distTo[w] );
                    }
                }
            }
        }
    }

    ~Dijkstra(){
        delete[] distTo;
        delete[] marked;
    }

    Weight shortestPathTo( int w ){
        assert( w >= 0 && w < G.V() );
        return distTo[w];
    }

    bool hasPathTo( int w ){
        assert( w >= 0 && w < G.V() );
        return marked[w];
    }

    void shortestPath( int w, vector<Edge<Weight>> &vec ){

        assert( w >= 0 && w < G.V() );

        stack<Edge<Weight>*> s;
        Edge<Weight> *e = from[w];
        while( e->v() != this->s ){
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);

        while( !s.empty() ){
            e = s.top();
            vec.push_back( *e );
            s.pop();
        }
    }

    void showPath(int w){

        assert( w >= 0 && w < G.V() );

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i].v()<<" -> ";
            if( i == vec.size()-1 )
                cout<<vec[i].w()<<endl;
        }
    }
};

#endif //INC_03_IMPLEMENTATION_OF_DIJKSTRA_DIJKSTRA_H
