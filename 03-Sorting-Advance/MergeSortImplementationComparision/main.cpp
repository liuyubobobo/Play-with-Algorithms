#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "MergeSort.h"

using namespace std;

// 这个例子用于比较归并排序中,若将aux数组作为参数传给__merge子过程,整个归并排序会更快
int main() {

    int n = 1000000;
    int T = 100;

    double time1 = 0.0, time2 = 0.0;
    for( int i = 0 ; i < T ; i ++ ) {
        int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
        int *arr2 = SortTestHelper::copyIntArray(arr1, n);

        time1 += SortTestHelper::testSort(mergeSort1, arr1, n);
        time2 += SortTestHelper::testSort(mergeSort2, arr2, n);

        delete[] arr1;
        delete[] arr2;
    }

    cout << "Merge Sort 1 Average Run Time: " << time1/T << " s"<<endl;
    cout << "Merge Sort 2 Average Run Time: " << time2/T << " s"<<endl;

    return 0;
}