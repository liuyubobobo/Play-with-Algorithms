//
// Created by liuyubobobo on 7/15/16.
//

#ifndef OPTIONAL_02_SHELL_SORT_INSERTIONSORT_H
#define OPTIONAL_02_SHELL_SORT_INSERTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;


template<typename T>
void insertionSort(T arr[], int n){

    for( int i = 1 ; i < n ; i ++ ) {

        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }

    return;
}

#endif //OPTIONAL_02_SHELL_SORT_INSERTIONSORT_H
