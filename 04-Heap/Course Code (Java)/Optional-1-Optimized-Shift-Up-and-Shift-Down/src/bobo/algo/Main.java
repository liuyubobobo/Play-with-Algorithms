package bobo.algo;

import java.util.Arrays;

public class Main {

    // 比较 MaxHeapSort 和 MaxHeapOSort 的性能的不同
    // 以此来检验 MaxHeap 进行ShiftUp和ShiftDown优化前后效率的不同
    public static void main(String[] args) {

        int N = 1000000;

        System.out.println("Test for random array, size = " + N + " , random range [0, " + N + "]");

        Integer[] arr1 = SortTestHelper.generateRandomArray(N, 0, N);
        Integer[] arr2 = Arrays.copyOf(arr1, arr1.length);

        SortTestHelper.testSort("bobo.algo.MaxHeapSort", arr1);
        SortTestHelper.testSort("bobo.algo.MaxHeapOSort", arr2);

        return;
    }
}