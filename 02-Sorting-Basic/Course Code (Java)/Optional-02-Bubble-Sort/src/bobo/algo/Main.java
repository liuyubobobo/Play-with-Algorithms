package bobo.algo;

import java.util.Arrays;

public class Main {

    // 比较SelectionSort, InsertionSort和BubbleSort三种排序算法的性能效率
    public static void main(String[] args) {

        int N = 20000;

        // 测试1 一般测试
        System.out.println("Test for random array, size = " + N + " , random range [0, " + N + "]");

        Integer[] arr1 = SortTestHelper.generateRandomArray(N, 0, N);
        Integer[] arr2 = Arrays.copyOf(arr1, arr1.length);
        Integer[] arr3 = Arrays.copyOf(arr1, arr1.length);
        Integer[] arr4 = Arrays.copyOf(arr1, arr1.length);

        SortTestHelper.testSort("bobo.algo.SelectionSort", arr1);
        SortTestHelper.testSort("bobo.algo.InsertionSort", arr2);
        SortTestHelper.testSort("bobo.algo.BubbleSort", arr3);
        SortTestHelper.testSort("bobo.algo.BubbleSort2", arr4);

        System.out.println();


        // 测试2 测试近乎有序的数组
        int swapTimes = 100;
        System.out.println("Test for nearly ordered array, size = " + N + " , swap time = " + swapTimes);

        arr1 = SortTestHelper.generateNearlyOrderedArray(N, swapTimes);
        arr2 = Arrays.copyOf(arr1, arr1.length);
        arr3 = Arrays.copyOf(arr1, arr1.length);
        arr4 = Arrays.copyOf(arr1, arr1.length);

        SortTestHelper.testSort("bobo.algo.SelectionSort", arr1);
        SortTestHelper.testSort("bobo.algo.InsertionSort", arr2);
        SortTestHelper.testSort("bobo.algo.BubbleSort", arr3);
        SortTestHelper.testSort("bobo.algo.BubbleSort2", arr4);

        System.out.println();

        // 测试3 测试完全有序的数组
        // 对于完全有序的数组，冒泡排序法也将成为O(n)级别的算法
        swapTimes = 0;
        N= 10000000;    // 由于插入排序法和冒泡排序法在完全有序的情况下都将成为O(n)算法
                        // 所以我们的测试数据规模变大，为1000,0000
        System.out.println("Test for ordered array, size = " + N);

        arr1 = SortTestHelper.generateNearlyOrderedArray(N, swapTimes);
        arr2 = Arrays.copyOf(arr1, arr1.length);
        arr3 = Arrays.copyOf(arr1, arr1.length);
        arr4 = Arrays.copyOf(arr1, arr1.length);

        // 在这种情况下，不再测试选择排序算法
        //SortTestHelper.testSort("bobo.algo.SelectionSort", arr1);
        SortTestHelper.testSort("bobo.algo.InsertionSort", arr2);
        SortTestHelper.testSort("bobo.algo.BubbleSort", arr3);
        SortTestHelper.testSort("bobo.algo.BubbleSort2", arr4);

        return;
    }
}
