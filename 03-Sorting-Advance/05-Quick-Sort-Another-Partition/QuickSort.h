//
// Created by liuyubobobo on 7/22/16.
//

#ifndef INC_05_QUICK_SORT_ANOTHER_PARTITION_QUICKSORT_H
#define INC_05_QUICK_SORT_ANOTHER_PARTITION_QUICKSORT_H

#include <iostream>
#include <algorithm>

using namespace std;


template <typename T>
int _partition(T arr[], int l, int r){

    T v = arr[l];
    int i = l+1, j = r;
    while( true ){
        while( i <= r && arr[i] <= v )
            i ++;

        while( j >= l+1 && arr[j] >= v )
            j --;

        if( i > j )
            break;

        swap( arr[i] , arr[j] );
    }

    swap( arr[l] , arr[j]);

    return j;
}

template <typename T>
void _quickSort(T arr[], int l, int r){

    if( l >= r )
        return;

    int p = _partition(arr, l, r);
    _quickSort(arr, l, p-1 );
    _quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n){

    _quickSort(arr, 0, n-1);
}

#endif //INC_05_QUICK_SORT_ANOTHER_PARTITION_QUICKSORT_H
