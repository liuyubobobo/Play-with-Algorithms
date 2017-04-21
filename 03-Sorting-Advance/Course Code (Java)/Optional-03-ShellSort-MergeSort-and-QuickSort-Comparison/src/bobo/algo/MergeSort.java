package bobo.algo;

import java.util.*;

// 自顶向下的归并排序, 含优化
public class MergeSort{

    // 我们的算法类不允许产生任何实例
    private MergeSort(){}

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

    // 递归使用归并排序,对arr[l...r]的范围进行排序
    // 其中aux为完成merge过程所需要的辅助空间
    private static void sort(Comparable[] arr, Comparable[] aux, int l, int r) {

        // 对于小规模数组, 使用插入排序
        if( r - l <= 15 ){
            InsertionSort.sort(arr, l, r);
            return;
        }

        int mid = (l+r)/2;
        sort(arr, aux, l, mid);
        sort(arr, aux, mid + 1, r);
        // 对于arr[mid] <= arr[mid+1]的情况,不进行merge
        // 对于近乎有序的数组非常有效,但是对于一般情况,有一定的性能损失
        if( arr[mid].compareTo(arr[mid+1]) > 0 )
            merge(arr, aux, l, mid, r);
    }

    public static void sort(Comparable[] arr){

        int n = arr.length;
        Comparable[] aux = new Comparable[n];
        sort(arr, aux, 0, n-1);
    }

    // 测试 MergeSort
    public static void main(String[] args) {

        int N = 1000000;
        Integer[] arr = SortTestHelper.generateRandomArray(N, 0, 100000);
        SortTestHelper.testSort("bobo.algo.MergeSort", arr);

        return;
    }
}