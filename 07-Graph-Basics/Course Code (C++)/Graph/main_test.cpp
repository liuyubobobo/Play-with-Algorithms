#include <iostream>
#include <vector>
#include <ctime>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "RandomGraph.h"

using namespace std;


int main() {

    int V = 100;
    int E = V*V/10;
    bool directed = false;

    SparseGraph sparseGraph = SparseGraph(V, directed);
    RandomGraph<SparseGraph>(sparseGraph, V, E);

    cout<<"test sparse adjance"<<endl;
    SparseGraph::adjIterator sparseAdj(sparseGraph, 0);
    for( int i = sparseAdj.begin() ; !sparseAdj.end() ; i = sparseAdj.next() )
        cout<<i<<" ";
    cout<<endl;


    DenseGraph denseGraph = DenseGraph(V, directed);
    RandomGraph<DenseGraph>(denseGraph, V, E);

    cout<<"test dense adjance"<<endl;
    DenseGraph::adjIterator denseAdj(denseGraph, 0);
    for( int i = denseAdj.begin() ; !denseAdj.end() ; i = denseAdj.next() )
        cout<<i<<" ";
    cout<<endl;

    return 0;
}