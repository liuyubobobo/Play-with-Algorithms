#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "MergeSort.h"

using namespace std;

int main() {

    int n = 1000000;

    // 测试1 一般性测试
    cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr = SortTestHelper::generateRandomArray(n,0,n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);

    delete[] arr;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 10;
    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);

    delete[] arr;

    return 0;
}