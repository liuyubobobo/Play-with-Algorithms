package bobo.algo;

import java.util.*;

public class MergeSortBU2{

    // 我们的算法类不允许产生任何实例
    private MergeSortBU2(){}

    // 将arr[l...mid]和arr[mid+1...r]两部分进行归并
    // 其中aux为完成merge过程所需要的辅助空间
    private static void merge(Comparable[] arr, Comparable[] aux, int l, int mid, int r) {

        System.arraycopy(arr, l, aux, l, r-l+1);

        // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
        int i = l, j = mid+1;
        for( int k = l ; k <= r; k ++ ){

            if( i > mid ){  // 如果左半部分元素已经全部处理完毕
                arr[k] = aux[j]; j ++;
            }
            else if( j > r ){   // 如果右半部分元素已经全部处理完毕
                arr[k] = aux[i]; i ++;
            }
            else if( aux[i].compareTo(aux[j]) < 0 ){  // 左半部分所指元素 < 右半部分所指元素
                arr[k] = aux[i]; i ++;
            }
            else{  // 左半部分所指元素 >= 右半部分所指元素
                arr[k] = aux[j]; j ++;
            }
        }
    }

    public static void sort(Comparable[] arr){

        int n = arr.length;

        // 对于小数组, 使用插入排序优化
        for( int i = 0 ; i < n ; i += 16 )
            InsertionSort.sort(arr, i, Math.min(i+15, n-1) );

        Comparable[] aux = new Comparable[n];
        for( int sz = 16; sz < n ; sz += sz )
            for( int i = 0 ; i < n - sz ; i += sz+sz )
                // 对于arr[mid] <= arr[mid+1]的情况,不进行merge
                if( arr[i+sz-1].compareTo(arr[i+sz]) > 0 )
                    merge(arr, aux, i, i+sz-1, Math.min(i+sz+sz-1,n-1) );

    }

    // 测试 MergeSort BU 2
    public static void main(String[] args) {

        // Merge Sort BU 2 也是一个O(nlogn)复杂度的算法，虽然只使用两重for循环
        // 所以，Merge Sort BU 2 也可以在1秒之内轻松处理100万数量级的数据
        // 注意：不要轻易根据循环层数来判断算法的复杂度，Merge Sort BU 2 就是一个反例
        // 关于这部分陷阱，推荐看我的《玩转算法面试》课程，第二章：《面试中的复杂度分析》：）
        int N = 1000000;
        Integer[] arr = SortTestHelper.generateRandomArray(N, 0, 100000);
        SortTestHelper.testSort("bobo.algo.MergeSortBU2", arr);

        return;
    }
}