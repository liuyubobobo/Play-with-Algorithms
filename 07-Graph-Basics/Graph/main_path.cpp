#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "Path.h"
#include "ShortestPath.h"
#include "ReadGraph.h"

using namespace std;


int main() {

    string filename = "testG2.txt";
    SparseGraph g = SparseGraph(6, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    cout<<endl;

    Path<SparseGraph> dfs(g,0,5);
    cout<<"DFS : ";
    dfs.showPath();

    ShortestPath<SparseGraph> bfs(g,0,5);
    cout<<"BFS : ";
    bfs.showPath();

    return 0;
}