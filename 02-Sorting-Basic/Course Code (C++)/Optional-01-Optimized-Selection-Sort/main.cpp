#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

using namespace std;

// 感谢github @zhengquan45 提出, 可以对选择排序进行优化
// 在每一轮中, 可以同时找到当前未处理元素的最大值和最小值
template<typename T>
void selectionSort(T arr[], int n){

    int left = 0, right = n - 1;
    while(left < right){
        int minIndex = left;
        int maxIndex = right;

        // 在每一轮查找时, 要保证arr[minIndex] <= arr[maxIndex]
        if(arr[minIndex] > arr[maxIndex])
            swap(arr[minIndex], arr[maxIndex]);

        for(int i = left + 1 ; i < right; i ++)
            if(arr[i] < arr[minIndex])
                minIndex = i;
            else if(arr[i] > arr[maxIndex])
                maxIndex = i;

        swap(arr[left], arr[minIndex]);
        swap(arr[right], arr[maxIndex]);

        left ++;
        right --;
    }

    return;
}

int main() {

    int n = 40000;
    
    // 测试1 一般测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);
    SortTestHelper::testSort("Selection Sort 2", selectionSort,arr3,n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout<<endl;


    // 测试2 有序性更强的测试
    cout<<"Test for more ordered random array, size = "<<n<<", random range [0, 3]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,3);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);
    SortTestHelper::testSort("Selection Sort 2", selectionSort,arr3,n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout<<endl;


    // 测试3 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);
    SortTestHelper::testSort("Selection Sort 2", selectionSort,arr3,n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}