//
// Created by liuyubobobo on 8/16/16.
//

#ifndef INC_06_HEAP_SORT_HEAPSORT_H
#define INC_06_HEAP_SORT_HEAPSORT_H

#include "Heap.h"

using namespace std;


template<typename T>
void heapSort2(T arr[], int n){

    MaxHeap<T> maxheap = MaxHeap<T>(arr,n);
    for( int i = n-1 ; i >= 0 ; i-- )
        arr[i] = maxheap.extractMax();

}


template<typename T>
void heapSort1(T arr[], int n){

    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        maxheap.insert(arr[i]);

    for( int i = n-1 ; i >= 0 ; i-- )
        arr[i] = maxheap.extractMax();

}

#endif //INC_06_HEAP_SORT_HEAPSORT_H
