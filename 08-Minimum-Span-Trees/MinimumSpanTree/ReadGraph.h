//
// Created by liuyubobobo on 9/13/16.
//

#ifndef MINIMUMSPANTREE_READGRAPH_H
#define MINIMUMSPANTREE_READGRAPH_H

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
            Weight w;
            ss>>a>>b>>w;
            assert( a >= 0 && a < V );
            assert( b >= 0 && b < V );
            graph.addEdge(a, b, w);
        }

        //cout<<"read "<<filename<<" successfully."<<endl;
    }
};

#endif //MINIMUMSPANTREE_READGRAPH_H
