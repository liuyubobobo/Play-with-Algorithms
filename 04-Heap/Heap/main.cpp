#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "IndexMaxHeap.h"
#include "IndexMinHeap.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void heapSortUsingMaxHeap(T arr[], int n){

    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        maxheap.insert(arr[i]);

    for( int i = n-1 ; i >= 0 ; i-- )
        arr[i] = maxheap.extractMax();

}

template<typename T>
void heapSortUsingIndexMaxHeap(T arr[], int n){

    IndexMaxHeap<T> indexMaxheap = IndexMaxHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        indexMaxheap.insert(i, arr[i]);

    for( int i = n-1 ; i >= 0 ; i-- )
        arr[i] = indexMaxheap.extractMax();

}

template<typename T>
void heapSortUsingMinHeap(T arr[], int n){

    MinHeap<T> minheap = MinHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        minheap.insert(arr[i]);

    for( int i = 0 ; i < n ; i++ )
        arr[i] = minheap.extractMin();

}

template<typename T>
void heapSortUsingIndexMinHeap(T arr[], int n){

    IndexMinHeap<T> indexMinheap = IndexMinHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        indexMinheap.insert(i, arr[i]);

    for( int i = 0 ; i < n ; i++ )
        arr[i] = indexMinheap.extractMin();

}

int main() {

    int n = 1000000;

    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    int* arr4 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Heap Sort Using Max Heap", heapSortUsingMaxHeap, arr1, n);
    SortTestHelper::testSort("Heap Sort Using Index Max Heap", heapSortUsingIndexMaxHeap, arr2, n);
    SortTestHelper::testSort("Heap Sort Using Min Heap", heapSortUsingMinHeap, arr3, n);
    SortTestHelper::testSort("Heap Sort Using Index Min Heap", heapSortUsingIndexMinHeap, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    return 0;
}