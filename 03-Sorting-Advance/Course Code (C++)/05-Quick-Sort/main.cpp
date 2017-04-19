#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertionSort.h"

using namespace std;

// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r){

    T v = arr[l];

    int j = l; // arr[l+1...j] < v ; arr[j+1...i) > v
    for( int i = l + 1 ; i <= r ; i ++ )
        if( arr[i] < v ){
            j ++;
            swap( arr[j] , arr[i] );
        }

    swap( arr[l] , arr[j]);

    return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r){

    if( l >= r )
        return;

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1 );
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n){

    __quickSort(arr, 0, n-1);
}


// 比较Merge Sort和Quick Sort两种排序算法的性能效率
// 两种排序算法虽然都是O(nlogn)级别的, 但是Quick Sort算法有常数级的优势
// Quick Sort要比Merge Sort快, 即使我们对Merge Sort进行了优化
int main() {

    int n = 1000000;

    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    // 但是对于近乎有序的数组, 我们的快速排序算法退化成了O(n^2)级别的算法
    // 思考一下为什么对于近乎有序的数组, 快排退化成了O(n^2)的算法? :)
//    int swapTimes = 100;
//    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
//    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
//    arr2 = SortTestHelper::copyIntArray(arr1, n);
//
//    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
//    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
//
//    delete[] arr1;
//    delete[] arr2;


    return 0;
}