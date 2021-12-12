#include <iostream>
#include "SortTestHelper.h"

using namespace std;

// 因为 arr 数组不会动，所以声明成 const
template<typename T>
void indexedSelectionSort(const T arr[], int indexes[], int n){

    for(int i = 0 ; i < n ; i ++){

        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            // 注意：比较的是 arr[indexes[j]] 和 arr[indexes[minIndex]] 的关系
            // 对比直接排序中，比较的是 arr[j] 和 arr[minIndex] 的关系
            if( arr[indexes[j]] < arr[indexes[minIndex]])
                minIndex = j;

        // 调整的是 indexes 数组，arr 数组不会动
        swap(indexes[i] , indexes[minIndex]);
    }
}

int main() {

    int N = 20000;
    int *arr = SortTestHelper::generateRandomArray(N,0,100000);

    // 在排序过程中，我们不动 arr，而动 indexes，indexes 中表示索引
    int *indexes = new int[N];
    for(int i = 0; i < N; i ++) indexes[i] = i;

    indexedSelectionSort(arr, indexes, N);

    // 最终，arr[indexes[0]], arr[indexes[1]], arr[indexes[2]]... 排成了一个有序数列
    for(int i = 1; i < N; i ++)
        assert(arr[indexes[i - 1]] <= arr[indexes[i]]);

    delete[] arr;
    delete[] indexes;

    return 0;
}