#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){

    for( int i = 1 ; i < n ; i ++ ) {

        // 写法1
//        for( int j = i ; j > 0 ; j-- )
//            if( arr[j] < arr[j-1] )
//                swap( arr[j] , arr[j-1] );
//            else
//                break;

        // 写法2
//        for( int j = i ; j > 0 && arr[j] < arr[j-1] ; j -- )
//            swap( arr[j] , arr[j-1] );

        // 写法3
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }

    return;
}

int main() {

    // 测试1 一般测试
    //int *arr = SortTestHelper::generateRandomArray(10000,0,10000);

    // 测试2 有序性更强的测试
    //int *arr = SortTestHelper::generateRandomArray(10000,0,10);

    // 测试3 测试近乎有序的数组
    int *arr = SortTestHelper::generateNearlyOrderedArray(10000,100);

    SortTestHelper::testSort("Insertion Sort", insertionSort,arr,10000);
    SortTestHelper::testSort("Selection Sort", selectionSort,arr,10000);

    delete(arr);

    return 0;
}