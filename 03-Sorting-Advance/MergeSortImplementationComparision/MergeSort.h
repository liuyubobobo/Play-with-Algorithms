//
// Created by liuyubobobo on 08/11/2016.
//

#ifndef MERGESORTIMPLEMENTATIONCOMPARISION_MERGESORT_H
#define MERGESORTIMPLEMENTATIONCOMPARISION_MERGESORT_H

#include <iostream>

using namespace std;


// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename  T>
void __merge1(T arr[], int l, int mid, int r){

    T aux[r-l+1];
    for( int i = l ; i <= r; i ++ )
        aux[i-l] = arr[i];

    int i = l, j = mid+1;
    for( int k = l ; k <= r; k ++ ){

        if( i > mid )   { arr[k] = aux[j-l]; j ++;}
        else if( j > r ){ arr[k] = aux[i-l]; i ++;}
        else if( aux[i-l] < aux[j-l] ){ arr[k] = aux[i-l]; i ++;}
        else                          { arr[k] = aux[j-l]; j ++;}
    }
}

// 递归使用归并排序,对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort1(T arr[], int l, int r){

    if( l >= r )
        return;

    int mid = (l+r)/2;
    __mergeSort1(arr, l, mid);
    __mergeSort1(arr, mid+1, r);
    __merge1(arr, l, mid, r);
}

// 归并排序,无优化
template<typename T>
void mergeSort1(T arr[], int n){

    __mergeSort1( arr , 0 , n-1 );
}



// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename  T>
void __merge2(T arr[], int l, int mid, int r, T aux[]){

    for( int i = l ; i <= r; i ++ )
        aux[i] = arr[i];

    int i = l, j = mid+1;
    for( int k = l ; k <= r; k ++ ){

        if( i > mid )   { arr[k] = aux[j]; j ++;}
        else if( j > r ){ arr[k] = aux[i]; i ++;}
        else if( aux[i] < aux[j] ){ arr[k] = aux[i]; i ++;}
        else                      { arr[k] = aux[j]; j ++;}
    }
}

// 递归使用归并排序,对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort2(T arr[], int l, int r, T aux[]){

    if( l >= r )
        return;

    int mid = (l+r)/2;
    __mergeSort2(arr, l, mid, aux);
    __mergeSort2(arr, mid+1, r, aux);
    __merge2(arr, l, mid, r, aux);
}

// 归并排序,将aux作为参数传递
template<typename T>
void mergeSort2(T arr[], int n){

    T aux[n];
    __mergeSort2( arr , 0 , n-1 , aux );
}

#endif //MERGESORTIMPLEMENTATIONCOMPARISION_MERGESORT_H
