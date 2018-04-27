#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Components.h"

using namespace std;

// 测试图的联通分量算法
int main() {

    // TestG1.txt - g1 and g2
    string filename1 = "testG1.txt";
    SparseGraph g1 = SparseGraph(13, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename1);
    Component<SparseGraph> component1(g1);
    cout<<"TestG1.txt, Using Sparse Graph, Component Count: "<<component1.count()<<endl;

    DenseGraph g2 = DenseGraph(13, false);
    ReadGraph<DenseGraph> readGraph2(g2, filename1);
    Component<DenseGraph> component2(g2);
    cout<<"TestG1.txt, Using Dense Graph, Component Count: "<<component2.count()<<endl;

    cout<<endl;

    // TestG2.txt - g3 and g4
    string filename2 = "testG2.txt";
    SparseGraph g3 = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph3(g3, filename2);
    Component<SparseGraph> component3(g3);
    cout<<"TestG2.txt, Using Sparse Graph, Component Count: "<<component3.count()<<endl;

    DenseGraph g4 = DenseGraph(7, false);
    ReadGraph<DenseGraph> readGraph4(g4, filename2);
    Component<DenseGraph> component4(g4);
    cout<<"TestG2.txt, Using Dense Graph, Component Count: "<<component4.count()<<endl;


    return 0;
}