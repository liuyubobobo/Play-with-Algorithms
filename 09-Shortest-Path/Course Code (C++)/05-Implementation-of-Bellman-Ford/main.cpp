#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "BellmanFord.h"

using namespace std;

// 测试Bellman-Ford算法
int main() {

    string filename = "testG2.txt";
    //string filename = "testG_negative_circle.txt";
    int V = 5;

    SparseGraph<int> g = SparseGraph<int>(V, true);
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

    cout<<"Test Bellman-Ford:"<<endl<<endl;

    int s = 0;
    BellmanFord<SparseGraph<int>, int> bellmanFord(g, s);
    if( bellmanFord.negativeCycle() )
        cout<<"The graph contain negative cycle!"<<endl;
    else
        for( int i = 0 ; i < V ; i ++ ) {
            if(i == s)
                continue;

            if (bellmanFord.hasPathTo(i)) {
                cout << "Shortest Path to " << i << " : " << bellmanFord.shortestPathTo(i) << endl;
                bellmanFord.showPath(i);
            }
            else
                cout << "No Path to " << i << endl;

            cout << "----------" << endl;
        }

    return 0;
}