//
// Created by liuyubobobo on 9/6/16.
//

#ifndef GRAPH_READGRAPH_H
#define GRAPH_READGRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;


template <typename Graph>
class ReadGraph{

public:
    ReadGraph(Graph &graph, const string &filename){

        ifstream file(filename);
        string line;
        int V, E;

        assert(file.is_open());
        //cout<<"open "<<filename<<" successfully."<<endl;

        assert( getline(file,line));
        stringstream ss(line);
        ss>>V>>E;
        assert( graph.V() == V );
        //cout<<"V = "<<V<<" , E = "<<E<<" , in "<<filename<<"."<<endl;

        for( int i = 0 ; i < E ; i ++ ){
            //cout<<"read line "<<i<<endl;
            assert( getline(file,line));
            stringstream ss(line);

            int a, b;
            ss>>a>>b;
            assert( a >= 0 && a < V );
            assert( b >= 0 && b < V );
            graph.addEdge(a, b);
        }

    }
};

#endif //GRAPH_READGRAPH_H
