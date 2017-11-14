package bobo.algo;

// 感谢github @zhengquan45 提出, 可以对选择排序进行优化
// 在每一轮中, 可以同时找到当前未处理元素的最大值和最小值
public class SelectionSort2 {

    // 我们的算法类不允许产生任何实例
    private SelectionSort2(){}

    public static void sort(Comparable[] arr){

        int left = 0, right = arr.length - 1;
        while(left < right){
            int minIndex = left;
            int maxIndex = right;

            // 在每一轮查找时, 要保证arr[minIndex] <= arr[maxIndex]
            if(arr[minIndex].compareTo(arr[maxIndex]) > 0)
                swap(arr, minIndex, maxIndex);

            for(int i = left + 1 ; i < right; i ++)
                if(arr[i].compareTo(arr[minIndex]) < 0)
                    minIndex = i;
                else if(arr[i].compareTo(arr[maxIndex]) > 0)
                    maxIndex = i;

            swap(arr, left, minIndex);
            swap(arr, right, maxIndex);

            left ++;
            right --;
        }
    }

    private static void swap(Object[] arr, int i, int j) {
        Object t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    // 测试SelectionSort2
    public static void main(String[] args) {

        int N = 20000;
        Integer[] arr = SortTestHelper.generateRandomArray(N, 0, 100000);
        SortTestHelper.testSort("bobo.algo.SelectionSort2", arr);

        return;
    }
}
