#include <iostream>
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "SortTestHelper.h"

using namespace std;

int main() {

    int n = 20000;

    // 测试1 一般测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort,arr1,n);
    SortTestHelper::testSort("Insertion Sort", insertionSort,arr2,n);

    delete[] arr1;
    delete[] arr2;

    cout<<endl;


    // 测试2 有序性更强的测试
    cout<<"Test for more ordered random array, size = "<<n<<", random range [0, 3]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,3);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort,arr1,n);
    SortTestHelper::testSort("Insertion Sort", insertionSort,arr2,n);

    delete[] arr1;
    delete[] arr2;

    cout<<endl;


    // 测试3 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort,arr1,n);
    SortTestHelper::testSort("Insertion Sort", insertionSort,arr2,n);

    delete[] arr1;
    delete[] arr2;

    return 0;
}