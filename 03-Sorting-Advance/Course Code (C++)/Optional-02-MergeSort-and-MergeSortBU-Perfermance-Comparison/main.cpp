#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"

using namespace std;

// 比较 Merge Sort 和 Merge Sort BU 的性能效率
// 使用更科学的比较方式, 每次比较都运行多次测试用例, 取平均值
// 同时比较了优化和不优化两种情况
// 总体来说, Merge Sort BU 比 Merge Sort 快一些。但优化后, 二者的性能差距不明显
// 对于这个问题更详细分析, 可以看课程的问答:
// http://coding.imooc.com/learn/questiondetail/3208.html
int main() {

    // 测试T个测试用例, 每个测试用例的数组大小为n
    int T = 100;
    int n = 1000000;

    // 比较 Merge Sort 和 Merge Sort BU 两种算法在不优化的情况下的性能效率
    double time1 = 0.0, time2 = 0.0;
    for( int i = 0 ; i < T ; i ++ ) {
        int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
        int *arr2 = SortTestHelper::copyIntArray(arr1, n);

        time1 += SortTestHelper::testSort(mergeSort1, arr1, n);
        time2 += SortTestHelper::testSort(mergeSortBU1, arr2, n);

        delete[] arr1;
        delete[] arr2;
    }

    cout << "Without Any Optimization:" << endl;
    cout << "Merge Sort    Average Run Time: " << time1/T << " s" << endl;
    cout << "Merge Sort BU Average Run Time: " << time2/T << " s" << endl;

    cout << endl;


    // 比较 Merge Sort 和 Merge Sort BU 两种算法在优化的情况下的性能效率
    time1 = 0.0, time2 = 0.0;
    for( int i = 0 ; i < T ; i ++ ) {
        int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
        int *arr2 = SortTestHelper::copyIntArray(arr1, n);

        time1 += SortTestHelper::testSort(mergeSort2, arr1, n);
        time2 += SortTestHelper::testSort(mergeSortBU2, arr2, n);

        delete[] arr1;
        delete[] arr2;
    }

    cout << "With Optimization:" << endl;
    cout << "Merge Sort    Average Run Time: " << time1/T << " s" << endl;
    cout << "Merge Sort BU Average Run Time: " << time2/T << " s" << endl;


    return 0;
}