/**
 * Created by liuyubobobo on 11/21/17.
 */
public class BinarySearch {

    private BinarySearch(){}

    // 二分查找法, 实现lower_bound
    // 即在一个有序数组arr中, 寻找大于等于target的元素的第一个索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回arr的元素个数 n
    public static int lower_bound(Comparable[] arr, Comparable target){

        if(arr == null)
            throw new IllegalArgumentException("arr can not be null.");

        int l = 0, r = arr.length;
        while(l != r){
            int mid = l + (r - l) / 2;
            if(arr[mid].compareTo(target) < 0)
                l = mid + 1;
            else    // nums[mid] >= target
                r = mid;
        }
        return l;
    }

    // 二分查找法, 实现upper_bound
    // 即在一个有序数组arr中, 寻找大于target的元素的第一个索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回arr的元素个数 n
    public static int upper_bound(Comparable[] arr, Comparable target){

        if(arr == null)
            throw new IllegalArgumentException("arr can not be null.");

        int l = 0, r = arr.length;
        while(l != r){
            int mid = l + (r - l) / 2;
            if(arr[mid].compareTo(target) <= 0)
                l = mid + 1;
            else    // nums[mid] > target
                r = mid;
        }
        return l;
    }
}
