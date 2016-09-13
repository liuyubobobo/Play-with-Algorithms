//
// Created by liuyubobobo on 9/11/16.
//

#ifndef GRAPH_PATH_H
#define GRAPH_PATH_H


#include <vector>
#include <stack>
#include <iostream>
#include <cassert>

using namespace std;


template <typename Graph>
class Path{

private:
    Graph &G;
    int n;
    int v, w;
    bool* visited;
    int *from;
    bool hasFoundPath;

    bool dfs(int v, int w){

        if( v == w )
            return true;

        visited[v] = true;
        typename Graph::adjIterator adj(G,v);
        for( int i = adj.begin() ; !adj.end() ; i = adj.next() )
            if( !visited[i] ){
                from[i] = v;
                if( dfs(i, w) )
                    return true;
            }

        return false;
    }

public:
    Path(Graph &graph, int v, int w):G(graph){

        n = graph.V();
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        visited = new bool[n];
        from = new int[n];
        for( int i = 0 ; i < n ; i ++ ){
            visited[i] = false;
            from[i] = -1;
        }
        this->v = v;
        this->w = w;

        hasFoundPath = dfs(v, w);
    }

    ~Path(){

        delete [] visited;
        delete [] from;
    }

    bool hasPath(){
        return hasFoundPath;
    }

    void path(vector<int> &vec){

        stack<int> inversePath;

        int p = w;
        while( p != -1 ){
            inversePath.push(p);
            p = from[p];
        }

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

#endif //GRAPH_PATH_H
