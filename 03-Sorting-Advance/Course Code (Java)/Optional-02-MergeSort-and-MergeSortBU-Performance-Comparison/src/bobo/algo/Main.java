package bobo.algo;

import java.util.Arrays;

public class Main {

    // 比较 Merge Sort 和 Merge Sort BU 的性能效率
    // 使用更科学的比较方式, 每次比较都运行多次测试用例, 取平均值
    // 同时比较了优化和不优化两种情况
    // 总体来说, Merge Sort BU 比 Merge Sort 快一些。但优化后, 二者的性能差距不明显
    // 对于这个问题更详细分析, 可以看课程的问答:
    // http://coding.imooc.com/learn/questiondetail/3208.html
    public static void main(String[] args) {

        // 测试T个测试用例, 每个测试用例的数组大小为n
        int T = 100;
        int N = 1000000;

        // 比较 Merge Sort 和 Merge Sort BU 两种算法在不优化的情况下的性能效率
        long time1 = 0, time2 = 0;
        for( int i = 0 ; i < T ; i ++ ) {
            Integer[] arr1 = SortTestHelper.generateRandomArray(N, 0, N);
            Integer[] arr2 = Arrays.copyOf(arr1, arr1.length);

            time1 += SortTestHelper.testSort2("bobo.algo.MergeSort", arr1);
            time2 += SortTestHelper.testSort2("bobo.algo.MergeSortBU", arr2);
        }
        System.out.println("Without Any Optimization:");
        System.out.println("Merge Sort    Average Run Time: " + time1/T + " ms");
        System.out.println("Merge Sort BU Average Run Time: " + time2/T + " ms");
        System.out.println();


        // 比较 Merge Sort 和 Merge Sort BU 两种算法在含优化的情况下的性能效率
        time1 = 0; time2 = 0;
        for( int i = 0 ; i < T ; i ++ ) {
            Integer[] arr1 = SortTestHelper.generateRandomArray(N, 0, N);
            Integer[] arr2 = Arrays.copyOf(arr1, arr1.length);

            time1 += SortTestHelper.testSort2("bobo.algo.MergeSort2", arr1);
            time2 += SortTestHelper.testSort2("bobo.algo.MergeSortBU2", arr2);
        }
        System.out.println("With Optimization:");
        System.out.println("Merge Sort    Average Run Time: " + time1/T + " ms");
        System.out.println("Merge Sort BU Average Run Time: " + time2/T + " ms");


        return;
    }
}