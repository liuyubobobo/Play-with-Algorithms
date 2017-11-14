
//
// Created by liuyubobobo on 7/16/16.
//

#ifndef INC_04_INSERTION_SORT_ADVANCE_SELECTIONSORT_H
#define INC_04_INSERTION_SORT_ADVANCE_SELECTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;


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

#endif //INC_04_INSERTION_SORT_ADVANCE_SELECTIONSORT_H
