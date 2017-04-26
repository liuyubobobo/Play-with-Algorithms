//
// Created by liuyubobobo on 4/25/17.
//

#ifndef CHAPTER_03_COMPLETED_CODE_MERGESORTBU_H
#define CHAPTER_03_COMPLETED_CODE_MERGESORTBU_H

#include <iostream>
#include <algorithm>

using namespace std;

// 自底向上的归并排序中, merge函数并没有改变
// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename  T>
void __mergeBU(T arr[], int l, int mid, int r){

    //* VS不支持动态长度数组, 即不能使用 T aux[r-l+1]的方式申请aux的空间
    //* 使用VS的同学, 请使用new的方式申请aux空间
    //* 使用new申请空间, 不要忘了在__merge函数的最后, delete掉申请的空间:)
    T aux[r-l+1];
    //T *aux = new T[r-l+1];

    for( int i = l ; i <= r; i ++ )
        aux[i-l] = arr[i];

    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
    int i = l, j = mid+1;
    for( int k = l ; k <= r; k ++ ){

        if( i > mid ){  // 如果左半部分元素已经全部处理完毕
            arr[k] = aux[j-l]; j ++;
        }
        else if( j > r ){  // 如果右半部分元素已经全部处理完毕
            arr[k] = aux[i-l]; i ++;
        }
        else if( aux[i-l] < aux[j-l] ) {  // 左半部分所指元素 < 右半部分所指元素
            arr[k] = aux[i-l]; i ++;
        }
        else{  // 左半部分所指元素 >= 右半部分所指元素
            arr[k] = aux[j-l]; j ++;
        }
    }

    //delete[] aux;
}

// 使用自底向上的归并排序算法
template <typename T>
void mergeSortBU(T arr[], int n){

    // Merge Sort Bottom Up 无优化版本
    for( int sz = 1; sz < n ; sz += sz )
        for( int i = 0 ; i < n - sz ; i += sz+sz )
            // 对 arr[i...i+sz-1] 和 arr[i+sz...i+2*sz-1] 进行归并
            __mergeBU(arr, i, i+sz-1, min(i+sz+sz-1,n-1) );

}

#endif //CHAPTER_03_COMPLETED_CODE_MERGESORTBU_H
