#include <iostream>
#include "MaxHeap.h"
#include "MaxHeapO.h"
#include "SortTestHelper.h"

using namespace std;

// 使用将n个元素插入最大堆中, 再将这n个元素从最大堆中取出的方式, 来对n个元素进行排序
// 以此来检验 MaxHeap 进行ShiftUp和ShiftDown优化前后效率的不同
template<typename T>
void maxHeapTestBySort(T arr[], int n){

    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        maxheap.insert(arr[i]);

    for( int i = n-1 ; i >= 0 ; i-- )
        arr[i] = maxheap.extractMax();
}

template<typename T>
void maxHeapOTestBySort(T arr[], int n){

    MaxHeapO<T> maxheap = MaxHeapO<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        maxheap.insert(arr[i]);

    for( int i = n-1 ; i >= 0 ; i-- )
        arr[i] = maxheap.extractMax();
}

int main() {

    int n = 1000000;

    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Sort by MaxHeap", maxHeapTestBySort, arr1, n);
    SortTestHelper::testSort("Sort by MaxHeap Optimized", maxHeapOTestBySort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    return 0;
}