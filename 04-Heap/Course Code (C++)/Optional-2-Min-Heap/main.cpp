#include <iostream>
#include "MinHeap.h"
#include "SortTestHelper.h"

using namespace std;

// 将所有的元素依次添加到最小堆中, 再在将所有元素从堆中依次取出来, 完成排序
// 使用这样的一个最小堆排序, 来检验我们的最小堆的正确性
// 思考：使用最小堆可不可以编写如第6小节所介绍的优化的快速排序算法？
template<typename T>
void heapSortUsingMinHeap(T arr[], int n){

    MinHeap<T> minheap = MinHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        minheap.insert(arr[i]);

    for( int i = 0 ; i < n ; i ++ )
        arr[i] = minheap.extractMin();

}

int main() {

    int n = 1000000;

    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("Heap Sort Using Min-Heap", heapSortUsingMinHeap, arr, n);

    return 0;
}