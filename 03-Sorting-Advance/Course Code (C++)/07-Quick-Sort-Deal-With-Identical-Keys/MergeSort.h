//
// Created by liuyubobobo on 7/23/16.
//

#ifndef INC_07_QUICK_SORT_DEAL_WITH_IDENTICAL_KEYS_MERGESORT_H
#define INC_07_QUICK_SORT_DEAL_WITH_IDENTICAL_KEYS_MERGESORT_H

#include <iostream>
#include <algorithm>
#include "InsertionSort.h"

using namespace std;


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

template<typename T>
void __mergeSort(T arr[], int l, int r){

    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

    int mid = (l+r)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    if( arr[mid] > arr[mid+1] )
        __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n){

    __mergeSort( arr , 0 , n-1 );
}

#endif //INC_07_QUICK_SORT_DEAL_WITH_IDENTICAL_KEYS_MERGESORT_H
