#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

using namespace std;


template<typename T>
void bubbleSort( T arr[] , int n){

    bool swapped;
    //int newn; // 理论上,可以使用newn进行优化,但实际优化效果较差

    do{
        swapped = false;
        //newn = 0;
        for( int i = 1 ; i < n ; i ++ )
            if( arr[i-1] > arr[i] ){
                swap( arr[i-1] , arr[i] );
                swapped = true;

                // 可以记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
                // 实际优化效果较差,因为引入了newn这个新的变量
                //newn = n;
            }

        //n = newn;

        // 优化,每一趟Bubble Sort都将最大的元素放在了最后的位置
        // 所以下一次排序,最后的元素可以不再考虑
        // 理论上,newn的优化是这个优化的复杂版本,应该更有效
        // 实测,使用这种简单优化,时间性能更好
        n --;

    }while(swapped);
}

int main() {

    int n = 10000;

    // Test for Random Array
    cout<<"Test for Random Array, size = "<<n<<", randome range [0, "<<n<<"]"<<endl;

    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout<<endl;


    // Test for Random Nearly Ordered Array
    int swapTimes = 100;

    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<", swap time = "<<swapTimes<<endl;

    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}