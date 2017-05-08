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

// 测试深度优先遍历和广度优先遍历的寻路算法
int main() {

    string filename = "testG2.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    cout<<endl;

    Path<SparseGraph> dfs(g,0);
    cout<<"DFS : ";
    dfs.showPath(6);

    ShortestPath<SparseGraph> bfs(g,0);
    cout<<"BFS : ";
    bfs.showPath(6);

    return 0;
}