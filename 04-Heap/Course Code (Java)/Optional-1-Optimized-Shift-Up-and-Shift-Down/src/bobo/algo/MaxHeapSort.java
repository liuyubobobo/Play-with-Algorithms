package bobo.algo;

import java.util.*;

// 使用将n个元素插入最大堆中, 再将这n个元素从最大堆中取出的方式, 来对n个元素进行排序
// 以此来检验 MaxHeap 进行ShiftUp和ShiftDown优化前后效率的不同
public class MaxHeapSort {

    // 我们的算法类不允许产生任何实例
    private MaxHeapSort(){}

    // 对整个arr数组使用MaxHeapSort排序
    // MaxHeapSort, 将所有的元素依次添加到堆中, 在将所有元素从堆中依次取出来, 即完成了排序
    public static void sort(Comparable[] arr){

        int n = arr.length;
        MaxHeap<Comparable> maxHeap = new MaxHeap<Comparable>(n);
        for( int i = 0 ; i < n ; i ++ )
            maxHeap.insert(arr[i]);

        for( int i = n-1 ; i >= 0 ; i -- )
            arr[i] = maxHeap.extractMax();
    }

    // 测试 MaxHeapSort
    public static void main(String[] args) {

        int N = 1000000;
        Integer[] arr = SortTestHelper.generateRandomArray(N, 0, 100000);
        SortTestHelper.testSort("bobo.algo.MaxHeapSort", arr);

        return;
    }
}