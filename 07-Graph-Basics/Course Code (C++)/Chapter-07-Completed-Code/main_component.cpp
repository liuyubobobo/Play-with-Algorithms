#include <iostream>
#include <vector>
#include <ctime>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "RandomGraph.h"
#include "Component.h"

using namespace std;

// 随机生成一个图, 求其连通性
int main() {

    // Test Random Graph Component
    int V = 100;
    int E = V*(V-1)/2/10;
    bool directed = false;

    SparseGraph g1 = SparseGraph(V, directed);
    RandomGraph<SparseGraph>(g1, V, E);

    Component<SparseGraph> component1(g1);
    cout<<"Test Random Graph, Component Count: "<<component1.count()<<endl;

    return 0;
}