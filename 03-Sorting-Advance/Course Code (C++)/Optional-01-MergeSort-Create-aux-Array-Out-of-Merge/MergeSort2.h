//
// Created by liuyubobobo on 20/04/2017.
//

#ifndef MERGESORT2_MERGESORT2_H
#define MERGESORT2_MERGESORT2_H

#include <iostream>

using namespace std;


// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
// 其中aux为完成merge过程所需要的辅助空间
template<typename  T>
void __merge2(T arr[], T aux[], int l, int mid, int r){

    // 由于aux的大小和arr一样, 所以我们也不需要处理aux索引的偏移量
    // 进一步节省了计算量:)
    for( int i = l ; i <= r; i ++ )
        aux[i] = arr[i];

    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
    int i = l, j = mid+1;
    for( int k = l ; k <= r; k ++ ){

        if( i > mid ){  // 如果左半部分元素已经全部处理完毕
            arr[k] = aux[j]; j ++;
        }
        else if( j > r ){  // 如果右半部分元素已经全部处理完毕
            arr[k] = aux[i]; i ++;
        }
        else if( aux[i] < aux[j] ) {  // 左半部分所指元素 < 右半部分所指元素
            arr[k] = aux[i]; i ++;
        }
        else{  // 左半部分所指元素 >= 右半部分所指元素
            arr[k] = aux[j]; j ++;
        }
    }

}

// 使用优化的归并排序算法, 对arr[l...r]的范围进行排序
// 其中aux为完成merge过程所需要的辅助空间
template<typename T>
void __mergeSort2(T arr[], T aux[], int l, int r){

    // 对于小规模数组, 使用插入排序
    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

    int mid = (l+r)/2;
    __mergeSort2(arr, aux, l, mid);
    __mergeSort2(arr, aux, mid+1, r);

    // 对于arr[mid] <= arr[mid+1]的情况,不进行merge
    // 对于近乎有序的数组非常有效,但是对于一般情况,有一定的性能损失
    if( arr[mid] > arr[mid+1] )
        __merge2(arr, aux, l, mid, r);
}


template<typename T>
void mergeSort2(T arr[], int n){

    // 在 mergeSort2中, 我们一次性申请aux空间,
    // 并将这个辅助空间以参数形式传递给完成归并排序的各个子函数
    T *aux = new T[n];

    __mergeSort2( arr , aux, 0 , n-1 );

    delete[] aux;   // 使用C++, new出来的空间不要忘记释放掉:)
}

#endif //MERGESORT2_MERGESORT2_H
