/**
 * Created by liuyubobobo on 11/21/17.
 */
public class BinarySearch {

    private BinarySearch(){}

    // 二分查找法, 在一个有序数组arr中, 寻找大于等于target的元素的第一个索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回arr的元素个数 n
    // 相当于 lower_bound
    public static int firstGreaterOrEqual(Comparable[] arr, Comparable target){

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

    // 二分查找法, 在一个有序数组arr中, 寻找大于target的元素的第一个索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回arr的元素个数 n
    // 相当于 upper_bound
    public static int firstGreaterThan(Comparable[] arr, Comparable target){

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

    // 二分查找法, 在一个有序数组arr中, 寻找小于等于target的元素的最大索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回 -1
    public static int lastLessOrEqual(Comparable[] arr, Comparable target){

        if(arr == null)
            throw new IllegalArgumentException("arr can not be null.");

        int l = -1, r = arr.length - 1;
        while(l != r){
            int mid = l + (r - l + 1) / 2;
            if(arr[mid].compareTo(target) > 0)
                r = mid - 1;
            else    // nums[mid] <= target
                l = mid;
        }

        return l;
    }

    // 二分查找法, 在一个有序数组arr中, 寻找小于target的元素的最大索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回 -1
    public static int lastLessThan(Comparable[] arr, Comparable target){

        if(arr == null)
            throw new IllegalArgumentException("arr can not be null.");

        int l = -1, r = arr.length - 1;
        while(l != r){
            int mid = l + (r - l + 1) / 2;
            if(arr[mid].compareTo(target) >= 0)
                r = mid - 1;
            else    // nums[mid] < target
                l = mid;
        }

        return l;
    }
}
