//
// Created by liuyubobobo on 20/04/2017.
//

#ifndef MERGESORTANDSHELLSORT_QUICKSORT2WAYS_H
#define MERGESORTANDSHELLSORT_QUICKSORT2WAYS_H


#include <iostream>
#include <algorithm>
#include "InsertionSort.h"

using namespace std;

// 双路快速排序的partition
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int _partition2(T arr[], int l, int r){

    // 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
    swap( arr[l] , arr[rand()%(r-l+1)+l] );
    T v = arr[l];

    // arr[l+1...i) <= v; arr(j...r] >= v
    int i = l+1, j = r;
    while( true ){
        // 注意这里的边界, arr[i] < v, 不能是arr[i] <= v
        // 思考一下为什么?
        while( i <= r && arr[i] < v )
            i ++;

        // 注意这里的边界, arr[j] > v, 不能是arr[j] >= v
        // 思考一下为什么?
        while( j >= l+1 && arr[j] > v )
            j --;

        // 对于上面的两个边界的设定, 有的同学在课程的问答区有很好的回答:)
        // 大家可以参考: http://coding.imooc.com/learn/questiondetail/4920.html

        if( i > j )
            break;

        swap( arr[i] , arr[j] );
        i ++;
        j --;
    }

    swap( arr[l] , arr[j]);

    return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void _quickSort2Ways(T arr[], int l, int r){

    // 对于小规模数组, 使用插入排序进行优化
    if( r - l <= 15 ){
        insertionSort(arr,l,r);
        return;
    }

    // 调用双路快速排序的partition
    int p = _partition2(arr, l, r);
    _quickSort2Ways(arr, l, p-1 );
    _quickSort2Ways(arr, p+1, r);
}

template <typename T>
void quickSort2Ways(T arr[], int n){

    srand(time(NULL));
    _quickSort2Ways(arr, 0, n-1);
}

#endif //MERGESORTANDSHELLSORT_QUICKSORT2WAYS_H
