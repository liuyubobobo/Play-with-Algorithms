import java.util.Arrays;

public class Main {

    private Main(){}

    private static Integer[] generateRandomOrderedArray(int n, int rangeL, int rangeR){

        Integer[] arr = new Integer[n];

        for(int i = 0 ; i < n ; i ++)
            arr[i] = (int)(Math.random() * (rangeR - rangeL + 1)) + rangeL;
        Arrays.sort(arr);
        return arr;
    }

    public static void main(String[] args) {

        int n = 1000;
        int m = 100;
        Integer[] arr = generateRandomOrderedArray(n, 0, m);

        /// 我们使用简单的线性查找法来验证我们写的二分查找法
        for (int i = -1; i <= m + 1; i++) {

            if (BinarySearch.lower_bound(arr, i) != LinearSearch.lower_bound(arr, i))
                throw new IllegalArgumentException("lower_bound error!");

            if (BinarySearch.upper_bound(arr, i) != LinearSearch.upper_bound(arr, i))
                throw new IllegalArgumentException("upper_bound error!");
        }

        System.out.println("test completed:)");
    }
}
