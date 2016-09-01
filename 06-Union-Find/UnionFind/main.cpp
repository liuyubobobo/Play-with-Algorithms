#include <iostream>
#include "UnionFindTestHelper.h"

using namespace std;

int main() {

    int n = 10000;

    UnionFindTestHelper::testUF1(n);
    UnionFindTestHelper::testUF2(n);
    UnionFindTestHelper::testUF3(n);
    //UnionFindTestHelper::testUF4(n);
    //UnionFindTestHelper::testUF5(n);

    return 0;
}