//
// Created by liuyubobobo on 9/6/16.
//

#ifndef GRAPH_RANDOMGRAPH_H
#define GRAPH_RANDOMGRAPH_H

#include <iostream>
#include <ctime>

using namespace std;


template <typename Graph>
class RandomGraph{

public:
    RandomGraph( Graph &graph, int V, int E){

        double p = (double)2*E / (V*(V-1));

        srand(time(NULL));
        for( int i = 0 ; i < V ; i ++ )
            for( int j = i+1 ; j < V ; j ++ ){

                double randomValue = (double)rand() / RAND_MAX;
                if( randomValue < p ){
                    graph.addEdge(i,j);
                }
            }
    }
};
#endif //GRAPH_RANDOMGRAPH_H
