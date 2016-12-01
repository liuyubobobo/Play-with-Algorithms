//
// Created by liuyubobobo on 7/13/16.
//

#ifndef INC_04_INSERTION_SORT_ADVANCE_SELECTIONSORT_H
#define INC_04_INSERTION_SORT_ADVANCE_SELECTIONSORT_H

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

#endif //INC_04_INSERTION_SORT_ADVANCE_SELECTIONSORT_H
