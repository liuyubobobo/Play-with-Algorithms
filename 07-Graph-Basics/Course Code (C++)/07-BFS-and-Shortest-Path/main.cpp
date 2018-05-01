#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Path.h"
#include "ShortestPath.h"

using namespace std;

// 测试无权图最短路径算法
int main() {

    string filename = "testG.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();

    // 比较使用深度优先遍历和广度优先遍历获得路径的不同
    // 广度优先遍历获得的是无权图的最短路径
    Path<SparseGraph> dfs(g,0);
    cout << "DFS : ";
    dfs.showPath(6);

    ShortestPath<SparseGraph> bfs(g,0);
    cout << "BFS : ";
    bfs.showPath(6);

    cout << endl;

    filename = "testG1.txt";
    SparseGraph g2 = SparseGraph(13, false);
    ReadGraph<SparseGraph> readGraph2(g2, filename);
    g2.show();

    // 比较使用深度优先遍历和广度优先遍历获得路径的不同
    // 广度优先遍历获得的是无权图的最短路径
    Path<SparseGraph> dfs2(g2,0);
    cout << "DFS : ";
    dfs2.showPath(3);

    ShortestPath<SparseGraph> bfs2(g,0);
    cout << "BFS : ";
    bfs2.showPath(3);

    return 0;
}