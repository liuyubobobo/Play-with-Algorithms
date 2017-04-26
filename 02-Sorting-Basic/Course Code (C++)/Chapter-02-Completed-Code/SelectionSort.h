//
// Created by liuyubobobo on 4/25/17.
//

#ifndef CHAPTER_02_COMPLETED_CODE_SELECTIONSORT_H
#define CHAPTER_02_COMPLETED_CODE_SELECTIONSORT_H

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

#endif //CHAPTER_02_COMPLETED_CODE_SELECTIONSORT_H
