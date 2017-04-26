package bobo.algo;

import java.util.*;

public class MinHeapSort {

    // 我们的算法类不允许产生任何实例
    private MinHeapSort(){}

    // 将所有的元素依次添加到最小堆中, 再在将所有元素从堆中依次取出来, 完成排序
    // 使用这样的一个最小堆排序, 来检验我们的最小堆的正确性
    // 思考：使用最小堆可不可以编写如第6小节所介绍的优化的快速排序算法？
    public static void sort(Comparable[] arr){

        int n = arr.length;
        MinHeap<Comparable> minHeap = new MinHeap<Comparable>(n);
        for( int i = 0 ; i < n ; i ++ )
            minHeap.insert(arr[i]);

        for( int i = 0 ; i < n ; i ++ )
            arr[i] = minHeap.extractMin();
    }

    // 测试 MinHeapSort
    public static void main(String[] args) {

        int N = 1000000;
        Integer[] arr = SortTestHelper.generateRandomArray(N, 0, 100000);
        SortTestHelper.testSort("bobo.algo.MinHeapSort", arr);

        return;
    }
}