//
// Created by liuyubobobo on 4/25/17.
//

#ifndef CHAPTER_04_COMPLETED_CODE_HEAPSORT_H
#define CHAPTER_04_COMPLETED_CODE_HEAPSORT_H

#include <iostream>
#include <algorithm>

// 优化的shiftDown过程, 使用赋值的方式取代不断的swap,
// 该优化思想和我们之前对插入排序进行优化的思路是一致的
template<typename T>
void __shiftDown(T arr[], int n, int k){

    T e = arr[k];
    while( 2*k+1 < n ){
        int j = 2*k+1;
        if( j+1 < n && arr[j+1] > arr[j] )
            j += 1;

        if( e >= arr[j] ) break;

        arr[k] = arr[j];
        k = j;
    }

    arr[k] = e;
}

// 不使用一个额外的最大堆, 直接在原数组上进行原地的堆排序
template<typename T>
void heapSort(T arr[], int n){

    // 注意，此时我们的堆是从0开始索引的
    // 从(最后一个元素的索引-1)/2开始
    // 最后一个元素的索引 = n-1
    for( int i = (n-1-1)/2 ; i >= 0 ; i -- )
        __shiftDown2(arr, n, i);

    for( int i = n-1; i > 0 ; i-- ){
        swap( arr[0] , arr[i] );
        __shiftDown(arr, i, 0);
    }
}

using namespace std;

#endif //CHAPTER_04_COMPLETED_CODE_HEAPSORT_H
