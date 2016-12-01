//
// Created by liuyubobobo on 14/11/2016.
//

#ifndef MERGESORTIMPLEMENTATIONCOMPARISON2_MERGESORT_H
#define MERGESORTIMPLEMENTATIONCOMPARISON2_MERGESORT_H

#include <iostream>
#include <algorithm>
#include "InsertionSort.h"

using namespace std;


// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename  T>
void __merge(T arr[], int l, int mid, int r){

    T aux[r-l+1];
    for( int i = l ; i <= r; i ++ )
        aux[i-l] = arr[i];

    int i = l, j = mid+1;
    for( int k = l ; k <= r; k ++ ){

        if( i > mid )   { arr[k] = aux[j-l]; j ++;}
        else if( j > r ){ arr[k] = aux[i-l]; i ++;}
        else if( aux[i-l] < aux[j-l] ){ arr[k] = aux[i-l]; i ++;}
        else                          { arr[k] = aux[j-l]; j ++;}
    }
}

// 递归使用归并排序,对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort1(T arr[], int l, int r){

    if( l >= r )
        return;

    int mid = (l+r)/2;
    __mergeSort1(arr, l, mid);
    __mergeSort1(arr, mid+1, r);
    __merge(arr, l, mid, r);
}

// 归并排序,无优化
template<typename T>
void mergeSort1(T arr[], int n){

    __mergeSort1( arr , 0 , n-1 );
}


template <typename T>
void mergeSortBU1(T arr[], int n){

    for( int sz = 1; sz <= n ; sz += sz )
        for( int i = 0 ; i < n ; i += sz+sz )
            // 对 arr[i...i+sz-1] 和 arr[i+sz...i+2*sz-1] 进行归并
            __merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1) );

}


template<typename T>
void __mergeSort2(T arr[], int l, int r){

    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

    int mid = (l+r)/2;
    __mergeSort2(arr, l, mid);
    __mergeSort2(arr, mid+1, r);
    if( arr[mid] > arr[mid+1] )
        __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort2(T arr[], int n){

    __mergeSort2( arr , 0 , n-1 );
}


template <typename T>
void mergeSortBU2(T arr[], int n){

    // Merge Sort Bottom Up 优化
    for( int i = 0 ; i < n ; i += 16 )
        insertionSort(arr,i,min(i+15,n-1));

    for( int sz = 16; sz <= n ; sz += sz )
        for( int i = 0 ; i < n - sz ; i += sz+sz )
            if( arr[i+sz-1] > arr[i+sz] )
                __merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1) );
}

#endif //MERGESORTIMPLEMENTATIONCOMPARISON2_MERGESORT_H
