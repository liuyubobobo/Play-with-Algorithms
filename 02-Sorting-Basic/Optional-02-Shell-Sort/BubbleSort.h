//
// Created by liuyubobobo on 7/15/16.
//

#include <iostream>
#include <algorithm>

using namespace std;


#ifndef OPTIONAL_02_SHELL_SORT_BUBBLESORT_H
#define OPTIONAL_02_SHELL_SORT_BUBBLESORT_H

template<typename T>
void bubbleSort( T arr[] , int n){

    bool swapped;

    do{
        swapped = false;
        for( int i = 1 ; i < n ; i ++ )
            if( arr[i-1] > arr[i] ){
                swap( arr[i-1] , arr[i] );
                swapped = true;
            }

        n --;

    }while(swapped);
}

#endif //OPTIONAL_02_SHELL_SORT_BUBBLESORT_H
