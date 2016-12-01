//
// Created by liuyubobobo on 9/24/16.
//

#ifndef INC_03_LAZY_PRIM_READGRAPH_H
#define INC_03_LAZY_PRIM_READGRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;


template <typename Graph, typename Weight>
class ReadGraph{

public:
    ReadGraph(Graph &graph, const string &filename){

        ifstream file(filename);
        string line;
        int V, E;

        assert(file.is_open());

        assert( getline(file,line));
        stringstream ss(line);
        ss>>V>>E;
        assert( graph.V() == V );

        for( int i = 0 ; i < E ; i ++ ){
            assert( getline(file,line));
            stringstream ss(line);

            int a, b;
            Weight w;
            ss>>a>>b>>w;
            assert( a >= 0 && a < V );
            assert( b >= 0 && b < V );
            graph.addEdge(a, b, w);
        }

    }
};

#endif //INC_03_LAZY_PRIM_READGRAPH_H
