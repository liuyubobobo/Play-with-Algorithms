//
// Created by liuyubobobo on 9/11/16.
//

#ifndef GRAPH_SHORTESTPATH_H
#define GRAPH_SHORTESTPATH_H


#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <cassert>

using namespace std;


template <typename Graph>
class ShortestPath{

private:
    Graph &G;
    int n;
    int v, w;
    bool* visited;
    int *from;
    int *ord;

public:
    ShortestPath(Graph &graph, int v, int w):G(graph){

        n = graph.V();
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        visited = new bool[n];
        from = new int[n];
        ord = new int[n];
        for( int i = 0 ; i < n ; i ++ ){
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }
        this->v = v;
        this->w = w;


        queue<int> q;
        q.push( v );
        visited[v] = true;
        ord[v] = 0;
        while( !q.empty() ){
            int p = q.front();
            q.pop();

            if( p == w )
                break;

            typename Graph::adjIterator adj(G,p);
            for( int i = adj.begin() ; !adj.end() ; i = adj.next() )
                if( !visited[p] ){
                    visited[p] = true;
                    from[i] = p;
                    ord[i] = ord[p] + 1;
                }
        }
    }

    ~ShortestPath(){

        delete [] visited;
        delete [] from;
        delete [] ord;
    }

    bool hasPath(){
        return visited[w];
    }

    int length(){
        return ord[w];
    }

    void path(vector<int> &vec){

        stack<int> inversePath;

        int p = w;
        while( p != -1 ){
            inversePath.push(p);
            p = from[p];
        }
        inversePath.push(v);

        vec.clear();
        while( !inversePath.empty() ){
            vec.push_back( inversePath.top() );
            inversePath.pop();
        }
    }

    void showPath(){

        vector<int> vec;
        path(vec);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i];
            if( i == vec.size()-1 )
                cout<<endl;
            else
                cout<<" -> ";
        }
    }
};

#endif //GRAPH_SHORTESTPATH_H
