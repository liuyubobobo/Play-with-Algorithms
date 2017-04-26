#include <iostream>
#include "IndexMinHeap.h"
#include "SortTestHelper.h"

using namespace std;

// 使用最小索引堆进行堆排序, 来验证我们的最小索引堆的正确性
template<typename T>
void heapSortUsingIndexMinHeap(T arr[], int n){

    IndexMinHeap<T> indexMinHeap = IndexMinHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        indexMinHeap.insert( i , arr[i] );

    for( int i = 0 ; i < n ; i ++ )
        arr[i] = indexMinHeap.extractMin();
}

int main() {

    int n = 1000000;

    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("Heap Sort Using Index-Min-Heap", heapSortUsingIndexMinHeap, arr, n);
    delete[] arr;

    return 0;
}