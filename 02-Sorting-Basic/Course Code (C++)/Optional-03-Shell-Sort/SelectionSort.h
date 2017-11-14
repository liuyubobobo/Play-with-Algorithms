//
// Created by liuyubobobo on 7/15/16.
//

#ifndef OPTIONAL_02_SHELL_SORT_SELECTIONSORT_H
#define OPTIONAL_02_SHELL_SORT_SELECTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;


template<typename T>
void selectionSort(T arr[], int n){

    for(int i = 0 ; i < n ; i ++){

        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;

        swap( arr[i] , arr[minIndex] );
    }
}

#endif //OPTIONAL_02_SHELL_SORT_SELECTIONSORT_H
