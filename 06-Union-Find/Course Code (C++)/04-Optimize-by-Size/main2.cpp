#include <iostream>
#include "UnionFind2.h"
#include "UnionFind3.h"

using namespace std;


// 演示极端情况下，UF2 会退化。
int main() {

    int n = 100000;

    UF2::UnionFind uf2 = UF2::UnionFind(n);

    time_t startTime = clock();
    for(int i = 1; i < n; i ++)
        uf2.unionElements(0, i);
    for(int i = 1; i < n; i ++)
        uf2.isConnected(0, i);
    time_t endTime = clock();

    cout<< "UF2: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;


    UF3::UnionFind uf3 = UF3::UnionFind(n);

    startTime = clock();
    for(int i = 1; i < n; i ++)
        uf3.isConnected(0, i);
    for(int i = 1; i < n; i ++)
        uf3.isConnected(0, i);
    endTime = clock();

    cout<< "UF3: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

    return 0;
}