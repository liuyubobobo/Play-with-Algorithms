package bobo.algo;

import java.util.Arrays;

public class Main {

    // 比较Merge Sort, MergeSortBU; 优化过的MergeSort和MergeSortBU
    // 以及三种快速排序算法的性能
    public static void main(String[] args) {

        int N = 1000000;

        // 测试1 一般性测试
        System.out.println("Test for random array, size = " + N + " , random range [0, " + N + "]");

        Integer[] arr1 = SortTestHelper.generateRandomArray(N, 0, N);
        Integer[] arr2 = Arrays.copyOf(arr1, arr1.length);
        Integer[] arr3 = Arrays.copyOf(arr1, arr1.length);
        Integer[] arr4 = Arrays.copyOf(arr1, arr1.length);
        Integer[] arr5 = Arrays.copyOf(arr1, arr1.length);
        Integer[] arr6 = Arrays.copyOf(arr1, arr1.length);
        Integer[] arr7 = Arrays.copyOf(arr1, arr1.length);

        SortTestHelper.testSort("bobo.algo.MergeSort", arr1);
        SortTestHelper.testSort("bobo.algo.MergeSortBU", arr2);
        SortTestHelper.testSort("bobo.algo.MergeSortO", arr3);
        SortTestHelper.testSort("bobo.algo.MergeSortBUO", arr4);
        SortTestHelper.testSort("bobo.algo.QuickSort", arr5);
        SortTestHelper.testSort("bobo.algo.QuickSort2Ways", arr6);
        SortTestHelper.testSort("bobo.algo.QuickSort3Ways", arr7);

        System.out.println();


        // 测试2 测试近乎有序的数组
        int swapTimes = 100;
        assert swapTimes >= 0;

        System.out.println("Test for nearly ordered array, size = " + N + " , swap time = " + swapTimes);

        arr1 = SortTestHelper.generateNearlyOrderedArray(N, swapTimes);
        arr2 = Arrays.copyOf(arr1, arr1.length);
        arr3 = Arrays.copyOf(arr1, arr1.length);
        arr4 = Arrays.copyOf(arr1, arr1.length);
        arr5 = Arrays.copyOf(arr1, arr1.length);
        arr6 = Arrays.copyOf(arr1, arr1.length);
        arr7 = Arrays.copyOf(arr1, arr1.length);

        SortTestHelper.testSort("bobo.algo.MergeSort", arr1);
        SortTestHelper.testSort("bobo.algo.MergeSortBU", arr2);
        SortTestHelper.testSort("bobo.algo.MergeSortO", arr3);
        SortTestHelper.testSort("bobo.algo.MergeSortBUO", arr4);
        SortTestHelper.testSort("bobo.algo.QuickSort", arr5);
        SortTestHelper.testSort("bobo.algo.QuickSort2Ways", arr6);
        SortTestHelper.testSort("bobo.algo.QuickSort3Ways", arr7);

        System.out.println();


        // 测试3 测试存在包含大量相同元素的数组
        System.out.println("Test for random array, size = " + N + " , random range [0,10]");

        arr1 = SortTestHelper.generateRandomArray(N, 0, 10);
        arr2 = Arrays.copyOf(arr1, arr1.length);
        arr3 = Arrays.copyOf(arr1, arr1.length);
        arr4 = Arrays.copyOf(arr1, arr1.length);
        arr5 = Arrays.copyOf(arr1, arr1.length);
        arr6 = Arrays.copyOf(arr1, arr1.length);
        arr7 = Arrays.copyOf(arr1, arr1.length);

        SortTestHelper.testSort("bobo.algo.MergeSort", arr1);
        SortTestHelper.testSort("bobo.algo.MergeSortBU", arr2);
        SortTestHelper.testSort("bobo.algo.MergeSortO", arr3);
        SortTestHelper.testSort("bobo.algo.MergeSortBUO", arr4);
        // 在包含大量重复元素的情况下, QuickSort会退化成O(n^2)算法, 在这里不做执行
        //SortTestHelper.testSort("bobo.algo.QuickSort", arr5);
        SortTestHelper.testSort("bobo.algo.QuickSort2Ways", arr6);
        SortTestHelper.testSort("bobo.algo.QuickSort3Ways", arr7);


        return;
    }
}