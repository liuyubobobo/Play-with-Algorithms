#include <iostream>
#include "UnionFind5.h"

using namespace std;

int main() {

    UF5::UnionFind uf = UF5::UnionFind(5);
    uf.unionElements(1,0);
    uf.unionElements(2,1);
    uf.unionElements(3,2);
    uf.unionElements(4,3);
    uf.show();

    cout<<"======"<<endl;
    uf.find(4);
    uf.show();

    return 0;
}