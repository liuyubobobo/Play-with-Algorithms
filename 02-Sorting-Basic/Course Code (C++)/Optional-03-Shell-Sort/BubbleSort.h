//
// Created by liuyubobobo on 7/15/16.
//

#ifndef OPTIONAL_02_SHELL_SORT_BUBBLESORT_H
#define OPTIONAL_02_SHELL_SORT_BUBBLESORT_H

#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void bubbleSort( T arr[] , int n){

    int newn; // 使用newn进行优化

    do{
        newn = 0;
        for( int i = 1 ; i < n ; i ++ )
            if( arr[i-1] > arr[i] ){
                swap( arr[i-1] , arr[i] );

                // 记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
                newn = i;
            }
        n = newn;
    }while(newn > 0);
}

#endif //OPTIONAL_02_SHELL_SORT_BUBBLESORT_H
