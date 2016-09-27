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
    vector<Edge<Weight>*> from;
    bool hasNegativeCycle;


    bool detectNegativeCycle(){

        for( int i = 0 ; i < G.V() ; i ++ ){
            typename Graph::adjIterator adj(G,i);
            for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() )
                if( !from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()] )
                    return true;
        }

        return false;
    }

public:
    BellmanFord(Graph &graph, int s):G(graph){

        this->s = s;
        distTo = new Weight[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            from.push_back(NULL);
        }

        from[s] = new Edge<Weight>(s,s,Weight());
        distTo[s] = Weight();

        for( int pass = 1 ; pass < G.V() ; pass ++ ){
            //cout<<"pass "<<pass<<endl;
            for( int i = 0 ; i < G.V() ; i ++ ){
                typename Graph::adjIterator adj(G,i);
                for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() )
                    if( !from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()] ){
                        distTo[e->w()] = distTo[e->v()] + e->wt();
                        from[e->w()] = e;
                    }
                //cout<<i<<":"<<distTo[i]<<" ";
            }
            //cout<<endl;
        }

        hasNegativeCycle = detectNegativeCycle();
        //cout<<"hasNegativeCycle : "<<hasNegativeCycle<<endl;
    }

    ~BellmanFord(){

        delete[] distTo;
        delete from[s];
    }

    bool negativeCycle(){
        return hasNegativeCycle;
    }

    Weight shortestPathTo( int w ){
        assert( w >= 0 && w < G.V() );
        assert( !hasNegativeCycle );
        return distTo[w];
    }

    bool hasPathTo( int w ){
        assert( w >= 0 && w < G.V() );
        return from[w] != NULL;
    }

    void shortestPath( int w, vector<Edge<Weight>> &vec ){

        assert( w >= 0 && w < G.V() );
        assert( !hasNegativeCycle );

        stack<Edge<Weight>*> s;
        Edge<Weight> *e = from[w];
        while( e->v() != e->w() ){
            cout<<*e<<endl;
            s.push(e);
            e = from[e->v()];
        }

        while( !s.empty() ){
            e = s.top();
            vec.push_back( *e );
            s.pop();
        }
        cout<<"get shortest path to "<<w<<endl;
    }

    void showPath(int w){

        assert( w >= 0 && w < G.V() );
        assert( !hasNegativeCycle );

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i].v()<<" -> ";
            if( i == vec.size()-1 )
                cout<<vec[i].w()<<endl;
        }
    }
};

#endif //SHORTESTPATH_BELLMANFORD_H
