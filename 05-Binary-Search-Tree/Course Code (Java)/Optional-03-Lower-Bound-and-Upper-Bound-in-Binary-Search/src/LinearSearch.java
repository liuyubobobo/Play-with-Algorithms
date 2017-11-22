/**
 * Created by liuyubobobo on 11/21/17.
 */
public class LinearSearch {

    private LinearSearch(){}

    // 线性查找法, 实现lower_bound
    // 即在一个有序数组arr中, 寻找大于等于target的元素的第一个索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回arr的元素个数 n
    public static int lower_bound(Comparable[] arr, Comparable target){

        if(arr == null)
            throw new IllegalArgumentException("arr can not be null.");

        for(int i = 0 ; i < arr.length ; i ++)
            if(arr[i].compareTo(target) >= 0)
                return i;

        return arr.length;
    }

    // 线性查找法, 实现upper_bound
    // 即在一个有序数组arr中, 寻找大于target的元素的第一个索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回arr的元素个数 n
    public static int upper_bound(Comparable[] arr, Comparable target){

        if(arr == null)
            throw new IllegalArgumentException("arr can not be null.");

        for(int i = 0 ; i < arr.length ; i ++)
            if(arr[i].compareTo(target) > 0)
                return i;

        return arr.length;
    }
}
