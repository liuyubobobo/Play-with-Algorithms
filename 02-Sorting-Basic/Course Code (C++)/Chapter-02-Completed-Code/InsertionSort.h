//
// Created by liuyubobobo on 4/25/17.
//

#ifndef CHAPTER_02_COMPLETED_CODE_INSERTIONSORT_H
#define CHAPTER_02_COMPLETED_CODE_INSERTIONSORT_H

template<typename T>
void insertionSort(T arr[], int n){

    for( int i = 1 ; i < n ; i ++ ) {
        T e = arr[i];
        int j; // j保存元素e应该插入的位置
        for (j = i; j > 0 && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }

    return;
}

#endif //CHAPTER_02_COMPLETED_CODE_INSERTIONSORT_H
