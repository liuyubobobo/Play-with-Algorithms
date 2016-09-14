#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <string>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"

using namespace std;

int main() {

    string filename = "testG1.txt";
    int V = 8;

//    string filename = "testG2.txt";
//    int V = 250;

    cout<<fixed<<setprecision(2);
    // Test Weighted Sparse Graph
    SparseGraph<double> g1 = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>> readGraph1(g1, filename);
    g1.show();
    cout<<endl;

    // Test Weighted Dense Graph
    DenseGraph<double> g2 = DenseGraph<double>(V, false);
    ReadGraph<DenseGraph<double>> readGraph2(g2, filename);
    g2.show();
    cout<<endl;

    return 0;
}