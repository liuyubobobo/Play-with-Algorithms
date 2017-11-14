#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

using namespace std;


// 我们的第一版bubbleSort
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

        // 优化, 每一趟Bubble Sort都将最大的元素放在了最后的位置
        // 所以下一次排序, 最后的元素可以不再考虑
        n --;

    }while(swapped);
}


// 我们的第二版bubbleSort,使用newn进行优化
template<typename T>
void bubbleSort2( T arr[] , int n){

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

int main() {

    int n = 20000;

    // 测试1 一般测试
    cout<<"Test for random array, size = "<<n<<", randome range [0, "<<n<<"]"<<endl;

    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort 2", bubbleSort, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;

    cout<<"Test for nNearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;

    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort 2", bubbleSort, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout<<endl;


    // 测试3 测试完全有序的数组
    // 对于完全有序的数组，冒泡排序法也将成为O(n)级别的算法
    swapTimes = 0;
    n = 10000000;    // 由于插入排序法和冒泡排序法在完全有序的情况下都将成为O(n)算法
                     // 所以我们的测试数据规模变大，为1000,0000
    cout<<"Test for ordered array, size = " << n << endl;

    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);

    // 在这种情况下，不再测试选择排序算法
    //SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort 2", bubbleSort, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;


    return 0;
}