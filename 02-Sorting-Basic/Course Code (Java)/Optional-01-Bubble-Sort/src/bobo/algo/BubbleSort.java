package bobo.algo;

public class BubbleSort {

    // 我们的算法类不允许产生任何实例
    private BubbleSort(){}

    public static void sort(Comparable[] arr){

        int n = arr.length;
        boolean swapped = false;
        //int newn; // 理论上,可以使用newn进行优化,但实际优化效果较差

        do{
            swapped = false;
            //newn = 0;
            for( int i = 1 ; i < n ; i ++ )
                if( arr[i-1].compareTo(arr[i]) > 0 ){
                    swap( arr , i-1 , i );
                    swapped = true;

                    // 可以记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
                    // 实际优化效果较差,因为引入了newn这个新的变量
                    //newn = n;
                }

            //n = newn;

            // 优化, 每一趟Bubble Sort都将最大的元素放在了最后的位置
            // 所以下一次排序, 最后的元素可以不再考虑
            // 理论上, newn的优化是这个优化的复杂版本,应该更有效
            // 实测, 使用这种简单优化, 时间性能更好
            n --;
        }while(swapped);
    }

    private static void swap(Object[] arr, int i, int j) {
        Object t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}
