#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include "BinarySearch.h"
#include "LinearSearch.h"

using namespace std;

int* generateRandomOrderedArray(int n, int rangeL, int rangeR){

    int* arr = new int[n];

    srand(time(NULL));
    for(int i = 0 ; i < n ; i ++)
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    sort(arr, arr + n);
    return arr;
}

int main() {

    int n = 1000;
    int m = 100;
    int* arr = generateRandomOrderedArray(n, 0, m);

    /// 我们使用简单的线性查找法来验证我们写的二分查找法
    for(int i = -1 ; i <= m + 1 ; i ++) {
        assert(BinarySearch::firstGreaterOrEqual(arr, n, i) ==
               LinearSearch::firstGreaterOrEqual(arr, n, i));
        assert(BinarySearch::firstGreaterThan(arr, n, i) ==
               LinearSearch::firstGreaterThan(arr, n, i));
        assert(BinarySearch::lastLessOrEqual(arr, n, i) ==
               LinearSearch::lastLessOrEqual(arr, n, i));
        assert(BinarySearch::lastLessThan(arr, n, i) ==
               LinearSearch::lastLessThan(arr, n, i));
    }

    cout << "test completed:)" << endl;

    return 0;
}