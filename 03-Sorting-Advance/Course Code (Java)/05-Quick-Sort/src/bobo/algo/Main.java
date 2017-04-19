package bobo.algo;

import java.util.Arrays;

public class Main {

    // 比较Merge Sort和Quick Sort两种排序算法的性能效率
    // 两种排序算法虽然都是O(nlogn)级别的, 但是Quick Sort算法有常数级的优势
    // Quick Sort要比Merge Sort快, 即使我们对Merge Sort进行了优化
    public static void main(String[] args) {

        int N = 1000000;

        System.out.println("Test for random array, size = " + N + " , random range [0, " + N + "]");

        Integer[] arr1 = SortTestHelper.generateRandomArray(N, 0, N);
        Integer[] arr2 = Arrays.copyOf(arr1, arr1.length);

        SortTestHelper.testSort("bobo.algo.MergeSort", arr1);
        SortTestHelper.testSort("bobo.algo.QuickSort", arr2);

        System.out.println();

        return;
    }
}